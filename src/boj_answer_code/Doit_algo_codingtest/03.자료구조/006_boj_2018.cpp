// Do it! 알고리즘 코딩테스트 책자
// 006번. 수들의 합 5 (BOJ #2018)

// 내가 쥐어짜낸 정답 코드 ...
#include <iostream>

using namespace std;

int s(int a, int l) {
    return (l-a+1) * (a+l) / 2;
}

int main(void) {
    int N;
    int a = 1, l = 2;
    int num = 2, res = 0;
    int sum = s(a, l);

    cin>>N;
    while(sum < N) {
        sum = s(a, l);
        if(sum < N) {
            l++;
            num++;
            continue;
        }
        else if(sum > N) {
            num--;
            a++;
            break;
        }
        else {
            res++;
            num--;
            a++;
            break;
        }
    }

    while(num > 1) {
        sum = s(a, l);
        if(sum < N) {
            l++;
            a++;
        }
        else if(sum > N) {
            num--;
            a++;
        }
        else {
            res++;
            num--;
            a++;
        }
    }

    res++;
    cout << res << endl;

    return 0;
}



// 책의 정답 코드(코드 복기 할 것!!)
