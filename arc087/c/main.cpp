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
    map<int, int> a;
    REP(i, n) {
        int ai;
        cin >> ai;
        a[ai] += 1;
    }

    int count = 0;
    
    for (auto i: a) {
        if (i.second > i.first) {
            count += i.second - i.first;
        } else if (i.second < i.first) {
            count += i.second;
        }
    }

    cout << count << endl;

    return 0;
}
