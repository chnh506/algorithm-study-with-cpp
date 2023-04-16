// Do it! 알고리즘 코딩테스트 책자
// 034. 수 묶기 (BOJ #1744)
// 노션 정리 링크 → https://chnh506.notion.site/BOJ-1744-be8daf8584ac475abaa9cf4b146d20fa

#include <cstdlib>
#include <functional>
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

void greedy(priority_queue<int>& pq);
void greedy(priority_queue<int, vector<int>, greater<int>>& pq);
int sum = 0;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin>>N;

    priority_queue<int> plus;
    priority_queue<int, vector<int>, greater<int>> minus;

    int temp;
    for(int i=0; i<N; i++) {
        cin>>temp;
        if(temp > 0) plus.push(temp);
        else minus.push(temp);
    }

    greedy(minus);
    greedy(plus);
    cout<<sum<<"\n";

    return 0;
}

void greedy(priority_queue<int>& pq) {
    int i, j;
    while(!pq.empty()) {
        if(pq.size() == 1) {
            sum += pq.top();
            pq.pop();
            break;
        }

        i = pq.top();
        pq.pop();
        j = pq.top();
        pq.pop();

        if(i * j > i + j) {
            sum += (i * j);
        }
        else {
            sum += i;
            pq.push(j);
        }
    }
}

void greedy(priority_queue<int, vector<int>, greater<int>>& pq) {
    int i, j;
    while(!pq.empty()) {
        if(pq.size() == 1) {
            sum += pq.top();
            pq.pop();
            break;
        }

        i = pq.top();
        pq.pop();
        j = pq.top();
        pq.pop();

        if(i * j > i + j) {
            sum += (i * j);
        }
        else {
            sum += i;
            pq.push(j);
        }
    }
}