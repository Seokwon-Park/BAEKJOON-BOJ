#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, ll>;
const int INF = 0x3f3f3f3f;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;
	int sz = 3;
	while (s.size() > sz) sz += 3;
	string ns = string(sz - s.size(), '0') + s;

	string ans(sz / 3, '0');
	for (int i = 0; i < sz; i+= 3)
	{
		int res = 0;
		for (int j = 2; j >=0; j--)
		{
			int bit = ns[i + 2 - j] - '0';
			res += bit << j;
		}
		ans[i / 3] = res + '0';
	}
	cout << ans;

	return 0;
}
