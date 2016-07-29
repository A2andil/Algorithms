//In The Name of Allah
#include <iostream>

using namespace std;

long long fib(int n){
    if(n==0||n==1)
        return n;
    int a=0,b=1,res;
   for(int i=2;i<=n;i++){
       res = a+b,a=b,b=res;
   }
   return res;
}
int main(){
    int n; cin>>n;
    cout<<fib(n)<<endl;
    return 0;
}
