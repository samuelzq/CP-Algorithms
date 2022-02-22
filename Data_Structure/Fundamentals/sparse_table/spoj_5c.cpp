/**
 * Codeforces - Longest Regular Bracket Sequence
 * http://codeforces.com/contest/5/problem/C
 * https://vjudge.net/problem/CodeForces-5C
 *
 * @File:   spoj_5c.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-02-23
 *
 **/
#include <bits/stdc++.h>

using namespace std;

stack<char> st;
int mlen = 0, cnt = 0;

int main(void)
{
	string str;
	int l = 0;

	cin >> str;

	for (int i = 0; i < str.size(); i++) {
		char c = str[i];
		if (c == '(') {
			if (!st.empty()) {
				if (l == mlen)
					cnt++;
				else if (l > mlen) {
					cnt = 1;
					mlen = l;
				}
			}
			st.push(c);
		} else if (c == ')') {
			if (st.empty()) {
				l = 0;
				continue;
			} else {
				l++;
				st.pop();
				if (st.empty()) {
					if (l == mlen)
						cnt++;
					else if (l > mlen) {
						cnt = 1;
						mlen = l;
					}
					l = 0;
				} else {
					if (i + 1 == str.size()) {
						if (l == mlen)
							cnt++;
						else if (l > mlen) {
							cnt = 1;
							mlen = l;
						}
						l = 0;
					}
				}
			}
		} else
			break;
	}
	if (mlen == 0)
		cnt = 1;
	cout << mlen * 2 << ' ' << cnt << '\n';
	return 0;
}
