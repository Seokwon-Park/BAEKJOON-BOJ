#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

string rev(string s)
{
	return string(s.rbegin(), s.rend());
}

string tail(string s)
{
	return s.substr(1);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	int ans = 0;
	for (int i = 1; i < n; i++)
	{
		if (v[i - 1] >= v[i])
		{
			if (v[i - 1] >= v[i] + k)
			{
				cout << -1;
				return 0;
			}
			else
			{
				v[i] += k;
				ans++;
			}
		}
	}
	cout << ans;

	return 0;
}