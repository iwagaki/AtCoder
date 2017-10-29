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
    int H, W;
    cin >> H >> W;

    vector<string> S;

    REP(i, H) {
        string si;
        cin >> si;
        S.push_back(si);
    }

    REP(i, H) {
        REP(j, W) {
            if (S[i][j] == '.') {
                int count = 0;
                for (int h = i - 1; h <= i + 1; h++) {
                    for (int w = j - 1; w <= j + 1; w++) {
                        if (h >= 0 && h < H && w >= 0 && w < W && S[h][w] == '#')
                            count++;
                    }
                }
                S[i][j] = '0' + count;
            }
        }
    }

    REP(i, H)
        cout << S[i] << endl;

    return 0;
}
