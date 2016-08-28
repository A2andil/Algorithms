//IN THE NAME OF ALLAH
#include<iostream>
using namespace std;

ll pow(int b, int p){
	cout << i << endl;
	if (p == 0) return 1;
	ll sq = pow(b, p / 2);
	sq = sq*sq;

	if (p % 2 == 1) sq *= b;
	return sq;
}

int main(){
	cout << pow(2, 32) << endl;
	return 0;
}
