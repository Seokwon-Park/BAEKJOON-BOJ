#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;

vector<int> isPrime(100005, true);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	vector<int> v;
	for (int i = 2; i * i <= 100000; i++)
	{
		if (!isPrime[i])continue;
		for (int j = i * i; j <= 100000; j += i)
		{
			isPrime[j] = false;
		}
	}

	for (int i = 2; i <= 100000; i++)
	{
		if (isPrime[i])
			v.push_back(i);
	}

	int tc;
	cin >> tc;
	while (tc--)
	{
		int k;
		cin >> k;
		int ans = INT_MAX;
		for (int i = 0; i < v.size(); i++)
		{
			int m = v[i];
			int res = max(k / m, 2);
			while (1)
			{
				if (res == m)
				{
					res++;
					continue;
				}
				if (!isPrime[res])
				{
					res++;
					continue;
				}
				if (res * m >= k)
				{
					ans = min(res * m, ans);
					break;
				}
				res++;
			}
		}
		cout << ans << '\n';

	}



	return 0;
}
