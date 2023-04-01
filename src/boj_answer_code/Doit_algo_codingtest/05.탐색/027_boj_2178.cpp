// Do it! 알고리즘 코딩테스트 책자
// 027. 미로 탐색 (BOJ #2178)
// 노션 정리 링크 → https://chnh506.notion.site/BOJ-2178-6218e6db414c410ea2cb59da0787f169

#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

typedef pair<int, int> Coord;

void bfs();
static vector<vector<char>> miro;
static vector<vector<int>> dist;
int N, M;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N>>M;

    miro = vector<vector<char>> (N+1, vector<char>(M+1));
    dist = vector<vector<int>> (N+1, vector<int>(M+1, -1));
    // 최단 거리를 저장하는 dist 2차원 벡터가 방문 여부 체크의 역할도 동시에 수행한다.

    for(int i=1; i<=N; i++) {
        for(int j=1; j<=M; j++) {
            cin>>miro[i][j];
        }
    }

    bfs();
    cout<<dist[N][M]<<"\n";


    return 0;
}

void bfs() {
    queue<Coord> q;
    q.push(make_pair(1, 1));
    dist[1][1] = 1;

    while(!q.empty()) {
        Coord cur = q.front();
        q.pop();

        int i = cur.first;
        int j = cur.second;
        
        // 1. 위쪽 인접좌표
        if(i > 1 && miro[i-1][j] == '1' && dist[i-1][j] == -1) {
            q.push(make_pair(i-1, j));
            dist[i-1][j] = dist[i][j] + 1;
        }

        // 2. 아래쪽 인접좌표
        if(i < N && miro[i+1][j] == '1' && dist[i+1][j] == -1) {
            q.push(make_pair(i+1, j));
            dist[i+1][j] = dist[i][j] + 1;
        }

        // 3. 왼쪽 인접좌표
        if(j > 1 && miro[i][j-1] == '1' && dist[i][j-1] == -1) {
            q.push(make_pair(i, j-1));
            dist[i][j-1] = dist[i][j] + 1;
        }

        // 4. 오른쪽 인접좌표
        if(j < M && miro[i][j+1] == '1' && dist[i][j+1] == -1) {
            q.push(make_pair(i, j+1));
            dist[i][j+1] = dist[i][j] + 1;
        }
    }
}