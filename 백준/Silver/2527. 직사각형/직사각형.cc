#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int tc = 4;
	while (tc--)
	{
		int x1, y1, p1, q1, x2, y2, p2, q2;
		cin >> x1 >> y1 >> p1 >> q1 >> x2 >> y2 >> p2 >> q2;

		if ((x1 == p2 && y1 == q2) || (p1 == x2 && q1 == y2) || (x1 == p2 && q1 == y2) || (p1 == x2) && (y1 == q2))
			cout << 'c';
		else if (x1 > p2 || y1 > q2 || p1 < x2 || q1 < y2)
			cout << 'd';
		else if (x1 == p2 || y1 == q2 || p1 == x2 || q1 == y2)
			cout << 'b';
		else
			cout << 'a';
		cout << '\n';
	}

	return 0;
}
