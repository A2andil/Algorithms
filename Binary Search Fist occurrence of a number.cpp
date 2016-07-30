//In The Name of Allah
#include <iostream>
#include<algorithm>
using namespace std;

int mar[10005];

int search(int k,int n){
    int low=0,hi=n-1,mid,res=-1;
    while(low<=hi){
        mid = (low+hi)/2;
        if(k==mar[mid]) res=mid,hi=mid-1;
        else if(k<mar[mid]) hi=mid-1;
        else if(k>mar[mid]) low=mid+1;
    }
    return res;
}

int main(){
    return 0;
}
