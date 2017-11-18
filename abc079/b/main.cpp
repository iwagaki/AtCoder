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

    long long l[86] = {0};
    l[0] = 2;
    l[1] = 1;
    for (int i = 1; i <= n; i++) {
        if (i > 1)
            l[i] = l[i - 1] + l[i - 2];
    }

    cout << l[n] << endl;

    return 0;
}
