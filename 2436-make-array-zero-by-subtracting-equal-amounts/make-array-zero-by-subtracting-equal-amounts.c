int minimumOperations(int* nums, int numsSize) {
    int count = 0;
    for(int i = 0; i < numsSize; i++){
        int flag = 0;
        for(int j = 0; j <= i; j++){
            if((i != j) && (nums[i] == nums[j])){
                flag = 1;
                break;
            }
        }
        if((flag == 0) && (nums[i] != 0))
            count++ ;
    }
    return count;
}