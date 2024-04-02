#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	while (n--)
	{
		string m;
		cin >> m;
		if ((*m.rbegin()- '0') % 2)
			cout << "odd";
		else
			cout << "even";
		cout << '\n';
	}
	
	return 0;
}