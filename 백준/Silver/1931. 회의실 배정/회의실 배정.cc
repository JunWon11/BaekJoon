#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second)
		return a.first < b.first;
	return a.second < b.second;
}

int main() {
	int n;
	cin >> n; // 회의의 수를 입력받음

	int start = 0, end = 0;
	vector<pair<int, int>> time;
	for (int i = 0; i < n; i++) { // 회의의 시작 시간, 종료 시간을 입력받음
		cin >> start >> end;
		time.push_back(make_pair(start, end));
	}

	sort(time.begin(), time.end(), comp); // 종료 시간이 빠른 순서대로 정렬

	int tmp = 0; // 이전 회의의 종료 시간을 저장할 변수
	int cnt = 0; // 회의의 수를 count할 변수
	for (int i = 0; i < n; i++) {
		if (time[i].first >= tmp) { // 이전 회의의 종료 시간보다 현재 회의의 시작 시간이 클 경우
			cnt++;
			tmp = time[i].second;
		}
	}

	cout << cnt;

	return 0;
}