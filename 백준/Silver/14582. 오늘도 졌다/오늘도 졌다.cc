#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	vector<int> my(9), vs(9);

	for (int& i : my)
		cin >> i;

	for (int& i : vs)
		cin >> i;

	bool isWin = false;

	int mys = 0, vss = 0;
	for (int i = 0; i < 9; i++)
	{
		mys += my[i];
		if (mys > vss)
			isWin = true;
		vss += vs[i];
	}

	if (isWin)
	{
		cout << "Yes";
	}
	else
	{
		cout << "No";
	}

	return 0;
}