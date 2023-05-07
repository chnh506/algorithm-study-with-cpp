// Do it! 알고리즘 코딩테스트 책자
// 044. 칵테일 (BOJ #1033)
// 노션 정리 링크 → https://chnh506.notion.site/BOJ-1033-8417a874582b4c869da975565c30f5d2

#include <iostream>
#include <utility>
#include <vector>
#include <tuple>

using namespace std;
typedef long long ll;
typedef tuple<ll, ll, ll> Node;  // 인접 리스트의 노드를 나타내기 위한 tuple

ll gcd(ll a, ll b);
void dfs(int k);

vector<tuple<int, int, int>> adjList[10];
ll lcm;
bool visited[10];
ll D[10];   // 각 노드 값을 저장하는 배열

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll N, a, b, p, q;
    cin>>N;
    lcm = 1;

    if(N == 1) {
        cout<<1<<"\n";
        return 0;
    }

    for(int i=0; i<N-1; i++) {
        cin>>a>>b>>p>>q;

        adjList[a].push_back(make_tuple(b, p, q));  // 인접 리스트에 저장
        adjList[b].push_back(make_tuple(a, q, p));

        // 두 수의 최소공배수는 두 수의 곱을 최대공약수로 나눈 것이다.
        lcm *= (p * q / gcd(p, q));
    }

    D[0] = lcm;
    dfs(0);

    ll mgcd = D[0];

    for(int i=1; i<N; i++) {
        mgcd = gcd(mgcd, D[i]);
    }

    for(int i=0; i<N; i++) {
        cout << D[i] / mgcd <<" ";
    }
    cout<<"\n";

    return 0;
}

// 더 간단한 유클리드 호제법 함수 코드.
ll gcd(ll a, ll b) {
    if(b == 0) return a;
    else return gcd(b, a % b);
}

void dfs(int k) {
    visited[k] = true;

    for(tuple<int, int, int> i : adjList[k]) {
        ll idx = get<0>(i);
        
        if(!visited[idx]) {
            D[idx] = D[k] * get<2>(i) / get<1>(i);
            dfs(idx);
        }
    }
}
