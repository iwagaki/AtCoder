#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double x, a, b;
    cin >> x >> a >> b;
    if (abs(x - a) < abs(x - b)) {
        cout << "A" << endl;
    } else {
        cout << "B" << endl;
    }

    return 0;
}
