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

	int aw = 0;
	int bw = 0;
	for (int i = 0; i < 10; i++)
	{
		if (a[i] > b[i])aw++;
		else if (a[i] < b[i]) bw++;
	}

	if (aw > bw)
		cout << 'A';
	else if (aw < bw)
		cout << 'B';
	else
		cout << 'D';

	return 0;
}
