#include <iostream>
#include <vector>

using namespace std;

int BubbleSort(vector<int>& A) {
    int n = A.size();
    int cnt = 0;
    for (int iter = 0; iter < n - 1; iter++) {
        bool swapped = false;
        for (int i = 0; i < n - iter - 1; i++) {
            if (A[i] > A[i + 1]) {
                swap(A[i], A[i + 1]);
                swapped = true;
                cnt += 1;
            }
        }
        if (!swapped) {
            break;
        }
    }
    return cnt;
}

int main() {
    int N;
    cin >> N;
    
    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    
    cout << BubbleSort(arr) << endl;
    
    return 0;
}