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
    string s2, t;
    cin >> s2 >> t;

    string sa = s2;
    for (auto& i : sa)
        if (i == '?')
            i = 'a';

    string s;
    
    REP(i, s2.size()) {
        bool isFound = false;
        REP(j, t.size()) {
            if (s2[i + j] == t[j] || s2[i + j] == '?') {
                if (j == (int)t.size() - 1)
                    isFound = true;
            } else
                break;
        }
        if (isFound) {
            string ss = sa;
            ss.replace(i, t.size(), t);
            s = s.empty() ? ss : (s > ss ? ss : s);
        }
    }

    if (s.empty())
        cout << "UNRESTORABLE" << endl;
    else
        cout << s << endl;

    return 0;
}
