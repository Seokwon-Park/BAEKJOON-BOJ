#include <bits/stdc++.h>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
       
    int remove = 0;
    int times = 0;
    
    string result = s;
    
    while(result != "1")
    {        
        int cnt = count(result.begin(), result.end(), '1');
        remove += result.length() - cnt;

        result = bitset<32>(cnt).to_string();
        result = result.substr(result.find('1'));
        cout << result << endl;
        times++;
    }
   
    answer.push_back(times);
    answer.push_back(remove);
    return answer;
}
