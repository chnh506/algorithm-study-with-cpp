// 문제 링크 : https://www.acmicpc.net/problem/2630
// 참고 자료 : https://ko.wikipedia.org/wiki/분할_정복_알고리즘
// "분할 정복 알고리즘은 보통 재귀를 통해 자연스럽게 구현된다." -> 재귀를 떠올려서 문제를 해결했다.
// 뇌피셜이긴 하지만 ,, 분할 정복 알고리즘을 시도할 때는 반사적으로 재귀를 떠올리는 것이 좋을 듯하다.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int p[128][128];
int white = 0, blue = 0;

void check_paper(int row, int col, int size) {
    int temp = p[row][col];
    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++) {
            if(p[row + i][col + j] != temp) {
                // 검사의 기준값이 되는 temp값과 하나라도 다른 값이 있는 경우 (즉, 색깔이 다른 칸이 있는 경우)
                check_paper(row, col, size / 2);
                check_paper(row, col + size / 2, size / 2);
                check_paper(row + size / 2, col, size / 2);
                check_paper(row + size / 2, col + size / 2, size / 2);
                return;
            }
        }
    }
    
    if(temp) blue++;
    else white++;
}

void boj_2630_main() {
    cin>>N;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin>>p[i][j];
        }
    }

    check_paper(0, 0, N);
    
    cout<<white<<endl;
    cout<<blue<<endl;
}