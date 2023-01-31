#include <iostream>

using namespace std;

int main(void) {
    int N;
    int k, min, max;

    cin >> N;
    
    // 맨 처음 수로 min과 max를 초기화!
    cin>>k;
    min = k;
    max = k;
    for(int i=1; i<N; i++) {
        cin >> k;
        if(k < min) min = k;
        if(k > max) max = k;
    }

    cout << min << " " << max << endl;

    return 0;
}