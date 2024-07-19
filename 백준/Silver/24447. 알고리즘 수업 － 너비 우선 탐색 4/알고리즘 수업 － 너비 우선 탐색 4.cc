#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

bool visited[100001];
vector<int> a[100001];
long long depth[100001];
long long seq[100001] = {0, };

void bfs(int start){
    int cnt = 0;
    queue<int> q;
    q.push(start);
    visited[start] = true;
    depth[start] = 0;
    seq[start] = cnt++;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        int headDepth = depth[x];
        seq[x] = cnt++;
        for(int i=0;i<a[x].size();i++){
            int y = a[x][i];
            if(!visited[y]){
                q.push(y);
                visited[y] = true;
                depth[y] = headDepth+1;
            }
        }
    }
}

int main(){
    int N, M, R;
    int x, y;
    long long int sum = 0;
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
    for(int i=1;i<=N;i++){
        sum += seq[i]*depth[i];
    }
    cout << sum;
    return 0;
}