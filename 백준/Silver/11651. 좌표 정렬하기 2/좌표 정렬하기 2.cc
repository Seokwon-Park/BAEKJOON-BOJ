#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<pair<int, int>> v;
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		v.push_back({ x,y });
	}

	sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b)
		{
			if (a.second == b.second)
				return a.first < b.first;
			else
				return a.second < b.second;
		});

	for (auto p : v)
	{
		cout << p.first << ' ' << p.second << '\n';
	}

	return 0;
}