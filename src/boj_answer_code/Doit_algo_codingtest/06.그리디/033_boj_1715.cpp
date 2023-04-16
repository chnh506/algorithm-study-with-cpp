// Do it! 알고리즘 코딩테스트 책자
// 033. 카드 정렬하기 (BOJ #1715)
// 노션 정리 링크 → https://chnh506.notion.site/BOJ-1715-163c08f7f702454cbc83992113681f0c

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin>>N;

    priority_queue<int, vector<int>, greater<int>> pq;
    int temp;
    for(int i=0; i<N; i++) {
        cin>>temp;
        pq.push(temp);
    }

    int sum = 0;
    while(pq.size() > 1) {
        int tempSum = 0;
        tempSum += pq.top();
        pq.pop();
        tempSum += pq.top();
        pq.pop();

        sum += tempSum;

        pq.push(tempSum);
    }

    cout<<sum<<"\n";

    return 0;
}
