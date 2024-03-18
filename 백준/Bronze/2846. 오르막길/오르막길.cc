#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vd = vector<double>;
using ll = long long;
using vll = vector<ll>;
template <typename T>
using vec = vector<T>;

vi t(1);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vi v(n);
	for (int& i : v)
	{
		cin >> i;
	}

	int h = v[0]; // 시작점의 높이를 기록
	int cur = 1; // 다음에 가야할 위치
	int upper = 0; // 얼마나 올라옴?
	int ans = INT_MIN; // 정답
	bool isupper = false;
	while (cur < v.size())
	{
		if (v[cur] > h) // 만약 다음 위치가 지금 위치보다 높아져야 오르막길이고
		{
			upper += v[cur] - h; // 그 높이 만큼 올라간다.
			h = v[cur]; // 도달한 높이를 갱신한다.
			isupper = true; // 오르막길이 있다는 것을 기록한다.
		}
		else // 만약 낮아지면? 이전에 오르막길이 있었다면 max값 갱신을 시도하고 없었다면 그냥 다른값만 초기화한다.
		{
			if (isupper)
			{
				ans = max(ans, upper);
			}
			h = v[cur];
			upper = 0;
		}
		cur++;
	}
	if (upper)
	{
		ans = max(ans, upper);
	}

	if (!isupper)
	{
		cout << 0;
	}
	else
	{
		cout << ans;
	}

	

	return 0;
}
