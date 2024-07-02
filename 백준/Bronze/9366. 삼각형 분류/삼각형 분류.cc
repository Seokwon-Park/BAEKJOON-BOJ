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

	int tc;
	cin >> tc;
	for(int i = 1 ;i<= tc; i++)
	{
		vector<int> v(3);
		cin >> v[0] >> v[1] >> v[2];

		sort(v.begin(), v.end());
		cout << "Case #" << i << ": ";
		if (v[2] >= v[0] + v[1])
			cout << "invalid!";
		else
			if (v[1] == v[2] && v[0] == v[1])
			{
				cout << "equilateral";
			}
			else if (v[0] == v[1] || v[1] == v[2])
			{
				cout << "isosceles";
			}
			else
			{
				cout << "scalene";
			}
		cout << '\n';
		
	}
	
	return 0; 
}