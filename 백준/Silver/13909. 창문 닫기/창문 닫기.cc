#include <bits/stdc++.h>

using namespace std;

int main()
{

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	int sqr_cnt = 0;
	for (int i = 1; i * i <= n; i++)
	{
		sqr_cnt++;
	}

	cout << sqr_cnt;

	return 0;
}