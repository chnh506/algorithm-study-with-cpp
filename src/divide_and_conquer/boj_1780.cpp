// 문제 링크 : https://www.acmicpc.net/problem/1780
// 2630번 문제에서 2*2 -> 3*3으로 바뀌었다는 것을 제외하고는 다를 바가 없다. 정확히 동일한 로직으로 풀어버림.
// 의문점 : 과연 이 문제를 분할정복으로 풀어야 한다는 것을 모르고 해결하려 했다면, 쉽게 해결할 수 있었을까?
// "난 이 문제를 분할정복으로 해결해야겠어!" 라고 판단을 내릴 수 있는 판단 근거는 무엇일까. 
// 추가적인 학습이 필요할 것 같다.


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int num_one = 0, num_mone = 0, num_zero = 0;
int p[2187][2187];

void divide_and_conquer(int row, int col, int size) {
    int idx = p[row][col];
    
    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++) {
            if(idx != p[row+i][col+j]) {
                divide_and_conquer(row, col, size/3);
                divide_and_conquer(row, col + size/3, size/3);
                divide_and_conquer(row, col + 2*size/3, size/3);
                divide_and_conquer(row + size/3, col, size/3);
                divide_and_conquer(row + size/3, col + size/3, size/3);
                divide_and_conquer(row + size/3, col + 2*size/3, size/3);
                divide_and_conquer(row + 2*size/3, col, size/3);
                divide_and_conquer(row + 2*size/3, col + size/3, size/3);
                divide_and_conquer(row + 2*size/3, col + 2*size/3, size/3);
                return;
            }
        }
    }

    if(idx == 1) num_one++;
    else if(idx == -1) num_mone++;
    else if(idx == 0) num_zero++;
    return;
}

void boj_1780_main() {
    cin>>N;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin>>p[i][j];
        }
    }

    divide_and_conquer(0, 0, N);

    cout<<num_mone<<'\n'<<num_zero<<'\n'<<num_one<<endl;
}