#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	vector<string> v(3);
	for (auto& s : v)
		cin >> s;
	
	string ans = v[0];
	for (int i = 0; i < 2; i++)
	{
		if (*v[i].rbegin() == *v[i+1].begin())
		{
			ans += '\'';
			ans += v[i+1].substr(1);
		}
		else
		{
			ans += v[i+1];
		}
	}

	cout << ans;

	return 0;
}