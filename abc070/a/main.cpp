#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    int a = N / 100;
//    int b = (N % 100) / 10;
    int c = (N % 100) % 10;

    if (a == c) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    
    return 0;
}
