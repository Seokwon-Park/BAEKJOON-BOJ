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

	int n;
	cin >> n;
	cin.ignore();
	for (int i = 0; i < n; i++)
	{
		string s;
		getline(cin, s);
		for (auto& c : s)
		{
			c = tolower(c);
		}

		bool isPelin = true;
		for (int i = 0; i < s.size() / 2; i++)
		{
			if (s[i] != s[s.size() - 1 - i])
			{
				isPelin = false;
				break;
			}
		}
		cout << (isPelin ? "Yes" : "No") << '\n';
	}

	return 0;
}
