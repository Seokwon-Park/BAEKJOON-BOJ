#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	vector<pii> v(1, { 0,600 });
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		int st = a / 100 * 60 + a % 100 - 10;
		int en = b / 100 * 60 + b % 100 + 10;
		v.push_back({ st,en });
	}
	v.push_back({ 1320, 1440 });
	sort(v.begin(), v.end(), [](auto a, auto b) 
		{
			if (a.second == b.second)
			{
				return a.first < b.first;
			}
			return a.second < b.second;
		});

	int ans = 0;
	for (int i = 0; i < v.size()-1; i++)
	{
		if (v[i].second < v[i+1].first)
		{
			ans = max(ans, v[i + 1].first - v[i].second);
		}
	}
	cout << ans;
	
	return 0;
}

