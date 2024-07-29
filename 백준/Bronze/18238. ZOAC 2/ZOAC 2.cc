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
	int cur = 0;
	int ans = 0;
	for (int i = 0; i < s.size(); i++)
	{
		int nxt = s[i] - 'A';
		if (nxt == cur) continue;
		int a = abs(cur - nxt);
		int b = 26 - a;
		if (a <= b)
			ans += a;
		else
			ans += b;
		cur = nxt;
	}
	cout << ans;

	return 0;
}