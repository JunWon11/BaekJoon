#include <iostream>
#include <algorithm>
int main(void) {
	int n, dp[5001];
	std::cin >> n;
	for (int i = 0; i <= n; i++)
		dp[i] = 5001;
	dp[3] = 1;
	dp[5] = 1;
	for (int i = 6; i <= n; i++) {
		dp[i] = std::min(dp[i - 3] + 1, dp[i - 5] + 1);
	}
	if (dp[n] >= 5001)std::cout << -1;
	else std::cout << dp[n];

	return (0);
}