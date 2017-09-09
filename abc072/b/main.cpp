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
    int N;
    cin >> N;

    int count = 0;

    for (int i = 1; i <= N; i++) {
        int l, r;
        cin >> l >> r;
        count += r - l + 1;
    }

    cout << count << endl;

    return 0;
}
