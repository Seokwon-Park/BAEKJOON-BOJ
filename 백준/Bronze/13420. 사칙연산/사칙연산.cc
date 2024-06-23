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

	int tc;
	cin >> tc;
	cin.ignore();
	while (tc--)
	{
		string s;
		getline(cin, s);
		istringstream iss(s);
		string ss;
		vector<string> v;
		while (getline(iss, ss, ' '))
		{
			v.push_back(ss);
		}

		ll a = stoll(v[0]);
		ll b = stoll(v[2]);
		ll c = stoll(v[4]);
		ll res = 0;
		if (v[1] == "+")
			res = a + b;
		else if (v[1] == "-")
			res = a - b;
		else if (v[1] == "*")
			res = a * b;
		else
			res = a / b;
		if (res == c)
			cout << "correct";
		else
			cout << "wrong answer";
		cout << '\n';
	}

	return 0;
}