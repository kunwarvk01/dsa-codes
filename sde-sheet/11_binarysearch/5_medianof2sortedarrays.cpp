/*
   Problem Statement: Given two sorted arrays arr1 and arr2 of size m and n
   respectively, return the median of the two sorted arrays.

   <-- Naive Approach --> O(m+n) O(m+n)
   - merge both arrays in sorted order
   - calculate median.
 */
#include <bits/stdc++.h>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	int m=nums1.size(); int n=nums2.size();
	int finalArray[n+m];
	int i=0,j=0,k=0;
	while(i<m && j<n) {
		if(nums1[i]<nums2[j])
			finalArray[k++] = nums1[i++];
		else
			finalArray[k++] = nums2[j++];

	}
	if(i<m)
		while(i<m)
			finalArray[k++] = nums1[i++];
	if(j<n)
		while(j<n)
			finalArray[k++] = nums2[j++];

	n = n+m;
	if(n%2==1)
		return finalArray[((n+1)/2)-1];
	else return ((double)finalArray[(n/2)-1]+(double)finalArray[(n/2)])/2;
}

/*

   <-- Optimal Naive Approach --> O(m+n) O(1)
   Use a pointer to store the postion of median
   update position while checking the other array.

   <-- Efficient Approach --> O(log(min(m,n))) O(n)
   video solution
 */
double mediann(int num1[],int num2[],int m,int n) {
	if(m>n)
		return mediann(num2,num1,n,m); //ensuring that binary search happens on minimum size array

	int low=0,high=m,medianPos=((m+n)+1)/2;
	while(low<=high) {
		int cut1 = (low+high)>>1;
		int cut2 = medianPos - cut1;

		int l1 = (cut1 == 0)? INT_MIN:num1[cut1-1];
		int l2 = (cut2 == 0)? INT_MIN:num2[cut2-1];
		int r1 = (cut1 == m)? INT_MAX:num1[cut1];
		int r2 = (cut2 == n)? INT_MAX:num2[cut2];

		if(l1<=r2 && l2<=r1) {
			if((m+n)%2 != 0)
				return max(l1,l2);
			else
				return (max(l1,l2)+min(r1,r2))/2.0;
		}
		else if(l1>r2) high = cut1-1;
		else low = cut1+1;
	}
	return 0.0;
}

int main() {
	vector<int> nums1 = {1,4,7,10,12};
	vector<int> nums2 = {2,3,6,15};
	int m = sizeof(nums1)/sizeof(nums1[0]);
	int n = sizeof(nums2)/sizeof(nums2[0]);
	return 0;
}
