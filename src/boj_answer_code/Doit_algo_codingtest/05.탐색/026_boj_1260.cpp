// Do it! 알고리즘 코딩테스트 책자
// 026. DFS와 BFS (BOJ #1260)
// 노션 정리 링크 → https://chnh506.notion.site/BOJ-1260-DFS-BFS-c29a7ffbb8ed4c1cb7e2a69b0ae7979b

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void dfs(int n);
void bfs(int n);

static vector<vector<int>> adjList;
static vector<bool> visited;
static queue<int> q;
int N, M, V;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N>>M>>V;
    adjList = vector<vector<int>> (N+1, vector<int>(0));

    int a, b;
    for(int i=0; i<M; i++) {
        cin>>a>>b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }  

    for(int i=1; i<=N; i++) {
        sort(adjList[i].begin(), adjList[i].end());
    }

    visited = vector<bool> (N+1, false);
    dfs(V);
    cout<<"\n";

    visited = vector<bool> (N+1, false);
    bfs(V);
    cout<<"\n";
    

    return 0;
}

void dfs(int n) {
    visited[n] = true;
    cout<<n<<" ";

    for(int i=0; i<adjList[n].size(); i++) {
        int k = adjList[n][i];

        if(!visited[k]) {
            dfs(k);
        }
    }
}

void bfs(int n) {
    q.push(n);
    visited[n] = true;

    while(!q.empty()) {
        int temp = q.front();
        cout<<temp<<" ";
        q.pop();

        for(int i=0; i<adjList[temp].size(); i++) {
            int k = adjList[temp][i];

            if(!visited[k]) {
                q.push(k);
                visited[k] = true;
            }
        }
    }
}
