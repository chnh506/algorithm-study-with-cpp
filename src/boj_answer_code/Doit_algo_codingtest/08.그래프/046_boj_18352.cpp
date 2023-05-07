// Do it! 알고리즘 코딩테스트 책자
// 046. 특정 거리의 도시 찾기 (BOJ #18352)
// 노션 정리 링크 → https://chnh506.notion.site/BOJ-18352-30fd2ecb5d2d4b86af1a708e8f2b36aa

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, K, X;
vector<vector<int>> A;  // 그래프의 인접 리스트 표현
vector<bool> visited;   // 방문 여부 체크 vector
vector<int> dist;       // X와의 거리 저장 vector
queue<int> q;           // bfs()에서 사용할 큐

void bfs(int node);

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N>>M>>K>>X;
    A = vector<vector<int>> (N+1);
    visited = vector<bool> (N+1, false);
    dist = vector<int> (N+1);
    dist[X] = 0;    // 자기 자신까지의 거리는 0

    int a, b;
    for(int i=0; i<M; i++) {
        cin>>a>>b;
        A[a].push_back(b);
    }

    bfs(X);

    bool count = false;
    for(int i=1; i<=N; i++) {
        if(dist[i] == K) {
            cout<<i<<"\n";
            count = true;
        }
    }

    if(!count) cout<<-1<<"\n";

    return 0;
}

void bfs(int node) {
    visited[node] = true;
    q.push(node);

    while(!q.empty()) {
        int temp = q.front();
        q.pop();

        for(int i=0; i<A[temp].size(); i++) {
            int p = A[temp][i];

            if(!visited[p]) {
                visited[p] = true;
                dist[p] = dist[temp] + 1;
                q.push(p);
            }
        }
    }
}
