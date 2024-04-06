#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<pair<int,int>> v(n);
	for (auto& [a,b]:v)
	{
		cin >> a >> b;
	}

	sort(v.begin(), v.end());
	int t = 0;
	for (int i = 0; i < n; i++)
	{
		auto [st, sec] = v[i];
		t = max(st, t);
		t += sec;
	}
	cout << t;

	return 0;
}
