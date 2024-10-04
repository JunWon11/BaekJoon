#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;
// records를 정렬 => substr(6,4)가 첫번째 기준, 두번째 기준은 substr(0,5)

bool comp(string a, string b){
    string a_number = a.substr(6,4);
    string b_number = b.substr(6,4);
    string a_time = a.substr(0,5);
    string b_time = b.substr(0,5);
    if(a_number == b_number) return a_time < b_time;
    return a_number < b_number;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    sort(records.begin(), records.end(), comp);
    
    map<string, int> time_sum;
    string now_num = "";
    
    vector<int> in_time;
    
    vector<string> numbers;
    
    for(int i=0;i<records.size();i++){
        if(now_num != records[i].substr(6,4)){ // 번호가 바뀌었으면 
            if(!in_time.empty()){ // 바뀌었는데 in이 남아있다? => 23:59 출차
                int in = in_time.back();
                in_time.pop_back();
                time_sum[now_num] += ((23*60+59) - in);
            }
            time_sum[records[i].substr(6,4)] = 0;
            now_num = records[i].substr(6,4);
            numbers.push_back(now_num);
        }
        if(records[i].substr(11) == "IN"){ // 들어온거면 
            in_time.push_back(stoi(records[i].substr(0,2))*60 + stoi(records[i].substr(3,2)));
        }
        else{
            int in = in_time.back();
            in_time.pop_back();
            int out = stoi(records[i].substr(0,2))*60 + stoi(records[i].substr(3,2));
            time_sum[now_num] += (out - in);
        }
    }
    
    if(!in_time.empty()){ // in이 남아있다? => 23:59 출차
        int in = in_time.back();
        in_time.pop_back();
        time_sum[now_num] += ((23*60+59) - in);
    }
    
    for(int i=0;i<numbers.size();i++){
        int t = time_sum[numbers[i]]; // 누적 시간 저장
        int sum = fees[1];
        if(t > fees[0])
            sum += ceil((double)(t - fees[0])/fees[2]) * fees[3];
        answer.push_back(sum);
    }
    
    return answer;
}