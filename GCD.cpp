//IN THE NAME OF ALLAH
#include<iostream>
#include<map>
#include<cmath>
#include<algorithm>
#include<iomanip>
#include<string>
#define ll long long
#define ui unsigned int
#define db double
#define fl float
using namespace std;

int gcd(int a, int b){
	if (b == 0) return a;
	return gcd(b, a%b);
}

int main(){
	cout << gcd(49, 10) << endl;
	return 0;
}
