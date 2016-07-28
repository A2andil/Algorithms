#include <iostream>

using namespace std;

void swap(int &a,int &b){
    a=a+b,b=a-b,a=a-b;
}

void sort(int *index,int size){
    int i,j,min,s;
    for(i=0;i<size-1;++i){
        min = *(index+i);
        for(j=i+1;j<size;++j)
            if(min>*(index+j))
                min = *(index+j),s = j;

        swap(*(index+i),*(index+s));
    }
}

int main()
{
    int n=0; cin>>n;
    int arr[n];
    for(int i=0;i<n;++i) cin>>arr[i];

    sort(arr,n);

    for(int i=0;i<n;++i) cout<<arr[i]<<' ';
    return 0;
}
