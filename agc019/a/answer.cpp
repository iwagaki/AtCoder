#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

long long q, h, s, d;
long long n;

int main() {
    cin >> q >> h >> s >> d;
    cin >> n;

    long long best1 = min(min(s, h * 2),  q * 4);
    long long best2 = min(d, best1 * 2);

    cout << (n / 2) * best2 + (n % 2) * best1 << endl;
    
    return 0;
}
