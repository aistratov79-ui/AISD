#include <sstream>
#include <string>

#include <iostream>
#include <vector>

using namespace std;

vector<int> InsertionSort(vector<int> arr) {
    int n = arr.size();
    
    for (int i = 0; i < n; i++) {
        int j = i;
        int key = arr[i];
        
        while (j >= 1 and arr[j - 1] > key) {
        	arr[j] = arr[j - 1];
        	j--;
		}
		arr[j] = key;
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
    
    vector<int> sorted = InsertionSort(numbers);
    
    for (size_t i = 0; i < sorted.size(); i++) {
        if (i > 0) {
            cout << " ";
        }
        cout << sorted[i];
    }
    cout << endl;
    
    return 0;
}