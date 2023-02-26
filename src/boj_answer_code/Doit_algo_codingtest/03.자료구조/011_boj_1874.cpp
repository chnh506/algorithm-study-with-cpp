// Do it! 알고리즘 코딩테스트 책자
// 011번. 스택 수열 (BOJ #1874)
// 노션 정리 링크 → https://www.notion.so/chnh506/BOJ-1874-314428f4a52c46ec8bf5bcec7f817cda?pvs=4

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int n, nextVal = 1, curIdx = 0;
vector<int> vec;
vector<char> resArr;
stack<int> s;

int main(void) { 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;
    int temp;
    for(int i=0; i<n; i++) {
        cin>>temp;
        vec.push_back(temp);
    }

    while(nextVal <= n || curIdx < n) {
        if(s.empty()) {     
            // 스택이 비어 있는 경우
            if(vec[curIdx] >= nextVal) {    
                // 이 경우, 스택에 push해 줌으로써 스택 수열을 만들 수 있는 기회가 아직 열려 있다.
                resArr.push_back('+');
                s.push(nextVal);
                nextVal++;
                continue;
            }
            else {  
                // vec[curIdx]가 nextVal보다 작은 경우는 스택 수열이 불가능한 경우이다. (오름차순으로 넣어주므로 이미 지나갔다는 뜻)
                cout << "NO" << "\n";
                return 0;
            }
        }
        else {
            if(vec[curIdx] == s.top()) {    
                // 스택 맨 위에 있는 숫자를 pop해 주고 다음으로 나아가면 된다.
                resArr.push_back('-');
                s.pop();
                curIdx++;
                continue;
            }
            else if(vec[curIdx] > s.top()) {    
                // s.top()이 더 작다 즉, 계속 nextVal이 vec[curIdx]와 같아질 때까지 늘려주면서 push해 주면 된다.
                resArr.push_back('+');
                s.push(nextVal);
                nextVal++;
                continue;
            }
            else {  
                // 마찬가지로, vec[curIdx]가 이미 스택의 밑부분에 깔려 있는 상황.. 불가능한 경우이다.
                cout << "NO" << "\n";
                return 0;
            }
        }
    }

    for(int i=0; i<resArr.size(); i++) {
        cout << resArr[i] << "\n";
    }

    return 0;
}

