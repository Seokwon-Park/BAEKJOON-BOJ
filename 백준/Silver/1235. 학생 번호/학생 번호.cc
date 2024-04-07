#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector<string> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	for (int i = 1; i <= v[0].size(); i++)
	{
		bool isDiff = true;
		set<string> s;
		for (int j = 0; j < n; j++)
		{
			string tmp = v[j].substr(v[j].size() - i);
			if (s.find(tmp) != s.end())
			{
				isDiff = false;
				break;
			}
			s.insert(tmp);
		}
		if (isDiff)
		{
			cout << i;
			return 0;
		}
	}

	return 0;
}