#include<bits/stdc++.h>
using namespace std;

bool isPrime[10005];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int tc;
	cin >> tc;

	fill(isPrime, isPrime + 10005, true);

	isPrime[1] = false;
	for (int i = 2; i*i <= 10001; i++)
	{
		if (!isPrime[i]) continue;
		for (int j = i * i; j <= 10001; j += i)
		{
			isPrime[j] = false;
		}
	}

	while (tc--)
	{
		int n;
		cin >> n;
		for (int i = n/2; i >= 2; i--)
		{
			if (isPrime[i])
			{
				if (isPrime[n - i])
				{
					cout << i << ' ' << n - i << '\n';
					break;
				}
			}
		}
	}

	

	return 0;
}
