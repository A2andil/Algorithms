//In The Name of Allah
#include <iostream>

using namespace std;

long long fib(int n){
    if(n==0||n==1)
        return n;
    return fib(n-1)+fib(n-2);
}
int main(){
    int n; cin>>n;
    cout<<fib(n)<<endl;
    return 0;
}
