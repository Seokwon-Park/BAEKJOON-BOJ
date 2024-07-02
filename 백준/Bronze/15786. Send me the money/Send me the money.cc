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
	
	int n, m;
	cin >> n >> m;
	string ori;
	cin >> ori;
	for (int i = 0; i < m; i++)
	{
		string s;
		cin >> s;
		int oix = 0;
		bool isPoss = false;
		for (auto c : s)
		{
			if (c == ori[oix])
			{
				oix++;
			}
			if (oix == ori.size())
			{
				isPoss = true;
				break;
			}
		}
		if (isPoss)
			cout << "true";
		else
			cout << "false";
		cout << '\n';
	}


	return 0;
}