// Do it! 알고리즘 코딩테스트 책자
// 028. 트리의 지름 (BOJ #1167)
// 노션 정리 링크 → https://chnh506.notion.site/BOJ-1167-66b3edd82f2141a0b6b8fc9a08aa82d9

#include <iostream>
#include <utility>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> Edge;

static vector<vector<Edge>> adjList;
static vector<int> dist;
static vector<bool> visited;
static queue<Edge> q;
int V;

int bfs(int start);

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>V;
    adjList = vector<vector<Edge>> (V+1, vector<Edge>(0));

    int n, a, b;
    for(int i=0; i<V; i++) {
        cin>>n;
        while(1) {
            cin>>a;
            if(a == -1) break;
            cin>>b;
            adjList[n].push_back(make_pair(a, b));
            continue;
        }
    }

    dist = vector<int> (V+1, 0);
    visited = vector<bool> (V+1, false);
    int res1 = bfs(1);

    dist = vector<int> (V+1, 0);
    visited = vector<bool> (V+1, false);
    int res2 = bfs(res1);

    cout << dist[res2] << "\n";

    return 0;
}

int bfs(int start) {
    visited[start] = true;
    dist[start] = 0;
    q.push(make_pair(start, 0));

    while(!q.empty()) {
        Edge temp = q.front();
        q.pop();

        for(int i=0; i<adjList[temp.first].size(); i++) {
            Edge k = adjList[temp.first][i];

            if(!visited[k.first]) {
                visited[k.first] = true;
                dist[k.first] = k.second + dist[temp.first];
                q.push(k);
            }
        }
    }

    int max = 0, res = 0;
    for(int i=1; i<=V; i++) {
        if(dist[i] > max) {
            max = dist[i];
            res = i;
        }
    }
    return res;
}