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

int s[2][1000][1000];


int main() {
    int n, k;
    cin >> n >> k;

    REP(i, n) {
        int xi, yi;
        string ci;
        cin >> xi >> yi >> ci;

        if (ci[0] == 'B')
            xi += k; // Do not use -= for %
        if (xi % (2 * k) >= k) {
            xi += k; // Do not use -= for %
            yi += k; // Do not use -= for %
        }

        if (yi % (2 * k) >= k)
            s[1][xi % k][yi % k]++;
        else
            s[0][xi % k][yi % k]++;
    }

    REP(p, 2) {
        for (int q = 1; q < k; q++) s[p][q][0] += s[p][q - 1][0];
        for (int r = 1; r < k; r++) s[p][0][r] += s[p][0][r - 1];
        for (int q = 1; q < k; q++) for (int r = 1; r < k; r++) s[p][q][r] += s[p][q - 1][r] + s[p][q][r - 1] - s[p][q - 1][r - 1];
    }

    int best = 0;

    REP(p, k) REP(q, k) {
        best = max(best,
                   max(s[0][k - 1][k - 1] - s[0][p][k - 1] - s[0][k - 1][q] + 2 * s[0][p][q] + s[1][p][k - 1] + s[1][k - 1][q] - 2 * s[1][p][q],
                       s[1][k - 1][k - 1] - s[1][p][k - 1] - s[1][k - 1][q] + 2 * s[1][p][q] + s[0][p][k - 1] + s[0][k - 1][q] - 2 * s[0][p][q]));
    }

    cout << best << endl;

    return 0;
}
