#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
//에디토리얼 참고함.
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, q;
	cin >> n >> q;
	bool ans = 0;
	//주위에 있는 항목과 스왑 1번 할때마다 2로 나눈 나머지가 변한다.
	for (int i = 0; i < q; i++)
	{
		int cmd, a, b;
		cin >> cmd >> a >> b; // a -> b까지 스왑 (b-a)번,이렇게 하면 b의 위치는 b-1이기 때문에 a위치까지 (b-1-a)
		// 2*(b-a) -1은 짝수 - 1이기때문에 무조건 홀수 번 스왑하기 때문에 나머지가 변한다.
		if (cmd == 1)
		{
			ans = !ans;
		}
		else // a와 b 교환 a-1과 b-1 교환.. 이런식으로 생각하면
			// 구간 원소 개수 / 2 번의 교환이 일어난다 교환 한번마다 나머지가 바뀌는거 계산하기
		{
			
			int res = (b - a + 1) / 2;
			if (res % 2 == 1) ans = !ans;
		}
		cout << ans << '\n';
	}

	return 0;
}