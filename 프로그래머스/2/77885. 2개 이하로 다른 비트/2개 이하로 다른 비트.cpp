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
    
    // 주어진 정수보다 큰 수부터 +1 씩 다른 비트의 개수가 2개 이하인 수를 찾아라
    // 짝수: f(x) = x + 1
    // 홀수: x의 연속된 1의 비트의 개수가 n개라고 할 때, n - 1자리의 비트 수만큼 더해진게 f값이 된다
    // ex) 101111 의 f값은 000111를 더한 값이 된다
    for (auto& n : numbers) {
        if (n % 2 == 0) { // 짝수
            answer.push_back(n + 1);
        } else { // 홀수
            long long bit = 1;
            // 가장 오른쪽부터 차례로 n 개의 연속된 1 로 이루어진 비트구하기
            while (true) {
                if ((n & bit) == 0) break;
                bit *= 2; // 곱하기 2 를 하면 다음 비트로
            }
            bit = bit / 2;
            answer.push_back(n + bit);
        }
    }
    
    return answer;
}
