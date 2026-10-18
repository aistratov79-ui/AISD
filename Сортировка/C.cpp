#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

void BubbleSort(vector<int>& A) {
    int n = A.size();
    for (int iter = 0; iter < n - 1; iter++) {
        bool swapped = false;
        for (int i = 0; i < n - iter - 1; i++) {
            if (A[i] < A[i + 1]) {
                swap(A[i], A[i + 1]);
                swapped = true;
            }
        }
        if (swapped == false) {
            break;
        }
    }
}

int main() {
    string input;
    getline(cin, input);
    
    vector<int> num;
    istringstream iss(input);
    int val;
    while (iss >> val) {
        num.push_back(val);
    }
    
    BubbleSort(num);
    
    for (size_t i = 0; i < num.size(); i++) {
        if (i > 0) cout << " ";
        cout << num[i];
    }
    cout << endl;
    
    return 0;
}