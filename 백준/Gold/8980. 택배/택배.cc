// !정답 풀이를 보고 작성한 코드임.
#include <bits/stdc++.h>

#define INF 0x3f3f3f3f

using namespace std;

int truck[2005];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, maxw;
	cin >> n >> maxw;
	int m;
	cin >> m;

	vector<tuple<int, int, int>> edge;
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		edge.push_back(tie(a, b, c));
	}

	//도착 지점 기준 오름차순으로 정렬한다.
	sort(edge.begin(), edge.end(), [](const auto& a, const auto& b)
		{
			if (get<1>(a) == get<1>(b))
			{
				return get<0>(a) < get<0>(b);
			}
			return get<1>(a) < get<1>(b);

		});

	//for (int i = 0; i < m; i++)
	//{
	//	int a, b, c;
	//	tie(a, b, c) = edge[i];
	//	cout << a << ' ' << b << ' ' << c << '\n';
	//}

	int answer = 0;
	int cur = 1;
	int curw = 0;
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		tie(a, b, c) = edge[i];

		bool chk = true;
		//그러니까 이건 a->b 로 가는경로에 남은 트럭 용량의 최솟값을 구하는거임.
		for (int j = a; j < b; j++)
		{
			c = min(c, maxw - truck[j]); 
			// a에서 b까지 보낼 무게 vs j마을에서 실을 수 있는 무게 중 더 작은값.
			{
				if (!c) // 만약 0이면 maxw == truck[j] 
					//더이상 실을 공간이 없다는 뜻이 되면 이 택배는 무시한다.
					// 실을 공간이 남아있어도 실을 수 있음. 
				{
					chk = false;
					break;
				}
			}
		}
		if (chk) // 만약 실을 수 있다면.
		{
			answer += c; // 보낼 수 있는 무게 만큼 정답에 더해준다.
			for (int j = a; j < b; j++) truck[j] += c; // 그리고 a b 구간 사이에 트럭에 실려있는 무게 값을 c만큼 더해준다.
		}
	}

	cout << answer;

	return 0;
}