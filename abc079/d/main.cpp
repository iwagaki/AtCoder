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

int h, w;
int c[10][10];
int a[200][200];


int main() {
    cin >> h >> w;

    REP(i, 10) REP(j, 10) {
        int cij;
        cin >> cij;
        c[i][j] = cij;
    }

    REP(i, h) REP(j, w) {
        int ahw;
        cin >> ahw;
        a[i][j] = ahw;
    }

    REP(k, 10) REP(i, 10) REP(j, 10)
        c[i][j] = min(c[i][j], c[i][k] + c[k][j]);

    long long sum = 0;

    REP(i, h) REP(j, w) {
        if (a[i][j] != -1)
            sum += c[a[i][j]][1];
    }
    
    cout << sum << endl;
    
    return 0;
}
