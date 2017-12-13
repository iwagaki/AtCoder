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
    int n, k;
    cin >> n >> k;

    map<int, int> ball;
    REP(i, n) {
        int ai;
        cin >> ai;
        ball[ai] += 1;
    }
    vector<pair<int, int>> ball2;
    for (auto i : ball)
        ball2.push_back({i.second, i.first});
    sort(ALL(ball2));

    int count = 0;

    for (int i = ball2.size() - 1; i >= 0; i--) {
        if (k <= 0)
           count += ball2[i].first;
        k--;
   }

    cout << count << endl;
}
