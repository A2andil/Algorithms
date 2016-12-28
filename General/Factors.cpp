//In The Name of Allah
//O(Sqrt(n)

#include <iostream>
#include<vector>

using namespace std;

int main(){
    vector<int> div;
    int n,i; cin>>n;

    for(i=1;i*i<n;++i)
        if(n%i==0)
            div.push_back(i),div.push_back(n/i);

        if(i*i==n)
            div.push_back(i);

        for(i=0;i<div.size();++i)
            cout<<div[i]<<endl;

    return 0;
}
