#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll gcd(ll a, ll b)
{
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;
	istringstream iss(s);
	vector<int> v;
	while (getline(iss, s, ':'))
	{
		v.push_back(stoi(s));
	}
	ll g = gcd(v[0], v[1]);

	cout << v[0] / g << ':' << v[1] / g;


	return 0;
}
