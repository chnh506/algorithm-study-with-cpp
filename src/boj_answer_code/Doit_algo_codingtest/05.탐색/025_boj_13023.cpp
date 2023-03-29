// Do it! 알고리즘 코딩테스트 책자
// 025. ABCDE (BOJ #13023)
// 노션 정리 링크 → https://chnh506.notion.site/BOJ-13023-ABCDE-e8b0a5610901461899856dc9deac9f55

#include <iostream>
#include <vector>

using namespace std;

void dfs(int n, vector<bool> visited, int depth);

static vector<vector<int>> adjList;
int res = 0;
int N, M;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N>>M;

    adjList = vector<vector<int>> (N, vector<int>(0));
    vector<bool> visited(N, false);

    int a, b;
    for(int i=0; i<M; i++) {
        cin>>a>>b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    for(int i=0; i<N; i++) {
        dfs(i, visited, 1);
    }
    cout<<res<<"\n";

    return 0;
}

void dfs(int n, vector<bool> visited, int depth) {
    if(depth == 5) {
        res = 1;
        return;
    }
    if(res == 1) return;

    visited[n] = true;
    
    for(int i=0; i<adjList[n].size(); i++) {
        int k = adjList[n][i];

        if(!visited[k]) {
            dfs(k, visited, depth + 1);
        }
    }

    visited[n] = false;
    return;
}