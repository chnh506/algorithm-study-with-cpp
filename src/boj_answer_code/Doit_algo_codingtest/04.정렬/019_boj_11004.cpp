// Do it! 알고리즘 코딩테스트 책자
// 019번. K번째 수 (BOJ #11004)
// 노션 정리 링크 → https://chnh506.notion.site/BOJ-11004-K-63d3c72e8c0d450287eda8fb0a4f89df

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K;
int v[5000001];

void quickSort(int start, int end) {
    int pivot = start;
    int i = pivot + 1;  // 왼쪽 출발 지점
    int j = end;    // 오른쪽 출발 지점

    while(i <= j) {
        // 포인터가 엇갈릴 때까지 반복하면 된다.
        while(i <= end && v[i] <= v[pivot]) i++;
        while(j > start && v[j] >= v[pivot]) j--;

        if(i > j) {
            // i와 j가 엇갈렸다. -> j값과 pivot값을 바꾼다!
            int temp = v[j];
            v[j] = v[pivot];    // j값은 pivot의 자리에
            v[pivot] = temp;    // 원래 pivot이었던 값은 j인덱스 자리에 둔다.
        } 
        else {
            // 멈추긴 했지만, 아직 i와 j가 엇갈리지 않았다. 
            // i값과 j값을 서로 바꿔주고, 계속 진행한다.
            int temp = v[i];
            v[i] = v[j];
            v[j] = temp;
        }
    }

    // 분할 정복 ㄱㄱ
    quickSort(start, j-1);
    quickSort(j+1, end);
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N>>K;
    for(int i=0; i<N; i++) {
        cin>>v[i];
    }

    // quickSort(0, N-1);
    sort(v, v+N);
    cout<<v[K-1]<<"\n";

    return 0;
}