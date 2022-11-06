/*
    Problem Statement: There is one meeting room in a firm. You are given two arrays, start and
    end each of size N.For an index ‘i’, start[i] denotes the starting time of the ith meeting
    while end[i]  will denote the ending time of the ith meeting. Find the maximum number of
    meetings that can be accommodated if only one meeting can happen in the room at a  particular
    time. Print the order in which these meetings will be performed.

    Input:  N = 6,  start[] = {1,3,0,5,8,5}, end[] =  {2,4,5,7,9,9}
    Output: 1 2 4 5

    <-- Brute Force --> O() O()
    Choose meetings that end early
    - sort start, end, pos
    - ans={1} (first meeting will always be performed), int limit to track end time of last meeting
    - if (start[i]>limit) push pos[i] to answer and update limit=end[i];
    - return ans;
 */


#include <bits/stdc++.h>
using namespace std;
struct meeting {
	int start;
	int end;
	int pos;
};

bool static comparator(struct meeting m1, meeting m2) {
	if (m1.end < m2.end) return true;
	else if (m1.end > m2.end) return false;
	else if (m1.pos < m2.pos) return true;
	return false;
}

void maxMeetings(int s[], int e[], int n) {
	struct meeting meet[n];
	for (int i = 0; i < n; i++) {
		meet[i].start = s[i], meet[i].end = e[i], meet[i].pos = i + 1;
	}

	sort(meet, meet + n, comparator);

	vector < int > answer;

	int limit = meet[0].end;
	answer.push_back(meet[0].pos);

	for (int i = 1; i < n; i++) {
		if (meet[i].start > limit) {
			limit = meet[i].end;
			answer.push_back(meet[i].pos);
		}
	}
	cout<<"The order in which the meetings will be performed is "<<endl;
	for (int i = 0; i < (int)answer.size(); i++) {
		cout << answer[i] << " ";
	}

}

int main() {
	int n = 6;
	int start[] = {1,3,0,5,8,5};
	int end[] = {2,4,5,7,9,9};
	maxMeetings(start, end, n);
	return 0;
}
