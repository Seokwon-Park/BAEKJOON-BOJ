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

	string n;
	ll real = 0;
	ll dot = 0;
	while (cin >> n)
	{
		istringstream iss(n);
		string s;
		vector<ll> v;
		while(getline(iss, s, '.'))
		{
			v.push_back(stoll(s));
		}
		real += v[0];
		dot += v[1];
	}
	real += dot / 100;
	dot %= 100;
	cout << real << '.' <<setw(2) << setfill('0') <<  dot;



	return 0;
}