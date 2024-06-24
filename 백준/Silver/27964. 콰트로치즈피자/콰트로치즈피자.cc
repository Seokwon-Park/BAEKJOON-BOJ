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
	
	set<string> cheese;

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		if (s.size() < 6) continue;
		else
		{
			string chk = s.substr(s.size() - 6);
			if (chk == "Cheese")
				cheese.insert(s);
		}
	}

	if (cheese.size() >= 4)
		cout << "yummy";
	else
		cout << "sad";

	return 0;
}