#include <iostream>

using namespace std;

int main(void) {
    int y, res = 0;
    cin>>y;

    if(y % 4 == 0) res = 1;
    if(y % 100 == 0) res = 0;
    if(y % 400 == 0) res = 1;

    cout << res << endl;

    return 0;
}