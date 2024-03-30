#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	vector<int> binus(t);
	for (int i = 0; i < t; i++)
	{
		cin >> binus[i];
	}

	int ans = 0;
	for (int i = 0; i < t; i++)
	{
		int enemy;
		cin >> enemy;
		if (binus[i] > enemy)
			ans += 3;
		else if (binus[i] == enemy)
			ans++;
	}
	cout << ans;

	return 0;
}