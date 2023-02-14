// Do it! 알고리즘 코딩테스트 책자
// 004번. 구간 합 구하기 5 (BOJ #11660)


#include <iostream>

using namespace std;

int N, M;
int mat[1025][1025] = {0, };
int rowSum[1025][1025] = {0, }, colSum[1025][1025] = {0, };

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N>>M;
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            cin>>mat[i][j];
        }
    }

    // 1. 원본 배열에서 가로 합 배열 구하기
    for(int i=1; i<=N; i++) {
        rowSum[i][1] = mat[i][1];
        for(int j=2; j<=N; j++) {
            rowSum[i][j] = rowSum[i][j-1] + mat[i][j];
        }
    }

    // 2. 가로 합 배열을 이용, 세로 합 배열 구하기
    for(int i=1; i<=N; i++) {
        colSum[1][i] = rowSum[1][i];
        for(int j=2; j<=N; j++) {
            colSum[j][i] = colSum[j-1][i] + rowSum[j][i];
        }
    }

    int x1, y1, x2, y2;
    for(int i=0; i<M; i++) {
        cin>>x1>>y1>>x2>>y2;
        int res = colSum[x2][y2] - colSum[x1-1][y2] - colSum[x2][y1-1] + colSum[x1-1][y1-1];
        cout << res << "\n";
    }

    return 0;
}