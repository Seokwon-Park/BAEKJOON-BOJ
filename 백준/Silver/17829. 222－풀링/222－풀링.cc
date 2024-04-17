#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int b[1024][1024];

int func(int x, int y, int n)
{
	if (n == 1)
	{
		return b[y][x];
	}
	int half = n / 2;
	vector<int> v(4);
	v[0] = func(x, y, half);
	v[1] = func(x+half, y, half);
	v[2] = func(x, y+half, half);
	v[3] = func(x+half, y+half, half);
	sort(v.begin(), v.end());
	return v[2];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> b[i][j];

	cout << func(0, 0, n);

	return 0;
}
