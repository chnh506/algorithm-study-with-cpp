// Do it! 알고리즘 코딩테스트 책자
// 008번. 좋다 (BOJ #1253)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) { 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, res = 0;
    vector<long> A;
    long long int i, j, target;

    cin>>N;
    long long int temp;
    for(int k=0; k<N; k++) {
        cin>>temp;
        A.push_back(temp);
    } 

    sort(A.begin(), A.end());

    for(int k=N-1; k>=0; k--) {
        target = A[k];
        i = 0;
        j = N-1;
        while(i < j) {
            if(i==k) {
                i++;
                continue;
            }
            if(j==k) {
                j--;
                continue;
            } 
            
            if(A[i] + A[j] < target) i++;
            else if(A[i] + A[j] > target) j--;
            else if(A[i] + A[j] == target) {
                res++;
                break;
            }
        }
    }

    cout << res << "\n";

    return 0;
}

