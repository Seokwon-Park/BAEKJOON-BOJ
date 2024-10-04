#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--)
	{
		int n;
		cin >> n;
		queue<int> A, U, D, P;

		for (int i = 0; i < n; i++)
		{
			int m;
			cin >> m;
			A.push(m);
		}

		int x = 0;
		bool canSort = true;
		while (!A.empty())
		{

			//일단 값을 할당하는 과정
			int a = A.front();
			int d = D.empty() ? 0 : D.back();
			int p = P.empty() ? 0 : P.back();
			A.pop();
			if (a == x + 1)
			{
				x++;
			}
			else
			{
				if (a == d + 1)
					D.push(a);
				else if (a == p + 1)
					P.push(a);
				else if (d == 0)
					D.push(a);
				else if (p == 0)
					P.push(a);
				else
				{
					canSort = false;
					break;
				}
			}

			if(!D.empty() && D.front() == x + 1)
			{
				while (!D.empty())
				{
					x++;
					D.pop();
				}
			}
			else if (!P.empty() && P.front() == x+1)
			{
				while (!P.empty())
				{
					x++;
					P.pop();
				}
			}
		}
		if (!canSort)
		{
			cout << "NO\n";
		}
		else
		{
			cout << "YES\n";
		}
	}

	return 0;
}

