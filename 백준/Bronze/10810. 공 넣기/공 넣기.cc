#include <iostream>
using namespace std;

int main() {
	int n, m, a, b, c;
	int ball[101] = { 0, };
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		for (int j = a-1; j <= b-1; j++)
			ball[j] = c;
	}
	for (int i = 0; i < n; i++)
		cout << ball[i] << " ";
	return 0;
}