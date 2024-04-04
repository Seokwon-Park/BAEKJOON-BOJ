#include <bits/stdc++.h>

using namespace std;

using ll = long long;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int e, f, c;
	cin >> e >> f >> c;

	int empty = e + f;
	int cola = 0;
	while (1)
	{
		int newcola = empty / c;
		if (newcola == 0)break;
		cola += newcola;
		empty %= c;
		empty += newcola;
	}
	cout << cola;

	return 0;
}