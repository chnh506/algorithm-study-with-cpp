#include <iostream>

using namespace std;

void bubble_sort() {
    // 버블 정렬 (Bubble Sort) 로 문제를 해결할 것이다.
    // Big - O Notation : O(n^2)
    // 문제 링크 : https://www.acmicpc.net/problem/2750
    // 참고 자료 : https://gmlwjd9405.github.io/2018/05/06/algorithm-bubble-sort.html


    int a[1001], N;
    int temp;

    cin>>N;
    for(int i=0; i<N; i++) {
        cin>>a[i];
    }

    for(int i=0; i<N-1; i++) {
        for(int j=1; j<N-i; j++) {
            if(a[j-1] > a[j]) {
                temp = a[j-1];
                a[j-1] = a[j];
                a[j] = temp;
            }
        }
    }

    for(int i=0; i<N; i++) {
        cout<<a[i]<<endl;
    }
}