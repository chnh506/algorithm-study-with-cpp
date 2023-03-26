// Do it! 알고리즘 코딩테스트 책자
// 022. 수 정렬하기 3 (BOJ #10989)
// 노션 정리 링크 → https://chnh506.notion.site/BOJ-10989-3-210b4adcede340a8816fbe004d919f07

#include <iostream>
#include <vector>

using namespace std;

// 계수 정렬(counting sort)! 
// O(N)인 정렬이고, 계수 정렬은 '비교를 하지 않는다.'
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 

    int N;
    cin>>N;

    vector<int> v(10001, 0);
    int temp;
    for(int i=0; i<N; i++) {
        cin>>temp;
        v[temp]++;
    }

    for(int i=1; i<=10000; i++) {
        for(int j=0; j<v[i]; j++) {
            cout<<i<<"\n";
        }
    }

    return 0;
}



/*
// Radix Sort로 해결하는 code
// 안타깝게도 .. 천만개의 인풋을 다 저장하는 과정에서, BOJ에서는 메모리 초과가 뜬다..
// 그래도, 공부하는 차원에서 Radix Sort 코드를 알아 두기는 하자.
#include <iostream>
#include <math.h>
#include <vector>
#include <deque>
#include <cmath>

using namespace std;

vector<deque<int>> qList;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 

    int N;
    cin>>N;
    
    qList = vector<deque<int>> (10, deque<int>(0));
    vector<int> v(N, 0);
    for(int i=0; i<N; i++) {
        cin>>v[i];
    }

    for(int i=1; i<=5; i++) {
        int idx = 0;
        for(int j=0; j<N; j++) {
            int digit = (v[j] % int(pow(10, i))) / int(pow(10, i-1));
            qList[digit].push_back(v[j]);
        }

        for(int j=0; j<10; j++) {
            while(!qList[j].empty()) {
                v[idx++] = qList[j].front();
                qList[j].pop_front();
            }
        }
    }

    for(int i=0; i<N; i++) {
        cout<<v[i]<<"\n";
    }

    return 0;
}
*/