//IN THE NAME OF ALLAH
#include<iostream>
#define LL long long
using namespace std;

LL Power(LL N, int M){
	if (!M) return 1;
	LL rs = Power(N, M / 2);
	return M % 2 ? rs*rs*N : rs*rs;
}

int main(){
	cout << Power(2, 32) << endl;
	return 0;
}
