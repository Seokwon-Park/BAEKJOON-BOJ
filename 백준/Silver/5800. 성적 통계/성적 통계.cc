#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int tc;
	cin >> tc;
	for (int i = 1; i <= tc; i++)
	{
		int n;
		cin >> n;
		vector<int> v(n);
		for (int& j : v)
			cin >> j;
		cout << "Class " << i << '\n';
		sort(v.begin(), v.end());
		int lgap = INT_MIN;
		for (int i = 0; i < n - 1; i++)
		{
			lgap = max(lgap, v[i + 1] - v[i]);
		}
		cout << "Max " << *v.rbegin() << ", Min " << *v.begin() << ", Largest gap " << lgap <<'\n';
	}


	return 0;
}