#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    int start = 0, end = 0, sum = 0;
    answer.push_back(0);
    answer.push_back(1000001);
    while(1){
        if(start > end or end > sequence.size())break;
        while(sum<k){
            sum += sequence[end++];
        }
        if(sum == k){
            if(end - start -1 < answer[1] - answer[0]){
                answer.pop_back();
                answer.pop_back();
                answer.push_back(start);
                answer.push_back(end-1);
            }
            sum -= sequence[start++];
        }
        else if(sum > k)
            sum -= sequence[start++];
    }
    return answer;
}