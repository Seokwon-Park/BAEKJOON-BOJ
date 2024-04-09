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
	vector<int> v(n);
	for (int& i : v)
		cin >> i;
	sort(v.begin(), v.end());
	vector<int> c(n, 0);
	fill(c.end() - 3, c.end(), 1);
	int ans = -1;
	do
	{
		vector<int> tri;
		for (int i = 0; i < n; i++)
		{
			if (c[i])
				tri.push_back(v[i]);
		}
		if (tri[2] < tri[0] + tri[1])
		{
			if (ans == -1)
			{
				ans = max(ans, tri[0] + tri[1] + tri[2]);
			}
			else
				break;
		}

	} while (next_permutation(c.begin(), c.end()));
	cout << ans;

	return 0;
}