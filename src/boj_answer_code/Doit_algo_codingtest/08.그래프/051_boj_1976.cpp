// Do it! 알고리즘 코딩테스트 책자
// 051. 여행 가자 (BOJ #1976)
// 노션 정리 링크 → https://chnh506.notion.site/BOJ-1976-40ba6975f8204423aa0f9d8e7dc215c0

#include <iostream>
#include <vector>

using namespace std;

int N, M;
int parent[201];
int set[201][201];
int plan[1001];

void unionfunc(int a, int b);
int find(int k);

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>N;
    cin>>M;
    
    for(int i=0; i<=N; i++) {
        parent[i] = i;
    }

    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            cin>>set[i][j];
        }
    }

    for(int i=1; i<=N; i++) {
        for(int j=i; j<=N; j++) {
            if(set[i][j] == 1) {
                unionfunc(i, j);
            }
        }
    }

    for(int i=0; i<M; i++) {
        cin>>plan[i];
    }

    for(int i=1; i<M; i++) {
        int p1 = find(plan[i-1]);
        int p2 = find(plan[i]);

        if(p1 == p2) continue;
        else {
            cout<<"NO"<<"\n";
            return 0;
        }
    }

    cout<<"YES"<<"\n";


    return 0;
}

void unionfunc(int a, int b) {
    a = find(a);
    b = find(b);

    if(a != b) parent[b] = a;
}

int find(int k) {
    if(k == parent[k]) return k;
    else return parent[k] = find(parent[k]);
}