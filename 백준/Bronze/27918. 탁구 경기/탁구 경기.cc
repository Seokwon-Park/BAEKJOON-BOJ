#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	int d = 0, p = 0;
	while (n--)
	{
		char c;
		cin >> c;
		if (c == 'D')d++;
		else p++;
		if (abs(d - p) >= 2) break;
	}
	cout << d << ':' << p;

	return 0;
}