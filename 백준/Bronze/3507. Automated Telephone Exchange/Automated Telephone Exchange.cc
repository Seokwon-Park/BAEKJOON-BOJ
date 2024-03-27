#include <bits/stdc++.h>

using namespace std;

using ll = long long;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	int ans = 0;
	if (n >= 199)// 198 - 99 - 99 까지가 최대
	{
		cout << 0;
		return 0;
	}
	for (int i = 0; i < 100; i++)
	{
		int m = n - i;
		if (m < 100)
			ans++;
	}
	cout << ans;

	return 0;
}