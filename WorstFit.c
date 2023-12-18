 #include<stdio.h> 
 int main() 
 { 
	  int p[20],b[20],check[20],first[20],max,internal[20]; 
	  int I,j,k,l,n,n1,f=0; 
	  printf("enter the no of process:"); 
	  scanf("%d",&n); 
	  printf("enter thesizes of each process:"); 
	  for(int i=0;i<n;i++) 
	  { 
	   	scanf("%d",&p[i]); 
	 } 
	 j=I;
	  printf("enter the no. of block:"); 
	  scanf("%d",&n1); 
	   
	  printf("enter the size of each block:"); 
	  for(int i=0;i<n1;i++) 
	  { 
		   scanf("%d",&b[i]); 
		   check[i]=0; 
		   first[i]=0; 
		   internal[i]=0; 
		   j++; 
	 } 
	 k=0; 
	  for(int i=0;i<n;i++) 
	 { 
		  l=1; 
		  f=0; 
		  max=-999; 
		  for(int j=0;j<n1;j++) 
		  { 
		   	if(b[j]>max && b[j]>=p[i] && check[j]!=1) 
		   	{	 
			    max=b[j]; 
			    k=j; 
			    f=1; 
		   	} 
		  } 
		    if(f==1) 
		  { 
			  first[k]=i+1; 
			  check[k]=1; 
			  internal[k]=b[k]-p[i]; 
			  k++; 
			  l++; 
	 	  } 
	  } 
	 printf("\n"); 
	 printf("b_s\tp_s\torder\tinternal_frag\n");
	 for(int i=0;i<n1;i++) 
	 printf("%d\t%d\t%d\t%d\n",b[i],p[i],first[i],internal[i]); 
   } 
