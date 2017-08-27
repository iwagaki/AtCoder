#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    map<int, long long> bars;
    vector<long long> bars2 = {0, 0};

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;

        if (bars.count(a) == 0) {
            bars[a] = 1;
        } else {
            bars[a]++;
        }
    }

    for (auto i : bars) {
        if (i.second >= 4) {
            bars2.push_back(i.first);
            bars2.push_back(i.first);
        } else if (i.second >= 2) {
            bars2.push_back(i.first);
        }
    }

    sort(bars2.begin(), bars2.end(), greater<int>());

    cout << bars2[0] * bars2[1] << endl;
    
    return 0;
}
