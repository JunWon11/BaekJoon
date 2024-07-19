#include <iostream>

using namespace std;

int room[51][51];

bool around(int i, int j, int N, int M) { // 주변에 청소되지 않은 칸이 있는 경우
    if (i > 0 && room[i-1][j] == 0) return true;
    if (i < N-1 && room[i+1][j] == 0) return true;
    if (j > 0 && room[i][j-1] == 0) return true;
    if (j < M-1 && room[i][j+1] == 0) return true;
    return false;
}

int main() {
    int N, M; // N이 세로, M이 가로
    int flag = 1;
    int cnt = 0;
    cin >> N >> M;
    int r, c, d;
    cin >> r >> c >> d;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) {
            cin >> room[i][j];
        }
    
    while (flag) {
        if (room[r][c] == 0) { // 조건 1번 : 현재 칸이 청소 되어 있지 않으면 청소
            room[r][c] = 2; // 청소 완료를 2로 표시 (1은 벽으로 가정)
            cnt++;
        }
        if (around(r, c, N, M)) {
            d = (d + 3) % 4; // 왼쪽으로 회전
            switch (d) {
                case 0:
                    if (r > 0 && room[r-1][c] == 0) r--;
                    break;
                case 1:
                    if (c < M-1 && room[r][c+1] == 0) c++;
                    break;
                case 2:
                    if (r < N-1 && room[r+1][c] == 0) r++;
                    break;
                case 3:
                    if (c > 0 && room[r][c-1] == 0) c--;
                    break;
                default:
                    break;
            }
        } else {
            switch (d) {
                case 0:
                    if (r < N-1 && room[r+1][c] != 1) r++;
                    else flag = 0;
                    break;
                case 1:
                    if (c > 0 && room[r][c-1] != 1) c--;
                    else flag = 0;
                    break;
                case 2:
                    if (r > 0 && room[r-1][c] != 1) r--;
                    else flag = 0;
                    break;
                case 3:
                    if (c < M-1 && room[r][c+1] != 1) c++;
                    else flag = 0;
                    break;
                default:
                    break;
            }
        }
    }
    cout << cnt;
    return 0;
}
