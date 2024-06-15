#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;

void printRoom(vector<pair<int, string>>& room)
{
	for (auto [lv, name] : room)
	{
		cout << lv << ' ' << name << '\n';
	}
}

int findRoom(vector<vector<pair<int, string>>>& rooms, int max_size, int lv)
{
	// 들어갈 수 있는 방을 찾는다
	for (int i = 0; i < rooms.size(); i++) 
	{
		if (rooms[i].size() == max_size) continue;
		if (abs(rooms[i][0].first - lv) > 10) continue;
		return i;
	}
	// 들어갈 수 있는 방이 없으면 새로운 방을 생성한다.
	vector<pair<int, string>> newRoom;
	rooms.push_back(newRoom);
	return rooms.size()-1; // 생성된 방의 인덱스를 반환한다.
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int p, m;
	cin >> p >> m;
	vector<vector<pair<int, string>>> rooms;
	queue<pair<int, string>> waitList;
	for (int i = 0; i < p; i++)
	{
		int lv;
		string name;
		cin >> lv >> name;
		waitList.push({ lv,name });
	}

	while(!waitList.empty())
	{
		auto [lv, name] = waitList.front();
		waitList.pop();
		int ix = findRoom(rooms, m, lv);
		rooms[ix].push_back({ lv, name });
	}

	for (int i = 0; i < rooms.size(); i++)
	{
		if (rooms[i].size() == m)
			cout << "Started!";
		else
			cout << "Waiting!";
		cout << '\n';
		sort(rooms[i].begin(), rooms[i].end(), [](auto& a, auto& b)
			{
				return a.second < b.second;
			});
		printRoom(rooms[i]);
	}

	return 0;
}
