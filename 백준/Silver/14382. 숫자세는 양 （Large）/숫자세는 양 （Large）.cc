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
	for(int i = 1; i<= tc; i++)
	{
		int n;
		cin >> n;
		cout << "Case #" << i << ": ";
		if (n == 0)
		{
			cout << "INSOMNIA\n";
			continue;
		}
		int j = 0;
		vector<bool> nums(10, false);
		while (++j)
		{
			int tmp = n * j;
			while (tmp)
			{
				nums[tmp % 10] = true;
				tmp /= 10;
			}
			if (count(nums.begin(), nums.end(), true) == 10)
			{
				cout << n*j;
				break;	
			}
		}
		cout << '\n';
	}

	return 0;
}

