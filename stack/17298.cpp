#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);	
			
	int n, num;
	cin >> n;
	stack<int> s;//index, tower height
	stack<int> answer;
	vector<int> input;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		input.push_back(num);
	}

	for (int i = 0; i <n; i++)
	{
		int tmp = input[n-1-i];
		while (!s.empty() && s.top() <= tmp)
		{			
			s.pop();
		}		

		if (s.empty())
		{
			answer.push(-1);
			s.push(tmp);
		}
		else
		{
			answer.push(s.top());
			s.push(tmp);
		}
	}

	while(!answer.empty())
	{
		cout << answer.top() << ' ';
		answer.pop();
	}
		

	return 0;
}
/*
역으로 생각하기
만약 3 5 2 7 이면
반대로 7 2 5 3이라는 입력이 들어온다고 생각한다.
stack이 empty인 경우 answer에 -1을 입력한다.
pop은 스택이 있을때만 while문을 실행하는데
stack.top() <= input인 경우에만 pop
아니면 input의 오른쪽에 있는 stack.top()이 크다는 뜻(입력값을 반대 순서로 적용했으므로)
pop을 해주는 이유는 만약 input보다 값이 작다면 어차피 오큰수가 될 수 없기 때문에

과정
stack s
answer stack as

s [7]
as [-1]

s [7, 2]
as [-1, 7]

s [7, 5]
as [-1, 7, 7]

s [7, 5, 3]
as [-1, 7, 7, 5]

as를 pop하면서 값을 출력하면 다시 역순으로 출력되므로 5, 7, 7, -1이 나온다.


*/
