#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	vector<bool> isPrime(n + 5, true);
	
	for (int i = 2; i * i <= n; i++)
	{
		if (!isPrime[i]) continue;
		for(int j = i*i; j <= n; j+=i)
		{
			isPrime[j] = false;
		}
	}

	int cnt = 0;
	vector<bool> isSejun(n + 1, true);
	for (int i = 2; i <= n; i++)
	{
		if(isPrime[i] && i >k)
			for (int j = i; j <= n; j += i)
			{
				isSejun[j] = false;
			}
	}

	cout << count(isSejun.begin(), isSejun.end(), true)-1;



	//x = 2^3 * 3^1 * ....

	return 0;
}