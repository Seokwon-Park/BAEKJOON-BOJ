#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	vector<int> a(10), b(10);
	for (int& i : a)
		cin >> i;
	for (int& i : b)
		cin >> i;

	char lwin = 'D';
	int as = 0;
	int bs = 0;
	for (int i = 0; i < 10; i++)
	{
		if (a[i] == b[i])
		{
			as++;
			bs++;
		}
		else if (a[i] < b[i])
		{
			bs += 3;
			lwin = 'B';
		}
		else
		{
			as += 3;
			lwin = 'A';
		}
	}

	cout << as << ' ' << bs << '\n';
	if (as == bs)
	{
		cout << lwin;
	}
	else
	{
		if (as > bs)
			cout << 'A';
		else
			cout << 'B';
	}

	return 0;
}