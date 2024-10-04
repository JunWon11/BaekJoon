#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end());
    for(int i=0;i<=citations.size();i++){
        int cnt = 0;
        for(int j=0;j<citations.size();j++){
            if(citations[j] >= i)
                cnt++;
        }
        if(cnt >= i and citations.size()-cnt <= i)answer = i;
    }
    return answer;
}