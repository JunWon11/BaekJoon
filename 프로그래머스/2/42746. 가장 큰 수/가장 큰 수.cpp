#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(string a, string b){
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> nums;
    for(int i = 0; i < numbers.size(); i++){
        nums.push_back(to_string(numbers[i]));
    }
    // 수정된 comp 함수로 정렬
    sort(nums.begin(), nums.end(), comp);
    
    // 모든 숫자가 0일 경우 0을 리턴하도록 처리
    if(nums[0] == "0") return "0";
    
    for(int i = 0; i < nums.size(); i++)
        answer += nums[i];
    
    return answer;
}
