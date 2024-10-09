#include <iostream>

using namespace std;

int main() {
	int coin[] = { 500, 100, 50, 10, 5, 1 };
	int n, cnt = 0;
	cin >> n;
	int k = 1000 - n;
	for (int i = 0; i < 6; i++) {
		if (k / coin[i]) {
			cnt += k / coin[i];
			k %= coin[i];
		}
	}
	cout << cnt;
	return 0;
}