#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	vector<bool> isPrime(4000005, true);

	isPrime[1] = false;
	for (int i = 2; i * i <= 4000000; i++)
	{
		if (!isPrime[i]) continue;
		for (int j = i * i; j <= 4000000; j += i)
		{
			isPrime[j] = false;
		}
	}

	int a,b,d;
	cin >> a >> b >> d;
	vector<int> v;
	int ans = 0;
	for (int i = a; i <= b; i++)
	{
		if (!isPrime[i])continue;
		int tmp = i;
		bool isInclude = false;
		while (tmp)
		{
			int r = tmp % 10;
			if (r == d)
			{
				isInclude = true;
				break;
			}
			tmp /= 10;
		}
		ans += isInclude;
	}

	cout << ans;


	return 0;
}