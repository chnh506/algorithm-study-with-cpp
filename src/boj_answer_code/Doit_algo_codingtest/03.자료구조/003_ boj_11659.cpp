// Do it! 알고리즘 코딩테스트 책자
// 003번. 구간 합 구하기 4 (BOJ #11659)

#include <iostream>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, i, j;
    int A[100001];  // 입력 배열
    int S[100001];  // 합 배열
    A[0] = 0;
    S[0] = 0;

    cin>>N>>M;
    for(int k=1; k<=N; k++) {
        cin>>A[k];
        S[k] = S[k-1] + A[k];
    }

    for(int k=0; k<M; k++) {
        cin>>i>>j;
        cout<<S[j]-S[i-1]<<"\n";
    }

    return 0;
}
