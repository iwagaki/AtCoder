#include <algorithm>
#include <array>
#include <climits> // INT, LONG, LLONG, UINT, ULONG, ULLONG
#include <cmath>
#include <cstdint>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

string a;

int main() {
    cin >> a;

    map<int, int> table;
    
    for (int i = 0; i < a.size(); i++)
        table[a[i] - 'a']++;

    long long count = 1;

    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            if (i < j && table.count(i) > 0 && table.count(j) > 0) {
                count += 1ll * table[i] * table[j];
            }
        }
    }

    cout << count << endl;

    return 0;
}
