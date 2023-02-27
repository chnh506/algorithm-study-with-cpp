// Do it! 알고리즘 코딩테스트 책자
// 013번. 카드2 (BOJ #2164)
// 노션 정리 링크 → https://chnh506.notion.site/BOJ-2164-2-93cd9ea9ffb449808f1b566d42aef247

#include <iostream>
#include <queue>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    queue<int> q;
    
    cin>>N;
    for(int i=1; i<=N; i++) {
        q.push(i);
    }

    while(q.size() > 1) {
        q.pop();
        q.push(q.front());
        q.pop();
    }

    cout<<q.front()<<"\n";

    return 0;
}

