/*
    Problem Statement: We are given two arrays that represent the arrival and departure times of
    trains that stop at the platform. We need to find the minimum number of platforms needed at
    the railway station so that no train has to wait.

    Input: N=6,
    arr[] = {9:00, 9:45, 9:55, 11:00, 15:00, 18:00}
    dep[] = {9:20, 12:00, 11:30, 11:50, 19:00, 20:00}
    Output:3

    <-- Brute Force --> O(n^2) O(1)
    nested for loops
    - calculate overlap for each train. store to count
    - update maxcount
    - return maxcount
 */


#include <bits/stdc++.h>
using namespace std;

int countPlatforms(int n,int arr[],int dep[])
{
	int ans=1; //final value
	for(int i=0; i<n; i++)
	{
		int count=1; // count of overlapping interval of only this iteration
		for(int j=i+1; j<n; j++)
			if((arr[i]>=arr[j] && arr[i]<=dep[j]) ||
			   (arr[j]>=arr[i] && arr[j]<=dep[i]))
				count++;
		ans=max(ans,count); //updating the value
	}
	return ans;
}

/*
    <-- Better Approach --> O(nlogn) O(1)
    SORTING
    - sort both the arrays
    - if(arr[i]<=dep[j]) count++ i++;
    - else count-- j++;
 */

int countPlatformss(int n,int arr[],int dep[])
{
	sort(arr,arr+n);
	sort(dep,dep+n);

	int ans=1, count=1, i=1, j=0;
	while(i<n && j<n)
	{
		if(arr[i]<=dep[j]) { //one more platform needed
			count++;
			i++;
		}
		else {//one platform can be reduced
			count--;
			j++;
		}
		ans=max(ans,count); //updating the value with the current maximum
	}
	return ans;
}
