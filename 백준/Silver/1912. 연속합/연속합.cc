#include <iostream>
#include <algorithm>
#include <vector>

int main(void) {
	int n, arr[100001];
	std::vector<int> dp;
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> arr[i];
	}
	dp.push_back(arr[0]);
	for (int i = 1; i < n; i++) {
		dp.push_back(arr[i] > (dp[i - 1] + arr[i]) ? arr[i] : (dp[i - 1] + arr[i]));
	}
	std::cout << *std::max_element(dp.begin(), dp.end());
	return (0);
}