#include <iostream>

using namespace std;

int N, M;
int ans = 0;
int arr[101];

int main(void) {
    cin>>N>>M;

    for(int i=0; i<N; i++) {
        cin>>arr[i];
    }

    for(int i=0; i<N-2; i++) {
        for(int j=i+1; j<N-1; j++) {
            for(int k=j+1; k<N; k++) {
                if(arr[i]+arr[j]+arr[k] > M) continue;
                else if(arr[i]+arr[j]+arr[k] > ans) {
                    ans = arr[i]+arr[j]+arr[k];
                    if(ans == M) {
                        cout<<ans<<endl;
                        return 0;
                    }
                }
                else continue;
            }
        }
    }

    cout<<ans<<endl;
    return 0;
}