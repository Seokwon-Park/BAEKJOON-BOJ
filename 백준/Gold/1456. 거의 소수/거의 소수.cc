#include <bits/stdc++.h>

using namespace std;

bool is_prime[10000005];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	unsigned long long a, b;
	cin >> a >> b;

	fill(is_prime, is_prime + 10000005, true);
	for (unsigned long long i = 2; i*i<= b; i++)
	{
		if (!is_prime[i]) continue;
		for (unsigned long long j = i * i; j <= b/j; j += i)
		{
			is_prime[j] = false;
		}
	}

	int answer = 0;
	for (long long i = 2; i * i <= b; i++)
	{
		if (is_prime[i]) // 소수일때
		{
			long long k = i * i;
			while (k <= b) {

				if (k >= a) ++answer;
				if (i > b/k) // k에 i를 곱한 값에 대해서
					// 이 값이 b보다 작거나 같아야 함(k*i <= b) 
					// k*i > b 라면 답이 될 수 없다.
					// 이러면 k*i가 longlong도 넘어갈 수 있음
					// i > b/k 로 바꾸면 long long / long long이기 때문에 범위가 보장된다.
					// 나누기를 써도 되는 만약 b를 k로 나눴을때 i보다 크거나 같은 값이 나오면 
					// k*i를 했을때 보다 작거나 같다는 것이 보장되기 때문이다.
					break; 

				k *= i;

			}
		}
	}

	//cout << i << '\n';

	cout << answer;

	return 0;
}