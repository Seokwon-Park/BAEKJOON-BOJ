#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int freq[10]; // 0~9;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n, d;
	cin >> n >> d;
	for (int i = 1; i <= n; i++)
	{
		int tmp = i;
		while (tmp)
		{
			freq[tmp % 10]++;
			tmp /= 10;
		}
	}
	cout << freq[d];

	return 0;
}