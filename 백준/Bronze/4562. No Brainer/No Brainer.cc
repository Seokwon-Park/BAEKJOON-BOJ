#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	while (n--)
	{
		int x, y;
		cin >> x >> y;
		cout << (x < y ? "NO BRAINS" : "MMM BRAINS");
		cout << '\n';
	}


	return 0;
}