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

	string s;
	cin >> s;

	vector<int> f, b;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '(' && s[i + 1] == '(')
		{
			b.push_back(i);
		}
		if (s[i] == ')' && s[i + 1] == ')')
		{
			f.push_back(i);
		}
	}

	int ans = 0;
	for (int i = 0; i < b.size(); i++)
	{
		int ix = lower_bound(f.begin(), f.end(), b[i])-f.begin();
		ans += f.size() - ix;
	}
	cout << ans;



	return 0;
}