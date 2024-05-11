#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int b, c, d;
	cin >> b >> c >> d;
	vector<int> bv(b);
	vector<int> cv(c);
	vector<int> dv(d);

	for (int i = 0; i < b; i++)
		cin >> bv[i];
	sort(bv.begin(), bv.end(), greater<int>());
	for (int i = 0; i < c; i++)
		cin >> cv[i];
	sort(cv.begin(), cv.end(), greater<int>());
	for (int i = 0; i < d; i++)
		cin >> dv[i];
	sort(dv.begin(), dv.end(), greater<int>());

	int m = min({ b,c,d });
	int ans = 0;
	for (int i = 0; i < m; i++)
	{
		ans += bv[i] + cv[i] + dv[i];
	}
	
	int dis = ans / 10 * 9;

	int single = 0;

	for (int i = m; i < b; i++)
		single += bv[i];
	for (int i = m; i < c; i++)
		single += cv[i];
	for (int i = m; i < d; i++)
		single += dv[i];

	cout << ans+ single << '\n' << dis + single;

	return 0;
}
