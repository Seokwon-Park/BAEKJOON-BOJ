#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int a, b;
int aa[11], bb[11];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 0; i < 18; i++)
	{
		int n;
		cin >> n;
		a += n;
		aa[n]++;
	}

	for (int i = 0; i < 18; i++)
	{
		int n;
		cin >> n;
		b += n;
		bb[n]++;
	}

	if (a > b)
	{
		cout << "Algosia";
	}
	else if (a < b)
	{
		cout << "Bajtek";
	}
	else
	{
		for (int i = 10; i >= 0; i--)
		{
			if (aa[i] > bb[i])
			{
				cout << "Algosia";
				return 0;
			}
			else if (aa[i] < bb[i])
			{
				cout << "Bajtek";
				return 0;
			}
		}
		cout << "remis";
	}

	return 0;
}