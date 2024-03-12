#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	string nn = to_string(n);
	int res = 0;
	bool div7 = (n % 7 == 0);
	bool has7 = false;
	for (char c : nn)
	{
		if (c == '7')
			has7 = true;
	}
	cout << (div7 ? 1 : 0) + (has7 ? 2 : 0);
	


	return 0;
}