### async/await
__비동기 위주로 프로그래밍할 때 자주 이용__

- async는 function 앞에 붙인다.
  - async function은 항상 promise를 반환한다.
- await은 async function에서만 작동한다.
  - promise가 처리될 때 까지 기다린다.

async/await 없이 프로미스만 이용
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
- 코드는 여전히 길다...

async/await 이용해서 코딩
```javascript
async function findAndSaveUser(Users) {
    let user = await Users.findOne({}); //여기!!
    user.name = 'zero';
    user = await user.save();
    user = await Users.findOne({gender: 'm'});
    //생략
}
```
- 코드가 몹시 짧아졌다.
- 예를들면 ㄴawait Uers.findOne({})이 resolve될 때 까지 기다렸다가 user가 초기화 된다.

