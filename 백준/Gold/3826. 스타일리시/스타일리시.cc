#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;

vector<int> findRCS(vector<vector<int>>& v)
{
	bool isAlreadyFind = false;
	vector<int> ret(3);
	for (int r = 1; r <= 20; r++)
	{
		for (int c = 1; c <= 20; c++)
		{
			for (int s = 1; s <= 20; s++)
			{
				bool isFind = true;
				for (int i = 0; i < v.size(); i++)
				{
					if (v[i][0] * r + v[i][1] * c + v[i][2] * s != v[i][3])
					{
						isFind = false;
						break;
					}
				}
				if (isFind)
				{
					if (!isAlreadyFind)
					{
						isAlreadyFind = true;
						ret = { r,c,s };
					}
					else
					{
						if (ret[0] != r)
							ret[0] = -99;
						if (ret[1] != c)
							ret[1] = -99;
						if (ret[2] != s)
							ret[2] = -99;
					}
				}
			}
		}
	}
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	while (1)
	{
		int p, q;
		cin >> p >> q;
		if (p == 0 && q == 0) break;
		int ro = 0, rc = 0, co = 0, cc = 0, so = 0, sc = 0;

		map<int, map<int, map<int, int>>> dp;
		vector<vector<int>> rcs;
		for (int i = 0; i < p; i++)
		{
			string s;
			cin >> s;
			if (i != 0)
			{
				int ix = 0;
				while (s[ix] == '.') ix++;
				rcs.push_back({ ro - rc , co - cc, so - sc, ix });
				dp[ro - rc][co - cc][so - sc] = ix;
			}
			for (auto c : s)
			{
				if (c == '(')
					ro++;
				if (c == '{')
					co++;
				if (c == '[')
					so++;
				if (c == ')')
					rc++;
				if (c == '}')
					cc++;
				if (c == ']')
					sc++;
			}
		}

		vector<int> rcsRes = findRCS(rcs);

		ro = 0, rc = 0, co = 0, cc = 0, so = 0, sc = 0;
		vector<int> ans;
		for (int i = 0; i < q; i++)
		{
			string s;
			cin >> s;
			if (i != 0)
			{
				if (dp[ro - rc][co - cc][so - sc])
					ans.push_back(dp[ro - rc][co - cc][so - sc]);
				else
				{
					int res = (ro - rc) * rcsRes[0] + (co - cc) * rcsRes[1] + (so - sc) * rcsRes[2];
					if (res < 0)
						ans.push_back(-1);
					else
						ans.push_back(res);
				}
			}
			else
			{
				ans.push_back(0);
			}
			for (auto c : s)
			{
				if (c == '(')
					ro++;
				if (c == '{')
					co++;
				if (c == '[')
					so++;
				if (c == ')')
					rc++;
				if (c == '}')
					cc++;
				if (c == ']')
					sc++;
			}
		}
		for (auto i : ans)
		{
			cout << i << ' ';
		}
		cout << '\n';
		//for (auto i : rcsRes)
		//{
		//	cout << i << ' ';
		//}
		//cout << '\n';
	}


	return 0;
}