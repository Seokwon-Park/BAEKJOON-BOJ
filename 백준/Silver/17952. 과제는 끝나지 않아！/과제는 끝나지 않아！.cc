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
	int ans = 0;
	int a = 0, t = 0;
	stack<pair<int, int>> at;
	for (int i = 0; i < n; i++)
	{
		int cmd;
		cin >> cmd;
		if (cmd == 1)
		{
			if (a != 0 && t != 0) // 만약 이전에 하던 작업이 있으면
			{ 
				at.push({ a,t }); // 상태를 저장
			}
			cin >> a >> t;
		}
		else
		{
			if (t == 0) // 주어진 작업이 없는데 해야할 작업도 없으면
				if (!at.empty()) // 남은 작업이 있는지 확인
				{
					tie(a, t) = at.top(); // 꺼내옴
					at.pop();
				}
		}
		t--; // 작업 진행
		if (t == 0) // 0초면 작업 끝남.
		{
			ans += a; // 스코어 더해줌.
		}
	}

	cout << ans;

	return 0;
}