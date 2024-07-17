#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	string s;
	cin >> s;

	vector<string> v;

	int st = 0;
	for (int i = 1; i < s.size(); i++)
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
		{
			v.push_back(s.substr(st, i - st));
			st = i;
		}
	}

	int ans = 0;
	for (auto str : v)
	{
		ans += (str.size() / 4 +(str.size()%4 == 0?0:1))*4 - str.size();
	}
	cout << ans;


	return 0;
}
