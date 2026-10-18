#include <iostream>
#include <vector>
using namespace std;

int BubbleSort(vector<int>& arr) {
    int n = arr.size();
    int counter = 0;
    for (int iter = 0; iter < n - 1; iter++) {
        bool swapped = false;
        for (int i = 0; i < n - iter - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                counter++;
                swapped = true;
            }
        }
        if (!swapped) break;
    }
    return counter;
}

int main() {
    int n;
    cin >> n;
    
    vector<int> numbers(n);
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }
    
    int swapCount = BubbleSort(numbers);
    cout << swapCount;
    
    return 0;
}