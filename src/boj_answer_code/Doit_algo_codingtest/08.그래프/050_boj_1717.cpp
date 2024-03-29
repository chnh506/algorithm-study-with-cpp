// Do it! 알고리즘 코딩테스트 책자
// 050. 집합의 표현 (BOJ #1717)
// 노션 정리 링크 → https://chnh506.notion.site/BOJ-1717-6717e916b397443f906c55876dc8d4e2

#include <iostream>
#include <vector>

using namespace std;

int n, m, a, b, Ari;  // Ari는 연산의 종류 받을 때 쓰기 위한 변수(Arithmetic)
vector<int> uf;
int l;

void uni(int a, int b);
int find(int k);

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>n>>m;
    uf.resize(n+1);
    for(int i=0; i<=n; i++) {
        uf[i] = i;
    }

    for(int i=0; i<m; i++) {
        cin>>Ari>>a>>b;
        
        if(Ari == 0) uni(a, b);
        else {
            int ans1 = find(a);
            int ans2 = find(b);

            if(ans1 == ans2) cout<<"YES"<<"\n";
            else cout<<"NO"<<"\n";
        }
    } 
    

    return 0;
}

void uni(int a, int b) {    
    // a와 b가 속해 있는 집합을 합치는 합집합 연산
    // b의 대표 노드를 a로 바꾼다.
    while(uf[a] != a) a = uf[a];
    while(uf[b] != b) b = uf[b];

    uf[b] = a;
}

int find(int k) {
    if(uf[k] != k) find(uf[k]);
    else {
        l = uf[k];
        return l;
    }

    uf[k] = l;
    return l;
}

/*
void unionfunc(int a, int b) {
    // union 연산: 바로 연결하는 것이 아니다. 대표 노드로 올라가서 대표 노드끼리 연결한다.
    a = find(a);
    b = find(b);

    if(a != b) {
        parent[b] = a;
    }
}

int find(int a) {
    // find 연산: 대표 노드를 찾아서 반환한다.
    if(a == parent[a]) return a;
    else return parent[a] = find(parent[a]);    // 재귀 함수 형태로 구현
}

bool checkSame(int a, int b) {
    // 두 원소가 같은 집합에 속해 있는지 확인한다.
    a = find(a);
    b = find(b);

    if(a == b) return true;
    return false;
}
*/