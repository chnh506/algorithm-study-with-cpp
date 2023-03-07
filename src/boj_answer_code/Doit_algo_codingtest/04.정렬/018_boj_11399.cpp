// Do it! 알고리즘 코딩테스트 책자
// 017번. 소트인사이드 (BOJ #1427)
// 노션 정리 링크 → https://chnh506.notion.site/BOJ-11399-ATM-cf2f9d3104844df384156468e9c838c6

#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin>>N;

    vector<int> P(N, 0);
    for(int i=0; i<N; i++) {
        cin>>P[i];
    }

    // 삽입정렬 코드!
    int i, j;
    for(i=1; i<N; i++) {
        int cur = P[i];
        for(j=i-1; j>=0; j--) {            
            if(P[j] > cur) P[j+1] = P[j];
            else break;
        } 
        P[j+1] = cur;
    }

    // 답을 구하기 위한 합 배열 생성 과정. (까먹지 않고 바로 쓴 거 좋았다~)
    vector<int> S(N, 0);
    int res = 0;
    S[0] = P[0];
    res += S[0];
    for(int i=1; i<N; i++) {
        S[i] = S[i-1] + P[i];
        res += S[i];
    }

    cout<<res<<"\n";

    return 0;
}

