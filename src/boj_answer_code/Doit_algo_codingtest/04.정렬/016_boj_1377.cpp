// Do it! 알고리즘 코딩테스트 책자
// 016번. 버블 소트 (BOJ #1377)
// 노션 정리 링크 → https://chnh506.notion.site/BOJ-1377-ccc58b93cee744adb536c6c3ccd3c752

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin>>N;

    vector<pair<int, int>> A(N);

    int temp;
    for(int i=0; i<N; i++) {
        cin>>temp;
        A[i] = {temp, i};
    }
    sort(A.begin(), A.end());

    int res = 0;
    for(int i=0; i<N; i++) {
        if(A[i].second - i > res) res = A[i].second - i;
    }

    cout<<res+1<<"\n";

    return 0;
}
