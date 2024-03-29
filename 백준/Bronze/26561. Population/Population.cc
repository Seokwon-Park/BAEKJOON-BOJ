#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		ll st;
		ll  d;
		cin >> st >> d;
		ll dead = d / 7;
		ll live = d / 4;
		cout << st - dead + live << '\n';
	}

	return 0;
}