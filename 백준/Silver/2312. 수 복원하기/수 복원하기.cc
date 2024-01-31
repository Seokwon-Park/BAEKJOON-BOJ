#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int tc;
	cin >> tc;
	while (tc--)
	{
		int n;
		cin >> n;
		vector<pair<int, int>> res;
		int tmp = n;
		for (int i = 2; tmp > 1; i++)
		{
			int cnt = 0;
			while (tmp % i == 0)
			{
				tmp /= i;
				cnt++;
			}
			if(cnt != 0)
				res.push_back({ i, cnt });
		}
		for (auto [num, cnt] : res)
		{
			cout << num << ' ' << cnt << '\n';
		}
		
	}

	return 0;
}
