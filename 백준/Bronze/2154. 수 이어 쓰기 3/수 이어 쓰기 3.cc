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
	
	string n;
	cin >> n;

	int ix = 1;
	int j = 0;
	int cur = 0;
	while(1)
	{
		string tmp = to_string(ix);
		for (int i = 0; i < tmp.size(); i++)
		{
			if (tmp[i] == n[j])
			{
				j++;
			}
			else
			{
				j = tmp[i] == n[0];
			}
			if (j == n.size())
			{
				cur += i+1;
				break;
			}
		}
		if (j == n.size())
		{
			cout << cur - (n.size() -1);
			return 0;
		}
		cur += tmp.size();
		ix++;
	}


	return 0;
}