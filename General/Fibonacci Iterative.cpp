//In The Name of Allah
#include <iostream>
#define ll long long
using namespace std;

ll Fibonacci(int n) {
	if (!n || n == 1) return n;
	ll a = 0, b = 1, rs;
	for (int i = 2; i <= n; i++){
		rs = a + b, a = b, b = rs;
	}
	return rs;
}
int main(){
	int n; cin >> n;
	cout << Fibonacci(n) << endl;
	return 0;
}
