#include <iostream>
#include <cstdlib>
using namespace std;

int visited[201] = { 0, };
int N;
int arr[8];

int func(int n, int level, int sum, int visit[]) {
    if (level == N - 1) return sum;
    visit[n + 100]++;
    int maxSum = sum; // 가능한 최대 sum을 저장할 변수
    for (int i = 0; i < N; i++) {
        if (visit[arr[i] + 100] != visited[arr[i]+100]) { // 방문하지 않은 곳만 방문
            // 재귀 호출 결과를 maxSum과 비교
            int currentSum = func(arr[i], level + 1, sum + abs(n - arr[i]), visit);
            if (currentSum > maxSum) {
                maxSum = currentSum;
            }
        }
    }
    visit[n + 100]--; // 재귀 호출이 끝나면 방문 표시를 해제
    return maxSum; // 최대 sum 반환
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        visited[arr[i] + 100]++;
    }
    int sum = 0, max = 0;
    for (int i = 0; i < N; i++) {
        int visit[201] = { 0, }; // 새로운 방문 배열 초기화
        sum = func(arr[i], 0, 0, visit);
        max = sum > max ? sum : max;
    }
    cout << max << endl;
    return 0;
}
