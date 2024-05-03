#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int v[205][205][205];
vector<int> ans;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a, b, c;
	cin >> a >> b >> c;

	queue<tuple<int, int, int>> q;
	q.push({ 0, 0, c });

	while (!q.empty())
	{
		auto [ac, bc, cc] = q.front();
		q.pop();

		if (v[ac][bc][cc]) continue;
		v[ac][bc][cc] = true;
		if (ac == 0) ans.push_back(cc);
		// a->b
		if (ac + bc <= b)
			q.push({ 0, ac + bc, cc });
		else
			q.push({ ac - (b - bc), b, cc });

		// a->c;
		if (ac + cc <= c)
			q.push({ 0, bc, cc + ac });
		else
			q.push({ ac - (c - cc), bc, c });

		// b->a
		if (ac + bc <= a)
			q.push({ ac+bc, 0, cc });
		else
			q.push({ a, bc-(a-ac), cc});

		// b->c
		if (cc + bc <= c)
			q.push({ ac, 0, cc+bc });
		else
			q.push({ ac, b-(c-cc), c});

		// c->a
		if (ac + cc <= a)
			q.push({ ac+cc, bc, 0 });
		else
			q.push({ a, bc, cc - (a-ac)});

		// c-> b
		if (cc + bc <= b)
			q.push({ ac, cc + bc, 0 });
		else
			q.push({ ac , b, cc - (b-bc)});
	}

	sort(ans.begin(), ans.end());
	for (int i : ans)
		cout << i << ' ';



	return 0;
}
