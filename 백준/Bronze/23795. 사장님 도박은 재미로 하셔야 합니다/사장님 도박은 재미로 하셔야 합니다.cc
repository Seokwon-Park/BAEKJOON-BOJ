#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int ans = 0;
	while (1)
	{
		int n;
		cin >> n;
		if (n == -1)break;
		ans += n;
	}
	cout << ans;

	return 0;
}
