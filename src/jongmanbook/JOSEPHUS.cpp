#include <iostream>
#include <list>

using namespace std;


int main(void) {
    int C, N, K;
    list<int> a;
    list<int>::iterator iter;

    cin>>C;
    for(int i=0; i<C; i++) {
        cin>>N>>K;
        
        for(int j=1; j<=N; j++) {
            a.push_back(j);
        }   // 사람들이 원형으로 둘러싼 형태를 리스트로 표현.

        iter = a.begin();
        iter = a.erase(iter);

        while(a.size() > 2) {
            for(int j=0; j<K-1; j++) {
                ++iter;
                if(iter == a.end()) iter = a.begin();
                // a.end()가 마지막 원소 다음 칸을 가리킨다는 개념을 이용한 trick!!!!
            }
            
            iter = a.erase(iter);
            if(iter == a.end()) iter = a.begin();
        }

        cout<<a.front()<<' '<<a.back()<<endl;

        while(!a.empty()) {
            a.pop_back();
        }
    }
    
    return 0;
}