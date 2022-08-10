#include <iostream>

using namespace std;

void insertion_sort() {
    // 삽입 정렬 (Insertion Sort) 로 문제를 해결할 것이다.
    // Big - O Notation : O(n^2)
    // 문제 링크 : https://www.acmicpc.net/problem/2750
    // 참고 자료 : https://gmlwjd9405.github.io/2018/05/06/algorithm-insertion-sort.html


    int N, a[1001];
    int i, j, key;

    cin >> N;
    for(i=0; i<N; i++) {
        cin>>a[i];
    }    

    for(i=1; i<N; i++) {
        key = a[i];

        for(j=i-1; j>=0; j--) {
            if(key < a[j]) a[j+1] = a[j];
            else break;
        }
        
        a[j+1] = key;
    }

    for(i=0; i<N; i++) {
        cout<<a[i]<<endl;
    }
}