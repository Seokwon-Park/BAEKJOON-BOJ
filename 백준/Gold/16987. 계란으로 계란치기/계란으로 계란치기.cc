#include <bits/stdc++.h>

using namespace std;

int max_v = INT_MIN;
int n;
vector<int> s, w;
bool breaked[8];

void func(int k) //가장 왼쪽의 계란
{
	if (k == n) // 손에 든 계란이 가장 오른쪽 계란인 경우
	{
		int cnt = 0;
		// 깨진 달걀 수를 센다.
		for (int j = 0; j < n; j++)
		{
			if (breaked[j]) 
				cnt++;
		}
		max_v = max(cnt, max_v);
		return;
	}
	if (breaked[k])
	{	
		func(k + 1);
		//손에 든 계란이 깨졌으면 그냥 다음 계란
		return;
	}

	bool can_hitable = false;
	for (int i = 0; i < n; i++)
	{
		if (i == k) continue;// 같은 계란에 대해서는 칠 수 없음
		if (breaked[i]) continue;// 이미 깨졌으면 칠 수 없음
		//칠 수 있는 경우 서로의 내구도를 깎는다.
		can_hitable = true;
		s[i] -= w[k]; 
		if (s[i] <= 0) breaked[i] = true; // 부딪혔는데 내구도가 0이하가 되면 깨졌다. 앞에서 이미 깨진 달걀은 걸렀기 때문에 이 조건만 있으면 됨.
		s[k] -= w[i];
		if (s[k] <= 0) breaked[k] = true;
		func(k + 1);
		s[i] += w[k];
		if (s[i] > 0 && breaked[i]) breaked[i] = false; // 깨진 달걀인데 부딪혔던 무게를 다시 더했을 때 양수면 안깨진걸로 복구
		s[k] += w[i];
		if (s[k] > 0 && breaked[k]) breaked[k] = false;
	}
	if (!can_hitable) func(k + 1); // 부딪힐 계란이 없으면 그냥 다음으로
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;


	for (int i = 0; i < n; i++)
	{
		int ss, ww;
		cin >> ss >> ww;
		s.push_back(ss);
		w.push_back(ww);
	}

	func(0);

	cout << max_v;

	return 0;
}