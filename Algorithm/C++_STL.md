### __pair__
__:2개의 데이터를 저장할 수 있는 변수, 비교 연산시 first, second 순으로 비교__  
_\#include \<utility>에 저장되어있지만, 보통 algorithm이나 vector 헤더 파일이 utility를 포함함_

```C++
#include <utility>
using namespace std;

int main(void){
    //선언
    pair<int, int> p;
    //생성자
    p = make_pair(4, 5);
    //C++ 11부터 사용가능
    p = {4, 5};
    //first, second로 접근
    p.first = 4;
    p.scond = 5;
}
```

### __stack, queue__
__:기본적인 stack, queue__  
_stack은 위로 쌓기 때문에 top, queue는 줄을 세우기에 front로 다르다._
```C++
/*스택*/
#include <stack>
using namespace std;

int main(void){
    //선언
    stack<int> st;
    //push, pop
    st.push(4);
    st.pop();
    //접근자
    int top = st.top();
    //원소의 수
    int size = st.size();
    //비어있는지?
    bool isEmpty = st.empty();
}
```

```C++
/*큐*/
#include <queue>
using namespace std;

int main(void){
    //선언
    queue<int> q;
    //push, pop
    q.push(4);
    q.pop();
    //접근자
    int front = q.front();
    //원소의 수
    int size = q.size();
    //비어있는지?
    bool isEmpty = q.empty();
}
```

### __vector__
__동적 배열__  
_알아서 메모리를 할당해주는 효자 컨테이너_

```C++
#include <vector>
using namespace std;

int main(void){
    // 선언
    vector<int> v;
    // push, pop
    v.push_back(4);
    v.pop_back();
    //참조
    v.front();
    v.back();
    //iterator
    v.begin();
    v.end();
    // 벡터의 크기
    v.size();
}
```

### __priority queue, deque__
__우선순위 큐, double ended queue__  
_deque은 vector와 동작이 비슷하며 vector의 단점을 보완하는 컨테이너이다._
```C++
/*priority queue*/
#inlcude <queue>
using namespace std;

int main(void){
    //선언
    priority_queue <int> pq;
    //접근자
    pq.top();
    //나머지 동일
}
```

```C++
/*double ended queue*/
#inlcude <deque>
using namespace std;

int main(void){
    //선언
    deque<int> dq;
    //push, pop (양방향 가능)
    dq.push_front(1);
    dq.push_back(2);
    dq.pop_front();
    dq.pop_back();
    //참조
    dq.front();
    dq.back();
}
```