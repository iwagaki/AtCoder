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
    int n, cn;
    cin >> n >> cn;

    vector<pair<int, int>> st[30];

    vector<int> tt;
    
    REP(i, n) {
        int si, ti, ci;
        cin >> si >> ti >> ci;
        auto sti = make_pair(si, ti);
        st[ci - 1].push_back(sti);
        tt.push_back(si);
        tt.push_back(ti - 1);
    }

    sort(ALL(tt));

    REP(i, cn)
        sort(ALL(st[i]));
    
    int maxCount = 0;
    int idx[30] = {0,};
    
    for (auto t : tt) {
        int count = 0;
        REP(j, cn) {
            for (;;) {
                if (idx[j] == st[j].size())
                    break;

                auto k = st[j][idx[j]];
                if (k.first - 1 <= t && t < k.second) {
                    count++;
                    break;
                } else if (k.second <= t) {
                    idx[j]++;
                } else {
                    break;
                }
            }
        }
        maxCount = max(maxCount, count);
    }

    cout << maxCount << endl;
    
    return 0;
}
