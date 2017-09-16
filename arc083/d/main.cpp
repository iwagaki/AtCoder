#include <algorithm>
#include <array>
#include <climits> // INT_MAX, LONG_MAX, LLONG_MAX, UINT_MAX, ULONG_MAX, ULLONG_MAX
#include <cmath>
#include <cstdint>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>

#define INF 1e9
#define REP(i,n) for (int i = 0; i < (n); ++i)
#define LOG(x) cerr << #x << " = " << (x) << endl

using namespace std;

int N;
int a[300][300];

int main() {
    cin >> N;

    REP(i, N) REP(j, N) {
        int ai;
        cin >> ai;
        a[i][j] = ai;
    }

    bool check = true;
    long long minDist = 0;

    REP(i, N) REP(j, N) {
        if (!check)
            break;
        
        if (i >= j)
            continue;

        bool shoudSkip = false;
        REP(k, N) {
            if (k == i || k == j)
                continue;
            
            if (a[i][k] + a[k][j] < a[i][j]) {
                check = false;
                break;
            }
            if (a[i][k] + a[k][j] == a[i][j])
                shoudSkip = true;
        }
        if (!shoudSkip)
            minDist += 1ll * a[i][j];
    }

    cout << (long long)(check ? minDist : -1) << endl;
    
    return 0;
}
