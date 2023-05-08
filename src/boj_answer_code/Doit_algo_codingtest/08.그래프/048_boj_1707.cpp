// Do it! 알고리즘 코딩테스트 책자
// 048. 이분 그래프 (BOJ #1707)
// 노션 정리 링크 → https://chnh506.notion.site/BOJ-1707-3979e45b289b4c159e6e4800ac08fc9c

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> A;  // 그래프의 인접 리스트 표현
vector<int> color;      // 색상 기록해두는 vector
void dfs(int node, int c);

int K, V, E, u, v;
bool res;               // 결과 변수

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>K;
    for(int i=0; i<K; i++) {
        res = true;
        cin>>V>>E;
        A = vector<vector<int>> (V+1);
        color = vector<int> (V+1, 0);

        for(int j=0; j<E; j++) {
            cin>>u>>v;
            A[u].push_back(v);
            A[v].push_back(u);
        }

        for(int i=1; i<=V; i++) {
            if(color[i] == 0) dfs(i, 1);
        }

        if(res) cout<<"YES"<<"\n";
        else cout<<"NO"<<"\n";
    }
    

    return 0;
}

void dfs(int node, int c) {
    color[node] = c;

    for(int i : A[node]) {
        if(color[i] == 0) dfs(i, c * -1);
        else if(color[i] == c) res = false;
        else continue;
    }
}