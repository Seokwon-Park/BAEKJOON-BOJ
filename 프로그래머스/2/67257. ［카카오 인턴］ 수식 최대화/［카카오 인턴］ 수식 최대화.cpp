#include <bits/stdc++.h>

using namespace std;

vector<long long> split(string str)
{
    istringstream iss(str);
    string s;

    vector<long long> nums;

    while (getline(iss, s, ' '))
    {
        nums.push_back(stoll(s));
    }

    return nums;
}

long long solution(string expression) {
    long long answer = 0;

    set<char> op;
    string splitstr = "";
    string originop = "";

    for (char c : expression)
    {
        string num;
        if (!isdigit(c))
        {
            op.insert(c);
            splitstr += ' ';
            originop += c;
        }
        else
        {
            splitstr += c;
        }
    }
    vector<long long> origin = split(splitstr);

    string ops(op.begin(), op.end());

    long long max_val = INT_MIN;

    do {
        string opstring = originop;
        vector<long long> nums = origin;

        for (int i = 0; i < ops.length(); i++)
        {
            for (int j = 0; j < opstring.size();)
            {
                if (opstring[j] == ops[i])
                {
                    if (opstring[j] == '*')
                    {
                        long long a = nums[j] * nums[j + 1];
                        nums.erase(nums.begin() + j, nums.begin() + j + 2);
                        opstring.erase(opstring.begin() + j, opstring.begin() + j + 1);
                        nums.insert(nums.begin() + j, a);
                    }
                    else if (opstring[j] == '-')
                    {
                        long long a = nums[j] - nums[j + 1];
                        nums.erase(nums.begin() + j, nums.begin() + j + 2);
                        opstring.erase(opstring.begin() + j, opstring.begin() + j + 1);
                        nums.insert(nums.begin() + j, a);
                    }
                    else if (opstring[j] == '+')
                    {
                        long long a = nums[j] + nums[j + 1];
                        nums.erase(nums.begin() + j, nums.begin() + j + 2);
                        opstring.erase(opstring.begin() + j, opstring.begin() + j + 1);
                        nums.insert(nums.begin() + j, a);
                    }
                }
                else
                {
                    j++;
                }
            }
        }
        if (abs(nums[0]) > max_val)
            max_val = abs(nums[0]);
    } while (next_permutation(ops.begin(), ops.end()));


    return max_val;
}