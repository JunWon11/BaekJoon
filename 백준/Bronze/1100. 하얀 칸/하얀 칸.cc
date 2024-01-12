#include <iostream>
using namespace std;

int main() {
	char str[8][9];
	int cnt = 0;
	for (int i = 0; i < 8; i++){
		cin >> str[i];
		for (int j = 0; j < 8; j++)
			if ((i + j) % 2 == 0 && str[i][j] == 'F')
				cnt++;
	}
	cout << cnt;
}