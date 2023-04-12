#include <bits/stdc++.h>

using namespace std;

long long answer;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);	
			
	int n, num;
	cin >> n;
	stack<int> s;//index, tower height
	vector<int> input;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		input.push_back(num);
	}

	for (int i = 0; i <n; i++)
	{
		int tmp = input[i];
		while (!s.empty() && s.top() <= tmp)
		{			
			s.pop();
		}		
		s.push(tmp);		
		answer += (int)s.size() - 1;
	}

	cout << answer;

	return 0;
}
/*
[10] 옥상을 볼 수 있는 건물 X : stack.size()-1 = 0
[10, 3] 높이 10에서 높이 3 옥상 보기 가능 : stack.size() - 1 = 1
[10, 7] 높이 10에서 높이 7의 옥상 보기 가능 : stack.size() - 1 = 1
[10, 7, 4] 높이 10에서 높이 4의 옥상 보기 가능(7의 옥상은 봤음), 높이 7에서 높이 4의 옥상보기 가능 : stack.size() - 1 = 2
[12] 옥상을 볼 수 있는 건물 X : stack.size() - 1 = 0
[12, 2] 높이 12에서 높이 2의 옥상 보기 가능 : stack.size() - 1 = 1
*/
