#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, x;
	cin >> n >> x;
	int mn = INT_MAX;
	vector<int> a(n);
	for (auto& i : a)
		cin >> i;
	for (int i = 0; i < n-1; i++)
	{
		mn = min((a[i] + a[i + 1]) * x, mn);
	}
	cout << mn;


	return 0;
}