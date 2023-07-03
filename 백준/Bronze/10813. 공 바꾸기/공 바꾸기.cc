#include <iostream>
using namespace std;

int main() {
	int n, m, a, b, temp, ball[101];
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		ball[i] = i + 1;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		temp = ball[a - 1];
		ball[a - 1] = ball[b - 1];
		ball[b - 1] = temp;
	}
	for (int i = 0; i < n; i++)
		cout << ball[i] << " ";
	return 0;
}