#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, d;
	cin >> n >> d;
	int total = 0;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		total += v[i];
	}
	int per = d / total;
	for (int i : v)
		cout << i * per << '\n';

	return 0;
}