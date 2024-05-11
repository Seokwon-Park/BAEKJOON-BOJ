#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t, n;
	cin >> t >> n;
	int f = 0;
	for (int i = 0; i < n; i++)
	{
		int m;
		cin >> m;
		f += m;
	}

	if (f >= t)
		cout << "Padaeng_i Happy";
	else
		cout << "Padaeng_i Cry";

	return 0;
}