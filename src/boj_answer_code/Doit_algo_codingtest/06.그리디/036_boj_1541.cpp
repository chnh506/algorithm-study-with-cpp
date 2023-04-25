// Do it! 알고리즘 코딩테스트 책자
// 036. 잃어버린 괄호 (BOJ #1541)
// 노션 정리 링크 → https://chnh506.notion.site/BOJ-1541-d8a3a613a0d2422f85dfee957b5fd48a

#include <iostream>
#include <vector>
#include <string>     

using namespace std;


int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string fx, num;
    int res = 0, temp = 0;

    cin>>fx;

    int idx = 0;
    while(fx[idx] != '-' && idx < fx.length()) {
        if(fx[idx] == '+') {
            res += stoi(num);
            num = "";
        }
        else {
            num = num + fx[idx];
        }
        idx++;
    }
    if(num != "") {
        res += stoi(num);
        num = "";
    }

    for(int i = idx+1; i<fx.length(); i++) {
        if(fx[i] == '+') {
            temp += stoi(num);
            num = "";
        }
        else if(fx[i] == '-') {
            temp += stoi(num);
            num = "";

            res -= temp;
            temp = 0;
        }
        else {  // 숫자일 때
            num = num + fx[i];
        }
    }
    if(num != "") {
        temp += stoi(num);
        res -= temp;
    }

    cout<<res<<"\n";

    return 0;
}
