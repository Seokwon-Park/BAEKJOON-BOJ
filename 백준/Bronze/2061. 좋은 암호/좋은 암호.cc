#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

int operator%(string s, int n)
{
	string ret = "";
	int tmp = 0;
	for (int i = 0; i < s.size(); i++)
	{
		int m = s[i] - '0';
		tmp = tmp * 10 + m;
		if (tmp >= n)
		{
			ret.push_back(tmp / n + '0');
			tmp = tmp % n;
		}
	}

	return tmp;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	string s;
	int k;
	cin >> s >> k;

	vector<bool> isPrime(k + 1, true);

	for (int i = 2; i * i <= k; i++)
	{
		if (!isPrime[i]) continue;
		for (int j = i * i; j <= k; j += i)
		{
			isPrime[j] = false;
		}
	}

	for (int i = 2; i < k; i++)
	{
		if (isPrime[i] && s%i == 0)
		{
			cout << "BAD" << ' ' << i;
			return 0;
		}
	}

	cout << "GOOD";

	return 0;
}