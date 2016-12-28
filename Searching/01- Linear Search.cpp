//In The Name Of Allah
#include <iostream>
using namespace std;

void search(int arr[], int key, int size) {
    for(int i = 0; i < size; i++)
        if(key == arr[i]) {
            cout << key << " present at index : " <<  i<< endl;
            return;
        }
    cout << "not found" << endl;
}

int main() {
    int arr[10] = {1, 2, 5, 3, 7, 8, 9, 4, 2, 1}, key;
    cout << "Enter key : "; cin >> key;
    search(arr, key, 10);
    return 0;
}
