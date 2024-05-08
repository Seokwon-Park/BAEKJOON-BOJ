#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int h, w, n, m;
	cin >> h >> w >> n >> m;
	n++;
	m++;

	int hres = h / n + (h % n > 0 ? 1 : 0);
	int wres = w / m + (w % m > 0 ? 1 : 0);
	cout << hres * wres;

	return 0;
}