#include <algorithm>
#include <array>
#include <climits> // INT_MAX, LONG_MAX, LLONG_MAX, UINT_MAX, ULONG_MAX, ULLONG_MAX
#include <cmath>
#include <cstdint>
#include <iostream>
#include <map>
#include <string>
#include <vector>

#define INF (INT_MAX >> 1)

using namespace std;

int main() {
    string s;
    cin >> s;

    bool has9 = false;
    for (auto i : s) {
        if (i == '9') {
            has9 = true;
            break;
        }
    }

    cout << (has9 ? "Yes" : "No") << endl;

    return 0;
}
