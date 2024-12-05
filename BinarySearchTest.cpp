#include<bits/stdc++.h>
#define eps 0.00001
using namespace std;
float bs(int n){
	float l=0, r=n;
	float mid;
	while(r-l>eps){
		mid=l+(r-l)/2;
		if(mid*mid<n)
		{
			
			l=mid;
		}
		else r=mid;	
		
	}
	return l+(r-l)/2;
}
int indexFind(int arr[], int n){
	int lo=0, hi=n-1, mid, ans;
	while(lo<=hi){
		mid=lo+(hi-lo)/2;
		if(mid==0 || arr[mid]>arr[mid-1]){
			ans=mid;
			lo=mid+1;
		}
		else if(arr[mid]<arr[mid-1])
			hi=mid-1;
	}
	return ans;
}
int upperBound(vll a, int x){
	int lo=0, hi=a.size()-1, mid, ans;
	while(lo<=hi){
		mid=lo+(hi-lo)/2;
		if(a[mid]>x){
			ans=mid;
			hi=mid-1;
		}
		else lo=mid+1;
	}
	return ans;
}
int lowerBound(vll a, int x){
	int lo=0, hi=a.size()-1, mid, ans;
	while(lo<=hi){
		mid=lo+(hi-lo)/2;
		if(a[mid]<x){
			ans=mid;
			lo=mid+1;
		}
		else hi=mid-1;
	}
	return ans;
}
int main(){
	
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	int index=indexFind(arr,n);
		cout<<index<<" "<<endl;
		//cout<<mid<<endl;
}
