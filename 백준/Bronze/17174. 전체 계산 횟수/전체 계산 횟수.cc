#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	int ans = 0;
	while (n)
	{
		ans += n;
		n /= m;
	}

	cout << ans;

	return 0;
}