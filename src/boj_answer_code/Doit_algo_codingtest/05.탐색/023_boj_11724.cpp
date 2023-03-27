// Do it! 알고리즘 코딩테스트 책자
// 023. 연결 요소의 개수 (BOJ #11724)
// 노션 정리 링크 → https://chnh506.notion.site/BOJ-11724-742566f50bdc484cbc3337984ed8b1fd

#include <iostream>
#include <vector>

using namespace std;

void dfs(int n);
static vector<vector<int>> adjList;
static vector<bool> visited;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 

    int N, M, u, v;
    int res = 0;
    cin>>N>>M;

    adjList = vector<vector<int>>(N+1, vector<int>(0));
    visited = vector<bool>(N+1, false);

    for(int i=1; i<=M; i++) {
        cin>>u>>v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);    // 처음에 이걸 안 써줘서 틀렸었음... "방향 없는" 그래프!
    }

    for(int i=1; i<=N; i++) {
        if(adjList[i].empty()) continue;
        if(!visited[i]) {
            res++;
            dfs(i);
        }
    }

    for(int i=1; i<=N; i++) {
        if(adjList[i].empty() && !visited[i]) res++;
    }

    cout<<res<<"\n";

    return 0;
}

void dfs(int n) {
    visited[n] = true;

    for(int i=0; i<adjList[n].size(); i++) {
        int k = adjList[n][i];

        if(!visited[k]) {
            dfs(k);
        }
    }
}

/*
// 재귀 대신 스택을 활용해서 DFS를 구현하는 방식!
// 스택에서 pop -> 탐색 순서 기록 -> 인접 노드 (방문 배열 검사 후) 스택에 push -> 방문 배열에 true 체크
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void bfs(int n);
static vector<vector<int>> adjList;
static stack<int> s;
static vector<bool> visited;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 

    int N, M, u, v;
    int res = 0;
    cin>>N>>M;

    adjList = vector<vector<int>>(N+1, vector<int>(0));
    visited = vector<bool>(N+1, false);

    for(int i=0; i<M; i++) {
        cin>>u>>v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    for(int i=1; i<=N; i++) {
        if(!visited[i]) {
            bfs(i);
            res++;
        }
    }

    cout<<res<<"\n";

    return 0;
}

void bfs(int n) {
    s.push(n);
    visited[n] = true;

    while(!s.empty()) {
        int t;
        t = s.top();
        s.pop();
        for(int i=0; i<adjList[t].size(); i++) {
            int k = adjList[t][i];

            if(!visited[k]) {
                s.push(k);
                visited[k] = true;
            }
        }
    }
}
*/