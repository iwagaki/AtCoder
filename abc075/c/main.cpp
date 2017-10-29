#include <algorithm>
#include <array>
#include <climits> // INT_MAX, LONG_MAX, LLONG_MAX, UINT_MAX, ULONG_MAX, ULLONG_MAX
#include <cmath>
#include <cstdint>
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


int N, M;
int d[50][50];

bool checkGraph(vector<int>& a, vector<int>& b, int l) {
    REP(i, 50) REP(j, 50) {
        if (i == j)
            d[i][j] = 0;
        else
            d[i][j] = INF;
    }

    REP(i, M) {
        if (i != l) {
            int ai = a[i];
            int bi = b[i];
            d[ai][bi] = d[bi][ai] = 1;
        }
     }

    REP(k, N) REP(i, N) REP(j, N) {
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);        
    }
    

    REP(i, N) for (int j = 0; j < i; j++) {
        if (d[i][j] == INF)
            return true;
    } 
    return false;
}


int main() {
    cin >> N >> M;

    vector<int> a, b;
    REP(i, M) {
        int ai, bi;
        cin >> ai >> bi;
        a.push_back(ai - 1);
        b.push_back(bi - 1);
     }

    int count = 0;
    REP(i, M)
        if (checkGraph(a, b, i))
            count++;

    cout << count << endl;
    
    return 0;
}
