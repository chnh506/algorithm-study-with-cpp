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
// while 조건을 end_idx가 N까지 증가할 때로 잡을 수 있었던 이유??
// start_idx와 end_idx 자체를 값으로 쓸 생각을 처음에 못 해서 메모리 초과가 나왔다 ...
int Doit006(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin>>N;

    int count = 1;
    int start_idx = 1;
    int end_idx = 1;
    int sum = 1;

    while(end_idx != N) {       // 어떻게 이 조건이 나온 것이지???
        if(sum == N) {
            count++;
            end_idx++;
            sum += end_idx;
        }
        else if(sum > N) {
            sum -= start_idx;
            start_idx++;
        }
        else {
            end_idx++;
            sum += end_idx;
        }
    }

    cout << count << "\n";
    
    return 0;
}