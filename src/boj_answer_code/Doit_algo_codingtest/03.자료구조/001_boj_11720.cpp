// Do it! 알고리즘 코딩테스트 책자
// 001번. 숫자의 합 (BOJ #11720)

#include <iostream>
#include <string>

using namespace std;

int main(void) {
    int n, res = 0;
    string str;

    cin>>n;
    cin>>str;

    for(int i=0; i<n; i++) {
        res += int(str[i] - '0');
    }

    cout<<res<<endl;

    return 0;
}