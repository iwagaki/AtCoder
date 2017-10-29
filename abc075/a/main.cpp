#include <algorithm>
#include <array>
#include <climits> // INT_MAX, LONG_MAX, LLONG_MAX, UINT_MAX, ULONG_MAX, ULLONG_MAX
#include <cmath>
#include <cstdint>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

#define ALL(x) (x).begin(), (x).end()
#define INF 1e9
#define LOG(x) cout << #x << " = " << (x) << endl
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

using namespace std;

int main() {
    map<int, int> count;

    for (int i = 0; i < 3; i++) {
        int ai;
        cin >> ai;
        count[ai]++;
    }

    for (auto i: count) {
        if (i.second == 1) {
            cout << i.first << endl;
            break;
        }
    }

    return 0;
}
