#include <bits/stdc++.h>

using namespace std;

using ll = long long;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<int> v(n);
		for(int i = 0; i< n; i++)
		{
			cin >> v[i];
		}

		sort(v.begin(), v.end());

		cout << ( *v.rbegin()- *v.begin()) * 2 << '\n';
	}


	return 0;
}
