#include <bits/stdc++.h>

using namespace std;

using ll = long long;

bool line[10001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	while (n--)
	{
		int a, b;
		cin >> a >> b;
		fill(line + a, line + b, true);
	}
	cout << count(line, line + 10005, true);

	return 0;
}