// Do it! 알고리즘 코딩테스트 책자
// 032. 동전 0 (BOJ #11047)
// 노션 정리 링크 → https://chnh506.notion.site/BOJ-11047-0-6dbbd292b830490292e76eb3a7bf04ad

#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int N, K;
    cin>>N>>K;

    vector<int> A(N);
    for(int i=0; i<N; i++) {
        cin>>A[i];
    }

    int sum = 0, num = 0;
    int i = N-1;
    while(i >= 0) {
        if(sum == K) {
            cout<<num<<"\n";
            break;
        }

        if(sum + A[i] > K) {
            i--;
            continue;
        }
        else {
            sum += A[i];
            num++;
        }
    }

    return 0;
}