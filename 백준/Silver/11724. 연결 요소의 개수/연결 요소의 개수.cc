#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector<int> graph[1001];
int visited[1001] = { 0, };

void bfs(int start) {
	queue<int> q;
	q.push(start); 
	visited[start] = 1;
	while (!q.empty()) {
		int k = q.front();
		q.pop();
		for (int i = 0; i < graph[k].size(); i++) {
			if (!visited[graph[k][i]]) {
				visited[graph[k][i]] = 1;
				q.push(graph[k][i]);
			}
		}
	}
}

int main(void) {
	cin >> n >> m;
	int a, b, cnt = 0;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			bfs(i);
			cnt++;
		}
	}
	cout << cnt << endl;
	return (0);
}