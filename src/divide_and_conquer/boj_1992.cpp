// 문제 링크 : https://www.acmicpc.net/problem/1992
// 전형적인 '분할 정복 알고리즘'으로 해결하는 문제.
// 맨 처음 틀린 코드를 쓰고, 문제점을 찾지 못하고 있었는데 ,,, 알고 보니 int형을 쓴 것이 문제였다.
// char형으로 자료형을 고쳐서 해결.
// Debugging을 해 보니까 바로 어디가 틀렸는 지 찾을 수 있었다. 디버깅의 중요성!!


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
char video[64][64];

void quad_tree(int row, int col, int size) {
    char st = video[row][col];

    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++) {
            if(st != video[row + i][col + j]) {
                cout<<"(";
                quad_tree(row, col, size / 2);
                quad_tree(row, col + size / 2, size / 2);
                quad_tree(row + size / 2, col, size / 2);
                quad_tree(row + size / 2, col + size / 2, size / 2);
                cout<<")";
                return;
            }
        }
    }

    cout<<st;
}

void boj_1992_main() {
    cin>>N;

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin>>video[i][j];
        }
    }

    quad_tree(0, 0, N);
    cout<<endl;
}