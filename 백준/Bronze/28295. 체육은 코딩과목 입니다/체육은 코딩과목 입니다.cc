#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int cur = 0; // NESW 0,1,2,3;
	for (int i = 0; i < 10; i++)
	{
		int t;
		cin >> t;
		if (t == 1)
			cur = (cur + 1) % 4;
		else if (t == 2)
			cur = (cur + 2) % 4;
		else
			cur = (cur + 3) % 4;
	}

	if (cur == 0) cout << 'N';
	if (cur == 1) cout << 'E';
	if (cur == 2) cout << 'S';
	if (cur == 3) cout << 'W';

	return 0;
}