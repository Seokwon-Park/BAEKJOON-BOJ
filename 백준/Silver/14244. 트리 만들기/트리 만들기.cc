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
	
	int n, m;
	cin >> n >> m;
	
	int i;
	for (i = 0; ; i++)
	{
		if (n - i == m)
			break;
		cout << i << ' ' << i + 1 << '\n';
	}

	for (int j = i + 1; j < i + m; j++)
	{
		cout << i << ' ' << j << '\n';
	}

	

	return 0;
}