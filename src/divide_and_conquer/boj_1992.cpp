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