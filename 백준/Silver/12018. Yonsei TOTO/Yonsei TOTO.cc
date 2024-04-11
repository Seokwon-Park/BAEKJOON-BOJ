#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<int> v;
	while (n--)
	{
		int p, l;
		cin >> p >> l;
		vector<int> vt(p);
		for (int i = 0; i < p; i++)
		{
			cin >> vt[i];
		}
		if (p < l)
		{
			v.push_back(1);
		}
		else
		{
			sort(vt.begin(), vt.end(), greater<int>());
			v.push_back(vt[l - 1]);
		}
	}
	sort(v.begin(), v.end());
	int ans = 0;
	for (int i : v)
	{
		if (m >= i)
		{
			m -= i;
			ans++;
		}
		else
			break;
	}

	cout << ans;


	return 0;
}
