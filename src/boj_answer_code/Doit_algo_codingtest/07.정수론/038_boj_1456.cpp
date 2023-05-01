// Do it! 알고리즘 코딩테스트 책자
// 038. 거의 소수 (BOJ #1456)
// 노션 정리 링크 → https://chnh506.notion.site/BOJ-1456-b63422f0275d49d983e20099a4377f71

#include <iostream>
#include <math.h>
#include <vector>
#include <cmath>    

using namespace std;

typedef long long ll;

vector<bool> prime;
void getPrime(ll N); 

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll A, B;
    cin>>A>>B;

    ll size = sqrt(B);
    prime = vector<bool>(size+1, true); // 10^14가 상한인 B값으로 벡터를 만들면 공간이 너무 커진다. -> bad_alloc 뜨는 듯.
    prime[0] = false; prime[1] = false;

    getPrime(size);

    ll count = 0;
    for(ll i=2; i<=size; i++) {
        if(prime[i]) {
            ll now = i * i;
            ll next;
            while(1) {
                if(now > B) break;

                if(A <= now && now <= B) count++;
                
                next = now * i;
                if(next % now != 0) break;  // 오버플로우 검사해서 거르기.
                else {
                    now = next;
                    continue;
                }
            }
        }
    }

    cout<<count<<"\n";

    return 0;
}

void getPrime(ll N) {
    for(ll i=2; i<=N; i++) {
        if(!prime[i]) continue; // 소수가 아닌 경우 그냥 skip

        for(ll j=i+i; j<=N; j+=i) {
            prime[j] = false;
        }
    }
}

