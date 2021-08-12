// 顺序查找
struct ElemType {
	int data;
};
typedef struct {
    ElemType *elem;
    int TabLeLen;
}SSTable;
int Search_Seq(SSTable ST, ElemType key) {
    ST.elem[0] = key; // 哨兵
    for (int i = ST.TabLeLen; ST.elem[i] != key; i--) { // 从后往前找
        return i;
    }  
}

// 二分查找
int Binary_Search(SSTable L, ElemType key) {
    int low = 0, high = L.TableLen - 1, mid;
    while (low <= high) {
        mid = (high - low) / 2 + low; // 取中间位置，防止溢出
        if (L.elem[mid] == key) {
            return mid;
        }
        else if (L.elem[mid] > key) {
            high = mid - 1; // 从前半部分继续查找
        }
        else {
            low = mid + 1; // 从后半部分继续查找
        }
    }
    return -1;
}
