// Do it! 알고리즘 코딩테스트 책자
// 015번. 수 정렬하기 (BOJ #2750)
// 노션 정리 링크 → 안 만듬(너무 간단...)

#include <iostream>
#include <vector>

using namespace std;


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    bool change;
    cin>>N;

    vector<int> v(N, 0);
    for(int i=0; i<N; i++) {
        cin>>v[i];
    }

    for(int i=0; i<N; i++) {
        change = false;
        for(int j=0; j<N-i-1; j++) {
            if(v[j] > v[j+1]) {
                change = true;

                int temp = v[j];
                v[j] = v[j+1];
                v[j+1] = temp;
            }
        }
        if(!change) break;
    }

    for(int i=0; i<N; i++) {
        cout << v[i] << "\n";
    }

    return 0;
}