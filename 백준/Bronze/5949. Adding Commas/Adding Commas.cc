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
	int st = 0;
	while (s.size() % 3 != 0)
	{
		s = '0' + s;
		st++;
	}
	
	string ans = s.substr(0, 3);
	for (int i = 1; i < s.size() / 3; i++)
	{
		ans += ',';
		ans += s.substr(i * 3, 3);
	}

	cout << ans.substr(st);

	

	return 0;
}