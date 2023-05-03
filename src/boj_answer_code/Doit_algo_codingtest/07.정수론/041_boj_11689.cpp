// Do it! 알고리즘 코딩테스트 책자
// 041. GCD(n, k) = 1 (BOJ #11689)
// 노션 정리 링크 → https://chnh506.notion.site/BOJ-11689-GCD-n-k-1-fab7c4b4f06446ed89b32c5d028234af

#include <iostream>
#include <math.h>
#include <vector>
#include <cmath>

typedef long long ll;
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n, res;  // n은 현재 소인수 구성, res는 서로소의 개수 변수
    cin>>n;
    res = n;

    for(ll k = 2; k <= sqrt(n); k++) {
        if(n % k != 0) continue;    // 소인수에 대해서만 오일러 피 함수를 수행한다.
        else {
            res = res - res / k;
            while(n % k == 0) n /= k;   // 특정 인수로 나눴으면, 그 인수는 전부 n에서 나눠서 없애준다.
        }
    }

    if(n > 1) { // 아직 소인수 구성이 남아있는 경우
        // 반복문에서 제곱근까지만 탐색했기 때문에 1개의 소인수가 누락되는 케이스
        res = res - res / n;
    }
    cout<<res<<"\n";

    return 0;
}