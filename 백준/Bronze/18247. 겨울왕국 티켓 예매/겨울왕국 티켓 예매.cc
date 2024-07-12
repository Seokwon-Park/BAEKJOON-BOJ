#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);	

	int tc;
	cin >> tc;
	int l = 'l' - 'a';
	while (tc--)
	{
		int n, m;
		cin >> n >> m;
		if (n - 1 < l || m < 4)
		{
			cout << -1;
		}
		else
		{
			cout << l * m + 4;
		}
		cout << '\n';
	}

	return 0;
}
