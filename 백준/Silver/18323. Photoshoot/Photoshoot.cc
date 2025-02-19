#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int n;
vector<int> ans;
int b[1005];
int isUsed[1005];



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n-1; i++)
	{
		cin >> b[i];
	}

	for (int start = 1; start <= n; start++)
	{
		ans.clear();
		fill(isUsed, isUsed + 1005, false);
		ans.push_back(start);
		isUsed[start] = true;
		bool isAns = true;
		for (int j = 0; j < n - 1; j++)
		{
			int next = b[j] - ans[j];
			if (next == ans[j] || next <=0 || isUsed[next] || next > n)
			{
				isAns = false;
				break;
			}
			ans.push_back(next);
		}
		if (isAns) break;
	}

	for (int i : ans)
	{
		cout << i << ' ';
	}
	

	return 0;
}



