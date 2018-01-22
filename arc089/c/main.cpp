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
    int n;
    cin >> n;
    pair<int, int> a;
    int x = 0;
    int y = 0;
    int t = 0;
    bool isReacheable = true;
    REP(i, n) {
        int ti, xi, yi;
        cin >> ti >> xi >> yi;
        int dx = abs(ti - t) - (abs(xi - x) + abs(yi - y));
        if (dx < 0 || (dx % 2) != 0) {
            isReacheable = false;
            break;
        }
        x = xi;
        y = yi;
        t = ti;
    }

    cout << (isReacheable ? "Yes" : "No") << endl;
    return 0;
}
