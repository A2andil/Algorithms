//In The Name of Allah
#include <iostream>

using namespace std;

long long fact(int n){
    long long res=1;
    for(int i=2;i<=n;i++)
        res*=i;
    return res;
}
int main(){
    int n; cin>>n;
    cout<<fact(n)<<endl;
    return 0;
}
