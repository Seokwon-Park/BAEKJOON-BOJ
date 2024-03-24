#include <bits/stdc++.h>

using namespace std;

using ll = long long;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int tc;
	cin >> tc;
	while (tc--)
	{
		int mn = INT_MAX;
		int sum = 0;
		for (int i = 0; i < 7; i++)
		{
			int input;
			cin >> input;
			if (input % 2 == 0)
			{
				sum += input;
				mn = min(mn, input);
			}
		}
		cout << sum << ' ' << mn << '\n';
	}

	return 0;
}
