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

int main() {
    int H, W;
    cin >> H >> W;

    map<int, int> a;
    REP(i, H) {
        string s;
        cin >> s;
        REP(j, W) {
            a[s[j] - 'a']++;
        }
    }

    int x4 = (H / 2) * (W / 2);
    int x2 = (H / 2) * (W % 2) + (W / 2) * (H % 2);
    int x1 = (W % 2) * (H % 2);
    
    for (auto i: a) {
        int j = i.second;
        if (x4 >= j / 4) {
            x4 -= j / 4;
            j = j % 4;
        }
        x2 -= j / 2;
        j = j % 2;
        x1 -= j;
    }

    if (x4 == 0 && x2 == 0 && x1 == 0) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
