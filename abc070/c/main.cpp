#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdint>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int64_t> list;
    for (int i = 0; i < N; i++) {
        int64_t t;
        cin >> t;
        list.push_back(t);
    }

    int64_t answer = 1;
    
    for (auto t : list) {
        int64_t m = max(answer, t);
        int64_t n = min(answer, t);
        while (n != 0) {
            int64_t tmp = n;
            n = m % n;
            m = tmp;
        }
        answer = answer / m * t;
    }

    cout << answer << endl;
    
    return 0;
}
