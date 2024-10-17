#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

//둘로 나눈다는 거에서 2진법과 관련이 있다?를 생각했어야 했나...
//최소로 만드려면 depth의 끝부분이 반드시 1이어야 하죠.

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
		int maxDepth = 0;
		if (s == "")
		{
			cout << 1 << '\n';
		}
		else
		{
			int curdepth = 0;
			for (auto c : s)
			{
				if (c == '[')
				{
					curdepth++;
					maxDepth = max(maxDepth, curdepth);
				}
				else
				{
					curdepth--;
				}
			}
			cout << (1 << maxDepth) << '\n';
		}

	}

	return 0;
}