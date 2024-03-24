#include <bits/stdc++.h>

using namespace std;

using ll = long long;

vector<ll> factorial;
ll n;

bool func(ll m, int ed)
{
	if (m == n)
		return true;
	for (int i = ed; i >= 0; i--)
	{
		if (m + factorial[i] > n) continue;
		return func(m + factorial[i], i-1);
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n;
	if (n == 0)
	{
		cout << "NO";
		return 0;
	}
	ll st = 1;
	factorial.push_back(st);
	for (int i = 1; i <= 20 ; i++)
	{
		st *= i;
		factorial.push_back(st);
	}

	if (func(0, 20))
	{
		cout << "YES";
	}
	else
		cout << "NO";

	return 0;
}