#include <sstream>
#include <string>

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void countingSort(vector<int>& arr) {
    if (arr.empty()) return;
    
    int max_val = *max_element(arr.begin(), arr.end());
    int min_val = *min_element(arr.begin(), arr.end());
    int range = max_val - min_val + 1;
    
    vector<int> count(range, 0);
    vector<int> output(arr.size());
    
    for (int num : arr) {
        count[num - min_val]++;
    }
    
    for (int i = 1; i < range; i++) {
        count[i] += count[i - 1];
    }
    
    for (int i = arr.size() - 1; i >= 0; i--) {
        output[count[arr[i] - min_val] - 1] = arr[i];
        count[arr[i] - min_val]--;
    }

    arr = output;
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
    
    countingSort(numbers);
    vector<int> sorted = numbers;
    
    for (size_t i = 0; i < sorted.size(); i++) {
        if (i > 0) {
            cout << " ";
        }
        cout << sorted[i];
    }
    cout << endl;
    
    return 0;
}