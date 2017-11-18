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


int n[4];

string func(int i, int sum, string equation) {
    if (i == 3) {
        if (sum == 7)
            return equation + "=7";
        else
            return "";
    }

    int next = n[i + 1];
    string s1 = func(i + 1, sum + next, equation + "+" + to_string(next));
    string s2 = func(i + 1, sum - next, equation + "-" + to_string(next));

    return s1 != "" ? s1 : s2;
}


int main() {
    string s;
    cin >> s;
    REP(i, s.size())
        n[i] = s[i] - '0';

    cout << func(0, n[0], to_string(n[0])) << endl;

    return 0;
}
