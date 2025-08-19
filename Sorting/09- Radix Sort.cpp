// In the name of God

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class RadixSort {
private:
    void countingSort(vector<int>& arr, int exp) {
        int n = arr.size();
        vector<int> output(n), count(10, 0);
        
        // Count occurrences of each digit
        for (int i = 0; i < n; i++)
            count[(arr[i] / exp) % 10]++;
        
        // Convert to cumulative count
        for (int i = 1; i < 10; i++)
            count[i] += count[i - 1];
        
        // Build output array (reverse order for stability)
        for (int i = n - 1; i >= 0; i--) {
            int digit = (arr[i] / exp) % 10;
            output[--count[digit]] = arr[i];
        }
        
        arr = output;
    }

public:
    void sort(vector<int>& arr) {
        if (arr.empty()) return;
        
        int maxNum = *max_element(arr.begin(), arr.end());
        
        // Sort by each digit position
        for (int exp = 1; maxNum / exp > 0; exp *= 10)
            countingSort(arr, exp);
    }
    
    void print(const vector<int>& arr) {
        cout << "[";
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i];
            if (i < arr.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
};

int main() {
    RadixSort rs;
    vector<int> arr = {170, 45, 75, 90, 2, 802, 24, 66};
    
    cout << "Before: ";
    rs.print(arr);
    
    rs.sort(arr);
    
    cout << "After:  ";
    rs.print(arr);
    
    return 0;
}
