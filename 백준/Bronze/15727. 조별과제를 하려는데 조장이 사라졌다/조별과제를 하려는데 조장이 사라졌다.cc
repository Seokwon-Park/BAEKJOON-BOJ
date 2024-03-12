#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int l;
	cin >> l;
	int ans = l / 5;
	if (l % 5 != 0)
		ans++;
	cout << ans;

	return 0;
}