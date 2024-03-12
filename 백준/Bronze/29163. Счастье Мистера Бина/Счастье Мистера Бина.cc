#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	int odd = 0;
	int even = 0;
	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		if (input % 2 == 0)
			even++;
		else
			odd++;
	}

	if (even > odd)
		cout << "Happy";
	else
		cout << "Sad";

	return 0;
}