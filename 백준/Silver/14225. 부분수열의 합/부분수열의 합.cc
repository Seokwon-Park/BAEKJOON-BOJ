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
	vector<int> v;

	for (int i = 0; i < n; i++)
	{
		int m;
		cin >> m;
		v.push_back(m);
	}
	sort(v.begin(), v.end());
	
	set<int> s;

	for (int i = 1; i <= n; i++)
	{
		vector<int> c(n, 0);
		fill(c.end() - i, c.end(), 1);
		do
		{
			int res = 0;
			for (int i = 0; i < n; i++)
			{
				if (c[i] == 1)
				{
					res += v[i];
				}
			}
			s.insert(res);
		} while (next_permutation(c.begin(), c.end()));
	}

	int k = 1;
	while (s.find(k) != s.end())
		k++;
	cout << k;

	return 0;
}