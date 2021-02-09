### class
__ES6에서는 class 문법도 추가되었다. 하지만 그저 프로토타입 기반 문법을 보기 좋게 클래스로 바꾼 것이다.__

프로토타입 상속 예제 코드
```javascript
var Human = function(type) {
    this.type = type || 'human';
};
Human.isHuman = function(human) {
    return human instance of Human;
};
Human.prototype.breathe = function() {
    alert('haaaam');
};

var Zero = function(type, fisrtName, lastName) {
    Human.apply(this, arguments);
    this.firstName = firstName;
    this.lastName = lastName;
};
Zero.prototype = Object.create(Human.prototype);
Zero.prototype.constructor = Zero; // 상속하는 부분
Zero.prototype.syaName = function () {
    alert(this.firstName + '' + this.lastName);
};

var oldZero = new Zero('human, 'XX', 'Woo');
Human.isHuman(oldZero); // ture
```
- 상속하는 부분이 깔끔하지 않다. (상당히 난해하고 이해하기 어렵다)
- 여담이지만, 리터럴을 사용하지 않는다.

클래스 기반 코드
```javascript
class Human {
    constructor(type = 'human') {
        this.type = type;
    }

    static isHuman(human) {
        return human instance of Human;
    }
   
    breathe() {
        alert('haaaam');    
    }
}

class Zero extends Human {
    constructor(type, firstName, lastName) {
        super(type);
        this.firstName = firstName;
        this.lastName = lastName;
    }

    sayName() {
        super.breathe();
        alert(`${this.firstName} ${this.lastName}`);
    }
}

const newZero = new Zero('human', 'XX' 'Woo');
Human.isHuman(newZero); // trure
```
- 클래스 문법으로 익숙하다.
  - 다만 이렇게 작성하였더라도 자바스크립트는 프로토타입 기반으로 동작함/
- 여담이지만, 리터럴을 사용하였다.