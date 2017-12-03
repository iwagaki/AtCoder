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

    int f[100][10];
    int p[100][11];
    
    REP(i, n) {
        REP(j, 5) {
            int fi;
            cin >> fi;
            f[i][j * 2 + 0] = fi;
            cin >> fi;
            f[i][j * 2 + 1] = fi;
        }
    }

    REP(i, n) REP(j, 11) {
        int pi;
        cin >> pi;
        p[i][j] = pi;
    }

    long long bestProfit = -LLONG_MAX;
    
    for (int i = 1; i <= 0b1111111111; i++) {
        long long profit = 0;
        REP(k, n) {
            int open = i;
            int c = 0;
            REP(j, 10) {
                if (((open & 0x1) == 1) && (f[k][j] == 1))
                    c++;
                open >>= 1;
            }
            profit += p[k][c];
        }
        bestProfit = max(bestProfit, profit);
    }

    cout << bestProfit << endl;
    
    return 0;
}
