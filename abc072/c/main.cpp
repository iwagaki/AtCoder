#include <algorithm>
#include <array>
#include <climits> // INT_MAX, LONG_MAX, LLONG_MAX, UINT_MAX, ULONG_MAX, ULLONG_MAX
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

    map<int, bool> numMap;

    for (int i = 1; i <= N; i++) {
        int a;
        cin >> a;
        numMap[a] ^= true;
    }

    int count = 0;
    
    for (auto i : numMap) {
        if (i.second)
            count++;
    }

    cout << count << endl;

    return 0;
}
