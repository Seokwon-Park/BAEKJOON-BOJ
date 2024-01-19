#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f

int dt[105][105]; // 티켓 쓰는 플로이드 워셜
int ndt[105][105]; // 티켓 안쓰는 플로이드 워셜

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, r;
	cin >> n >> r;
	unordered_map<string, int> cts;
	unordered_map<string, int> info; // 0: free, 1:50%, 2:no sale
	info["Mugunghwa"] = 0;
	info["ITX-Saemaeul"] = 0;
	info["ITX-Cheongchun"] = 0;

	info["S-Train"] = 1;
	info["V-Train"] = 1;

	info["Subway"] = 2;
	info["Bus"] = 2;
	info["Taxi"] = 2;
	info["Airplane"] = 2;
	info["KTX"] = 2;
	for (int i = 0; i <= n; i++)
	{
		fill(dt[i], dt[i] + n + 1, INF);
		fill(ndt[i], ndt[i] + n + 1, INF);
		dt[i][i] = 0;
		ndt[i][i] = 0;
	}
	for (int i = 1; i <= n; i++)
	{

		string city;
		cin >> city;
		cts[city] = i;
	}
	int m;
	cin >> m;
	vector<int> trip;
	for (int i = 0; i < m; i++)
	{
		string city;
		cin >> city;
		trip.push_back(cts[city]);
	}

	int k;
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		string train, cu, cv;
		int cost;
		cin >> train >> cu >> cv >> cost;
		int u = cts[cu], v = cts[cv];
		cost *= 2; // 나누기 2를 했을때 소숫점 자리를 처리하기 위해서 그냥 전체 코스트를 *2해준다.(티켓값도 *2 해야한다.)
		//티켓 샀을 때
		if (info[train] == 0)
			dt[u][v] = min(dt[u][v], 0);
		
		else if (info[train] == 1)
			dt[u][v] = min(dt[u][v], cost / 2);
		else
			dt[u][v] = min(dt[u][v],  cost);
		
		// 티켓 안 샀을 때
		ndt[u][v] = min(ndt[u][v], cost);

		dt[v][u] = dt[u][v];
		ndt[v][u] = ndt[u][v];
	}

	for (int i = 1; i <= n; i++)
		for (int s = 1; s <= n; s++)
			for (int t = 1; t <= n; t++)
			{
				dt[s][t] = min(dt[s][t], dt[s][i] + dt[i][t]);
				ndt[s][t] = min(ndt[s][t], ndt[s][i] + ndt[i][t]);
			}

	int cur = trip[0]; // 첫여행지를 시작 위치로 하자.
	int res = 0; // 티켓 쓴 결과 계산하고 티켓값을 더한다.
	int nres = 0; // 티켓 안쓴결과
	for (int i = 1; i < m; i ++)
	{
		res += dt[cur][trip[i]];
		nres += ndt[cur][trip[i]];
		cur = trip[i];
	}

	res += r*2;//티켓값을 더해준다. (50퍼센트 할인 때문에 2를 곱해야함)


	//cout << res << ' ' << nres;
	// 티켓을 사는 값이 저렴한 경우에만( 같은 경우에는 no)
	cout << (res < nres ? "Yes" : "No");

	return 0;
}