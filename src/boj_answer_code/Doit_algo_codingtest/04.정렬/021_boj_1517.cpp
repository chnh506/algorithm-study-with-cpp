// Do it! 알고리즘 코딩테스트 책자
// 021. 버블 소트 (BOJ #1517)
// 노션 정리 링크 → https://chnh506.notion.site/BOJ-1517-b85e81b97b6d427caa94f017e82c115c

#include <iostream>
#include <vector>

using namespace std;

// #1. 내가 작성한 오답 코드
// 책과 핵심 로직 자체는 완벽하게 같음에도 불구, 계속 3%에서 "틀렸습니다"가 뜬다. (테케도 잘 통과하는데...)
// 어떤 부분이 틀린 걸까 ..?
// 해결 @@!! -> res값이 int 자료형이면 오버플로우가 발생하는 것 때문이었음 .. .............
void mergeSort(vector<int> & A, vector<int> & temp, int begin, int end);
long long int res = 0;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin>>N;

    vector<int> A(N, 0);
    vector<int> temp(N, 0);
    for(int i=0; i<N; i++) {
        cin>>A[i];
    }

    mergeSort(A, temp, 0, N-1);
    cout<<res<<"\n";

    return 0;
}

void mergeSort(vector<int> & A, vector<int> & temp, int begin, int end) {
    if(end - begin < 1) {
        return;
    }

    int mid = (begin + end) / 2;
    mergeSort(A, temp, begin, mid);
    mergeSort(A, temp, mid + 1, end);

    for(int i=begin; i <= end; i++) {
        temp[i] = A[i];
    }

    int idx = begin;
    int i = begin;
    int j = mid + 1;
    while(i <= mid && j <= end) {
        if(temp[i] > temp[j]) {
            res += j - idx;
            A[idx++] = temp[j++];
        }
        else {
            A[idx++] = temp[i++];
        }
    }

    while(i <= mid) {
        A[idx++] = temp[i++];
    }
    while(j <= end) {
        A[idx++] = temp[j++];
    }
}

/*
// #2. 책에 나와 있는 정답 코드
// 위 1번 오답 코드와 어떤 부분이 달라서 얘는 정답이 되었을까?
void merge_sort(int begin, int end);
static vector<int> A;
static vector<int> tmp;
static long result;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin>>N;
    A = vector<int>(N+1, 0);
    tmp = vector<int>(N+1, 0);

    for(int i=1; i<=N; i++) {
        cin >> A[i];
    }

    result = 0;
    merge_sort(1, N);
    cout<<result<<"\n";
}

void merge_sort(int begin, int end) {
    if(end - begin < 1) return;

    int mid = (begin + end) / 2;
    merge_sort(begin, mid);
    merge_sort(mid + 1, end);

    for(int i = begin; i <= end; i++) {
        tmp[i] = A[i];
    }

    int idx = begin;
    int i = begin;
    int j = mid + 1;

    while(i <= mid && j <= end) {
        if(tmp[i] > tmp[j]) {
            result += j - idx;
            // result = result + mid - i + 1;
            A[idx++] = tmp[j++];
        }
        else {
            A[idx++] = tmp[i++];
        }
    }

    while(i <= mid) {
        A[idx++] = tmp[i++];
    }
    while(j <= end) {
        A[idx++] = tmp[j++];
    }
}
*/