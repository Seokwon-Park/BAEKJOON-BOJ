#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int v[1005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> v[i];
	}

	int q;
	cin >> q;

	for (int i = 0; i < q; i++)
	{
		int cmd;
		cin >> cmd;
		int l, r;
		if (cmd == 1)
		{
			int k;
			cin >> l >> r >> k;
			int cnt = 0;
			for (int i = l; i <= r; i++)
			{
				if (v[i] == k)
					cnt++;
			}
			cout << cnt << '\n';
		}
		else
		{
			cin >> l >> r;
			for (int i = l; i <= r; i++)
			{
				v[i] = 0;
			}
		}
	}


	return 0;
}

