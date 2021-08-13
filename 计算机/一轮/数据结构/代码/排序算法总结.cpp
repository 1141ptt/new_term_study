#include <bits/stdc++.h>
using namespace std;
// 插入排序
// 直接插入排序
void InsertSort(int A[],int n) {
    int i, j, temp;
    for (i = 1; i < n; i++) { // 将各元素插入到已排好序的序列中
        if (A[i] < A[i - 1]) { // 若A[i]关键字小于前缀
            temp = A[i]; // 用temp暂存A[i]
            for (j = i - 1; j >= 0 && A[j] > temp; j--) { // 检查所有已经排好序的元素
                A[j + 1] = A[j]; // 所有大于temp的元素向后挪位
            }
            A[j + 1] = temp; // 复制到插入位置
        }
    }
}
// 折半插入排序
void InsertSortBinary(int A[], int n) {
    for (int i = 1; i < n; i++) { // 开始以a[0]作为有序序列，从a[1]开始找到当前元素a[i]应该放置的位置 
		int low = 0, high = i - 1, mid; // 每次寻找a[i]的位置，都要更新这些数据 
		while (low <= high) { // 二分思想循环寻找a[i]的位置 
			mid = (low + high) / 2;  
			if (A[i] <= A[mid])
				high = mid - 1;  // high指针减小 
			else
				low = mid + 1;   // low指针增加 
		}  // 循环结束，low就是a[i]应该放置的位置 
		int temp = A[i];  
		for (int j = i; j > low; j--)  // 将元素向后平移
			A[j] = A[j - 1];  
		A[low] = temp; // 将元素temp = a[i] 放置到low位置 
	}
} 
// 希尔排序
void ShellSort(int A[], int n)
{
	int h = 1;
	while (h < n) 
		h = 3 * h + 1;
	while (h>0) {
		for (int j = h; j < n; j++) {
			int key = A[j];
			int i = j - h;
			while(i >= 0 && A[i] > key)	{
				A[i + h] = A[i];
				i = i - h;
			}
			A[i + h] = key;
		}
		h = h / 3;
	}
}
// 冒泡排序
void BubbleSort(int A[],int size)
{
    for (int j= 0; j < size - 1; j++) { // 控制每次循环最大元素浮动到数组最后
        for (int i = 0; i < size - 1- j; i++) { // 控制左右相邻的比较
            if (A[i] > A[i + 1]) {
                int tmp = A[i];
                A[i] = A[i + 1];
                A[i + 1] = tmp;
            }
        }
    }
}
// 快速排序
//快速排序（从小到大）
void QuickSort(int left, int right, int A[])
{
	if(left >= right)
		return;
	int i, j, base, temp;
	i = left, j = right;
	base = A[left];  //取最左边的数为基准数
	while (i < j)
	{
		while (A[j] >= base && i < j)
			j--;
		while (A[i] <= base && i < j)
			i++;
		if(i < j)
		{
			temp = A[i];
			A[i] = A[j];
			A[j] = temp;
		}
	}
	//基准数归位
	A[left] = A[i];
	A[i] = base;
	QuickSort(left, i - 1, A);//递归左边
	QuickSort(i + 1, right, A);//递归右边
}
// 选择排序
void SelectSort(int A[], int n)
{
    for(int i = 0 ; i < n ; i++) {
        // 寻找[i, n)区间里的最小值
        int minIndex = i;
        for( int j = i + 1 ; j < n ; j ++ )
            if(A[j] < A[minIndex] )
                minIndex = j;

        swap(A[i], A[minIndex]);
    }
}
// 归并排序
void Merge(int arr[],int low,int mid,int high){
    //low为第1有序区的第1个元素，i指向第1个元素, mid为第1有序区的最后1个元素
    int i=low,j=mid+1,k=0;  //mid+1为第2有序区第1个元素，j指向第1个元素
    int *temp=new int[high-low+1]; //temp数组暂存合并的有序序列
    while(i<=mid&&j<=high){
        if(arr[i]<=arr[j]) //较小的先存入temp中
            temp[k++]=arr[i++];
        else
            temp[k++]=arr[j++];
    }
    while(i<=mid)//若比较完之后，第一个有序区仍有剩余，则直接复制到t数组中
        temp[k++]=arr[i++];
    while(j<=high)//同上
        temp[k++]=arr[j++];
    for(i=low,k=0;i<=high;i++,k++)//将排好序的存回arr中low到high这区间
	arr[i]=temp[k];
    delete []temp;//释放内存，由于指向的是数组，必须用delete []
}
void MergeSort(int arr[], int low,int high) {
    if(low>=high) { return; } // 终止递归的条件，子序列长度为1
    int mid =  low + (high - low)/2;  // 取得序列中间的元素
    MergeSort(arr,low,mid);  // 对左半边递归
    MergeSort(arr,mid+1,high);  // 对右半边递归
    Merge(arr,low,mid,high);  // 合并
} 
int main() {
    int A[10] = {56, 24, 78, 12, 63, 94, 21, 33, 24, 86};
    int B[10] = {56, 24, 78, 12, 63, 94, 21, 33, 24, 86};
    int C[10] = {56, 24, 78, 12, 63, 94, 21, 33, 24, 86};
    int D[10] = {56, 24, 78, 12, 63, 94, 21, 33, 24, 86};
    int E[10] = {56, 24, 78, 12, 63, 94, 21, 33, 24, 86};
    int F[10] = {56, 24, 78, 12, 63, 94, 21, 33, 24, 86};
    int G[10] = {56, 24, 78, 12, 63, 94, 21, 33, 24, 86};
    InsertSort(A, 10);
    for (int i = 0; i < 10; i++) {
		cout << A[i] << " ";
	}
	cout << endl;
	InsertSortBinary(B, 10);
	for (int i = 0; i < 10; i++) {
		cout << B[i] << " ";
	}
	cout << endl;
	ShellSort(C, 10);
	for (int i = 0; i < 10; i++) {
		cout << C[i] << " ";
	}
	cout << endl;
	BubbleSort(D, 10);
	for (int i = 0; i < 10; i++) {
		cout << D[i] << " ";
	}
	cout << endl;
    QuickSort(0, 9, E);
	for (int i = 0; i < 10; i++) {
		cout << E[i] << " ";
	}
	cout << endl;
	SelectSort(F, 10);
	for (int i = 0; i < 10; i++) {
		cout << F[i] << " ";
	}
	cout << endl;
	MergeSort(G, 0, 9);
	for (int i = 0; i < 10; i++) {
		cout << G[i] << " ";
	}
	cout << endl;
	return 0;
}
