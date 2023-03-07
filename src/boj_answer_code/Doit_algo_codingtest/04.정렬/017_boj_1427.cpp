// Do it! 알고리즘 코딩테스트 책자
// 017번. 소트인사이드 (BOJ #1427)
// 노션 정리 링크 → https://chnh506.notion.site/BOJ-1427-cbddaf008ec849989e4879db60b3a489

#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin>>N;
    string strN = to_string(N);

    // vector<int> v;
    // int divider = 10;
    // while(N / divider != 0) { divider *= 10; }
    // divider /= 10;

    // while(N/10 != 0) {
    //     v.push_back(N/divider);
    //     N %= divider;
    //     divider /= 10;
    // }
    // v.push_back(N);

    // int max;
    // for(int i=0; i<v.size(); i++ ) {
    //     max = i;
    //     for(int j=i; j<v.size(); j++) {
    //         if(v[j] > v[max]) max = j;
    //     }

    //     if(i != max) {
    //         int temp = v[i];
    //         v[i] = v[max];
    //         v[max] = temp;
    //     }
    // }

    int max = 0;
    for(int i=0; i<strN.length(); i++) {
        max = i;
        for(int j=i; j<strN.length(); j++) {
            if(strN[j] > strN[max]) max = j;
        }

        if(i != max) {
            char temp = strN[i];
            strN[i] = strN[max];
            strN[max] = temp;
        }
    }

    for(int i=0; i<strN.length(); i++) {
        cout<<strN[i]<<"";
    }
    cout<<"\n";


    return 0;
}
