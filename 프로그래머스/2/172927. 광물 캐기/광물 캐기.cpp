#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(vector<int> a, vector<int> b){
    if(a[0] == b[0]){
        if(a[1] == b[1]){
            return a[2] > b[2];
        }
        return a[1] > b[1];
    }
    return a[0] > b[0];
}

int solution(vector<int> picks, vector<string> minerals) {
    int answer = 0;
    // 5개씩 끊어서 다이아, 철, 돌 순으로 개수 저장하는 벡터
    int sum_picks = picks[0] + picks[1] + picks[2];
    vector<vector<int>> v;
    vector<int> amount = {0,0,0};
    for(int i=0;i<minerals.size();i++){
        if(minerals[i] == "diamond") amount[0]++;
        else if(minerals[i] == "iron") amount[1]++;
        else if(minerals[i] == "stone")amount[2]++;
        if((i%5 == 4 or i == minerals.size()-1) and v.size() < sum_picks){
            // 광물 묶음이 곡괭이 수보다 작아야 push하는 것
            // 만약에 크면 뒤에 있는 광물부터 캐는 경우가 생김
            v.push_back(amount);
            amount = {0,0,0};
        }
    }
    
    sort(v.begin(), v.end(), comp);
    
    for(int i=0;i<v.size();i++){
        if(picks[0] > 0){ // 다이아 곡괭이 O
            picks[0]--;
            answer+=(v[i][0] + v[i][1] + v[i][2]);
        }
        else{
            if(picks[1] > 0){ // 다이아 곡괭이 X, 철 곡괭이 O
                picks[1]--;
                answer += (v[i][0]*5 + v[i][1] + v[i][2]);
            }
            else{
                if(picks[2] > 0){
                    picks[2]--;
                    answer += (v[i][0]*25 + v[i][1]*5 + v[i][2]);
                }
            }
        }
    }
    
    return answer;
}