/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void merge(int *nums, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = malloc(n1 * sizeof(int));
    int *R = malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++)
        L[i] = nums[left + i];

    for (int j = 0; j < n2; j++)
        R[j] = nums[mid + 1 + j];

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            nums[k] = L[i];
            i++;
        }
        else
        {
            nums[k] = R[j];
            j++;
        }

        k++;
    }

    while (i < n1)
    {
        nums[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        nums[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

void mergeSort(int *nums, int left, int right)
{
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;

    mergeSort(nums, left, mid);
    mergeSort(nums, mid + 1, right);

    merge(nums, left, mid, right);
}

int* sortArray(int* nums, int numsSize, int* returnSize)
{
    *returnSize = numsSize;

    if (numsSize <= 1)
        return nums;

    mergeSort(nums, 0, numsSize - 1);

    return nums;
}

