#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	string src, dst ;
	int mile;
	char code;
	int res = 0;
	while (true)
	{
		cin >> src;
		if (src == "0")
		{
			cout << res << '\n';
			res = 0;
			continue;
		}
		else if (src == "#")
		{
			break;
		}
		cin >> dst >> mile >> code;
		if (code == 'F')res += mile * 2;
		else if (code == 'B')
		{
			res += (int)(ceil((double)mile * 1.5));
		}
		else
		{
			if (mile <= 500)
			{
				res += 500;
			}
			else
			{
				res += mile;
			}
		}
		
			
	}


	

	return 0;
}