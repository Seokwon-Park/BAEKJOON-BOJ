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

	int n;
	cin >> n;

	vector<int> pieces(3, 0);
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		if (s == "1/2")
			pieces[1]++;
		else if (s == "1/4")
			pieces[0]++;
		else
			pieces[2]++;
	}
	// 일단 3/4랑 같이 먹을 수 있는건 1/4밖에 없어서 이녀석을 먼저 검사한다.
	// 근데 생각을 해보자 일단 3/4피스는 무조건 1자리를 먹어야 된다.
	ans += pieces[2]; // 3/4 + 1/4
	if (pieces[2] < pieces[0])
	{
		pieces[0] -= pieces[2];
	}
	else
	{
		pieces[0] = 0;
	}

	//1/2pieces는 2조각을 1조각으로 합칠 수 있다. 일단 얘네로 1판을 만들 ㅅ ㅜ있는 만큼 만든다.
	ans += pieces[1] / 2; // 1/2 + 1/2

	// 그럼 1조각 또는 0조각이 남을 것이다.
	pieces[1] %= 2;

	// 그럼 걍 더해서 4로 나누고 나머지 여부에 따라 1을 더해준다.
	int left = pieces[0] + pieces[1] * 2;

	ans += left / 4 + (left % 4 != 0 ? 1 : 0);

	cout << ans;

	return 0;
}
