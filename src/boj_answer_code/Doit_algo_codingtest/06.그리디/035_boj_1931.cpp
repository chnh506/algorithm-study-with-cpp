// Do it! 알고리즘 코딩테스트 책자
// 035. 회의실 배정 (BOJ #1931)
// 노션 정리 링크 → https://chnh506.notion.site/BOJ-1931-bda82bd679ee427387a4b40ceac565b0

#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>


using namespace std;

typedef pair<int, int> Meet;    // first가 시작 시간, second가 종료 시간

bool compare(const Meet &a, const Meet &b) {
    if(a.second == b.second) {
        if(a.first < b.first) return true;
        else return false;
    }
    else {
        if(a.second < b.second) return true;
        else return false;
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin>>N;

    vector<Meet> v(N);
    int s, f;
    for(int i=0; i<N; i++) {
        cin>>s>>f;
        v[i] = make_pair(s, f);
    }
    sort(v.begin(), v.end(), compare);

    Meet cur = v[0];
    int count = 1;
    for(int i=1; i<N; i++) {
        if(cur.second <= v[i].first) {
            cur = v[i];
            count++;
        }
    }

    cout<<count<<"\n";

    return 0;
}
