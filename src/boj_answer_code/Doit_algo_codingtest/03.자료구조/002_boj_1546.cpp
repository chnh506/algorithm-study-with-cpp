// Do it! 알고리즘 코딩테스트 책자
// 002번. 평균 (BOJ #1546)

#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    int N, max = 0;
    double res = 0;
    vector<int> scores(1000);

    cin>>N;
    for(int i=0; i<N; i++) {
        cin>>scores[i];
        if(scores[i] > max) max = scores[i];
    }

    for(int i=0; i<N; i++) {
        res += scores[i];
    }
    res = (res / max) * 100 / N;

    cout<<res<<endl;

    return 0;
}