#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int res = 0;
	for (int i = 0; i < 6; i++)
	{
		int input;
		cin >> input;
		res += input * 5;
	}
	cout << res;

	return 0;
}