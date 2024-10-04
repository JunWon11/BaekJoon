#include <vector>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0, cnt = 0;
    int idx[200001] = {0,};
    for(int i=0;i<nums.size();i++){
        idx[nums[i]]++;
    }
    
    for(int i=0;i<200001;i++){
        if(idx[i])cnt++;
    }
    
    answer = (cnt > nums.size()/2) ? nums.size()/2 : cnt;
    
    return answer;
}