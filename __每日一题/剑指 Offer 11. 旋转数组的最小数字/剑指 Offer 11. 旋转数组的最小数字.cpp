//二分查找
int minArray(int* numbers, int numbersSize){
    int low=0;  
    int high=numbersSize-1;
    int mid=low;
    while(low<high){
        //mid=(low+high)/2  可能会溢出
        mid=low+(high-low)/2;   //防止溢出
        if(numbers[mid]>numbers[high])
            low=mid+1;
        else if(numbers[mid]<numbers[high])
            high=mid;
        else   //或者直接顺序查找
            --high;
    }
    return numbers[low];
}
