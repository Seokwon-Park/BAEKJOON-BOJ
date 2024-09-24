#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;

vector<ll> v;

void func(ll n)
{
	v.push_back(n);
	int en = n % 10;
	if (en == 0)return;
	for (int i = en - 1; i >= 0; i--)
	{
		func(n * 10 + i);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	
	for (int i = 0; i < 10; i++)
	{
		func(i);
	}
	sort(v.begin(), v.end());

	if (v.size() < n)
	{
		cout << -1;
	}
	else
	{
		cout << v[n - 1];
	}


	return 0;
}

