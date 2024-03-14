#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	int cnt = 0;
	for (int i = 0; i < 5; i++)
	{
		int num;
		cin >> num;
		if (num == n) cnt++;
	}
	cout << cnt;
	return 0;
}