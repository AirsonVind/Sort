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



//��������  ʱ�临�Ӷȣ�O(n^2) �ռ临�Ӷȣ�O(1)
Status InsertSort(ElemType a[],int n)
{
    if (n == 0)
    {
        return ERROR;
    }
    
    //����N-1�ֲ������
    for(int i=1; i<n; i++)
    {
        //�����ҵ�Ԫ��a[i]��Ҫ�����λ��
        int j=0;
        while((a[j]<a[i]) && (j<i))
        {
            j++;
        }
        //��Ԫ�ز��뵽��ȷ��λ��
        if(i != j)  //���i==j��˵��a[i]�պ�����ȷ��λ�ã�����ִ�в���
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






//�������� ʱ�临�Ӷȣ�O(nlog(n) �ռ临�Ӷȣ�O(log(n))
void QuickSort(int left,int right,ElemType a[])
{
    int i,j,t,temp;
    if(left>right) return;

    temp=a[left]; //temp�д�Ż�׼��
    i=left;
    j=right;
    while(i!=j)
    {
       //�ȴ��ұ߿�ʼ��
       while(a[j]>=temp && i<j)
            j--;
       //�ٴ������
       while(a[i]<=temp && i<j)
            i++;
       //�����������������е�λ��
       if(i<j)
       {
            t=a[i];
            a[i]=a[j];
            a[j]=t;
       }
    }
    //���ս���׼����λ
    a[left]=a[i];
    a[i]=temp;

    QuickSort(left,i-1,a);//����������ߵ�
    QuickSort(i+1,right,a);//���������ұߵ�
}

//�鲢����


// �鲢�����еĺϲ��㷨
void Merge(int array[], int left, int m, int right)
{
    int aux[MAXSIZE] = {0};  // ��ʱ���� ������ʹ����ʱ���飬��������������ϲ�Ϊһ����������Ƚ��鷳��
    int i; //��һ����������
    int j; //�ڶ�����������
    int k; //��ʱ��������
    
    for (i = left, j = m+1, k = 0; k <= right-left; k++) // �ֱ� i, j, k ָ�����������ײ���
    {
        //�� i �����һ�������β�������ڶ�����������Ԫ�ظ��Ƶ� ��ʱ������
        if (i == m+1)
        {
            aux[k] = array[j++];
            continue;
        }
        //�� j ����ڶ��������β��������һ����������Ԫ�ظ��Ƶ� ��ʱ������
        if (j == right+1)
        {
            aux[k] = array[i++];
            continue;
        }
        //�����һ������ĵ�ǰԪ�� �� �ڶ�������ĵ�ǰԪ��С���� ��һ������ĵ�ǰԪ�ظ��Ƶ� ��ʱ������
        if (array[i] < array[j])
        {
            aux[k] = array[i++];
        }
        //����ڶ�������ĵ�ǰԪ�� �� ��һ������ĵ�ǰԪ��С���� �ڶ�������ĵ�ǰԪ�ظ��Ƶ� ��ʱ������
        else
        {
            aux[k] = array[j++];
        }
    }
    
    //���������ʱ���� Ԫ�� ˢ�� ����������� array �У�
    //i = left , �����������array ����ʼλ��
    //j = 0�� ��ʱ�������ʼλ��
    for (i = left, j = 0; i <= right; i++, j++)
    {
        array[i] = aux[j];
    }
}
 
// �鲢����
void MergeSort(int array[], int start, int end)
{
    if (start < end)
    {
        int i;
        i = (end + start) / 2;
        // ��ǰ�벿�ֽ�������
        MergeSort(array, start, i);
        // �Ժ�벿�ֽ�������
        MergeSort(array, i + 1, end);
        // �ϲ�ǰ��������
        Merge(array, start, i, end);
    }
}

//��������
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
    }//�ҵ������е����ֵ����Сֵ
    if (max > MAXSIZE)
    {
        return ERROR;
    }
    ElemType new[max+1];
    for(int i = 0;i <= max;i++){
        new[i] = 0;
    }//����Ԫ�ع���
    for(int i = 0;i < n;i++){
        temp = a[i];
        new[temp]++;
    }//���м���
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
    printf("�������������е�ֵ(������),����-1��ֹͣ:\n");
    do
    {
        printf("�������%d��ֵ��",i+1);
        scanf("%d",&c[i]);
    } while (c[i++] > 0);
    length = i - 1;
    left = 0;
    right = length-1;
    printf("��ѡ������ʽ:��1.�������� 2.�������� 3.�鲢���� 4.��������\n");
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
    printf("�����Ľ����:");
    for(i = 0;i < length;i++){
        printf("%d ",c[i]);
    }
    return 0;
}