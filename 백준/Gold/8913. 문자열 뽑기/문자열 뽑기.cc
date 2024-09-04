#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

bool ans;
map<vector<int>, bool> dp;

bool func(vector<int>& v)
{
	if (dp.find(v) != dp.end())
	{
		return dp[v];
	}
	if (v.size() == 1)
	{
		if (v[0] > 1)
		{
			return true;
		}
		return false;
	}
	for (int i = 0; i < v.size(); i++)
	{
		vector<int> nxt;
		if (v[i] < 2) continue;
		if (i == 0) // 맨앞지우는 경우 연결 x
		{
			for (int j = 1; j < v.size(); j++)
			{
				nxt.push_back(v[j]);
			}
		}
		else if (i == v.size() - 1) // 맨 끝 지우는 경우 연결 x
		{
			nxt = v;
			nxt.pop_back();
		}
		else // 그외의 경우 연결
		{
			for (int j = 0; j < i - 1; j++)
			{
				nxt.push_back(v[j]);
			}
			nxt.push_back(v[i - 1] + v[i + 1]);
			for (int j = i+2; j < v.size(); j++)
			{
				nxt.push_back(v[j]);
			}
		}
		if (func(nxt))
		{
			return dp[v] = true;
		}
	}
	return dp[v] =  false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		ans = false;
		string s;
		cin >> s;
		vector<int> v;
		char prev = '\0';
		int cont = 0;
		for (char c : s)
		{
			if (prev == '\0')
			{
				prev = c;
				cont = 1;
				continue;
			}
			if (prev == c)
			{
				cont++;
			}
			else
			{
				v.push_back(cont);
				cont = 1;
				prev = c;
			}
		}
		if (cont != 0)
			v.push_back(cont);

		cout << func(v) << '\n';
	}

	return 0;
}
