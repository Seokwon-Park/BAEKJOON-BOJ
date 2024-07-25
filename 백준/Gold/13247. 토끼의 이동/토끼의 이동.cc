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

	string s;
	int r;
	cin >> s >> r;
	int n = s.size();
	//int k = 1 << n - 1;

	vector<int> comb(n, 0);
	fill(comb.begin(), comb.begin() + r, 1);

	int t = 0;
	int rabbits = 0;
	do
	{
		vector<int> prev; // 'R' 칸을 처리하기 위해 이전상태 저장
		string tmp = s;
		vector<int> curc = comb;
		while (tmp.size() > 2)// 시뮬레이션
		{
			vector<int> res(tmp.size(), 0); // 시뮬레이션마다 결과 저장할 배열
			for (int i = 0; i < tmp.size(); i++)
			{
				if (curc[i] == 0) continue; // 이동할 토끼 없으면 skip
				if (i == 0) // 0번 칸은 무조건 오른쪽
				{
					res[i + 1] += curc[i];
				}
				else if (i == tmp.size() - 1 || i == tmp.size()-2) // size-1, size-2번 칸은 무조건 왼쪽으로
				{
					res[i - 1] += curc[i];
				}
				else if (tmp[i] == 'W')
				{
					res[i - 1] += curc[i];
				}
				else if (tmp[i] == 'B')
				{
					res[i + 1] += curc[i];
				}
				else
				{
					if (tmp.size() == n) // 한번도 이동한적 없는 상태.
						res[i - 1] += curc[i];
					else if (prev[i + 1] == 1) // 이전상태에서 'W'칸이 1이면 다시 오른쪽으로 이동
						res[i + 1] += curc[i];
					else if (prev[i - 1] == 1) // 이전상태에서 'B'칸이 1이면 다시 왼쪽으로 이동
						res[i - 1] += curc[i];
				}
			}
			for (int i = 0; i < tmp.size(); i++)
			{
				if (res[i] > 1) // 토끼가 한마리보다 많으면 제외한다.
					res[i] = 0;
			}
			prev = curc; // 현재 상태 저장
			curc = res; // 시뮬레이션 결과 저장
			tmp.pop_back();// 게임에서  오른쪽 칸 제거
		} // 시뮬레이션 끝
		rabbits += curc[0] + curc[1]; // 시뮬레이션 끝나면 2칸 남게 되기 때문에 이 값만 조사해서 더해준다.
		t++; // 조합 수 +1;
	} while (prev_permutation(comb.begin(), comb.end())); // 토끼가 위치할 수 있는 조합 

	cout << fixed;
	cout << setprecision(9);
	cout << (double)rabbits / (double)t; // 시뮬레이션에서 총 살아남은 토끼수 / 조합 가지 수

	return 0;
}