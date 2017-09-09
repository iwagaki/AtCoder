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

vector<vector<int>> edge;
vector<vector<int>> dist;

int minDist(int n, int start, int end) {
    vector<bool> check(n, false);
    vector<int> d(n, INF);
    d[start] = 0;
    
    for (int i = 0; i < n; i++) {
        int min = INF;
        int now = 0;
        for (int j = 0; j < n; j++) {
            if (!check[j] && min > d[j]) {
                min = d[j];
                now = j;
            }
        }

        if (min == INF)
            break;

        check[now] = true;

        for (size_t j = 0; j < edge[now].size(); j++) {
            int next = edge[now][j];
            int nextd = d[now] + dist[now][j];
            if (nextd < d[next])
                d[next] = nextd;
        }
    }

    return d[end];
}

int minDist(int total, int from, vector<int> rList, map<int, map<int, int>>& rDist) {
    int d = INF;

    if (rList.size() == 0)
        return total;
    
    for (size_t i = 0; i < rList.size(); i++) {
        int dx = 0;
        if (from != -1)
            dx = rDist[from][rList[i]];

        vector<int> rList2 = rList;
        rList2.erase(rList2.begin() + i);

        d = min(d, minDist(total + dx, rList[i], rList2, rDist));
    }

    return d;
}

int main() {
    int N, M, R;
    cin >> N >> M >> R;

    vector<int> rList;

    for (int i = 0; i < N; i++) {
        dist.push_back({});
        edge.push_back({});
    }
 
    for (int i = 0; i < R; i++) {
        int r;
        cin >> r;
        rList.push_back(r - 1);
    }

    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        
        edge[a - 1].push_back(b - 1);
        dist[a - 1].push_back(c);
        edge[b - 1].push_back(a - 1);
        dist[b - 1].push_back(c);
    }

    map<int, map<int, int>> rDist;
    for (size_t i = 0; i < rList.size(); i++)
        for (size_t j = 0; j < rList.size(); j++)
            if (i < j)
                rDist[rList[i]][rList[j]] = rDist[rList[j]][rList[i]] = minDist(N, rList[i], rList[j]);

    cout << minDist(0, -1, rList, rDist) << endl;
    
    return 0;
}
