#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    string s1, s2;
    cin >> s1;
    cin >> s2;

    long long count = 1;
    int color = 3;
    for (int i = 0; i < n; i++) {
        if (s1[i] == s2[i]) {
            count *= color;
            color = 2;
        } else {
            i++;
            if (color == 3)
                count *= 6;
            if (color == 2)
                count *= 2;
            if (color == 1)
                count *= 3;
            color = 1;
        }
    }
    cout << count % 1000000007 << endl;
    
    return 0;
}
