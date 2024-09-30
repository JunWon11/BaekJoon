#include <iostream>

using namespace std;

int main(void) {
	int n, d, k, c;
	int result = 0;
	int sushi[30001] = { 0, };
	cin >> n >> d >> k >> c;
	for (int i = 0; i < n; i++) {
		cin >> sushi[i];
	}
	for (int i = 0; i < n; i++) { // 첫 번째 부터 k개 탐색
		int visited[3001] = { 0, };
		int cnt = 0;
		for (int j = 0; j < k; j++) {
			if (visited[sushi[(i+j)%n]] == 0) {
				visited[sushi[(i + j) % n]] = 1; // 방문한 초밥 번호의 index에 1을 저장
				cnt++;
			}
		}
		if (visited[c] == 0)cnt++;
		result = cnt > result ? cnt : result;
	}
	cout << result;
	return (0);
}