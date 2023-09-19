#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    
    sort(A.begin(), A.end(), greater<int>());
    sort(B.begin(), B.end(), greater<int>());
    
    //for(auto i: A)
    //    cout << i << " ";
    
    //cout << endl;
    int ixA = 0;
    int ixB = 0;
    while(ixA != A.size() && ixB != B.size())
    {
        //cout << A[ixA] << " " << B[ixB] << endl;
        if(A[ixA] < B[ixB])
        {
            ixA++;
            ixB++;
            answer++;
        }
        else
        {
            ixA++;
        }
    }
    
    
    return answer;
}
