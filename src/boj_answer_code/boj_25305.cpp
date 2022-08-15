#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool desc(int a, int b) {
    return a > b;
}

void boj_25305() {
    vector<int> score;
    int N, k, s_elem;

    cin>>N>>k;
    for(int i=0; i<N; i++) {
        cin>>s_elem;
        score.push_back(s_elem);
    }

    sort(score.begin(), score.end(), desc);
    cout<<score[k-1]<<endl;
}