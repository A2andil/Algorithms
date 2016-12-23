//IN THE NAME OF ALLAH
#include<iostream>
using namespace std;

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int lcm(int a, int b) {
	return a / gcd(a, b) * b;
}

int main() {
	cout << lcm(49, 10) << endl;
	return 0;
}
