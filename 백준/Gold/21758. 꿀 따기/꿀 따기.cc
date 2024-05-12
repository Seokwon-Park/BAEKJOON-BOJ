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
	vector<int> v(n + 1);
	vector<int> pfsum(n + 1, 0);

	for (int i = 1; i <= n; i++)
	{
		cin >> v[i];
		pfsum[i] = pfsum[i - 1] + v[i];
	}

	int res1 = pfsum[n] - v[1];
	int tmp = 0;
	for (int i = 2; i <= n; i++)
	{
		tmp = max(tmp, pfsum[n] - pfsum[i-1] - v[i]*2);
	}
	res1 += tmp;

	tmp = 0;
	int res2 = pfsum[n] - v[n]; 
	for (int i = n-1; i > 1; i--)
	{
		tmp = max(tmp, pfsum[i] - v[i] * 2);
	}
	res2 += tmp;

	int res3 = 0;
	for (int i = 2; i < n; i++)
	{
		res3 = max(res3, pfsum[i] - v[1]+ pfsum[n-1] - pfsum[i-1]);
	}

	cout << max({ res1, res2, res3 });
	

	return 0;
}
