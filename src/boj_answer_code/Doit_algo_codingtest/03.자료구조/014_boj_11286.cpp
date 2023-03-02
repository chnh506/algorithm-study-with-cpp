// Do it! 알고리즘 코딩테스트 책자
// 014번. 절댓값 힙 (BOJ #11286)
// 노션 정리 링크 → https://chnh506.notion.site/BOJ-11286-7e0dbb23dcf149a8a02863fb6d17bde2

#include <cstdlib>
#include <iostream>
#include <queue>

using namespace std;

struct cmp {
    bool operator()(int n1, int n2) {
        if(abs(n1) > abs(n2))
            return true;
        else if(abs(n1) == abs(n2)) {
            if(n1 > n2) return true;
            else return false;
        }
        return false;
    }
};

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, x;
    priority_queue<int, vector<int>, cmp> pq;

    cin>>N;

    for(int i=0; i<N; i++) {
        cin>>x;

        if(x != 0) pq.push(x);
        else {
            if(pq.empty()) cout<<0<<"\n";
            else {
                cout<<pq.top()<<"\n";
                pq.pop();
            }
        }
    }   

    return 0;
}
