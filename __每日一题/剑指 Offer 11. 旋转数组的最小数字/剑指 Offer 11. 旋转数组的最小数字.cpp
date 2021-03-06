//���ֲ���
int minArray(int* numbers, int numbersSize){
    int low=0;  
    int high=numbersSize-1;
    int mid=low;
    while(low<high){
        //mid=(low+high)/2  ���ܻ����
        mid=low+(high-low)/2;   //��ֹ���
        if(numbers[mid]>numbers[high])
            low=mid+1;
        else if(numbers[mid]<numbers[high])
            high=mid;
        else   //����ֱ��˳�����
            --high;
    }
    return numbers[low];
}
