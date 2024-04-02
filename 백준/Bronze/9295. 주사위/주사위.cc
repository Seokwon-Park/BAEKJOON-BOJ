#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for(int i = 1; i<=t;i++)
	{
		int n, m;
		cin >> n >> m;
		cout << "Case " << i << ": " << n + m << '\n';
	}
	
	return 0;
}