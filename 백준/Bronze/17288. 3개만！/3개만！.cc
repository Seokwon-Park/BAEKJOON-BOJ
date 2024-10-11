#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'009;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;

	int cur = -1;
	int cnt = 0;
	int ans = 0;
	for (auto c : s)
	{
		int c2i = c - '0';
		if (c2i != cur + 1)
		{
			if (cnt == 3)
			{
				ans++;
			}
			cur = c2i;
			cnt = 1;
		}
		else
		{
			cur++;
			cnt++;
		}
	}
	if (cnt == 3)ans++;
	cout << ans;

	return 0;
}

