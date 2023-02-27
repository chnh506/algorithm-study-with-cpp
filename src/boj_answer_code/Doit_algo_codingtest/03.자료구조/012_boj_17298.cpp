// Do it! 알고리즘 코딩테스트 책자
// 012번. 오큰수 (BOJ #17298)
// 노션 정리 링크 → https://chnh506.notion.site/BOJ-17298-9de268db1cc84a519bb06c1118913b85

#include <iostream>
#include <stack>
#include <vector>

using namespace std;


int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin>>N;

    vector<int> A(N, 0);
    for(int i=0; i<N; i++) {
        cin>>A[i];
    }

    vector<int> nge(N, 0);
    stack<int> s;
    for(int i=N-1; i>=0; i--) {
        if(s.empty()) {
            nge[i] = -1;
            s.push(A[i]);
            continue;
        }

        while(A[i] >= s.top()) {
            // 스택의 맨 위 값이 A[i]보다 작다면(즉, 오큰수가 될 수 없다면),
            // pop해 버리는 것을 반복하다가 스택이 비면 -1 저장.
            s.pop();
            if(s.empty()) {
                nge[i] = -1;
                break;
            }
        }

        if(!s.empty()) {
            // pop하는 과정을 반복했을 때 스택이 비지 않았다면,
            // top에 있는 값이 오큰수! (인덱스가 큰 것부터 먼저 push되니까)
            nge[i] = s.top();
        }

        // 이번 인덱스의 값을 스택에 push하고 그 다음(즉, 1 작은) 인덱스의 오큰수 찾으러 loop
        s.push(A[i]);
    }

    for(int i=0; i<N; i++) {
        cout<<nge[i]<<" ";
    }
    cout<<"\n";

    return 0;
}

