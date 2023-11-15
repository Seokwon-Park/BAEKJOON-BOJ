#include <bits/stdc++.h>

using namespace std;

int main()
{

	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<int> vec(8);

	for (int i = 0; i < 8; i++)
	{
		cin >> vec[i];
	}
	if (is_sorted(vec.begin(), vec.end()))
	{
		cout << "ascending";
	}
	else if (is_sorted(vec.rbegin(), vec.rend()))
	{
		cout << "descending";
	}
	else
	{
		cout << "mixed";
	}

	return 0;
}