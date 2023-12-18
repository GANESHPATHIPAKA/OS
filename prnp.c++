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
	int cmp;
	int priority;
};

int checkZero(struct job a[],int n,int currentTime){
	int shortestPriority=INT_MAX;
	int shortestPriorityIndex=-1;
	for(int i=0;i<n;i++){
		if(!a[i].cmp && a[i].priority <=shortestPriority && a[i].at<=currentTime){
			shortestPriority=a[i].priority;
			shortestPriorityIndex=i;
		}
	}
	return shortestPriorityIndex;
}
int check(struct job a[],int n){
	int shortestPriority=INT_MAX;
	int shortestPriorityIndex=-1;
	int arrivalCheck=INT_MAX;
	for(int i=0;i<n;i++){
		if(!a[i].cmp && a[i].priority <= shortestPriority){
			if(a[i].priority == shortestPriority){
				if(arrivalCheck>a[i].at){
					arrivalCheck=a[i].at;
					shortestPriority=a[i].priority;
					shortestPriorityIndex=i;
				}
				else{
					continue;
				}
			}
			else{
			arrivalCheck=a[i].at;
			shortestPriority=a[i].priority;
			shortestPriorityIndex=i;
			}
			
		}
	}
	return shortestPriorityIndex;
}

void complete(struct job a[],int n){
	int currentTime=0;
	
	for(int i=0;i<n;i++){
	int shortestPriorityIndex=checkZero(a,n,currentTime);
	if(shortestPriorityIndex==-1){
		shortestPriorityIndex=check(a,n);
		if(currentTime <= a[shortestPriorityIndex].at){
			currentTime=a[shortestPriorityIndex].at;
		}
	}
	
		a[shortestPriorityIndex].ct=currentTime+a[shortestPriorityIndex].bt;
		a[shortestPriorityIndex].tat=a[shortestPriorityIndex].ct-a[shortestPriorityIndex].at;
		a[shortestPriorityIndex].wt=a[shortestPriorityIndex].tat-a[shortestPriorityIndex].bt;
		a[shortestPriorityIndex].rt=currentTime;
		a[shortestPriorityIndex].cmp=true;
		currentTime=a[shortestPriorityIndex].ct;
	}
	
}

void print(struct job a[],int n){
	cout<<"P.T\t PR.T\t A.T\t B.T\t C.T\t T.A.T\t W.T\t R.T \n"; 
	for(int i=0;i<n;i++){
		cout<< a[i].pt <<" \t "<<a[i].priority <<"\t"<<a[i].at <<" \t "<< a[i].bt <<" \t "<< a[i].ct <<" \t "<< a[i].tat <<" \t "<< a[i].wt <<" \t "<< a[i].rt <<"\n"; 
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
	cout<<"Enter Priority : \n";
	for(int i=0;i<n;i++){
		cin>>a[i].priority;
	}
	complete(a,n);
	print(a,n);
	avg(a,n);
	return 0;
}

/*
Enter n : 7
Enter Arrival Time : 
0 2 1 4 6 5 7
Enter Burst Time : 
3 5 4 2 9 4 10
Enter Priority : 
2 6 3 5 7 4 10
P.T	 PR.T	 A.T	 B.T	 C.T	 T.A.T	 W.T	 R.T 
1 	 2	0 	 3 	 3 	 3 	 0 	 0
2 	 6	2 	 5 	 18 	 16 	 11 	 13
3 	 3	1 	 4 	 7 	 6 	 2 	 3
4 	 5	4 	 2 	 13 	 9 	 7 	 11
5 	 7	6 	 9 	 27 	 21 	 12 	 18
6 	 4	5 	 4 	 11 	 6 	 2 	 7
7 	 10	7 	 10 	 37 	 30 	 20 	 27
Average Waiting Time : 7.71429
Average TurnAround Time : 13


*/
