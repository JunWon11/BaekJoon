#include <iostream>

int main(void) {
	int k, a[45] = { 0, }, b[45] = { 0 , };
	std::cin >> k;
	a[0] = 1;
	for (int i = 1; i <= k; i++) {
		a[i] = b[i - 1];
		b[i] = a[i - 1] + b[i - 1];
	}
	std::cout << a[k] << " " << b[k];
	return (0);
}