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

    vector<bool> m;
    for (int i = 1; i <= N; i++) {
        int p;
        cin >> p;
        m.push_back(i == p ? true : false);
    }

    int count = 0;

    for (int i = 0; i < N; i++) {
        if (m[i]) {
            count++;
            if (i + 1 < N && m[i + 1])
                i++;
        }        
    }

    cout << count << endl;
    
    return 0;
}
