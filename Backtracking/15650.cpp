#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[10];
int isused[10];

void bt(int k)
{
	if (k == m)
	{
		for (int i = 0; i < m; i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		if (!isused[i])
		{
			if (k != 0)
			{
				if (arr[k - 1] < i)
				{
					arr[k] = i;
					isused[i] = 1;
					bt(k + 1);
					isused[i] = 0;
				}
			}
			else
			{
				arr[k] = i;
				isused[i] = 1;
				bt(k + 1);
				isused[i] = 0;
			}

		}

	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);				

	cin >> n >> m;
	
	bt(0);

	
	return 0;
}

