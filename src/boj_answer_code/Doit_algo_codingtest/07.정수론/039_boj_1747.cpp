// Do it! 알고리즘 코딩테스트 책자
// 039. 소수&팰린드롬 (BOJ #1747)
// 노션 정리 링크 → https://chnh506.notion.site/BOJ-1747-359248d52c0d422b99cafa3762633c48

#include <iostream>
#include <math.h>
#include <vector>
#include <cmath>   
#include <string> 

using namespace std;

vector<bool> prime;
void getPrime(int N); 

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int max = 10000000;
    prime = vector<bool>(max, true); 
    prime[0] = false; prime[1] = false;

    getPrime(max);

    int N, res;
    cin>>N;

    for(int i=2; i<=max; i++) {
        if(!prime[i]) continue;
        if(i < N) continue;

        string str = to_string(i);
        int len = str.length();
        bool isPal = true;  // 숫자가 팰린드롬인지 판별하기 위해 사용하는 변수

        for(int j=0; j<len/2; j++) {
            if(str[j] != str[len-(j+1)]) {
                isPal = false;
                break;
            }
            else continue;
        }

        if(isPal) {
            cout<<i<<"\n";
            return 0;
        }
    }

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