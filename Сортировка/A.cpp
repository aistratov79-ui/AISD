#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

void SelectionSort(vector<int>& A) {
    int n = A.size();
    for (int i = 0; i < n - 1; i++) {
        int key = A[i];
        int ind = i;
        for (int j = i + 1; j < n; j++) {
            if (A[j] > key) {
                key = A[j];
                ind = j;
            }
        }
        if (i != ind) {
            swap(A[i], A[ind]);
        }
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
    
    SelectionSort(numbers);
    
    for (size_t i = 0; i < numbers.size(); i++) {
        if (i > 0) cout << " ";
        cout << numbers[i];
    }
    cout << endl;
    
    return 0;
}