//in the name of God

#include <iostream>
#define ll long long
using namespace std;

const int mx = 1002;
ll Fib[mx];
ll Fibonacci(int n) {
	Fib[0] = 0, Fib[1] = 1;
	for (int i = 2; i <= n; i++) {
		Fib[i] = Fib[i - 1] + Fib[i - 2];
	}
	return Fib[n];
}
int main() {
	int n; cin >> n;
	cout << Fibonacci(n) << endl;
	return 0;
}
