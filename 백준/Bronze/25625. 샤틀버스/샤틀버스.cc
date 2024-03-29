#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int x, y;
	cin >> x >> y;
	if (y >= x)
		cout << y - x;
	else
		cout << x + y;


	return 0;
}