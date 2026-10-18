#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

void InsertionSort(vector<int>& A) {
    int n = A.size();
    for (int i = 1; i < n; i++) {
        int key = A[i];
        int j = i;
        while (j >= 1 && A[j - 1] > key) {
            A[j] = A[j - 1];
            j -= 1;
        }
        A[j] = key;
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
    
    InsertionSort(numbers);
    
    for (size_t i = 0; i < numbers.size(); i++) {
        if (i > 0) cout << " ";
        cout << numbers[i];
    }
    cout << endl;
    
    return 0;
}