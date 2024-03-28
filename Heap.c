#include <stdio.h>
#include <stdlib.h>
#define size 100

void heapify(int a[], int n){
    int i, j, v, k, heap;
    for(i = n / 2; i >= 1; i--){
        k = i; 
        v = a[i];
        heap = 0;
        while (!heap && 2 * k <= n){
            j = 2 * k;
            if (j < n && a[j] < a[j + 1]){
                j++;
            }
            if (v >= a[j]){
                heap = 1;
            } else {
                a[k] = a[j];
                k = j;
            }
        }
        a[k] = v;
    }
}


void heapSort(int a[], int n){
    heapify(a, n);
    for(int i = n; i > 1; i--){
        int ele = a[1];
        a[1] = a[i];
        a[i] = ele;
        heapify(a, i - 1); // Corrected the size of the array to be heapified
    }
}

int main(){
    int a[size], n, ch, ele;

    //heap creation
    printf("Enter no of elements: \n");
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        printf("Enter element : \n");
        scanf("%d", &a[i]);
    }
    heapify(a, n);

    while(1){
        printf("Enter 1-Insert, 2-Delete, 3-Display, 4-Sort 5-Exit : ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            if( n < size){
                printf("Enter the element to insert : \n");
                scanf("%d", &ele);
                a[++n] = ele;
                heapify(a, n);
                break;
            }else{
                printf("Priority queue is full!");
                break;
            }
        case 2: if(n > 0){
                    ele = a[1];
                    a[1] = a[n];
                    n--;
                    heapify(a, n);
                    printf("Deleted element is %d\n", ele);
                    break;
            }else{
                printf("Priority queue is empty!");
                break;
            }
        case 3:
            printf("Heap is ");
            for(int i = 1; i <= n; i++){
                printf("%d ", a[i]);
            }
            printf("\n");
            break;
        case 4:
		heapSort(a, n);
		printf("Heap after sorting: ");
		for(int i = 1; i <= n; i++) {
		    printf("%d ", a[i]);
		}
		printf("\n");
               break;
        default:
            exit(0);
        }
    }
    return 0;
}

