#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n, a;
	cin >> n >> a;
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		int m;
		cin >> m;
		ans += m / a;
	}
	cout << ans;

	return 0;
}