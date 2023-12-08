#include <bits/stdc++.h>

using namespace std;


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	vector<int> ondo(n+1);
	
	int input;
	for (int i = 1; i <= n; i++)
	{
		cin >> input;
		ondo[i] += ondo[i-1]+input;		
	}

	int max = INT_MIN;
	for (int i = k; i <= n; i++)
	{
		if (max < ondo[i] - ondo[i - k])
		{
			max = ondo[i] - ondo[i - k];
		}
	}

	cout << max;
	
	return 0;
}