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

	int n;
	cin >> n;
	vector<vector<int>> v(n);
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		vector<int> check(s.size(), -1);
		
		int ix = 0;
		for (int j = 0; j < s.size(); j++)
		{
			if (check[j] != -1) continue;
			char c = s[j];
			for (int k = 0; k < s.size(); k++)
			{
				if (s[k] == c)
					check[k] = ix;
			}
			ix++;
		}
		v[i] = check;
	}

	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			if (v[i] == v[j])
				ans++;
		}
	}

	cout << ans;

	return 0;
}