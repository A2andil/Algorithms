//In The Name of Allah
#include <iostream>

using namespace std;

long long fact(int n){
    if(n==0||n==1)
        return 1;
    return n*fact(n-1);
}
int main(){
    int n; cin>>n;
    cout<<fact(n)<<endl;
    return 0;
}
