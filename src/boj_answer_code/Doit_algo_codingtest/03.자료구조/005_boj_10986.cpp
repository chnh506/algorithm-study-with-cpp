#include <iostream>

using namespace std;

long N, M, res = 0;
long S[1000001] = {0, };
long C[1001] = {0, };

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N>>M;
    int temp;
    for(int i=1; i<=N; i++) {
        cin>>temp;
        S[i] = S[i-1] + temp;
    }

    for(int i=1; i<=N; i++) {
        int remainder = S[i] % M;

        if(remainder == 0) res++;
        C[remainder]++;
    }

    for(int i=0; i<M; i++) {
        if(C[i] > 1) {
            res += C[i] * (C[i] - 1) / 2;
        }
    }

    cout<<res<<"\n";

    return 0;
}