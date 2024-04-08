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

	int ix = n;
	for (int i = n-2; i >= 0; i--)
	{
		if (v[i] > v[i + 1])
			ix = i+1;
	}
	if (ix == n)
	{
		cout << -1;
		return 0;
	}

	prev_permutation(v.begin(), v.end());

	for (int i : v)
		cout << i << ' ';

	return 0;
}
