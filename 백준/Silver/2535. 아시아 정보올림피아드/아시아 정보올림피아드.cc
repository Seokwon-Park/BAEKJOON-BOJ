#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int limit[101];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	vector<tuple<int, int, int>> v;
	while (n--)
	{
		int a, b, score;
		cin >> a >> b >> score;
		v.push_back(tie(score, a, b));
	}
	sort(v.begin(), v.end(), greater<tuple<int,int,int>>());
	
	vector<pair<int, int>> ans;
	for (auto [score, a, b] : v)
	{
		if (limit[a] < 2)
		{
			limit[a]++;
			ans.push_back({ a, b });
		}
		if (ans.size() == 3)break;
	}

	for (auto [x, y] : ans)
	{
		cout << x << ' ' << y << '\n';
	}


	return 0;
}