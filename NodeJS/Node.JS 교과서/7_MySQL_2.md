## 시퀄라이즈 Sequelize
- ORM(Object - relational Mapping): 자바스크립트 객체와 데이터베이스의 릴레이션을 매핑해주는 도구
- 자바스크립트 구문을 알아서 SQL로 바꿔줌

## mySQL 연결하기
``` javascript
const {sequelize} = require('./models');

sequelize.sync({ force: flase })
    .then (() => {
        console.log("연결 성공");
    })
    .catch((err) => {
        console.error(err);
    })
```
## 모델 정의하기
MySQL의 테이블 <=(대응)=> 시퀄라이즈 모델, 시퀄라이즈는 저 둘을 연동시키는 역할을 함.

아래의 코드는 이전에 만든 SQL의 user를 다시 쓴 것임.
```javascript
const Sequelize = require('sequelize');

//클래스 문법을 사용하지만, 패턴만 숙지하면 크게 문제가 되지 않음
module.exports = class User extends Sequelize.Model {
  static init(sequelize) {
    return super.init({
      name: {
        type: Sequelize.STRING(20),
        allowNull: false,
        unique: true,
      },
      age: {
        type: Sequelize.INTEGER.UNSIGNED,
        allowNull: false,
      },
      married: {
        type: Sequelize.BOOLEAN,
        allowNull: false,
      },
      comment: {
        type: Sequelize.TEXT,
        allowNull: true,
      },
      created_at: {
        type: Sequelize.DATE,
        allowNull: false,
        defaultValue: Sequelize.NOW,
      },
    }, {
      sequelize,
      timestamps: false,//true인 경우 createdAT과 updateAt 컬럼 추가함
      underscored: false,//camel case가 기본인데, snaked case로 바꾸는 옵션
      modelName: 'User',//모델 이름을 설정가능
      tableName: 'users',//실제 DB의 테이블이름이 됨, 보통 모델이름을 소문자+복수형으로 적음
      paranoid: false,//deletedAt이 만들어짐
      charset: 'utf8',
      collate: 'utf8_general_ci',
    });
  }

  static associate(db) { // 관계 정의하기
    //hasMany vs belongsTo
    //user한 명이 여러개의 댓글을 다니까 user가 hasMany
    db.User.hasMany(db.Comment, { foreignKey: 'commenter', sourceKey: 'id' });
    //user한 명이 여러개의 댓글을 다니까 comment가 belongsTo
    //db.Comment.belongsTo(db.User, {foreignKey: 'commenter', targetKey: 'id'});
  }
};
```

## 관계 정의하기
- 위와 같이 user와 comment의 관계는 1:N과 같은 관계임
- 물론 당연히 1:1과 N:M의 관계도 있다.

__1:1의 관계에서는__: (유저와 info의 관계)
- hasMany대신에 hasOne을 사용한다.
- 1:1이라고 해도 hasOne과 belongsTo를 바꾸면 안된다.
```javascript
db.User.hasOne(db.Info, {foreignKey: 'UserId', sourceKey: 'id'});
db.Info.belongsTo(db.User, {foreignKey: 'UserId', targetKey: 'id'});
```

__N:M의 관계에서는__: (태그와 게시물의 관계)
- belongsToMany 메서드를 이용하면 된다.
```javascript
db.Post.belongsToMany(db.Hastag, {through: 'PostHashtag'});
db.Hashtag.belongsToMany(db.Post, {through: 'PostHashtag'});
```

## 시퀄라이즈 쿼리 정리: CREATE
```javascript
const { User } = require('../models');
User.create({
  name: 'zero',
  age: 24,
  married: false,
  comment: '자기소개',
})
```
- models 모듈에서 User 모델을 불러왔다는 가정하에 진행하였음
- 데이터를 넣을 때, MySQL의 자료형이 아니라 시퀄라이즈 모델에 정의한 자료형 대로 넣어야 한다.

## 시퀄라이즈 쿼리 정리: READ
```javascript
User.findAll({}); //users 테이블의 모든 데이터를 조회하는 SQL문을 만든다.
User.findOne({}); //하나만 가져온다.


//attributes 옵션을 이용해서 원하는 컬럼만 가져올 수 있다.
User.findall({
  attributes: ['name', 'married'],
});

//where 옵션이 조건들을 나열하는 옵션이다.
User.findAll({
  attributes: ['name', 'age'],
  where: {
    married: true,
    age: {[Op.gt]: 30},//Op.gt(초과)
  }
})

//order과 limit offset 등의 옵션도 설정할 수 있다.
User.findAll({
  attributes: ['id', 'name'],
  order: ['age', 'DESC'],
  limit: 1,
  offset: 1,
});
```

## 시퀄라이즈 쿼리 정리: UPDATE
```javascript
User.update({
  comment: '바꿀내용',
}, {
  where: {id:2},
});
```

## 시퀄라이즈 쿼리 정리: DELETE
```javascript
User.destroy({
  where: {id:2},
});
```
