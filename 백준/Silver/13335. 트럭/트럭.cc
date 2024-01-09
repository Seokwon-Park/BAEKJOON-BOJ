#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, w, l;
	cin >> n >> w >> l;

	vector<int> trucks(n);
	for (int i = n - 1; i >= 0; i--)
	{
		cin >> trucks[i];
	}
	queue<int> q;

	for (int i = 0; i < w; i++)
	{
		q.push(0);
	}

	int cur_w = 0;

	int t = 0;
	int finished = 0;
	int nxt_truck = trucks.back();
	while (finished < n) //끝난 트럭이 아직 n대 미만임?
	{
		t++; // 그래도 시간은 간다.
		if (q.front() != 0) // 트럭 내릴 차례임?
		{
			cur_w -= q.front(); // 다리하중 다시 돌려주삼 ㅋ
			finished++; // 끝난 트럭 하나 추가
		}
		q.pop(); // 트럭이던 공기던 일단 뺌 ㅋ
		if (cur_w + nxt_truck <= l) //다음 트럭 다리에 올라갈 수 ㅣㅇㅆ음?
		{//ㅇㅇ
			cur_w += nxt_truck;
			q.push(nxt_truck);
			trucks.pop_back();
			if (trucks.empty())
			{
				t += w;
				break;
			}
			if (!trucks.empty())
			{
				nxt_truck = trucks.back();
			}
		}
		else // ㄴㄴ
		{
			q.push(0);
		}
	}

	cout << t;


	return 0;
}