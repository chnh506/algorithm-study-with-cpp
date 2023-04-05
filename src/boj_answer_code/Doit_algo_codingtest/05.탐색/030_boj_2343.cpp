// Do it! 알고리즘 코딩테스트 책자
// 030. 기타 레슨 (BOJ #2343)
// 노션 정리 링크 → https://chnh506.notion.site/BOJ-2343-ba07c4a02ddd4ea0b83a7912a4d76985

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin>>N>>M;

    vector<int> lesson(N);
    int max = 0, total = 0;
    for(int i=0; i<N; i++) {
        cin>>lesson[i];
        if(lesson[i] > max) max = lesson[i];
        total += lesson[i];
    }  

    int s = max, e = total, mid;
    while(s <= e) {
        mid = (s + e) / 2;      // mid 값이 블루레이의 크기로 쓰이게 된다.
        int sum = 0, count = 1;    
        // sum: 한 블루레이에 저장한 레슨 길이를 임시로 담아두는 변수 
        // count: 지금까지 사용한 블루레이 개수
        
        for(int i=0; i<N; i++) {
            if(sum + lesson[i] > mid) {
                count++;
                sum = lesson[i];
                if(count > M) break;
            }
            else {
                sum += lesson[i];
            }
        }

        if(count > M) s = mid + 1;
        else e = mid - 1;
    }

    cout<<s<<"\n";

    return 0;
}