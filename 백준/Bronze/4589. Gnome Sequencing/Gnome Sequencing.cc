#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> v(3);
	cout << "Gnomes:\n";
	while (n--)
	{
		for (int i = 0; i < 3; i++)
		{
			cin >> v[i];
		}
		bool isLeSorted = true;
		for (int i = 0; i < 2; i++)
		{
			if (v[i] > v[i + 1])
			{
				isLeSorted = false;
				break;
			}
		}
		bool isGrSorted = true;
		for (int i = 0; i < 2; i++)
		{
			if (v[i] < v[i + 1])
			{
				isGrSorted = false;
				break;
			}
		}
		if (isLeSorted || isGrSorted)
			cout << "Ordered\n";
		else
			cout << "Unordered\n";
	}


	return 0;
}