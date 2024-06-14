#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, q;
	cin >> n >> q;
	vector<int> loc(n+1);
	for (int i = 1; i <= n; i++)
	{
		cin >> loc[i];
	}

	for (int i = 0; i < q; i++)
	{
		int cmd, a, b;
		cin >> cmd >> a >> b;
		if (cmd == 1)
		{
			loc[a] = b;
		}
		else
		{
			cout << abs(loc[a] - loc[b]) << '\n';
		}
	}


		
	return 0;
}