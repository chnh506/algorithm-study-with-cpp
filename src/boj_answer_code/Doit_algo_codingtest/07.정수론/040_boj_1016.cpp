// Do it! 알고리즘 코딩테스트 책자
// 040. 제곱 ㄴㄴ 수 (BOJ #1016)
// 노션 정리 링크 → https://chnh506.notion.site/BOJ-1016-9dc23eae27e94c3fb51d08150afbb708

#include <iostream>
#include <math.h>
#include <vector>
#include <cmath>

typedef long long ll;
using namespace std;

vector<bool> prime;
vector<bool> nPow(1000001, true);
void getPrime(int N); 

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll min, max;
    cin>>min>>max;

    ll size = sqrt(max);
    prime = vector<bool> (size+1, true);
    getPrime(size);

    for(ll i=2; i<=size; i++) {
        if(!prime[i]) continue;
        else {
            ll s_idx = min / (i * i);
            ll temp = (i * i) * s_idx;
            while(temp <= max) {
                if(temp >= min) nPow[temp-min] = false;
                temp += (i * i);
            }
        }
    }

    ll cnt = 0;
    for(int i=0; i<=max-min; i++) {
        if(nPow[i]) cnt++;
    }

    cout<<cnt<<"\n";
    
    return 0;
}

void getPrime(int N) {
    for(int i=2; i<=sqrt(N); i++) {
        if(!prime[i]) continue; // 소수가 아닌 경우 그냥 skip

        for(int j=i+i; j<=N; j+=i) {
            prime[j] = false;
        }
    }
}