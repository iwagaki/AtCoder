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
    int N, K;
    vector<pair<int, int>> ab;

    cin >> N >> K;
    for (int i = 0; i < N; ++i) {
        int ai, bi;
        cin >> ai >> bi;
        ab.push_back({ai, bi});
    }

    // sort(ALL(ab), [&] (const pair<int, int>&a, const pair<int, int>& b) -> bool { return a.first < b.first; });

    // int msb = 0;
    // for (long long i = 1; i <= INT_MAX; i <<= 1) {
    //     if (i > K)
    //         break;
    //     msb++;
    // }

    unsigned int mask_seed = 1;
    long long maxValue = 0;
    for (int i = 1; i <= 30; i++, mask_seed <<= 1) {
        int mask = K;
        if (i > 1) {
            if ((K & mask_seed) == 0)
                continue;
            mask = K & ~mask_seed; // i-th bit = 0
            mask |= (mask_seed - 1); // 0 to (i - 1)-th bit = 1
        }
        long long value = 0;
        for (auto j : ab) {
            if ((j.first & ~mask) == 0) {
                value += j.second;
            }
        }
        maxValue = max(maxValue, value);
    }

    cout << maxValue << endl;
    
    return 0;
}
