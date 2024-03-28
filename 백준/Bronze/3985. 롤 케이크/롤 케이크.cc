#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int cake[1005];
int pieces[1005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int l, n;
	cin >> l >> n;
	int pre = INT_MIN;
	int ix = 0;
	for (int i = 1; i <= n; i++)
	{
		int p, k;
		cin >> p >> k;
		if (k - p + 1 > pre)
		{
			pre = k - p + 1;
			ix = i;
		}

		for (int j = p; j <= k; j++)
		{
			if (cake[j] == 0)
			{
				cake[j] = i;
				pieces[i]++;
			}
		}
	}
	int mx = max_element(pieces + 1, pieces + n + 1) - pieces;
	cout << ix << '\n' << mx;


	return 0;
}