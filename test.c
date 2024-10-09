void resver(int *a,int left,int right){

    while(left<right){
        int tmp=a[left];
        a[left]=a[right];
        a[right]=tmp;
        left++;
        right--;
    }

}
void rotate(int* nums, int numsSize, int k) {
    k%=numsSize;

    resver(nums,0,numsSize-1-k);
    resver(nums,numsSize-k,numsSize-1);
    resver(nums,0,numsSize-1);

}
