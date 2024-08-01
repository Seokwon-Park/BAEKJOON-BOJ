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

	string s;
	cin >> s;
	int n = s.size();
	s = 'N' + s;

	int ans = 0;
	if (count(s.begin(), s.end(), 'Y') == 0)
	{
		cout << ans;
		return 0;
	}
	for (int i = 1; i <= n; i++)
	{
		if (s[i] != 'Y')continue;
		for (int j = i; j < s.size(); j += i)
		{
			if (s[j] == 'Y') s[j] = 'N';
			else s[j] = 'Y';
		}
		int ycnt = count(s.begin(), s.end(), 'Y');
		ans++;
		if (ycnt == 0)
		{
			cout << ans;
			return 0;
		}
	}

	cout << -1;

	return 0;
}