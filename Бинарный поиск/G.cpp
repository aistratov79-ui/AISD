#include <iostream>
#include <vector>

using namespace std;

int n, k;
vector<int> a;

bool good(int x) {
    if (x == 0) {
        return true;
    }
    int cnt = 0;
    for (int ln : a) {
        cnt += ln / x;
    }
    return cnt >= k;
}

int main() {
    cin >> n >> k;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int l = 0, r = 10000000 + 1;
    for (int i = 0; i < 100; i++) {
        int m = (r + l) / 2;
        if (good(m)) {
            l = m;
        } else {
            r = m;
        }
    }
    cout << l << endl;

    return 0;
}