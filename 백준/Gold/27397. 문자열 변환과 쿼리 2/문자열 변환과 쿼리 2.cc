#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int changed[256];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	string s;
	int n;
	cin >> s >> n;

	for (int i = 'A'; i <= 'z'; i++) changed[i] = i;
	for (int i = 0; i < n; i++)
	{
		int cmd;
		cin >> cmd;
		if (cmd == 1)
		{
			char a, b;
			cin >> a >> b;
			for (int j = 'A'; j <= 'z'; j++)
			{
				if (changed[j] == a)
					changed[j] = b;
			}
		}
		else
		{
			int prev = changed[s[0]];
			int cnt = 0;
			int res = 0;
			for (auto c : s)
			{
				if (prev == changed[c])
				{
					cnt++;
				}
				else
				{
					res = max(res, cnt);
					cnt = 1;
					prev = changed[c];
				}
			}
			res = max(res, cnt);
			cout << res << '\n';
		}
	}

	return 0;
}