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
    string sn = to_string(n);

    int fx = 0;
    REP(i, sn.size()) {
        fx += sn[i] - '0';
    }

    cout << ((n % fx == 0) ? "Yes" : "No") << endl;
    
    return 0;
}
