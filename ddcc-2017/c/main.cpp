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
    int N, C;
    cin >> N >> C;
    vector<int> L;
    REP (i, N) {
        int li;
        cin >> li;
        L.push_back(li);
    }

    sort(ALL(L));

    int total = 0;

    for (int i = 0, j = N - 1; i <= j;) {
        if (i != j) {
            if (C - L[j] >= L[i] + 1)
                i++;
        }
        j--;
        total++;
    }

    cout << total << endl;

    return 0;
}
