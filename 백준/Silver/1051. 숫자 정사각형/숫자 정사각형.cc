#include <iostream>
using namespace std;

int main() {
	int n, m, result = 1;
	char str[51][51];
	cin >> n >> m;
	int minL = (n > m) ? m : n;
	for (int i = 0; i < n; i++) {
		cin >> str[i];
	}
	for (int k = minL; k > 0; k--) {
		for (int i = 0; i <= n - k; i++) {
			for (int j = 0; j <= m - k; j++) {
				if (str[i][j] == str[i][j + k - 1] && str[i][j] == str[i + k - 1][j] && str[i][j] == str[i + k - 1][j + k - 1])
					result = (k * k > result) ? k * k : result;
			}
		}
	}
	cout << result;
	return 0;
}