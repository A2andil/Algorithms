//In The Name of Allah
#include <iostream>

bool IS_Prime(int n){
    if(n==1||n==2||n==3) return true;
    
    for(int i=2;i*i<=n;i++)
        if(n%i==0) return false;
    return true;
}

int main(){
    int n; std::cin>>n;
    std::cout << IS_Prime(n);
 return 0;
}
