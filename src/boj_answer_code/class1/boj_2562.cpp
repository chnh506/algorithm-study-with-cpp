#include <iostream>

using namespace std;

int main(void) {
    int k;
    int maxval = 0, idx = 0;

    for(int i=0; i<9; i++) {
        cin>>k;
        if(k > maxval) {
            maxval = k;
            idx = i+1;
        }
    }

    cout<<maxval<<"\n"<<idx<<endl;

    return 0;
}