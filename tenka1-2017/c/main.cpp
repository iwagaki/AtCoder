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
    int N;
    cin >> N;

    for (int h = 1; h <= 3500; h++) {
        for (int n = 1; n <= 3500; n++) {
            long long x = 1ll * 4 * h * n - N * n - N * h;
            long long y = 1ll * N * h * n;
            if (x > 0 && y % x == 0) {
                cout << h << " " << n << " " << y / x << endl;
                return 0;
            }
        }
    }
    
    return 0;
}
