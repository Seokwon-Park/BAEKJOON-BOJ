#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

bool isPrime[2000005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	fill(isPrime, isPrime + 2000005, true);

	int n, m;
	cin >> n >> m;
	isPrime[1] = false;
	for (int i = 2; i * i <= 2000000; i++)
	{
		if (isPrime[i] == false) continue;
		for (int j = i * i; j <= 2000000; j += i)
		{
			isPrime[j] = false;
		}
	}

	int st = 0;
	while (st+(n-1)*m <= 2000000)
	{
		st++;
		if (isPrime[st])
		{
			continue;
		}
		bool isPoss = true;
		vector<int> v;
		for (int i = 0; i < n; i++)
		{
			if (isPrime[st + i * m])
			{
				isPoss = false;
				break;
			}
			v.push_back(st + i * m);
		}
		if (isPoss)
		{
			for (auto i : v)
			{
				cout << i << ' ';
			}
			return 0;
		}
	}
	cout << -1;

	return 0;
}