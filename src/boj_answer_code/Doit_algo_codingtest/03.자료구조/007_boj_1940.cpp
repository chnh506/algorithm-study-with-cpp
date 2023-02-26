// Do it! 알고리즘 코딩테스트 책자
// 007번. 주몽 (BOJ #1940)
// 노션 정리 링크 → https://chnh506.notion.site/BOJ-1940-8a608d4229564f329ac56cbc1d4e6c9b

#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
    int N, M, res = 0;
    int A[15001];

    cin>>N>>M;
    int temp;
    for(int i=0; i<N; i++) {
        cin>>A[i];
    }

    sort(A, A+N);

    int s_idx = 0, e_idx = N-1;
    while(s_idx < e_idx) {
        if(A[s_idx] + A[e_idx] > M) e_idx--;
        else if(A[s_idx] + A[e_idx] < M) s_idx++;
        else {
            res++;
            s_idx++;
            e_idx--;
        }
    }

    cout<<res<<"\n";

    return 0;
}

