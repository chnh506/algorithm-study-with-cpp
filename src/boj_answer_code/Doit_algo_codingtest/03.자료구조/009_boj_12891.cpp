// Do it! 알고리즘 코딩테스트 책자
// 009번. DNA 비밀번호 (BOJ #12891)

#include <iostream>
#include <string>

using namespace std;

int main(void) { 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int s, p, res = 0;
    cin>>s>>p;
    string dna;
    cin>>dna;
    int A, C, G, T;
    cin>>A>>C>>G>>T;

    int curA=0, curC=0, curG=0, curT=0;
    for(int k=0; k<p; k++) {
        if(dna[k] == 'A') curA++;
        else if(dna[k] == 'C') curC++;
        else if(dna[k] == 'G') curG++;
        else if(dna[k] == 'T') curT++;
    }
    if(curA >= A && curC >= C && curG >= G && curT >= T) res++;

    for(int i=1, j=p; j<s; i++, j++) {
        if(dna[i-1] == 'A') curA--;
        else if(dna[i-1] == 'C') curC--;
        else if(dna[i-1] == 'G') curG--;
        else if(dna[i-1] == 'T') curT--;

        if(dna[j] == 'A') curA++;
        else if(dna[j] == 'C') curC++;
        else if(dna[j] == 'G') curG++;
        else if(dna[j] == 'T') curT++;

        if(curA >= A && curC >= C && curG >= G && curT >= T) res++;
    }

    cout << res << "\n";

    return 0;
}
