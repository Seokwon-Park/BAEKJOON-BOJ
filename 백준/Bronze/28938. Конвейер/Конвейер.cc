#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int res = 0;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		res += input;
	}

	if (res == 0)
		cout << "Stay";
	else if (res < 0)
		cout << "Left";
	else
		cout << "Right";

	return 0;
}