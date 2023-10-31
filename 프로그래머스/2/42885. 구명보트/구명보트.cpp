#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    sort(people.begin(), people.end());
    int left = 0;
    int right = people.size()-1;
    while(left <= right) 
    {
        if(people[right] + people[left] > limit)
        {
            right--;
            answer++;
        }
        else
        {
            left++;
            right--;
            answer++;
        }
    }
    
    return answer;
}