// Do it! 알고리즘 코딩테스트 책자
// 049. 물통 (BOJ #2251)
// 노션 정리 링크 → https://chnh506.notion.site/BOJ-2251-353d6ec7bf194fa7ba4761b0c695d47b

#include <iostream>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

int Sender[6] = {0, 0, 1, 1, 2, 2};
int Receiver[6] = {1, 2, 0, 2, 0, 1};
bool answer[201];
bool visited[201][201];
int now[3];     // A, B, C 각 물통의 용량
void bfs();


int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>now[0]>>now[1]>>now[2];
    bfs();

    for(int i=0; i<=200; i++) {
        if(answer[i]) cout<<i<<" ";
    }

    return 0;
}

void bfs() {
    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));
    visited[0][0] = true;
    answer[now[2]] = true;

    while(!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();

        int A = p.first;
        int B = p.second;
        int C = now[2] - A - B;

        for(int i=0; i<6; i++) {
            int next[] = {A, B, C};
            next[Receiver[i]] += next[Sender[i]];
            next[Sender[i]] = 0;

            // 대상 물통의 용량보다 물을 많이 넣어서 넘쳤을 때
            if(next[Receiver[i]] > now[Receiver[i]]) {
                // 초과하는 만큼 다시 이전 물통에 넣는다.
                next[Sender[i]] = next[Receiver[i]] - now[Receiver[i]];
                // 대상 물통은 최대로 채운다.
                next[Receiver[i]] = now[Receiver[i]]; 
            } 

            // A와 B의 물의 양을 이용해서 각 노드를 방문했는지 체크한다.
            if(!visited[next[0]][next[1]]) {
                visited[next[0]][next[1]] = true;
                q.push(make_pair(next[0], next[1]));
            }

            if(next[0] == 0) answer[next[2]] = true;
        }
    }
}

