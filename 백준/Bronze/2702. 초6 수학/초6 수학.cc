#include<iostream>
#include<string>

using namespace std;

using ll = long long;

ll gcd(ll a, ll b)
{
	while (b != 0)
	{
		int tmp = b;
		b = a % b;
		a = tmp;
	}
	return a;
}

ll lcm(ll a, ll b)
{
	return a / gcd(a, b) * b;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--)
	{
		int a, b;
		cin >> a >> b;
		cout << lcm(a, b) << ' '<< gcd(a, b) << '\n';
	}
	
	return 0;
}