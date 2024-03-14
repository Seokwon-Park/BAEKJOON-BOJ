
#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int a, b;
	cin >> a >> b;
	if (a == 2)
	{
		if (b == 18) cout << "Special";
		else if (b < 18) cout << "Before";
		else cout << "After";
	}
	else if (a > 2)
	{
		cout << "After";
	}
	else
		cout << "Before";

	return 0;
}