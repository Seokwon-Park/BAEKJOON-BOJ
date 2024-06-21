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

	while (1)
	{
		string s;
		getline(cin, s);
		if (s == "EOI") break;
		for (auto& c : s)
		{
			if (isalpha(c))
				c = tolower(c);
		}
		istringstream iss(s);
		string tmp;
		bool isFound = 0;
		while (getline(iss, tmp, ' '))
		{
			if (tmp.substr(0, 4) == "nemo")
				isFound = 1;
		}
		if (isFound)
			cout << "Found";
		else
			cout << "Missing";
		cout << '\n';
	}

	return 0;
}