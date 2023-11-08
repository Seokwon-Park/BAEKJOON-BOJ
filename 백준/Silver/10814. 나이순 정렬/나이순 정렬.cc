#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<pair<int, string>> v;
	for (int i = 0; i < n; i++)
	{
		int x;
		string y;
		cin >> x >> y;
		v.push_back({ x,y });
	}

	stable_sort(v.begin(), v.end(), [](pair<int, string> a, pair<int, string> b)
		{
			return a.first < b.first;
		});

	for (auto p : v)
	{
		cout << p.first << ' ' << p.second << '\n';
	}

	return 0;
}