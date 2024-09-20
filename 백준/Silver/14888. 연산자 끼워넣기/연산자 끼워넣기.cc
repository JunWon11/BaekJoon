#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int n;
vector<int> v;
int op[4];
int max_num = INT_MIN;
int min_num = INT_MAX;

void recur(int cur, int total)
{
    if (cur == n)
    {
        max_num = max(max_num, total);
        min_num = min(min_num, total);
        return;
    }

    for (int i = 0; i < 4; i++){
        if (!op[i]) continue;

        op[i]--;
        if (i == 0){
            recur(cur + 1, total + v[cur]);
        }
        else if (i == 1){
            recur(cur + 1, total - v[cur]);
        }
        else if (i == 2){
            recur(cur + 1, total * v[cur]);
        }
        else if (i == 3){
            recur(cur + 1, total / v[cur]);
        }
        op[i]++;
    }
}

int main()
{
    cin >> n;

    int a;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        v.push_back(a);
    }

    for (int i = 0; i < 4; i++) cin >> op[i];

    recur(1, v[0]);
    cout << max_num << '\n' << min_num;

    return 0;
}