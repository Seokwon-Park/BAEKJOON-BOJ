#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	int ans = m;
	bool isNeg = false;
	for(int i = 1; i<=n;i++)
	{
		int a, b;
		cin >> a >> b;
		m += a;
		m -= b;
		if(m >=0)
			ans = max(ans, m);
		else
		{
			isNeg = true;
		}
	}

	if (isNeg)
		cout << 0;
	else
		cout << ans;

	return 0;
}