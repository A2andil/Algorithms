//In The Name of Allah
#include <iostream>
#include <algorithm>
using namespace std;

const int sz = 10005;
int mar[sz];

int search(int k, int n) {
	int lw = 0, hi = n - 1, md, rs = -1;
	while (lw <= hi) {
		md = (lw + hi) / 2;
		if (k == mar[md]) rs = md, hi = md - 1;
		else if (k < mar[md]) hi = md - 1;
		else lw = md + 1;
	}
	return rs;
}

int main(){
	//put your code here

	return 0;
}
