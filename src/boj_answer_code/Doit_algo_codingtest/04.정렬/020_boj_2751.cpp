// Do it! 알고리즘 코딩테스트 책자
// 020. 수 정렬하기 2 (BOJ #2751)
// 노션 정리 링크 → https://chnh506.notion.site/BOJ-2751-2-0bfc284a917141799fb8169e595ba070

#include <iostream>
#include <vector>

using namespace std;
void merge(vector<int> & arr, vector<int> & sortArr, int begin, int mid, int end);
void mergeSort(vector<int> & arr, vector<int> & sortArr, int begin, int end);

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin>>N;

    vector<int> arr(N, 0);
    vector<int> sortArr(N, 0);
    for(int i=0; i<N; i++) {
        cin>>arr[i];
    }

    mergeSort(arr, sortArr, 0, N-1);
    for(int i=0; i<N; i++) {
        cout<<arr[i]<<"\n";
    }

    return 0;
}

void merge(vector<int> & arr, vector<int> & sortArr, int begin, int mid, int end) {
    int sortIdx = begin;
    int i = begin;
    int j = mid + 1;

    while(i <= mid && j <= end) {
        if(arr[i] < arr[j])
            sortArr[sortIdx] = arr[i++];
        else 
            sortArr[sortIdx] = arr[j++];

        sortIdx++;
    }

    while(i <= mid) {
        sortArr[sortIdx++] = arr[i++];
    }

    while(j <= end) {
        sortArr[sortIdx++] = arr[j++];
    }

    for(int k = begin; k<=end; k++) {
        arr[k] = sortArr[k];
    }   // 정렬 완료된 부분만 원본에 반영해 두기.
}

void mergeSort(vector<int> & arr, vector<int> & sortArr, int begin, int end) {
    if(begin < end) {
        int mid = (begin + end) / 2;
        mergeSort(arr, sortArr, begin, mid);
        mergeSort(arr, sortArr, mid + 1, end);
        merge(arr, sortArr, begin, mid, end);
    }
}