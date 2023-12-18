#include<bits/stdc++.h>
using namespace std;

void WorstFit(int p,int process[],int b,int block[]){
	int allocation[p];
	for(int i=0;i<p;i++){
		allocation[i]=-1;
	}
	
	for(int i=0;i<p;i++){
		for(int j=0;j<b;j++){
			if(block[j] >= process[i]){
			allocation[i]=j;
			block[j]=block[j]-process[i];
			break;
			}
		}
	}
	cout<<"process\tblock\tallocation"<<endl;
	for(int i=0;i<p;i++){
		cout<<i+1<<"\t"<<process[i];
		if(allocation[i]!=-1){
			cout<<"\t"<<allocation[i]+1<<endl;
		}
		else{
			cout<<"\t"<<"Not Allocated."<<endl;
		}
	}
}

int main(){
	cout<<"Enter the no. of Process : ";
	int p,b;
	cin>>p;
	cout<<"Enter Processes :";
	int process[p];
	for(int i=0;i<p;i++){
		cin>>process[i];
	}
	cout<<"Enter the no. of Block : ";
	cin>>b;
	int block[b];
	cout<<"Enter Blocks :";
	for(int i=0;i<b;i++){
		cin>>block[i];
	}
	WorstFit(p,process,b,block);
	return 0;
}


/*
Enter the no. of Process : 4
Enter Processes :212 417 112 426
Enter the no. of Block : 5
Enter Blocks :100 500 200 300 600
process	block	allocation
1	212	2
2	417	5
3	112	2
4	426	Not Allocated.
*/
