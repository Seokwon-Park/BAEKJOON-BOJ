#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	int ix = 1;
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		int m;
		cin >> m;
		if (m != ix)
			cnt++; // delete
		else
			ix++;
		
	}
	cout << cnt;
	return 0;
}