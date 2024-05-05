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
	
	vector<int> up(h+1, 0);
	vector<int> down(h+1, 0);

	for (int i = 0; i < n; i++)
	{
		int m;
		cin >> m;
		if (i % 2)
		{
			up[m]++;
		}
		else
		{
			down[m]++;
		}
	}

	vector<int> pfup(h + 1, 0);
	vector<int> pfdown(h + 1, 0);
	for (int i = h; i >0; i--)
	{
		pfup[i - 1] = pfup[i] + up[i - 1];
		pfdown[i - 1] = pfdown[i] + down[i - 1];
	}

	vector<int> res(h + 1, 0);
	for (int i = 1; i <= h; i++)
	{
		res[i] = pfup[i] + pfdown[h - i + 1];
	}
	
	int val = *min_element(res.begin()+1, res.end());
	int range = count(res.begin() + 1, res.end(), val);
	cout << val << ' ' << range;

	return 0;
}