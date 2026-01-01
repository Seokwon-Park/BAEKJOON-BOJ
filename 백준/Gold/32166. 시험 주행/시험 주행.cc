#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
//const int MOD = 987'654'321;
template <typename key, typename value>
using Hash = unordered_map<key, value>;

double dist(pii p1, pii p2)
{
	int xd = p1.first - p2.first;
	int yd = p1.second - p2.second;
	return sqrt(xd * xd + yd * yd);
}



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	vector<pii> p(3);
	vector<double> v(3);
	vector<double> d(3);
	vector<int> w(3);
	for (int i = 0; i < 3; i++)
	{
		int x, y;
		cin >> x >> y >> v[i];
		p[i] = { x,y };
	}

	for (int i = 0; i < 3; i++)
	{
		cin >> w[i];
	}

	for (int i = 0; i < 3; i++)
	{
		d[i] = dist(p[i], p[(i + 1)%3]);
	}

	vector<double> ans(3, 0);
	for (int i = 0; i < 3; i++)
	{
		if (v[i] == 0) continue;
		int nxt = (i + 1) % 3;
		int nnxt = (i + 2) % 3;
		double tcur = d[i] / v[i]; // 내 구간에서는 내가 내 속도대로 감
		if (v[nxt] != 0) // 다음 정점에 출발할 차량이 있으면
		{
			double tnxt = d[nxt] / v[nxt]; 
			tcur += d[nxt] / v[i];
			if (tcur <= tnxt) //만약 d[nxt] 구간에서 내가 얘를 따라잡았을때 
			{
				if (w[nxt] == 1) //1차선 도로면
				{
					tcur = tnxt; // p[nxt]의 차량과 같은 속도로 도착한다.
				}
				// 그럼 이제 이후에는 d[nnxt]는 이미 추월을 했기때문에 그냥 가면된다.
				tcur += d[nnxt] / v[i];
			}
			else // 따라잡지 못했으면
			{
				// 일단 d[nxt]는 자기속도로 달린 상태고 nnxt에서 만날 가능성이 있음
				tnxt += d[nnxt] / v[nxt];
				tcur += d[nnxt] / v[i];

				if (tcur <= tnxt) //만약 d[nnxt] 구간에서 내가 얘를 따라잡았을때 
				{
					if (w[nnxt] == 1) //1차선 도로면
					{
						tcur = tnxt; // p[nxt]의 차량과 같은 속도로 도착한다.
					}
				}
			}
		
		}
		else // 다음 정점이 아니면 다다음 정점에 차량이 있다는 것
		{
			//그럼 다음정점의 도로도 내 속도대로 감
			tcur += d[nxt] / v[i];
			double tnxt = d[nnxt] / v[nnxt]; // 얘는 그동안 다 갔을수도 있고 안갔을수도 있어
			tcur += d[nnxt] / v[i];
			if (tcur <= tnxt) // 내가 한바퀴를 돈시간이 nnxt에서 출발해서 다음정점에 가는 시간보다 짧아야함 
			{
				if (w[nnxt] == 1) //1차선 도로면 추월이 안돼
				{
					tcur = tnxt; // p[nxt]의 차량과 같은 속도로 도착한다.
				}
			}

		}
		ans[i] = tcur;
	}

	for (auto i : ans)
	{
		if (i == 0)
		{
			cout << "-\n";
		}
		else
		{
			cout << fixed << setprecision(6) << i << '\n';
		}
	}

	return 0;
}
