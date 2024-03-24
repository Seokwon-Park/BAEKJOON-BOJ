#include <bits/stdc++.h>

using namespace std;

using ll = long long;

char battle(vector<int>& a, vector<int>& b)
{
	for (int i = 4; i >= 1; i--)
	{
		if (a[i] == b[i]) continue;
		if (a[i] > b[i])
			return 'A';
		else
			return 'B';
	}
	return 'D';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--)
	{
		int a, b;
		cin >> a;
		vector<int> va(5), vb(5);
		int card;
		for (int i = 0; i < a; i++)
		{
			cin >> card;
			va[card]++;
		}
		cin >> b;
		for (int i = 0; i < b; i++)
		{
			cin >> card;
			vb[card]++;
		}
		cout << battle(va, vb) << '\n';

	}

	return 0;
}