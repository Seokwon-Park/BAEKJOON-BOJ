#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<pair<int, string>> p;
	set<int> s;
	for (int i = 0; i < n; i++)
	{
		int mx = -1;
		int cont = 0;
		for (int j = 0; j < m; j++)
		{
			char x;
			cin >> x;
			if (x == '.')
			{
				cont++;
			}
			else
			{
				mx = max(cont, mx);
				cont = 0;
			}
		}
		mx = max(cont, mx);

		string name;
		cin >> name;

		s.insert(mx);
		p.push_back({ mx, name });
	}

	cout << s.size()<< '\n';
	for (auto [x, y] : p)
	{
		cout << x << ' ' << y << '\n';
	}
	
	return 0;
}
