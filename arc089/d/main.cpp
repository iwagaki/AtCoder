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


int countmap[2][2000][2000];


int getScore(int i, int x, int y, int k) {
    if (x < 0 || y < 0 || x - k + 1 >= 2 * k || y - k + 1 >= 2 * k)
        return 0;

    int x1 = min(x - k, 2 * k - 1);
    int y1 = min(y, 2 * k - 1);

    int x2 = min(x, 2 * k - 1);
    int y2 = min(y - k, 2 * k - 1);

    int x3 = min(x - k, 2 * k - 1);
    int y3 = min(y - k, 2 * k - 1);

    x = min(x, 2 * k - 1);
    y = min(y, 2 * k - 1);

    int score = countmap[i][x][y];

    if (x1 >= 0 && y1 >= 0)
        score -= countmap[i][x1][y1];

    if (x2 >= 0 && y2 >= 0)
        score -= countmap[i][x2][y2];

    if (x3 >= 0 && y3 >= 0)
        score += countmap[i][x3][y3];

    return score;
}


int main() {
    int n, k;
    cin >> n >> k;

    REP(i, n) {
        int xi, yi;
        string ci;
        cin >> xi >> yi >> ci;
        countmap[(ci[0] == 'W') ? 0 : 1][xi % (2 * k)][yi % (2 * k)]++;
    }

    REP(p, 2) REP(q, 2 * k) REP(r, 2 * k) {
        if (q > 0)
            countmap[p][q][r] += countmap[p][q - 1][r];
        if (r > 0)
            countmap[p][q][r] += countmap[p][q][r - 1];
        if (q > 0 && r > 0)
            countmap[p][q][r] -= countmap[p][q - 1][r - 1];
    }

    int best = 0;

    REP(p, 2 * k) REP(q, 2 * k) {
        int current = 0;

        int index = 0;
        REP(i, 5) REP(j, 5) {
            current += getScore(index, p - 2 * k + k * i, q - 2 * k + k * j, k);
            index ^= 1;
        }

        best = max(best,current);
    }
    
    cout << best << endl;
    
    return 0;
}
