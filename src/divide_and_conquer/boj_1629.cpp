// 문제 링크 : https://www.acmicpc.net/problem/1629
// 머가리 깨져 가면서 해결 ...
// 재귀 호출의 횟수(시간복잡도) / 모듈러 곱셈 연산 / 크기에 맞는 올바른 자료형 선택 등등.. 
// 틀린 부분을 알아가면서 해결하는 데 많은 시간이 걸렸다.
// 노션 페이지에 적어둔 코드들을 참고해서 정확히 어떤 이유로 틀린 코드들을 썼던 건지 점검할 것!


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long int A, B, C;

long long int pow(long long int A, long long int B, long long int C) {
    long long int tmp;
    // cout<<"B = "<<B<<endl;
    if(B == 0) return 1;
    else if(B == 1) return A % C;
    else {
        if(B % 2 == 0) {
            tmp = pow(A, B/2, C);
            return (tmp * tmp) % C;
        }
        else {
            tmp = pow(A, (B-1)/2, C);
            return ((tmp * tmp) % C * A) % C;
        }
    }
}

void boj_1629_main() {
    long long int res;
    cin>>A>>B>>C;

    res = pow(A, B, C);
    cout<<res<<endl;
}