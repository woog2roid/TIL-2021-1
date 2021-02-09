### 프로미스
- ES6부터는 JS와 노드의 API들이 콜백 대신 프로미스 기반으로 재구성 됨
- 콜백지옥을 극복했다는 평가를 받음

"프로미스"
- 실행은 바로 하되 결과값은 나중에 받는 객체
- 결과값은 실행이 완료된 후 then이나 catch 메서드를 통해 받음
  - new Promise는 바로 실행되지만, 결과값은 tehn을 붙여야만 받을 수 있음
```javascript
const condition = true;
const promise = new Promise((resolve, reject) => {
    if(condition) {
        resolve('성공');
    }
    else {
        reject('실패');
    }
});
//다른 코드가 들어갈 수 있음

promise
    .then((message) => {
        console.log(message); //성공(resolve)한 경우 실행
    })
    .catch((error) => {
        console.log(error); //실패(reject)한 경우 실행
    })
    .finally(() => {
        console.log('무조건') // 끝나고 무조건 실행
    });
```
1. new Promise로 프로미스 객체 생성
2. resolve와 reject를 매개변수로 하는 callback함수를 넣기
3. 프로미스 내부적으로 resolve가 호출되면 then이 실행됨/ reject가 호출되면 catch가 실행됨

### 콜백을 프로미스로 바꾸기
콜백
```javascript
function findAndSaveUser(Users) {
    Users.findOne({}, (err, user) => { //첫 번째 콜백
        if (err) {
            return console.error(err);
        }
        user.name = 'zero';
        user.save((err) => {
            if (err) { //두 번째 콜백
                return console.error(err);
            }
            Users.findOne({gender:'m'}, (err,user) => { //세 번째 콜백
                //생략
            })
        })
    })
}
```
- 코드의 깊이가 점점 깊어짐
- 에러도 계속해서 따로 처리해주어야 함

프로미스
```javascript
function findAndSaveUser(Users) {
    Users.findOne({})
        .then((user) => {
            user.name = 'zero';
            return user.save();
        })
        .then((user) => {
            return Users.findOne({gender: 'm'});
        })
        .then((user) => {
            //생략
        })
        .catch(err => {
            console.error(err);
        })
}
```
- then 메서드들은 순차적으로 진행됨
- 마지막 catch에서 한번에 에러처리를 할 수 있음
- 하지만, 메서드가 프로미스 방식을 지원할 때만 이렇게 바꿀 수 있음
  - findOne, save가 프로미스 객체를 가지고 있다고 가정한 코드임
  - 즉, new Promise가 내부에 구현되어있어야 함