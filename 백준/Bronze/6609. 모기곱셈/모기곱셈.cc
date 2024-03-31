#include <bits/stdc++.h>

using namespace std;

using ll = long long;

bool isPelin(string s)
{
	int n = s.size();
	for (int i = 0; i < n / 2; i++)
	{
		if (s[n - i - 1] != s[i])
			return false;
	}
	return true;

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int m, p, l, e, r, s, n;
	while (cin >> m >> p >> l >> e >> r >> s >> n)
	{
		int week = 0;
		while (week != n)
		{
			int tmp = m * e;
			m = p / s;
			p = l / r;
			l = tmp;
			week++;
		}
		cout << m << '\n';
	}


	return 0;
}