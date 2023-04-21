#include <bits/stdc++.h>

using namespace std;

long long POW(long long num, long long times)
{
	long long res = 1;

	for (int i = 0; i < times; i++)
	{
		res *= num;
	}

	return res;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	string n;
	int b;
	cin >> n >> b;
	long long res = 0;
	
	int len = n.length()-1;
	for (int i = 0; i < n.length(); i++)
	{
		long long mul = POW(b, i);
		if ((n[len - i] - 'A') < 0)
		{
			res += (n[len-i] - '0') * mul;
		}
		else
			res += (n[len-i] - 'A' + 10) *mul;
	}

	cout << res;

	return 0;
}
