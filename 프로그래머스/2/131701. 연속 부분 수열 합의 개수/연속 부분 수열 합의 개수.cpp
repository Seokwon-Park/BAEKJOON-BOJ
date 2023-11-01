#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    set<int> s;
    
    int n = elements.size();
    int len =1;
    for(int i = 0; i< n; i++)
    {
        int sum = 0;
        for(int j =0; j<n; j++)
        {
            int idx = (i+j) %n;
            sum += elements[idx];
            s.insert(sum);            
        }
    }
    
    //for(auto i = s.begin(); i!= s.end(); i++)
    //{
    //    cout << *i;
    //}
    answer = s.size();
    return answer;
}