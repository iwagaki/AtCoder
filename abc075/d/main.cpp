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

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> x, y;
    REP(i, N) {
        int xi, yi;
        cin >> xi >> yi;
        x.push_back(xi);
        y.push_back(yi);
    }

    vector<int> X = x;
    vector<int> Y = y;

    sort(ALL(X));
    sort(ALL(Y));

    int countMap[50][50];

    REP(i, X.size()) REP(j, Y.size()) {
        int count = 0;
        REP(k, N)
            if (x[k] <= X[i] && y[k] <= Y[j])
                count++;

        countMap[i][j] = count;
    }

    long long m = LLONG_MAX;

    for (size_t i = 0; i < X.size() - 1; i++) {
        for (size_t j = 0; j < Y.size() - 1; j++) {
            for (size_t k = 1; k < X.size(); k++) {
                for (size_t l = 1; l < Y.size(); l++) {
                   int count = countMap[k][l];
                    if (i > 0 && j == 0)
                        count -= countMap[i - 1][l];
                    else if (j > 0 && i == 0)
                        count -= countMap[k][j - 1];
                    else if (i > 0 && j > 0)
                        count -= countMap[i - 1][l] + countMap[k][j - 1] - countMap[i - 1][j - 1];
                    
                    if (count >= K)
                        m = min(m, 1ll * (X[k] - X[i]) * (Y[l] - Y[j]));
                }
            }
        }
    }

    cout << m << endl;
 
    return 0;
}
