#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	sort(a.begin(), a.end());
	int ans = 0;
	for (int i = 0; i < n; i++) // a[i]번째 수가 다른 수들의 합으로 나타낼 수 있는가
	{
		bool chk = false;
		for (int j = 0; j < n; j++)
		{
			if (j == i) continue;
			int ix = lower_bound(a.begin(), a.end(), a[i] - a[j]) - a.begin();
			while (ix < n && a[ix] == a[i] - a[j])
			{
				if (ix != i && ix != j) { ans++; chk = true; break; }
				ix++;
			}
			if (chk) break;
		}
	}
	cout << ans;


	return 0;
}
