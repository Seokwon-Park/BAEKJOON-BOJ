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
		vector<int> v(5);
		int total = 0;
		for (int& i : v)
		{
			cin >> i;
			total += i;
		}
		sort(v.begin(), v.end());
		total -= (*v.begin() + *v.rbegin());
		if (abs(*(v.begin() + 1) - *(v.rbegin() + 1)) >= 4)
			cout << "KIN";
		else
			cout << total;
		cout << '\n';
	}

	return 0;
}