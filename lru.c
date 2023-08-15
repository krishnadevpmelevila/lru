
#include <stdio.h>
#include<limits.h>

int checkhit(int q[],int incoming, int occupied){
	for(int u=0;u<occupied;u++){
		if(q[u]==incoming){
			return 1;
		}
	}
	return 0;
}

int printfn(int q[],int occupied){
	printf("\t\t");
	for(int u=0; u<occupied;u++){
		printf("%d\t\t",q[u]);
	}
}

void main(){
	int p,f,pagefault,occup=0;
	f=f;
	int pinc[50];
	int q[50];

            int index;
	printf("Enter number of frames: ");
	scanf("%d",&f);
	printf("Enter number of pages: ");
	scanf("%d",&p);
	printf("Enter pages: ");
	
	for(int i=0;i<p;i++){
		scanf("%d",&pinc[i]);
	}
	printf("Page\t\t\t\t\tF1\t\tF2\t\tF3\t\t\t\t\t\t\t\tHIT/MISS\n");
	for(int i=0;i<p;i++){
	printf("%d:\t\t\t",pinc[i]);
		if(checkhit(q,pinc[i],occup)){
			printfn(q,occup);
			printf("\t\t\t\t\t\t\t\t\tHIT");
		}
		else if(occup<f){
			q[occup]=pinc[i];
			occup++;
			pagefault++;
			printfn(q,occup);
            printf("\t\t\t\t\t\t\t\t\tMISS");


			
		}
		else{
			int max = 0;
			int dist[20];
			for(int j=0;j<f;j++){
				dist[j]=0;
				for(int k=i-1;k>=0;k--){
					++dist[j];
					if(q[j]==pinc[k]){
						break;
					}
				}
				if(dist[j]>max){
					max=dist[j];
					index=j;
				}
				}
				q[index]=pinc[i];
				pagefault++;
				printfn(q,occup);
			printf("\t\t\t\t\t\t\t\t\tMISS");

				
			
			}
			
			
			
			
			
		
		printf("\n");
		
	}
	 printf("Page Fault: %d",pagefault);
}
