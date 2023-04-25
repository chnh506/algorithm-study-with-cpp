// Do it! 알고리즘 코딩테스트 책자
// 037. 소수 구하기 (BOJ #1929)
// 노션 정리 링크 → https://chnh506.notion.site/BOJ-1929-c4bf157337254dc89ed62f03c8f75972

#include <iostream>
#include <vector>
#include <cmath>    

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int M, N;
    cin>>M>>N;

    vector<bool> prime(N+1, true);
    prime[0] = false; prime[1] = false;

    for(int i=2; i<=int(sqrt(N)); i++) {
        if(!prime[i]) continue; // 소수가 아닌 경우 그냥 skip

        for(int j=i+i; j<=N; j+=i) {
            prime[j] = false;
        }
    }

    for(int i=M; i<=N; i++) {
        if(prime[i]) cout<<i<<"\n";
    }

    return 0;
}