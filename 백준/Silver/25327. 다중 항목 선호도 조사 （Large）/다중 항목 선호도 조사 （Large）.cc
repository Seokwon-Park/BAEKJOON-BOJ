#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

unordered_map<string, int> um;

string v[3][3] =
{
	{"kor", "eng", "math"},
	{"apple", "pear", "orange"},
	{ "red", "blue", "green" },
};

void func(int k, int& ans, string key, vector<string> quest)
{
	if (k == 3)
	{
		ans += um[key];
		return;
	}
	
	
	if (quest[k] == "-")
	{
		for (int i = 0; i < 3; i++)
		{
			func(k+1, ans, key+v[k][i], quest);
		}
	}
	else
	{
		func(k+1, ans, key+quest[k], quest);
	}

}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		string key = "";
		for (int j = 0; j < 3; j++)
		{
			string k;
			cin >> k;
			key += k;
		}
		um[key]++;
	}

	for (int i = 0; i < m; i++)
	{
		vector<string> tmp(3);
		int ans = 0;
		for (int j = 0; j < 3; j++)
		{
			cin >> tmp[j];
		}
		func(0, ans, "", tmp);
		cout << ans << '\n';
	}

	return 0;
}