#include<bits/stdc++.h>
using namespace std;

struct job{
	int pt;
	int at;
	int bt;
	int ct;
	int rt;
	int wt;
	int tat;
	bool cmp;
};


int check(struct job a[],int n,int time){
	int shortestBurst=INT_MAX;
	int shortestBurstIndex=-1;
	for(int i=0;i<n;i++){
	if(!a[i].cmp && a[i].at <= time){
		if(a[i].bt < shortestBurst){
			shortestBurst=a[i].bt;
			shortestBurstIndex=i;
		}
		}
	}
	return shortestBurstIndex;
}

void complete(struct job a[],int n){
	int currentTime=0;
	int time=0;
	int k=0;
	
	while(k<n){
	int shortestBurstIndex=check(a,n,time);
	if(shortestBurstIndex != -1){
		a[shortestBurstIndex].ct=currentTime+a[shortestBurstIndex].bt;
		a[shortestBurstIndex].tat=a[shortestBurstIndex].ct-a[shortestBurstIndex].at;
		a[shortestBurstIndex].wt=a[shortestBurstIndex].tat-a[shortestBurstIndex].bt;
		a[shortestBurstIndex].rt=a[shortestBurstIndex].wt;
		a[shortestBurstIndex].cmp=true;
		time=a[shortestBurstIndex].ct;
		currentTime=time;
		k=k+1;
		}
		else{
			time=time+1;
			currentTime=currentTime+1;
		}
	}
	
}

void print(struct job a[],int n){
	cout<<"P.T\t A.T\t B.T\t C.T\t T.A.T\t W.T\t R.T \n"; 
	for(int i=0;i<n;i++){
		cout<< a[i].pt <<" \t "<<a[i].at <<" \t "<< a[i].bt <<" \t "<< a[i].ct <<" \t "<< a[i].tat <<" \t "<< a[i].wt <<" \t "<< a[i].rt <<"\n"; 
	}
}

void avg(struct job a[],int n){
	int wtSum=0;
	int  tatSum=0;
	for(int i=0;i<n;i++){
		wtSum=wtSum+a[i].wt;
		tatSum=tatSum+a[i].tat;
	}
	float wtAvg=(float)wtSum/n;
	float tatAvg=(float)tatSum/n;
	cout<<"Average Waiting Time : "<<wtAvg<<"\n";
	cout<<"Average TurnAround Time : "<<tatAvg<<"\n";
}

int main(){
	int n;
	cout<<"Enter n : ";
	cin>>n;
	job a[n];
	cout<<"Enter Arrival Time : \n";
	for(int i=0;i<n;i++){
		cin>>a[i].at;
		a[i].pt=i+1;
		a[i].cmp=false;
	}
	cout<<"Enter Burst Time : \n";
	for(int i=0;i<n;i++){
		cin>>a[i].bt;
	}
	complete(a,n);
	print(a,n);
	avg(a,n);
	return 0;
}


