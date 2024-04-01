#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	int st = 1;
	int ed = 1;
	int sum = 1;
	int cnt = 0;
	while (st <= ed)
	{
		if (sum < n)
		{
			ed++;
			sum += ed;
		}
		else if (sum > n)
		{
			sum -= st;
			st++;
		}
		else
		{
			cnt++;
			ed++;
			sum += ed;
		}
	}
	cout << cnt;


	return 0;
}