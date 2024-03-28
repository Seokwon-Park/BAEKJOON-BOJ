#include <bits/stdc++.h>


using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int m;
		cin >> m;
		vector<int> v(m);
		for (int& i : v)cin >> i;
		bool isgood = true;
		for (int i = 1; i < m; i++)
		{
			if (v[i - 1] * 2 > v[i])
			{
				isgood = false;
				break;
			}
		}
		cout << "Denominations: ";
		for (int i : v)
			cout << i << ' ';
		cout << '\n';
		if (isgood)
			cout << "Good coin denominations!\n";
		else
			cout << "Bad coin denominations!\n";
		cout << '\n';
	}

	return 0;
}