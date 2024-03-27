#include <bits/stdc++.h>

using namespace std;

using ll = long long;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	vector<int> v(n);
	for (int& i : v)
		cin >> i;
	int m;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int k, l, r;
		cin >> k >> l >> r;
		
		if (k == 1)
		{
			for (int i = l - 1; i <= r - 1; i++)
			{
				v[i] = v[i] * v[i] % 2010;
			}
		}
		else
		{
			int sum = 0;
			for (int i = l - 1; i <= r - 1; i++)
			{
				sum += v[i];
			}
			cout << sum << '\n';
		}
	}
	return 0;
}