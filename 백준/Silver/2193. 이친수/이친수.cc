#include <iostream>

int main(void) {
	long long int n,dp_zero[91], dp_one[91];
	std::cin >> n;
	dp_zero[1] = 0;
	dp_zero[2] = 1;
	dp_one[1] = 1;
	dp_one[2] = 0;
	for (int i = 2; i <= n; i++) {
		dp_zero[i] = dp_zero[i - 1] + dp_one[i - 1];
		dp_one[i] = dp_zero[i - 1];
	}
	std::cout << dp_one[n] + dp_zero[n];
	return (0);
}