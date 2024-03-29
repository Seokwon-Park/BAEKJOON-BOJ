#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	for(int i =1; i<=tc; i++)
	{
		int n;
		cin >> n;
		cout << "Case #" << i << ": ";
		if (n <= 25)
			cout << "World Finals";
		else if (n <= 1000)
			cout << "Round 3";
		else if (n <= 4500)
			cout << "Round 2";
		else
			cout << "Round 1";
		cout << '\n';
	}

	return 0;
}