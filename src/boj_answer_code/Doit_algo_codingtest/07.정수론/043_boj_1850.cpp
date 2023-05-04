// Do it! 알고리즘 코딩테스트 책자
// 043. 최대공약수 (BOJ #1850)
// 노션 정리 링크 → https://chnh506.notion.site/BOJ-1850-5d4b7d53d6df40eebd97188e2ab558dc

#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

ll gcd(ll a, ll b);

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll A, B;
    cin>>A>>B;

    ll len = gcd(A, B);
    for(ll i=0; i<len; i++) {
        cout<<1;
    }
    cout<<"\n";

    return 0;
}

// 더 간단한 유클리드 호제법 함수 코드.
ll gcd(ll a, ll b) {
    if(b == 0) return a;
    else return gcd(b, a % b);
}
