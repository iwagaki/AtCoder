#include <algorithm>
#include <array>
#include <climits> // INT_MAX, LONG_MAX, LLONG_MAX, UINT_MAX, ULONG_MAX, ULLONG_MAX
#include <cmath>
#include <cstdint>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>

#define INF 1e9
#define REP(i,n) for (int i = 0; i < (n); ++i)
#define LOG(x) cerr << #x << " = " << (x) << endl

using namespace std;

int main() {
    string s;
    cin >> s;

    if (s.find("YAKI") == 0) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
