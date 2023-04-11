#include <bits/stdc++.h>

using namespace std;

int ans[500001];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);	
			
	int n, h;
	cin >> n;
	stack<pair<int, int>> s;//index, tower height

	s.push({ 0, -1 });
	for (int i = 1; i <= n; i++)
	{
		cin >> h;
		while (s.top().first != 0 && s.top().second < h)
		{			
			s.pop();
		}
		ans[i] = s.top().first;
		s.push({ i, h });		
	}

	for (int k = 1; k<= n; k++)
		cout << ans[k] << ' ';


	return 0;
}


