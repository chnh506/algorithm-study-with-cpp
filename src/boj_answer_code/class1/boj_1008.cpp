#include <iostream>

using namespace std;

int main(void) {
    double A, B;
    double res;

    cin >> A >> B;
    res = A / B;

    cout.precision(15);
    cout << res << endl;

    return 0;
}