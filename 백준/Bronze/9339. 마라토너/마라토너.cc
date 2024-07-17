#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--)
	{
		int k;
		cin >> k;
		vector<int> stu(k);
		for (int i = 0; i < k; i++)
		{
			cin >> stu[i];
		}
		sort(stu.begin(), stu.end());
		int n;
		cin >> n;
		int h = 24;
		int m = 0;
		int num = 0;
		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			int nn, hh, mm;
			cin >> nn >> hh >> mm;
			if (hh == -1)continue;
			if (binary_search(stu.begin(), stu.end(), nn))
			{
				if (hh < 6 || (hh == 6 && mm == 0))
					cnt++;
				if (hh < h)
				{
					h = hh;
					m = mm;
					num = nn;
				}
				else if(hh == h && mm < m)
				{
					h = hh;
					m = mm;
					num = nn;
				}
			}
		}
		cout << num << ' ' << cnt << '\n';

	}

	return 0;
}