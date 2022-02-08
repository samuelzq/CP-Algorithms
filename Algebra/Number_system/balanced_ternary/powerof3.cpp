/**
 * Topcoder SRM 604, Div1-250
 * https://community.topcoder.com/stat?c=problem_statement&pm=12917&rd=15837
 * https://vjudge.net/problem/TopCoder-12917
 *
 * @File:   powerof3.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-02-08
 *
 **/
#include <bits/stdc++.h>

using namespace std;

class PowerOfThree
{
public:
	int f[30];
	void cal(int x)
	{
		int t = abs(x);
		for (int i = 0; t; i++) {
			int tmp = t % 3;
			if (tmp != 0)
				f[i]++;
			if (tmp == 2)
				t++;
			if (tmp == 1)
				t--;
			t /= 3;
		}
	}

	string ableToGet(int x, int y)
	{
		memset(f, 0, sizeof(f));
		cal(x);
		cal(y);
		
		bool isend = 0;
		for(int i = 0; i < 21; i++) {
			if(f[i] == 0)
				isend = 1;
			if((isend && f[i] > 0) || f[i] > 1)
				return "Impossible";
		}
		return "Possible";
	}
};
