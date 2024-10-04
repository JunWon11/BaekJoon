#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());
    while(pq.top() < K){
        if(pq.size() <= 1){
            answer = -1;
            break;
        }
        int min1 = pq.top();
        pq.pop();
        int min2 = pq.top();
        pq.pop();
        pq.push(min1+min2*2);
        answer++;
    }
    return answer;
}