void Merge(int a[],int p,int q,int r){
    int n1 = q - p + 1;
    int n2 = r - q;

    int L[n1 + 1];
    int R[n2 + 1];

    int i;
    int j;

    for(i = 0; i < n1; i++){
        L[i] = a[p + i];
    }

    for(j = 0; j < n2; j++){
        R[j] = a[q + 1 + j];
    }
    L[n1] = INT_MAX;
    R[n2] = INT_MAX;
    
    i = 0;
    j = 0;

    for(int k = p; k <= r; k++){
        if(L[i] <= R[j]){
            a[k] = L[i];
            i++;
        }
        else{
            a[k] = R[j];
            j++;
        }
    }
}

void MergeSort(int a[],int p,int r){
    if(p < r){
        int q = (p + r)/2;
        MergeSort(a,p,q);
        MergeSort(a,q + 1,r);
        Merge(a,p,q,r);
    }
}

int maxProductDifference(int* nums, int numsSize){
    MergeSort(nums,0,numsSize - 1);
    int prod_dif = (nums[numsSize-1] * nums[numsSize-2]) - (nums[1] * nums[0]);
    return prod_dif; 
}

