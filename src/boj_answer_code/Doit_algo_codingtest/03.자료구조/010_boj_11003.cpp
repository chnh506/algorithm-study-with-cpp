// Do it! 알고리즘 코딩테스트 책자
// 010번. 최솟값 찾기 (BOJ #11003)
// 노션 정리 링크 -> https://www.notion.so/chnh506/BOJ-11003-34e85ee40ca144d3aefbaed3b45d06e1?pvs=4

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
