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

long long getMaxMultilpleLessThanOrEqual(long long v, long long a) {
    return (v / a) * a;
}

long long getMinMultilpleMoreThanOrEqual(long long v, long long a) {
    return ((v + a - 1) / a) * a;
}


int main() {
    int k;
    cin >> k;

    vector<long long> a;
    REP(i, k) {
        long long ai;
        cin >> ai;
        a.push_back(ai);
    }

    reverse(ALL(a));

    long long minTotal = a[0];
    long long maxTotal = a[0] + a[0] - 1;

    if (a[0] != 2) {
        cout << "-1" << endl;
        return 0;
    }

    for (int i = 1; i < (int)a.size(); i++) {
        long long newMinTotal = getMinMultilpleMoreThanOrEqual(minTotal, a[i]);
        long long newMaxTotal = getMaxMultilpleLessThanOrEqual(maxTotal, a[i]) + a[i] - 1;

        if (newMaxTotal < newMinTotal ||
            getMaxMultilpleLessThanOrEqual(newMinTotal, a[i]) < minTotal ||
            getMaxMultilpleLessThanOrEqual(newMaxTotal, a[i]) > maxTotal) {
            cout << "-1" << endl;
            return 0;
        }

        minTotal = newMinTotal;
        maxTotal = newMaxTotal;

    }

    cout << minTotal << " " << maxTotal << endl;
        
    return 0;
}
