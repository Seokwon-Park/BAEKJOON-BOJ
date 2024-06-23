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

	int tc = 1;
	while (1)
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

		if (v[1] == "E") break;
		int a = stoi(v[0]);
		int b = stoi(v[2]);

		cout << "Case " << tc++ << ": ";
		cout << boolalpha;
		if (v[1] == ">")
			cout << (a > b);
		else if (v[1] == ">=")
			cout << (a >= b);
		else if (v[1] == "<")
			cout << (a < b);
		else if (v[1] == "<=")
			cout << (a <= b);
		else if (v[1] == "==")
			cout << (a == b);
		else if (v[1] == "!=")
			cout << (a != b);
		cout << '\n';
	}

	return 0;
}