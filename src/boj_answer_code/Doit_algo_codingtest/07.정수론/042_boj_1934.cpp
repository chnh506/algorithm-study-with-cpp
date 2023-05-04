// Do it! 알고리즘 코딩테스트 책자
// 042. 최소공배수 (BOJ #1934)
// 노션 정리 링크 → https://chnh506.notion.site/BOJ-1934-3b248e18b5384504a10bf377980e502d

#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b);

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, A, B;
    cin>>T;

    for(int i=0; i<T; i++) {
        cin>>A>>B;
        int res = gcd(A, B);
        cout<<A * B / res<<"\n";
    }

    return 0;
}

int gcd(int a, int b) {
    int l, r;
    if(a > b) {
        l = a;
        r = b;
    }
    else {
        l = b;
        r = a;
    }

    if(r == 0) return l;
    else return gcd(r, l % r);
}

/*
// 더 간단한 유클리드 호제법 함수 코드.
int gcd(int a, int b) {
    if(b == 0) return a;
    else return gcd(b, a % b);
}
*/