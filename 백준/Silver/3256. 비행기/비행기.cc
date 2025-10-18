#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
//const int MOD = 1'000'000'007;
const int MOD = 987'654'321;
template <typename key, typename value>
using Hash = unordered_map<key, value>;

int load[1005];
int isused[1005];
int t;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	queue<int> q;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		q.push(x);
	}

	int left = 0;
	while (!q.empty() || left > 0)
	{
		if (!q.empty() && isused[1] == 0) // 1번행이 비어있으면
		{
			int x = q.front();
			q.pop();
			isused[1] = x;
			left++;
		}
		for (int i = 1000; i >= 1; i--)
		{
			if (isused[i] != 0)//사람이 서 있는 칸이면
			{
				if (isused[i] != i) // 자기 자리가 아닐때
				{
					if (isused[i + 1] == 0) // 다음칸이 비어있으면
					{
						isused[i + 1] = isused[i]; // 다음칸으로 보내
						isused[i] = 0;
					}
				}
				else //자기 자리면
				{
					//이미 짐을 싣고있나?
					if (load[i] > 0)
					{
						load[i]--;
						if (load[i] == 0) // 다실었으면 들어가
						{
							isused[i] = 0;
							left--;
						}
					}
					else // 짐을 안싣고 있어 그럼 시작해 5-1초 4
					{
						load[i] = 4;
					}
				}
			}
		}
		t++;
	}

	cout << t;

	return 0;
}
