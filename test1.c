void Swap(int* px, int* py)
{
	int tmp = *px;
	*px = *py;
	*py = tmp;
}
void sortColors(int* nums, int numsSize) {
    int left=0;
    int right=numsSize-1;
    int cur=0;
    while(cur<=right){
        if(nums[cur]==2){
            Swap(&nums[cur],&nums[right]);
            right--;
        }
        else if(nums[cur]==1){
            cur++;
        }else{
            Swap(&nums[left],&nums[cur]);
            left++;
            //if (cur == left) 
                cur++;
        }
    }
}
