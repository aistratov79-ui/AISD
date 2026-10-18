#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

vector<int>& CountSort(vector<int>& A) {
    int k = *max_element(A.begin(), A.end());
    vector<int> counter(k + 1, 0);
    for (int x : A) {
        counter[x] += 1;
    }
    A.clear();
    for (int num = 0; num < k + 1; num++) {
        for (int c = 0; c < counter[num]; c++) {
            A.push_back(num);
        }
    }
    return A;
}

int main() {
    string input;
    getline(cin, input);
    
    vector<int> arr;
    istringstream iss(input);
    int val;
    while (iss >> val) {
        arr.push_back(val);
    }
    
    CountSort(arr);
    
    for (size_t i = 0; i < arr.size(); i++) {
        if (i > 0) cout << " ";
        cout << arr[i];
    }
    cout << endl;
    
    return 0;
}