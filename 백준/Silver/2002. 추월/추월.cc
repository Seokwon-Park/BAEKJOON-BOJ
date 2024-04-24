#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	unordered_map<string, int> inn;
	vector<int> v;
	for (int i = 0; i < n; i++)
	{
		string s; 
		cin >> s;
		inn[s] = i;
	}
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		v.push_back(inn[s]);
	}	
	
	int ans = 0;
	for (int i = 0; i < n-1; i++) 
	{
		for (int j = i + 1; j < n; j++)
		{
			if (v[i] > v[j]) 
				// 만약 i 번째로 빠져나온 차량이 들어간 순서가 v[i]일 때
				// i보다 나중에 빠져나온 차량 중에 더 빨리 들어간 순서v[j]가 더 작으면
				// i는 추월을 했다는 뜻이다.
			{
				ans++;
				break;
			}
		}
	}
	cout << ans;

	return 0;
}
