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
#define REP(i,n) for (int i = 0; i < (b); ++i)
#define LOG(x) cerr << #x << " = " << (x) << endl

using namespace std;

int main() {
    int A, B, C, D, E, F;
    cin >> A >> B >> C >> D >> E >>  F;

    int maxSugar = 0;
    int maxWater = 0;
    double maxRate = -1.0;

    for (int waterA = 0; waterA <= F; waterA += 100 * A) {
        for (int waterB = 0, water = waterA; water <= F; waterB += 100 * B, water = waterA + waterB) {
            for (int sugarC = 0; water + sugarC <= F; sugarC += C) {
                for (int sugarD = 0, sugar = sugarC; water + sugar <= F; sugarD += D, sugar = sugarC + sugarD) {
                    if (sugar > E * (water / 100))
                        continue;

                    if (sugar + water == 0)
                        continue;
                    
                    double ra = 1.0 * sugar * 100 / (sugar + water);
                    if (ra > maxRate) {
                        maxSugar = sugar;
                        maxWater = water;
                        maxRate = ra;
                    }
                }
            }
        }
    }
    
    cout << maxSugar + maxWater << " " << maxSugar << endl;
    return 0;
}
