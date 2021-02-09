### 구조분해 할당
__객체와 배열로부터 속성이나 요소를 쉽게 꺼낼 수 있음__

```javascript
const candyMachine = {
    status: {
         name: 'node',
         count: 5,
    },
    getCandy() {
        this.status.count--;
        return this.status.count;
    },
};

const {getCAndy, status: {count}} = candyMachine;
/*
var getCandy = candyMachine.getCandy;
var count = candyMachine.status.count;
와 동일한 코드
*/
```