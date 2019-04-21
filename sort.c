#include<stdio.h>
#include<stdlib.h>


#define MAXSIZE 1000
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define OVERFLOW -2
typedef int Status;
typedef int ElemType;



//插入排序  时间复杂度：O(n^2) 空间复杂度：O(1)
Status InsertSort(ElemType a[],int n)
{
    if (n == 0)
    {
        return ERROR;
    }
    
    //进行N-1轮插入过程
    for(int i=1; i<n; i++)
    {
        //首先找到元素a[i]需要插入的位置
        int j=0;
        while((a[j]<a[i]) && (j<i))
        {
            j++;
        }
        //将元素插入到正确的位置
        if(i != j)  //如果i==j，说明a[i]刚好在正确的位置，否则执行插入
        {
            int temp = a[i];
            for(int k = i; k > j; k--)
            {
                a[k] = a[k-1];
            }
            a[j] = temp;
        }
    }
    return OK;
}






//快速排序 时间复杂度：O(nlog(n) 空间复杂度：O(log(n))
void QuickSort(int left,int right,ElemType a[])
{
    int i,j,t,temp;
    if(left>right) return;

    temp=a[left]; //temp中存放基准数
    i=left;
    j=right;
    while(i!=j)
    {
       //先从右边开始找
       while(a[j]>=temp && i<j)
            j--;
       //再从左边找
       while(a[i]<=temp && i<j)
            i++;
       //交换两个数在数组中的位置
       if(i<j)
       {
            t=a[i];
            a[i]=a[j];
            a[j]=t;
       }
    }
    //最终将基准数归位
    a[left]=a[i];
    a[i]=temp;

    QuickSort(left,i-1,a);//继续处理左边的
    QuickSort(i+1,right,a);//继续处理右边的
}

//归并排序


// 归并排序中的合并算法
void Merge(int array[], int left, int m, int right)
{
    int aux[MAXSIZE] = {0};  // 临时数组 （若不使用临时数组，将两个有序数组合并为一个有序数组比较麻烦）
    int i; //第一个数组索引
    int j; //第二个数组索引
    int k; //临时数组索引
    
    for (i = left, j = m+1, k = 0; k <= right-left; k++) // 分别将 i, j, k 指向各自数组的首部。
    {
        //若 i 到达第一个数组的尾部，将第二个数组余下元素复制到 临时数组中
        if (i == m+1)
        {
            aux[k] = array[j++];
            continue;
        }
        //若 j 到达第二个数组的尾部，将第一个数组余下元素复制到 临时数组中
        if (j == right+1)
        {
            aux[k] = array[i++];
            continue;
        }
        //如果第一个数组的当前元素 比 第二个数组的当前元素小，将 第一个数组的当前元素复制到 临时数组中
        if (array[i] < array[j])
        {
            aux[k] = array[i++];
        }
        //如果第二个数组的当前元素 比 第一个数组的当前元素小，将 第二个数组的当前元素复制到 临时数组中
        else
        {
            aux[k] = array[j++];
        }
    }
    
    //将有序的临时数组 元素 刷回 被排序的数组 array 中，
    //i = left , 被排序的数组array 的起始位置
    //j = 0， 临时数组的起始位置
    for (i = left, j = 0; i <= right; i++, j++)
    {
        array[i] = aux[j];
    }
}
 
// 归并排序
void MergeSort(int array[], int start, int end)
{
    if (start < end)
    {
        int i;
        i = (end + start) / 2;
        // 对前半部分进行排序
        MergeSort(array, start, i);
        // 对后半部分进行排序
        MergeSort(array, i + 1, end);
        // 合并前后两部分
        Merge(array, start, i, end);
    }
}

//计数排序
Status CountSort(ElemType a[],int n)
{
    ElemType temp;
    int k = 0;
    if (n == 0)
    {
        return ERROR;
    }
    int max = 0,min = 0;
    for(int i = 0;i < n;i++){
        if (a[i] >= max)
        {
            max = a[i];
        }
        if (a[i] <= min)
        {
            min = a[i];
        }
    }//找到数组中的最大值和最小值
    if (max > MAXSIZE)
    {
        return ERROR;
    }
    ElemType new[max+1];
    for(int i = 0;i <= max;i++){
        new[i] = 0;
    }//数组元素归零
    for(int i = 0;i < n;i++){
        temp = a[i];
        new[temp]++;
    }//进行计数
    for(int i = 0;i <= max;i++){
        if (new[i] != 0)
        {
            for(int j = new[i];j > 0;j--){
                a[k++] = i;
            }
        } 
    }
}


int main()
{
    int i = 0,n;
    int length;
    char temp;
    int left,right;
    ElemType c[MAXSIZE];
    printf("依次输入数组中的值(正整数),输入-1以停止:\n");
    do
    {
        printf("请输入第%d个值：",i+1);
        scanf("%d",&c[i]);
    } while (c[i++] > 0);
    length = i - 1;
    left = 0;
    right = length-1;
    printf("请选择排序方式:（1.插入排序 2.快速排序 3.归并排序 4.计数排序）\n");
    scanf("%d",&n);
    switch (n)
    {
    case 1:
        InsertSort(&c,length);    
        break;
    case 2:
        QuickSort(left,right,&c);
        break;
    case 3:
        MergeSort(&c,left,right);
    case 4:
        CountSort(&c,length);    
    default:
        break;
    }
    printf("排序后的结果是:");
    for(i = 0;i < length;i++){
        printf("%d ",c[i]);
    }
    return 0;
}