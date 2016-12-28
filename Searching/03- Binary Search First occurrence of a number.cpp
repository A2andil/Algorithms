//In The Name of Allah
#include <iostream>
#include<algorithm>
using namespace std;

const int sz = 10005;
int mar[sz];

int search(int k, int n) {
    int lw = 0, hi = n - 1, mid, rs = -1;
    while(lw <= hi) {
        mid = (low + hi) / 2;
        if(k == mar[mid]) rs = mid, hi = mid - 1;
        else if(k < mar[mid]) hi = mid - 1;
        else lw = mid + 1;
    }
    return rs;
}

int main(){
    //put your code here

    return 0;
}
