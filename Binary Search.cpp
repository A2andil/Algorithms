#include<iostream>

using namespace std;

int binary_search(int[] array, int key, int left, int right) 
{
      if (left > right)
            return -1;
      int middle = (left + right) / 2;
      
      if (array[middle] == key)
            return middle;
      else if (array[middle] > key)
            return binarySearch(array, key, left, middle - 1);
      else
            return binarySearch(array, key, middle + 1, right);           
}

int main()
{
   int arr[10] = {1,3,5,7,9,11,13,15,17,19};
   int index = binary_search(arr,15,0,9);
   cout<<index<<endl;
   return 0;
}
