#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t, s;
	cin >> t >> s;
	
	if (t >= 12 && t <= 16)
	{
		if (s == 1)
			cout << 280;
		else
			cout << 320;
	}
	else
	{
		cout << 280;
	}
	return 0;
}