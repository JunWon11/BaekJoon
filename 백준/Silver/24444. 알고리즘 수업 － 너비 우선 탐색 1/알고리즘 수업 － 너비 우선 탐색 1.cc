#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int visited[100001];
vector<int> a[100001];
int seq[100001] = {0,};

void bfs(int start){
    int cnt = 1;
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        seq[x] = cnt++;
        visited[x] = true;
        for(int i=0;i<a[x].size();i++){
            int k = a[x][i];
            if(!visited[k]){
                visited[k] = true;
                q.push(k);
            }
        }
    }
}

int main(){
    int N, M, R;
    int x, y;
    cin >> N >> M >> R;
    for(int i=0;i<M;i++){
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    for(int i=1;i<=N;i++){
        sort(a[i].begin(), a[i].end());
    }
    bfs(R);
    for(int i=1;i<=N;i++)
        cout << seq[i] << "\n";
    return 0;
}