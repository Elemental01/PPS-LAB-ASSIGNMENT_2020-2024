#include<stdio.h>
#include<stdlib.h>

void swap(int *i,int *j){
    int temp;
    temp=*j;
    *j=*i;
    *i=temp;
}

void selectionsort(int *a, int n){  
    int i, j, min,temp,pos;  
      
    for(i=0;i<n-1;i++){
           min=*(a+i);
           pos=i;
           for(j=i+1;j<n;j++){
               if(min>*(a+j)){
                   pos=j;
                   min=*(a+j);
               }
           }
           if(i!=pos){
             /*temp=a[i];
             a[i]=a[pos];
             a[pos]=temp;*/
             swap((a+i),(a+pos));
           }
    }
}

void insertionsort(int *a,int n){
  int i,j,temp;
  for(i=1;i<n;i++){
    temp=*(a+i);
    j=i-1;
    while((temp<*(a+j))&&(j>=0)){
      *(a+j+1)=*(a+j);
      j=j-1;
    }
    *(a+j+1)=temp;
  }
}

void merge(int *a,int lb,int mid,int ub){
  int i=lb, j= mid+1, k=lb;
  int b[50];
  while(i<=mid&&j<=ub){
    if(*(a+i)<=*(a+j)){
      b[k]=*(a+i);
      i++;
      k++;
    }
    else{
      b[k]=*(a+j);
      j++;
      k++;
    }
  }
    while(j<=ub){
      b[k]=*(a+j);
      j++;
      k++;
    }
    while(i<=mid){
      b[k]=*(a+i);
      i++;
      k++;
    }
  for(k=lb;k<=ub;k++){
    *(a+k)=b[k];
  }
}

void mergesort(int a[],int lb, int ub){
  int mid;
  if(lb<ub){
    mid=(lb+ub)/2;
    mergesort(a,lb,mid);
    mergesort(a,mid+1,ub);
    merge(a,lb,mid,ub);
  }
}

int partition(int *a,int lb,int ub){
  int key,i,j;
  //int temp=0;
  key=a[lb];
  i=lb;
  j=ub;
  while(i<j){
    while(*(a+i)<=key){
      i++;
    }
    while(*(a+j)>key){
      j--;
    }
    if(i<j){
      /*temp=a[i];
      a[i]=a[j];
      a[j]=temp;*/
      swap((a+i),(a+j));
    }
  }
    /*temp=a[lb];
    a[lb]=a[j];
    a[j]=temp;*/
    swap((a+j),(a+lb));
  return j;
}

void quicksort(int a[],int lb,int ub){
  int loc;
  if(lb<ub){
    loc=partition(a,lb,ub);
    quicksort(a,lb,loc-1);
    quicksort(a,loc+1,ub);
  }
}

void display(int *a,int n)
{
  int i;
    for(i=0;i<n;i++)
   {
        printf("%d",*(a+i));
   }

}


int main(){
  int n,i,c;
  int arr[50];
    printf("Enter Array Size\n");
    scanf("%d",&n);

    printf("Enter Array Elements\n");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);

    while(1){
     printf("\n1.Selection\n 2.Insertion\n 3.QuickSort\n 4.MergeSort\n 5.To display\n 6.Exit\n");
     printf("Enter from which sorting algorithm you want to sort-\n");
     scanf("%d",&c);
     switch(c){
       case 1:
       selectionsort(arr,n);
         break;
       case 2:
         insertionsort(arr,n);
         break;
       case 3:
         quicksort(arr,0,n-1);
         break;
       case 4:
         mergesort(arr,0,n-1);
         break;
       case 5:
         display(arr,n);
         break;
       case 6:
         exit(0);
       default:
         printf("Wrong Choice\n");        
     }
   }

  
    return 0;
}

