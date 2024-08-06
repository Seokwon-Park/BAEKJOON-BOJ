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
	
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	ll prevStack = 1;
	ll ans = 1;
	for (int i = 1; i < n; i++)
	{
		if (v[i - 1] < v[i])
		{
			prevStack++;
		}
		else
		{
			prevStack = 1LL;
		}
		ans += prevStack;
	}
	cout << ans;



	return 0;
}