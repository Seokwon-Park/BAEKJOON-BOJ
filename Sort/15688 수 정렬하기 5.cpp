#include <bits/stdc++.h>

using namespace std;

// Counting sort

int arr[2000002];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, input;
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{		
		cin >> input;
		arr[input + 1000000]++;
	}

	for(int i = 0; i< 2000002; i++)
	{
		if (arr[i] == 0) 
			continue;
		else
		{
			for (int j = 0; j < arr[i]; j++)
			{
				cout << i - 1000000 << '\n';
			}
		}
	}

	return 0;
}
