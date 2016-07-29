//In The Name of Allah
#include <iostream>

using namespace std;

long long power(int n,int ms){
    if(ms==0)
        return 1;
    return n*power(n,ms-1);
}
int main(){
    int n,ms; cin>>n>>ms;
    cout<<power(n,ms)<<endl;
    return 0;
}
