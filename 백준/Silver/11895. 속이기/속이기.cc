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
	
	int n;
	cin >> n;
	int res = 0;
	int mn = INF;
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		res ^= x;
		mn = min(mn, x);
		sum += x;
	}

	if (res)
	{
		cout << 0;
	}
	else
	{
		cout << sum - mn;
	}

	


	return 0;
}



