#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<pair<int, int>> v;
	for (int i = 0; i < n; i++)
	{
		int d, c;
		cin >> d >> c;
		v.push_back({ d,c });
	}

	sort(v.begin(), v.end());
	//for (auto [x, y] : v)
	//	cout << x << ' ' << y << '\n';
	int cost = INT_MAX;
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		int tmp = v[i].second;
		if (tmp < cost)
		{
			cost = tmp;
			cnt++;
		}
	}

	cout << cnt;
	return 0;
}
