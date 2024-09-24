#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	string str;
	cin >> str;
	istringstream iss(str);
	string s;
	vector<string> v;
	bool useColon = false;
	while (getline(iss, s, ':'))
	{
		if (s.empty())
		{
			if (useColon) continue;
			useColon = true;
		}
		v.push_back(s);
	}
	
	string ans = "";
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i].empty())
		{
			int fillzero = 8 - (v.size() - 1);
			for (int j = 0; j < fillzero; j++)
			{
				ans += "0000:";
			}
		}
		else
		{
			ans += string(4 - v[i].size(), '0') + v[i];
			if (i != v.size() - 1) ans += ':';
		}
	}
	if (ans[ans.size() - 1] == ':') ans.pop_back();

	cout << ans;

	return 0;
}

