class Solution {
    void merge(vector<int>&nums, int l, int mid, int r, int &count)
    {
        int i=l;
        int j = mid+1;
        vector<int>temp;
        
        while(i<mid+1&&j<=r)
        {
            if(nums[i]<=nums[j])
            {
                temp.push_back(nums[i]);
                i++;
            }
            else{
                // if(nums[i]>2*nums[j])
                // count+=(mid-i+1);
                temp.push_back(nums[j]);
                j++;
            }
        }
        while(i<mid+1)
        {
            temp.push_back(nums[i]);
            i++;
        }
        while(j<=r)
        {
            temp.push_back(nums[j]);
            j++;
        }

        for(int i=l;i<=r;i++)
        {
            nums[i]=temp[i-l];
        }
    }
    
    void counting(vector<int>&arr, int l, int mid, int r, int &count)
    {
        int j = mid+1;
        for(int i=l;i<=mid;i++)
        {
            while(j<=r&&arr[i]>2ll*arr[j])
            {
                count+=(mid-i+1);
                j++;
            }
        }
    }


    void mergeSort(vector<int>&nums, int l, int r, int& count)
    {
        if(l<r)
        {
            int mid = l+(r-l)/2;
            mergeSort(nums, l, mid, count);
            mergeSort(nums, mid+1, r, count);
            counting(nums,l,mid,r,count);
            merge(nums, l, mid, r, count);
        }
    }

public:
    int reversePairs(vector<int>& nums) {
        int count=0;
        int n = nums.size();
        mergeSort(nums, 0, n-1, count);
        return count;
    }
};