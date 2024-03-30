#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> v(n-1);
	for (int& i : v)
		cin >> i;
	vector<int> ans(n, 1);
	for (int i = 0; i < n-1; i++)
	{
		ans[v[i] + 1] = i + 2;
	}

	for (int i : ans)
		cout << i << ' ';

	return 0;
}