#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--)
	{
		bool fail = false;
		vector<pair<int, int>> v;
		for (int i = 0; i < 4; i++)
		{
			int x, y;
			cin >> x >> y;
			v.push_back({ x,y });
		}
		sort(v.begin(), v.end());
		auto [x0, y0] = v[0];
		auto [x1, y1] = v[1];
		auto [x2, y2] = v[2];
		auto [x3, y3] = v[3];
		for (int i = 0; i < 4; i++)
		{
			for (int j = i+1; j < 4; j++)
			{
				if (v[i] == v[j])
				{
					fail = true;
					break;
				}
			}
			if (fail)break;
		}

		ll edge1 = (x1 - x0) * (x1 - x0) + (y1 - y0) * (y1 - y0);
		ll edge2 = (x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2);
		ll edge3 = (x2 - x0) * (x2 - x0) + (y2 - y0) * (y2 - y0);
		ll edge4 = (x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1);
		
		if (edge1 != edge2 || edge1 != edge3 || edge2 != edge4 || edge3 != edge4)
		{
			fail = true;
		}
		ll hyp = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
		if (edge1 + edge2 != hyp)
		{
			fail = true;
		}
		if (fail)
			cout << 0;
		else
			cout << 1;
		cout << '\n';
	}

	return 0;
}