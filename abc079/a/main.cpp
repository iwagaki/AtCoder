#include <algorithm>
#include <array>
#include <climits> // INT_MAX, LONG_MAX, LLONG_MAX, UINT_MAX, ULONG_MAX, ULLONG_MAX
#include <cmath>
#include <cstdint>
#include <cstring> // memset
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
    string n;
    cin >> n;

    int count = 0;
    bool isGood = false;
    REP(i, n.size()) {
        if (i > 0 && n[i - 1] == n[i]) {
            count++;
            if (count == 2)
                isGood = true;
        } else {
            count = 0;
        }
    }
    if (isGood)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}
