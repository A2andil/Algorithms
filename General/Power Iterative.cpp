//In The Name of Allah
#include <iostream>

using namespace std;

long long power(int n,int ms){
    if(ms==0)
        return 1;
    int res =1;
    for(int i=1;i<=ms;i++)
        res *=n;
    /*
     * while(ms>0){
     * res *=n;
     * ms--
     * }
     * */
    return res;
}
int main(){
    int n,ms; cin>>n>>ms;
    cout<<power(n,ms)<<endl;
    return 0;
}
