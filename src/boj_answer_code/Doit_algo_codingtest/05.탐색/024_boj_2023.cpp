// Do it! 알고리즘 코딩테스트 책자
// 024. 신기한 소수 (BOJ #2023)
// 노션 정리 링크 → https://chnh506.notion.site/BOJ-2023-af0b085e681e4e8b9a2f05f565e2afab


// 책의 모범답안 정답코드
#include <iostream>
#include <vector>

using namespace std;

int N;
bool isPrime(int n);
void dfs(int n, int digit);

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 

    cin>>N;
    dfs(2, 1);
    dfs(3, 1);
    dfs(5, 1);
    dfs(7, 1);
    
    return 0;
}

bool isPrime(int n) {
	for (int i=2; i<n; i++) {
		if (n % i == 0) { //i가 n의 약수라면 소수가 아니므로 false return
			return false;
		}
	}
	//2 ~ n-1까지 약수가 없다면 소수이므로, true return
	return true;
}

void dfs(int n, int digit) {
    if(digit == N) {
        if(isPrime(n))
            cout<<n<<"\n";
        return;
    }

    for(int i=1; i<=9; i++) {
        if(i % 2 == 0) continue;
        if(isPrime(n * 10 + i)) {
            dfs(n * 10 + i, digit + 1);
        }
    }
}


// 나의 정답 코드
/*
#include <iostream>
#include <vector>

using namespace std;

int N, digit;
static vector<int> res;
bool isPrime(int n);
void dfs(int n);

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 

    cin>>N;
    for(int i=2; i<=9; i++) {
        digit = 1;
        dfs(i);
    }

    for(int i=0; i<res.size(); i++) {
        cout<<res[i]<<"\n";
    }

    return 0;
}

bool isPrime(int n) {
	for (int i=2; i<n; i++) {
		if (n % i == 0) { //i가 n의 약수라면 소수가 아니므로 false return
			return false;
		}
	}
	//2 ~ n-1까지 약수가 없다면 소수이므로, true return
	return true;
}

void dfs(int n) {
    if(digit == N && isPrime(n)) {
        res.push_back(n);
        digit--;
        return;
    }

    if(!isPrime(n)) {
        digit--;
        return;
    }
    else {
        for(int i=1; i<=9; i++) {
            int k = n * 10 + i;
            digit++;
            dfs(k);
        }
    }

    digit--;
    return;
}
*/