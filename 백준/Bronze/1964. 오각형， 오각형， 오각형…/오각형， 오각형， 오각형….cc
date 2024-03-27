#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	int ans = 5;
	if (n == 1)
	{
		cout << ans;
		return 0;
	}
	for (int i = 2; i <= n; i++)
	{
		ans = (ans + i * 5 - (i * 2 - 1)) % 45678;
	}
	cout << ans;

	return 0;
}