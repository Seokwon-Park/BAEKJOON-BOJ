#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	stack<pair<int,int>> s;

	long long answer = 0;
	//long long 최악의 경우 같은 사람만 50만명 int -> overflow
	// 2명 = 1 / 3명 = 3 / 4명 = 6 / 5명 10 / 6명 15 ....
	int n;
	cin >> n;
		
	for (int i = 0; i < n; i++)
	{		
		int input;
		cin >> input;

		int equal_stack = 1;//키가 같은 사람일 경우에도 pop은 한다. 대신 연속된 수만큼 저장을 해준다.
		while(!s.empty() && input >= s.top().first)
		//일단 입력값인 input보다 작다면 이후의 사람들과는 쌍이 될수 없다는 뜻이므로
		//pop해준다.
		{			
			answer += s.top().second;//pop하기전 stack에 쌓인 count만큼 더해준다.(같은 값으 경우)
			if (input == s.top().first)//앞사람과 같은 키의 경우
			{			
				equal_stack += s.top().second;//이전의 같은 키의 사람이 몇명 서있다라는 것을 저장하기 위함
			}			
			s.pop();// 필요한 값을 다 기록했으므로 pop해준다.
		}
		if (!s.empty())answer++;
		//입력한 값이 top()보다 작아서 
		//pop이 발생하지 않았다. 즉 서로 볼 수 있는 쌍이다.
		//만약 붙어있지 않더라도 while문의 pop을 거쳐서 나왔기 때문에 top()과 사이에 있는 값이 
		//input보다 작다는 뜻이므로 서로 볼 수 있는 쌍이다.
		s.push({ input,equal_stack });
		//볼 수 있는쌍과 같은사람 수 값을 푸쉬한다.
	}
	cout << answer;
	return 0;
}

