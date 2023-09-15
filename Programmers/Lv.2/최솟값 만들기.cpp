#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;

    sort(A.begin(), A.end());
    //sort(B.begin(), B.end(), [](int &a, int &b){ return a> b;});
    sort(B.rbegin(), B.rend());
    
    for(int i = 0 ; i< A.size(); i++)
    {
        answer += A[i] * B[i];
    }
    //std::inner_product(A.begin(), A.end(), B.begin(), 0);
    // 1벡터 시작, 1벡터 끝, 2벡터 시작위치, 초기값
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    
    cout << "Hello Cpp" << endl;

    return answer;
}
