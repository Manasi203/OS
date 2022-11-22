#include<stdio.h>

int main(){
    int n;
    printf("\nenter no of processes ");
   scanf("%d",&n);
   int bt[n],at[n],finish[n],rbt[n],p[n],wtm[n],tat[n];
    printf("\nenter bt and at");
   for(int i=0;i<n;i++){
       scanf("%d",&bt[i]);
        scanf("%d",&at[i]);
       rbt[i]=bt[i];
       
        p[i]=i;
        finish[i]=0;
        wtm[i]=0;

   }
    int q;
     printf("\nenter time quantum ");
     scanf("%d",&q);
      int time=0,i=0,pending=n;
      printf("\n\nGantt chart=>");
      while(pending>0){
        if(finish[i]==0 && at[i]<=time && rbt[i]<=q){
            time+=rbt[i];
            finish[i]=1;
            pending--;
            wtm[i]-=at[i];
            tat[i]=wtm[i]+bt[i];
            for(int j=0;j<rbt[i];j++){
                printf("P%d  ",p[i]);
            
            }
            for(int j=0;j<n;j++){
                if(j==i || finish[j]==1)continue;
                wtm[j]+=rbt[i]; 
            }
            rbt[i]=0;


        }
        else if(finish[i]==0 && at[i]<=time && rbt[i]>=q){
            time+=q;
            rbt[i]-=q;
             for(int j=0;j<q;j++){
                printf("P%d",p[i]);
            
            }
            for(int j=0;j<n;j++){
                if(j==i || finish[j]==1)continue;
                wtm[j]+=q;
            }
        }

        i=(i+1)%n;


      }
      printf("\n\nProcess  AT  BT  WT  TAT");
      for(int i=0;i<n;i++){
        printf("\nP%d \t %d \t %d \t %d \t %d ",p[i],at[i],bt[i],wtm[i],tat[i]);
      }




    return 0;}