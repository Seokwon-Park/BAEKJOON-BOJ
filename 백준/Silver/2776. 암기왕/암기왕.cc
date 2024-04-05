#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--)
	{
		int n;
		cin >> n;
		vector<int> v(n);
		for (int& i : v)
			cin >> i;
		sort(v.begin(), v.end());
		int m;
		cin >> m;
		vector<int> v2(m);
		
		for (int& i : v2)
		{
			cin >> i;
			if (binary_search(v.begin(), v.end(), i))
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}
	}

	return 0;
}
