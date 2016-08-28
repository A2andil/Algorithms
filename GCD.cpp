//IN THE NAME OF ALLAH
#include<iostream>
using namespace std;

int gcd(int a, int b){
	if (b == 0) return a;
	return gcd(b, a%b);
}

int main(){
	cout << gcd(49, 10) << endl;
	return 0;
}
