#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	vector<tuple<string, int, int>> v;
	for (int i = 0; i < n; i++)
	{
		string s;
		int st, ba;
		cin >> s >> st >> ba;
		v.push_back(tie(s, st, ba));
	}
	int ans = 0;
	for (int i = 123; i <= 987; i++)
	{
		string s = to_string(i);
		if (s[0] == s[1] || s[1] == s[2] || s[2] == s[0])continue;
		if (count(s.begin(), s.end(), '0'))continue;
		bool isAns = true;
		for (int j = 0; j < n; j++)
		{
			string cmp;
			int st, ba;
			tie(cmp, st, ba) = v[j];
			vector<bool> isExist(10, false);
			for (int k = 0; k < 3; k++)
			{
				isExist[cmp[k]-'0'] = true;
			}
			int cst = 0;
			int cba = 0;
			for (int k = 0; k < 3; k++)
			{
				if (cmp[k] == s[k]) cst++;
				else
				{
					if (isExist[s[k] - '0'])
						cba++;
				}
			}
			if (cba != ba || st != cst)
			{
				isAns = false;
				break;
			}
		}
		if (isAns)
		{
			ans++;
		}
	}

	cout << ans;

	return 0;
}