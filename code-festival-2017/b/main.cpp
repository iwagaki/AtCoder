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
    int N, M, K;
    cin >> N >> M >> K;

    bool isFound = false;
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= M; j++) {
            if (i * M + (- i + (N - i)) * j == K) {
                isFound = true;
                break;
            }
        }
    }

    cout << (isFound ? "Yes" : "No") << endl;

    return 0;
}
