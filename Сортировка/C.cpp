#include <sstream>
#include <string>

#include <iostream>
#include <vector>

using namespace std;

void BubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int iter = 0; iter < n - 1; iter++) {
        bool swapped = false;
        for (int i = 0; i < n - iter - 1; i++) {
            if (arr[i] < arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

int main() {
    string input;
    getline(cin, input);
    
    vector<int> numbers;
    istringstream iss(input);
    int num;
    
    while (iss >> num) {
        numbers.push_back(num);
    }
    
    vector<int> sorted = numbers;
    BubbleSort(sorted);
    
    for (size_t i = 0; i < sorted.size(); i++) {
        if (i > 0) {
            cout << " ";
        }
        cout << sorted[i];
    }
    cout << endl;
    
    return 0;
}