// 문제 링크 : https://www.acmicpc.net/problem/1920
// 탐색 문제. 정렬 후 이진 탐색으로 문제를 해결했다.
// 처음 로직을 짤 때는 Binary Search 부분을 재귀를 이용해서 구현했으나, 10% 지점에서 시간초과가 계속 남.
// 시간초과 관련 질문들을 참고한 후, 재귀 대신 while 반복문을 이용해 다시 구현. -> 성공!
// 참고 자료 : 시간 초과로 틀렸을 때, BOJ의 질문 검색만 몇 개 참고함. (https://www.acmicpc.net/board/view/68834)
// 추가: 함수의 인자로 '포인터를 이용해 벡터의 주소만 전달'하는 방법! 참고하기.

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int binarySearch(vector<int> &A, int target) {
    int left = 0; 
    int right = A.size() - 1;
    int mid;

    while(left <= right) {
        mid = (left + right) / 2;

        if(A[mid] == target) 
            return 1;
        else if(A[mid] > target) 
            right = mid - 1;
        else 
            left = mid + 1; 
    }

    return 0;
}

void boj_1920_main() {
    int N, M, num;
    vector<int> A;
    int k;

    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        scanf("%d", &num);
        A.push_back(num);
    }

    sort(A.begin(), A.end());
    
    scanf("%d", &M);
    for(int i=0; i<M; i++) {
        scanf("%d", &k);
        printf("%d\n", binarySearch(A, k));
    }
}