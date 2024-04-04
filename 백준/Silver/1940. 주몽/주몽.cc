#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	set<int> s;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		s.insert(v[i]);
	}

	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		auto res = s.find(m - v[i]);
		if (res != s.end() && res != s.find(v[i]))
		{
			s.erase(v[i]);
			s.erase(m - v[i]);
			cnt++;
		}
	}

	cout << cnt;


	return 0;
}