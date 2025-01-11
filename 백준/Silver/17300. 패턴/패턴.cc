#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

bool isUsed[10];

std::pair<bool, int> isIndirect[10][10];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	isIndirect[1][3] = { true,2 };
	isIndirect[1][9] = { true,5 };
	isIndirect[1][7] = { true,4 };
	isIndirect[2][8] = { true,5 };
	isIndirect[3][1] = { true,2 };
	isIndirect[3][7] = { true,5 };
	isIndirect[3][9] = { true,6 };
	isIndirect[4][6] = { true,5 };
	isIndirect[6][4] = { true,5 };
	isIndirect[7][1] = { true,4 };
	isIndirect[7][3] = { true,5 };
	isIndirect[7][9] = { true,8 };
	isIndirect[8][2] = { true,5 };
	isIndirect[9][1] = { true,5 };
	isIndirect[9][3] = { true,6 };
	isIndirect[9][7] = { true,8 };

	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	int cur = v[0];
	isUsed[cur] = true;
	for (int i = 1; i < n; i++)
	{
		// 연결할 선이 이미 사용중인 선이면
		if (true == isUsed[v[i]])
		{
			cout << "NO";
			return 0;
		}
		//바로 연결할 수 있는 선이 아닌경우
		if (isIndirect[cur][v[i]].first == true)
		{
			//그 중간에 있는 선이 사용중이 아니면 안댐
			if (false == isUsed[isIndirect[cur][v[i]].second])
			{
				cout << "NO";
				return 0;
			}
		}
		//다 통과하면 cur 갱신하고 사용여부 갱신
		cur = v[i];
		isUsed[v[i]] = true;
	}

	cout << "YES";

	return 0;
}