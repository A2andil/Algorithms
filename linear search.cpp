#include <iostream>

using namespace std;

int main()
{
    int n,arr[10] = {1,2,3,4,5,6,7,8,9,10};
    cin>>n;
    for(int i=0;i<10;i++)
        if(n==arr[i])
        {
            cout<<"Found at :"<<i<<endl;
            break;
        }
        else if(i==9)
            cout<<"Not Found!"<<endl;

    return 0;
}
