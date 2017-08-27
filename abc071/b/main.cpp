#include <iostream>

using namespace std;

int main() {
    string s;
    cin >> s;

    int check[26] = {0,};

    for (int i = 0; i < s.size(); i++) {
        check[s[i] - 'a'] = 1;
    }

    for (int i = 0; i < 26; i++) {
        if (check[i] == 0) {
            cout << static_cast<char>('a' + i) << endl;
            return 0;
        }
    }
    cout << "None" << endl;
    
    return 0;
}
