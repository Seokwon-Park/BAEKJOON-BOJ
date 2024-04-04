#include <bits/stdc++.h>

using namespace std;

using ll = long long;



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string a, b;
	cin >> a >> b;
	int mn = INT_MAX;
	for(int i = 0; i<= b.size() -a.size(); i++)
	{
		int cnt = 0;
		for (int j = 0; j < a.size(); j++)
		{
			if (a[j] != b[i+j])
				cnt++;
		}
		if (cnt < mn)
		{
			mn = cnt;
		}
	}
	cout << mn;

	return 0;
}