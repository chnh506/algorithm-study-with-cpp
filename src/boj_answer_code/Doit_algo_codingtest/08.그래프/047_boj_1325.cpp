// Do it! 알고리즘 코딩테스트 책자
// 047. 효율적인 해킹 (BOJ #1325)
// 노션 정리 링크 → https://chnh506.notion.site/BOJ-1325-deeb0beaf3904e6e97a67cb1c91c82fe

#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> adj;    // 인접 리스트 그래프
vector<int> res;            // 해킹 가능한 컴퓨터의 대수 저장
vector<bool> visited;       // 각 노드의 방문 여부 체크
queue<int> q;
void bfs(int node);

int N, M, A, B;
int maxNum = 0;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N>>M;
    adj.resize(N+1);
    res.resize(N+1);

    for(int i=0; i<M; i++) {
        cin>>A>>B;
        adj[A].push_back(B);
    }

    visited.resize(N+1);
    for(int i=1; i<=N; i++) {
        fill(visited.begin(), visited.end(), false);
        bfs(i);
    }

    for(int i=1; i<=N; i++) {
        if(res[i] > maxNum) maxNum = res[i];
    }

    for(int i=1; i<=N; i++) {
        if(res[i] == maxNum) cout<<i<<" ";
    }
    cout<<"\n";
    

    return 0;
}

void bfs(int node) {
    visited[node] = true;
    q.push(node);

    while(!q.empty()) {
        int temp = q.front();
        q.pop();

        for(int i=0; i<adj[temp].size(); i++) {
            int k = adj[temp][i];

            if(!visited[k]) {
                visited[k] = true;
                res[k]++;
                q.push(k);
            }
        }
    }
}
