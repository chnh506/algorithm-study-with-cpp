#include <iostream>

using namespace std;

int main(void) {
    int arr[9] = {0, };
    for(int i=1; i<=8; i++) {
        cin>>arr[i];
    }

    for(int i=1; i<=8; i++) {
        if(arr[i] != i) 
            break;
        else if(i == 8) {
            cout << "ascending" << endl;
            return 0;
        }
        else
            continue;
    }

    for(int i=1; i<=8; i++) {
        if(arr[i] != 9-i) 
            break;
        else if(i == 8) {
            cout << "descending" << endl;
            return 0;
        }
        else
            continue;
    }

    cout << "mixed" << endl;
    return 0;
}