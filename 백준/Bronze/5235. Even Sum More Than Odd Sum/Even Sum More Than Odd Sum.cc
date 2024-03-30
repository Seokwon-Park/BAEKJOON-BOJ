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
		int even = 0;
		int odd = 0;
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			int m;
			cin >> m;
			if (m % 2)
			{
				odd += m;
			}
			else
			{
				even += m;
			}

		}
		if (even > odd)
			cout << "EVEN";
		else if (even < odd)
			cout << "ODD";
		else
			cout << "TIE";
		cout << '\n';
	}

	return 0;
}
