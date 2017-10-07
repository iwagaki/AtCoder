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
    int H, W, A, B;
    cin >> H >> W;
    cin >> A >> B;
    int m[200][200];

    REP(i, H) {
        string s;
        cin >> s;
        REP(j, W)
            m[i][j] = (s[j] == 'S') ? 1 : 0;
    }

    int pair4 = 0;
    int pair3 = 0;
    int pair2w = 0;
    int pair2h = 0;
    int pair1 = 0;

    REP(i, H / 2) REP(j, W / 2) {
        int a = m[i][j];
        int b = m[H - 1 - i][j];
        int c = m[i][W - 1 - j];
        int d = m[H - 1 - i][W - 1 - j];
        int test = a + b + c + d;
        if (test == 4) {
            pair4++;
        } else if (test == 3) {
            pair3++;
        } else if (test == 2) {
            if (a + b == 2 || c + d == 2) {
                pair2h++;
            } else if (a + c == 2 || b + d == 2) {
                pair2w++;
            } else {
                pair1 += 2;
            }
        } else if (test == 1) {
            pair1++;
        }
    }

    if (pair4 > 0 && pair3 + pair2w + pair2h + pair1 == 0) {
        pair4--;
        pair3++;
    } else if (pair4 + pair3 + pair1 == 0) {
        if (pair2w > 0 && pair2h == 0) {
            pair2w--;
        }
        if (pair2h > 0 && pair2w == 0) {
            pair2h--;
        }
    }

    int happiness = A + B;
    happiness += pair4 * (A + B) + pair4 * max(A, B);
    happiness += max(A * (pair3 + pair2h), B * (pair3 + pair2w));

    cout << happiness << endl;
    return 0;
}
