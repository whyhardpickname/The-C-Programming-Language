#include<stdio.h>

/* 将整数数组v的元素V[left],...,v[right]按升序就地排序 */
/* 快速排序:选取集合任意元素作为中枢值,按小于中枢值与否划分为两个子集,
    再按照相同规则划分子集直至子集元素个数小于2时停止.*/
void qsort(int v[], int left, int right)
{
    int i;
    /* 下标: 子集的最后一个元素下表*/
    int stored;

    void swap(int v[], int i, int j);

    /* 判断子集元素个数是否还需划分 */
    if (left >= right)
    {
        return;
    }

    /* 选取中间元素作为中枢值,并与最左边元素交换 */
    swap(v, left, (left + right) / 2);
    stored = left;
    /* 划分集合 */
    for (i = left + 1; i <= right; i++)
    {
        if (v[i] < v[left])
        {
            /* ++stored因为第一个是中枢值,同时保证stored指向最后一个小于中枢值的元素 */
            swap(v, ++stored, i);
        }
    }
    /* 将中枢值与最后一个小于中枢值的元素 */
    swap(v, left, stored);
    /* 递归处理划分的子集 */
    qsort(v, left, stored - 1);
    /* stored必然小于或等于右边子集,无需排序 */
    qsort(v, stored + 1, right);
}

void swap(int v[], int i, int j)
{
    int temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}


int main()
{
    int v[] = {6, 5, 4, 3, 2, 1};
    qsort(v, 0, 5);
    for (int i = 0; i < 6; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");
    return 0;
}