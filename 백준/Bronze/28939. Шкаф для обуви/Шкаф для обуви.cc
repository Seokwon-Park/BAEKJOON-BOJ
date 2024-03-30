#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	int k, m1, m2;
	cin >> k >> m1 >> m2;
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		int h, ki;
		cin >> h >> ki;
		for (int j = 0; j < ki; j++)
		{
			int fsize;
			cin >> fsize;
			int hlow = fsize * m2;
			int hhigh = fsize * m1;
			if (!(hlow <= h *k && hhigh >= h)) cnt++;
		}
	}
	cout << cnt;

	return 0;
}