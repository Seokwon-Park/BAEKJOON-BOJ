#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	string s;
	cin >> s;

	string tmp = "";
	
	bool isVit = false;
	for (int i = 0; i < n; i++)
	{
		tmp += s[i];
		int diff = 0;
		for (int j = 0; j < tmp.size(); j++)
		{
			if (tmp[j] != s[s.size() - tmp.size() + j])
				diff++;
		}
		if (diff == 1)
		{
			isVit = true;
			break;
		}
	}

	if (isVit)
		cout << "YES";
	else
		cout << "NO";


	return 0;
}
