#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> v(n);
	for (int& i : v)
		cin >> i;

	int ix = 0;
	for (int i = 1; i < n; i++)
	{
		if (v[i - 1] < v[i])
			ix = i;
	}
	if (ix == 0)
	{
		cout << -1;
		return false;
	}

	next_permutation(v.begin(), v.end());

	for (int i : v)
		cout << i << ' ';
	
	return 0;
}