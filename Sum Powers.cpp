//IN THE NAME OF ALLAH
#include<iostream>
using namespace std;

//a^1+a^3+a^3+...+a^n
ll sumPowers(int a,int n){
	if (n == 0) return 0;

	if (n % 2 == 1) a*(a*sumPowers(a, n - 1));

	ll half = sumPowers(a, n / 2);
	return half*(1 + half - sumPowers(a, n / 2 - 1));
}

int main(){
	cout << sumPowers(5,6)<<endl;
	return 0;
}
