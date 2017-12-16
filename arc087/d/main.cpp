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

void update(set<int>& setX, int count) {
    set<int> temp(setX);
    setX.clear();
    for (auto i: temp) {
        setX.insert(i + count);
        setX.insert(i - count);
    }
}


int main() {
    string s;
    cin >> s;
    int x, y;
    cin >> x >> y;
    s += "T";
        
    set<int> setX = {0};
    set<int> setY = {0};

    int count = 0;
    int sign = -1;
    
    for (auto i: s) {
        if (i == 'F') {
            count++;
        } else if (i == 'T') {
            if (sign == -1) {
                setX.erase(0);
                setX.insert(count);
                sign = 1;
            } else if (sign == 1) {
                update(setX, count);
            } else if (sign == 0) {
                update(setY, count);
            }
            sign ^= 1;
            count = 0;
        } 
    }

    cout << ((setX.count(x) == 1 && setY.count(y) == 1) ? "Yes" : "No") << endl;
    
    return 0;
}
