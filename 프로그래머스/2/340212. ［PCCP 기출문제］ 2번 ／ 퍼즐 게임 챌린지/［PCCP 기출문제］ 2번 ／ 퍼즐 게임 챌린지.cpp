#include <string>
#include <vector>
#include <climits>
using namespace std;

bool possible(vector<int> diffs, vector<int> times, long long limit, int mid) {
    long long sum = 0;
    for (int i = 0; i < diffs.size(); i++) {
        if (mid >= diffs[i])
            sum += times[i];
        else
            sum += (diffs[i] - mid) * (times[i] + (i > 0 ? times[i-1] : 0)) + times[i];
    }
    return sum <= limit;
}

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int answer = INT_MAX;
    int l = 1, r = 100001;
    while(l<=r){
        int mid = (l+r)/2;
        if(possible(diffs, times, limit,mid)){
            answer = (mid < answer)?mid:answer;
            r = mid-1;
        }
        else
            l = mid+1;
    }
    return answer;
}