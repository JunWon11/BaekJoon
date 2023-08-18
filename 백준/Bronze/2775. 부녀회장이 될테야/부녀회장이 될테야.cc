#include <iostream>
using namespace std;
int main()
{
	int t, k, n;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int sum[15][15] = { 0 };
		cin >> k >> n;
		for (int j = 1; j <= n; j++)
			sum[0][j] = j;
		for (int a = 1; a <= k; a++)
		{
			for (int b = 1; b <= n; b++)
			{
				for (int c = 1; c <= b; c++)
					sum[a][b] += sum[a-1][c];
			}
		}
		cout << sum[k][n] << "\n";
	}
	return 0;
}