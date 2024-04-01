#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using bigint = vector<int>;

bigint fibo[10000];

const int base = 1e9;

bigint add(bigint s1, bigint s2)
{
	int n = max(s1.size(), s2.size());
	while (s1.size() < n)
		s1.push_back(0);
	while (s2.size() < n)
		s2.push_back(0);

	int carry = 0;
	bigint ret(n, 0);
	for (int i = 0; i < n; i++)
	{
		ll res = (ll)s1[i] + (ll)s2[i] + (ll)carry;
		ret[i] = res % base;
		carry = res / base;
	}
	if (carry)
	{
		ret.push_back(carry);
	}
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;

	fibo[0] = vector<int>(1, 0);
	fibo[1] = vector<int>(1, 1);

	for (int i = 2; i <= n; i++)
	{
		fibo[i] = add(fibo[i - 1], fibo[i - 2]);
	}

	for (int i= fibo[n].size()-1; i>= 0; i--)
	{
		if(i < fibo[n].size()-1)
			cout << setw(9) << setfill('0') << fibo[n][i];
		else
			cout << fibo[n][i];
	}

	return 0;
}