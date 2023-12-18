#include<bits/stdc++.h>
using namespace std;

struct job{
	int pt;
	int at;
	int bt;
	int dbt;
	int ct;
	int rt;
	int wt;
	int tat;
	int ft;
	int priority;
};



void complete(struct job a[],int n){
	int currentTime=0;
	int process =0;
	int shortestPriorityIndex=0;
	int shortestPriority=INT_MAX;
	int finishTime;
	bool check=false;
	
	while(process!=n){
	
		for(int i=0;i<n;i++){
			if(a[i].dbt > 0 && a[i].priority<shortestPriority && a[i].at<=currentTime){
				shortestPriorityIndex=i;
				shortestPriority=a[i].priority;
				check=true;
			}
		}
		if(check==false){
			currentTime++;
			continue;
		}
		else{
			if(a[shortestPriorityIndex].ft==-1){
				a[shortestPriorityIndex].ft=currentTime;
			}
		}
		a[shortestPriorityIndex].dbt--;
		
		shortestPriority=a[shortestPriorityIndex].priority;
		if(a[shortestPriorityIndex].dbt == 0){
			shortestPriority=INT_MAX;
		}
		if(a[shortestPriorityIndex].dbt == 0){
			process++;
			check=false;
			finishTime=currentTime+1;
			
			a[shortestPriorityIndex].ct=finishTime;
			a[shortestPriorityIndex].wt=finishTime - a[shortestPriorityIndex].bt-a[shortestPriorityIndex].at;
			a[shortestPriorityIndex].tat=a[shortestPriorityIndex].bt + a[shortestPriorityIndex].wt;
			a[shortestPriorityIndex].rt=a[shortestPriorityIndex].ft-a[shortestPriorityIndex].at;
			if(a[shortestPriorityIndex].wt < 0){
				a[shortestPriorityIndex].wt=0;
			}
		}
	currentTime++;
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
		a[i].ft=-1;
	}
	cout<<"Enter Burst Time : \n";
	for(int i=0;i<n;i++){
		cin>>a[i].bt;
		a[i].dbt=a[i].bt;
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
Enter n : 5
Enter Arrival Time : 
0 1 2 3 5
Enter Burst Time : 
3 4 6 4 2
Enter Priority : 
3 2 4 6 10
P.T	 PR.T	 A.T	 B.T	 C.T	 T.A.T	 W.T	 R.T 
1 	 3	0 	 3 	 7 	 7 	 4 	 0
2 	 2	1 	 4 	 5 	 4 	 0 	 0
3 	 4	2 	 6 	 13 	 11 	 5 	 5
4 	 6	3 	 4 	 17 	 14 	 10 	 10
5 	 10	5 	 2 	 19 	 14 	 12 	 12
Average Waiting Time : 6.2
Average TurnAround Time : 10
*/
