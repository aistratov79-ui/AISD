#include <sstream>
#include <string>

#include <iostream>
#include <vector>

using namespace std;

vector<int> SelectionSort(vector<int> arr) {
    int n = arr.size();
    
    for (int i = 0; i < n - 1; i++) {
        int ind = i;
        int key = arr[i];
        
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > key) {
                key = arr[j];
                ind = j;
            }
        }

        if (i != ind) {
            int prom = arr[ind];
            arr[ind] = arr[i];
            arr[i] = prom;
        }
    }
    
    return arr;
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
    
    vector<int> sorted = SelectionSort(numbers);
    
    for (size_t i = 0; i < sorted.size(); i++) {
        if (i > 0) {
            cout << " ";
        }
        cout << sorted[i];
    }
    cout << endl;
    
    return 0;
}