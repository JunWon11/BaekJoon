#include <iostream>
using namespace std;
int main()
{
	int n, cnt = 0, min = 10000;
	cin >> n;
	for (int i = 0;i<1667;i++)
	{
		for (int j = 0; j<1001; j++)
		{
			if (n == 3 * i + 5 * j)
			{
				cnt = i + j;
				min = (cnt < min) ? cnt : min;
			}
		}
	}
	if (min == 10000)
		min = -1;
	cout << min;
	return 0;
}