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
	
	int n, k;
	cin >> n >> k;

	vector<vector<int>> v;
	for (int i = 0; i < k; i++)
	{
		int num, sr, sc, tr, tc;
		cin >> num >> tr >> tc;
		//어떤 X 숫자의 기본 좌표 (x-1)/3+1 (x-1)%3+1
		sr = (num - 1) / n + 1;
		sc = (num - 1) % n + 1;

		v.push_back({ sr, sc, tr,tc, num });
	}

	for (int i = 0; i < k; i++)
	{
		vector<int> cmd = v[i];
		int cmove = cmd[1] <= cmd[3] ? cmd[3] - cmd[1] : cmd[3] - cmd[1] + n;
		int rmove = cmd[0] <= cmd[2] ? cmd[2] - cmd[0] : cmd[2] - cmd[0] + n;
		
		for (int j = 0; j < k; j++)
		{
			if (v[i][0] == v[j][0])
			{
				v[j][1] = (v[j][1] - 1 + cmove) % n + 1;
			}
		}
		for (int j = 0; j < k; j++)
		{
			if (v[i][1] == v[j][1])
			{
				v[j][0] = (v[j][0] - 1 + rmove) % n + 1;
			}
		}

		cout << rmove + cmove << '\n';
	}


	return 0;
}