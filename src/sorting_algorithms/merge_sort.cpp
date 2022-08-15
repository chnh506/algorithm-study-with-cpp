// 합병 정렬 (Merge Sort) 로 문제를 해결할 것이다.
// Big - O Notation : O(n log n)
// 문제 링크 : https://www.acmicpc.net/problem/2751
// 참고 자료 : https://gmlwjd9405.github.io/2018/05/08/algorithm-merge-sort.html

// 코드(알고리즘) 자체는 맞았는데, vector를 사용하는 방법에서 문제가 있었다. (배열로 고쳐주니 맞음.)
// 배열과 같은 STL의 개념이 부족하다. 추가적인 공부가 필요할 듯. (반복자 같은 것들 ..) 차근차근 해 나가자.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, num;
int list[1000001];
int sorted[1000001];
// vector<int> v;
// vector<int> sorted;        // merge하는 과정에서 정렬된 값을 따로 저장해 두는 vector

void merge(int list[], int left, int mid, int right) {
    int l_idx = left;                 // 두 리스트 중 왼쪽 리스트의 인덱스를 위한 변수
    int r_idx = mid + 1;              // 두 리스트 중 오른쪽 리스트의 인덱스를 위한 변수
    int s_idx = left;                 // merge해서 정렬한 결과를 sorted 리스트의 넣어주기 위해 필요한 인덱스 변수

    while(l_idx <= mid && r_idx <= right) {
        if(list[l_idx] < list[r_idx]) {
            sorted[s_idx++] = list[l_idx++];
        }
        else {
            sorted[s_idx++] = list[r_idx++];
        }
    }

    while(l_idx <= mid) {
        sorted[s_idx++] = list[l_idx++];
    } 

    while(r_idx <= right) {
        sorted[s_idx++] = list[r_idx++];
    }

    for(int i=left; i<=right; i++) {
        list[i] = sorted[i];
    }
}

void mergeSort(int list[], int left, int right) {
    int mid = (left + right) / 2;

    // left == right일 때는, 리스트 element의 수가 하나밖에 없음.
    // 이때는, 이미 정렬된 것으로 간주, 따라서 재귀 탈출.
    if (left < right) {
        mergeSort(list, left, mid);            // 왼쪽 절반에 대해 재귀 호출 실행
        mergeSort(list, mid+1, right);          // 오른쪽 절반에 대해 재귀 호출 실행
        merge(list, left, mid, right);               // 왼쪽 절반 + 오른쪽 절반을 크기순으로 정렬
    }
}

void mergeSortMain() {
    cin>>N;
    for(int i=0; i<N; i++) {
        cin>>list[i];
    }

    mergeSort(list, 0, N-1);

    for(int i=0; i<N; i++) {
        cout<<list[i]<<'\n';
    }
}