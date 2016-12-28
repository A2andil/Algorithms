//In The Name Of Allah
#include<iostream>
using namespace std;

int binary_search(int[] arr, int key, int left, int right)  {
      if (left > right) return -1;
      int mid = (left + right) / 2;
      if (arr[mid] == key) return mid;
      else if (arr[mid] > key)
            return binarySearch(arr, key, left, mid - 1);
      else
            return binarySearch(arr, key, mid + 1, right);
}

int main() {
   int arr[10] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19 };
   int index = binary_search(arr, 15, 0, 9);
   cout << index << endl;
   return 0;
}
