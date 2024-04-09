#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, x;
	cin >> n >> x;
	vector<int> v(n + 1);
	vector<int> pfsum(n + 1);
	for (int i = 1; i <= n; i++)
	{
		cin >> v[i];
		pfsum[i] = pfsum[i - 1] + v[i];
	}
	int mx = 0;
	int cnt = 0;
	for (int i = x; i <= n; i++)
	{
		int tmp = pfsum[i] - pfsum[i - x];
		if (mx < tmp)
		{
			mx = tmp;
			cnt = 1;
		}
		else if (mx == tmp)
		{
			cnt++;
		}
	}
	if (mx == 0)
		cout << "SAD";
	else
		cout << mx << '\n' << cnt;

	return 0;
}