#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int n, k;
int arr[10005];
int swapped = 0;

void sort()
{
	for (int i = 1; i < n; i++)
	{
		int loc = i - 1;
		int temp = arr[i];

		while (0 <= loc && temp < arr[loc])
		{
			arr[loc + 1] = arr[loc];
			loc--;
			swapped++;
			if (swapped == k)
			{
				return;
			}
		}
		if (loc + 1 != i)
		{
			arr[loc + 1] = temp;
			swapped++;
			if (swapped == k)
			{
				return;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	sort();

	if (swapped == k)
	{
		for (int i = 0; i < n; i++)
		{
			cout << arr[i] << ' ';
		}
	}
	else
	{
		cout << -1;
	}

	return 0;
}



