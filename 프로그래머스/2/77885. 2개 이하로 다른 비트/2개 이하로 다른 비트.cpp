#include <bits/stdc++.h>
using namespace std;

long long OddBit(long long n)
{
    bitset<64> xorbit(n);
    for(int i = 0; i < xorbit.size(); i++)
    {
        if(xorbit[i] == 0)
        {
            n += 1<<(i-1);
            break;
        }
    }

    return n;
}

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    
    for (auto& n : numbers) {
        if (n % 2 == 0) { // 짝수
             answer.push_back(n + 1);
        } else { // 홀수
            long long bit = 1;
            while ((n & bit) != 0)
            {
                bit *= 2; 
            }
            bit = bit / 2;
            answer.push_back(n + bit);
        }
    }
    
    return answer;
}
