#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	int p;
	cin >> p;

	
	if (n >= 20)
	{
		p = min(p - 2000, p * 3 / 4);
	}
	else if (n >= 15)
	{
		p = min(p - 2000, p * 9 / 10);
	}
	else if (n >= 10)
	{
		p = min(p - 500, p * 9 / 10);
	}
	else if (n >= 5)
	{
		p -= 500;
	}
	

	cout << max(0, p);

	return 0;
}