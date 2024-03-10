#include <bits/stdc++.h>

#define INF 0x3f3f3f3f

using namespace std;

long long gcd(long long a, long long b)
{
	if (b == 0) return a;
	return gcd(b, a % b);
}

long long lcm(long long a, long long b)
{
	return a / gcd(a, b) * b;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	long long n, a, b, c, d;
	cin >> n >> a >> b >> c >> d;

	if (d * a > b * c) // b/a d/c => bc/ac 와 da/ac를 비교하는 것임.
	{
		swap(a, c);
		swap(b, d);
	}

	long long l = lcm(a, c);
	
	long long answer = LLONG_MAX;
	for (long long i = 0; i < l / a; i++)
	{
		long long cc = i * b;
		if (n - i * a > 0) cc += (((n - i * a - 1) / c) + 1) * d;
		answer = min(answer, cc);
	}

	cout << answer;
	
	return 0;
}