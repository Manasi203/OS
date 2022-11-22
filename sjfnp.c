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
   //sort
   int temp;
   for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        if(rbt[i]<rbt[j]){
        temp=bt[i];
        bt[i]=bt[j];
        bt[j]=temp;

        temp=at[i];
        at[i]=at[j];
        at[j]=temp;
        
        temp=finish[i];
        finish[i]=finish[j];
        finish[j]=temp;

          temp=rbt[i];
        rbt[i]=rbt[j];
        rbt[j]=temp;
        temp=p[i];
        p[i]=p[j];
        p[j]=temp;
       
        }
    }
   }

  printf("\n\nGantt => ");
   int pending=n,i=0,time=0;
   while(pending>0){
    for(i=0;i<n;i++){
    if(finish[i]==0 && at[i]<=time){
        printf("P%d ",p[i]+1);

        time+=bt[i];
       
         pending--;
            finish[i]=1;
             for(int j=0;j<n;j++){
                if(j==1 || finish[j]==1)continue;
                wtm[j]+=bt[i];
        }
            wtm[i]-=at[i];
            tat[i]=wtm[i]+bt[i];
       
        break;
    }
    }
   }
    printf("\n\nProcess  AT  BT  WT  TAT");
      for(int i=0;i<n;i++){
        printf("\nP%d \t %d \t %d \t %d \t %d ",p[i]+1,at[i],bt[i],wtm[i],tat[i]);
      }



   return 0;
}