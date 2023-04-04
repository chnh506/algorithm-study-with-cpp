// Do it! 알고리즘 코딩테스트 책자
// 029. 수 찾기 (BOJ #1920)
// 노션 정리 링크 → https://chnh506.notion.site/BOJ-1920-e3bc591c22024b55ac9328a8ba502634

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin>>N;

    vector<int> A(N, 0);
    for(int i=0; i<N; i++) {
        cin>>A[i];
    }
    sort(A.begin(), A.end());

    int M, tar;
    cin>>M;
    for(int i=0; i<M; i++) {
        int s = 0, e = N-1, res = 0;
        cin>>tar;

        while(s <= e) {
            int mid = (s + e) / 2;
            if(A[mid] > tar) e = mid - 1;
            else if(A[mid] < tar) s = mid + 1;
            else {
                res = 1;
                break;
            }
        }

        cout<<res<<"\n";
    }

    return 0;
}