#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, h;
	cin >> n >> h;
	
	vector<int> up;
	vector<int> down;

	for (int i = 0; i < n; i++)
	{
		int m;
		cin >> m;
		if (i % 2)
		{
			up.push_back(m);
		}
		else
		{
			down.push_back(m);
		}
	}
	sort(up.begin(), up.end());
	sort(down.begin(), down.end());
	vector<int> tmp;
	for (int i = 1; i <= h; i++)
	{
		auto d = lower_bound(down.begin(), down.end(), i);
		auto u = lower_bound(up.begin(), up.end(), h - i + 1);
		int sum = (down.end() - d) + (up.end() - u);
		tmp.push_back(sum);
	}
	
	sort(tmp.begin(), tmp.end());
	int val = tmp[0];
	int range = upper_bound(tmp.begin(), tmp.end(), val) - lower_bound(tmp.begin(), tmp.end(), val);

	cout << val << ' ' << range;

	return 0;
}