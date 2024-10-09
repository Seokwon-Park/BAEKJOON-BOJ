#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;


int solve(string& s)
{
	string cur(s.size(), 'A');

	int ret = 0;
	vector<int> v;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] != cur[i])
		{
			int c2i = s[i] - 'A';
			int l = c2i;
			int r = 26 - c2i;
			ret += min(l, r);
			v.push_back(i);
		}
	}

	if (v.empty()) return ret;
	int mind = min((int)v[v.size() - 1], (int)(s.size()-v[0]));
	for (int i = 0; i < v.size() - 1; i++)
	{
		int l = v[i];
		int r = v[i + 1];
		int ld = v[i];
		int rd = s.size() - v[i + 1];
		if (ld > rd)
			mind = min(mind, rd * 2 + ld);
		else
			mind = min(mind, rd + ld * 2);

	}

	ret += mind;

	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--)
	{
		string s;
		cin >> s;
		cout << solve(s) << '\n';
	}

	return 0;
}