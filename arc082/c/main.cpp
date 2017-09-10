#include <algorithm>
#include <array>
#include <climits> // INT, LONG, LLONG, UINT, ULONG, ULLONG
#include <cmath>
#include <cstdint>
#include <iostream>
#include <map>
#include <string>
#include <vector>

#define INF (INT_MAX >> 1)

using namespace std;

int main() {
    int N;
    cin >> N;

    map<int, int> m;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        m[a]++;
        m[a - 1]++;
        m[a + 1]++;
    }

    int maxCount = 0;
    for (auto i : m)
        maxCount = max(maxCount, i.second);

    cout << maxCount << endl;
    
    return 0;
}
