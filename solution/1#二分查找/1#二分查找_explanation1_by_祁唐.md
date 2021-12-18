# 祁唐的解法

二分查找需要注意的是那个“二分点”的选择。

即关于，偶数长度、奇数长度的数组范围的“二分点”。

其实，选取中点，只是因为Log2最快，但，本身也不必严格要求中点。

——**只要能够将`target`与分割点做比较，并完全遍历那个被选择的分割段即可**。

因此：

```cpp

int pm = (pr + pl) / 2; 
// 0 10 --> 5(奇数长度，中间); 3 8 -->5(偶数长度，中间偏左)
//cout<<pl<<" "<<pr<<" " <<pm<<endl;
if (target == nums[pm]) // 如果分割点即是所查询的位置
    return pm;
if (target > nums[pm]) // 如果target在mid右边
    return binary_s(nums, pm, pr, target); // 查询右边子段
else
    return binary_s(nums, pl, pm, target); // 反之则左边

```

## 一个值得注意的返回条件

最需要注意的是子段仅由3个元素长度、或2个元素长度的时候。

```cpp
(0+1)/2==0
```

看起来不太妙。

那没事。遍历就行。 😄

```cpp

// 结束条件
if (pl + 1 >= pr)
{
    if (target == nums[pr])
        return pr;
    if (target == nums[pl])
        return pl;
    return -1;
}

```

经过分类讨论，发现3个元素是可以用之前的逻辑handle的，只需要对子段只有2个元素的时候，遍历2个元素求解就行了。

------

经leetcode测试，可以通过所有测试集。
