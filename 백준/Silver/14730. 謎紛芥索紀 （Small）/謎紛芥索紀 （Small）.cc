#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		int c, k;
		cin >> c >> k;
		ans += c * k;
	}
	cout << ans;

	return 0;
}