// Do it! 알고리즘 코딩테스트 책자
// 010번. 최솟값 찾기 (BOJ #11003)
// 노션 정리 링크 -> https://chnh506.notion.site/BOJ-11003-34e85ee40ca144d3aefbaed3b45d06e1

#include <iostream>
#include <deque>

using namespace std;

typedef pair<int, int> Node;

int main(void) { 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, L;
    cin>>N>>L;

    deque<Node> dq;

    for(int i=0; i<N; i++) {
        int a;
        cin>>a;

        while(!dq.empty() && dq.back().second > a) {
            dq.pop_back();
        }
        dq.push_back(Node(i, a));

        if(dq.front().first <= i - L) {
            dq.pop_front();
        }

        cout<<dq.front().second<<" ";
    }

    cout << "\n";

    return 0;
}


// another answer code
// 원래 AccessEmptyContainer 런타임 에러가 떴었으나 ... 해결하는 데 성공!
// 디버깅의 중요성 ...
#include <iostream>
#include <deque>
#include <vector>

using namespace std;

typedef pair<int, int> Node;

int main1(void) { 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, L;
    cin>>N>>L;
    
    vector<int> A(N+1, 0);
    for(int i=1; i<=N; i++) {
        cin>>A[i];
    }

    deque<Node> dq;
    dq.push_back(Node(1, A[1]));
    cout<<dq.front().second<<" ";

    for(int i=2; i<=N; i++) {
        while(!dq.empty() && dq.back().second > A[i]) {
            dq.pop_back();
        }
        dq.push_back(Node(i, A[i]));

        if(i - dq.front().first >= L) dq.pop_front();

        cout<<dq.front().second<<" "; 
    }

    cout << "\n";

    return 0;
}