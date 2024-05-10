#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;



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
		int total = 0;
		int ix = 0;
		int t = 0;
		vector<int> v(n);
		for (int i = 0; i < n; i++)
		{
			int m;
			cin >> m;
			v[i] = m;
			if (m > t)
			{
				t = m;
				ix = i;
			}
			total += m;
		}
		if (count(v.begin(), v.end(), t) > 1)
		{
			cout << "no winner";
		}
		else
		{
			if (t * 2 > total)
				cout << "majority winner " << ix + 1;
			else
				cout << "minority winner " << ix + 1;
		}
		cout << '\n';
		
	}


	return 0;
}