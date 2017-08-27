#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int A, B, C, D;
    cin >> A >> B >> C >> D;

    cout << max((B - A) + (D - C) - (max(D, B) - min(A, C)), 0) << endl;

    return 0;
}
