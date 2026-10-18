#include <iostream>
#include <vector>

using namespace std;

bool can_place(vector<int>& a, int k, int dist) {
    int count = 1;
    int last_point = a[0];

    for (int point : a) {
        if (last_point + dist > point) {
            continue;
        } else {
            count += 1;
            last_point = point;
        }
    }

    return count >= k;
}

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    int l = 0;
    int r = a[N - 1] - a[0] + 1;

    while (l + 1 < r) {
        int m = (l + r) / 2;

        if (can_place(a, K, m)) {
            l = m;
        } else {
            r = m;
        }
    }

    cout << l << endl;

    return 0;
}