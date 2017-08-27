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

int n, q, k;

map<int, long long> cost;
map<int, map<int, long long>> tree;

void dfs(int v, int p, long long c) {
    cost[v] = c;
    for (auto e : tree[v]) {
        if (e.first == p)
            continue;
        dfs(e.first, v, c + e.second);
    }
}

int main() {
    cin >> n;
    
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        tree[a - 1][b - 1] = c;
        tree[b - 1][a - 1] = c;
    }

    cin >> q >> k;

    dfs(k - 1, INF, 0);
    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        cout << cost[x - 1] + cost[y - 1] << endl;
    }
    
    return 0;
}
