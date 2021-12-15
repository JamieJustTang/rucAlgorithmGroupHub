# rucAlgorithmGroup 简介
code hub of ruc algorithm group (a pure interest group)

- 最初来源于RUC数学建模协会大群的一时兴起，拉了个算法讨论群，日常活动为【每日一题】；
- 【每日一题】根据[labuladong
的fucking-algorithm](https://github.com/labuladong/fucking-algorithm?from=from_parent_mindnote)(我们姑且称之为F书）来跟进算法类型和进度。
- 这是小组的代码仓库。请大家随意fork
- 提供自己的解法的时候，在对应题目的文件夹下提交**cpp/py/...代码文件+md代码解释**，**命名格式见下**。

-------

# 名词解释

## “每日一题”

> 看上去是“每日一题”，实际上更新频率并不是严格按照每天！
> ——对了，考试周罢工！（by 祁唐）

发布：

- 目前由祁唐来负责每天**在群里**发布一条“进度合适”的算法题目。并在`./questions`目录下添加该题目描述。
- 如果题目来自外部OJ，则提供OJ的题目链接；
- 如果题目来自可获得数据，则提供测试数据。

解答：

- 群成员先`fork`一下本仓库（[基础教程点这里](https://blog.csdn.net/joelovegreen/article/details/42913163)）；
- 然后，自己完成解法后，写一个`md`文件做解释，同时`pull request`到对应的`./solution/<question_number#name>`目录，祁唐会尽快查看和通过；
- 如果一道题**1周内没有解答**，祁唐会上传一个*不知道从哪里弄来的暗黑解法*，提交到`./solution/<question_number#name>`，即对应题号的文件夹下；
- 解法命名方式：`<question_number#name>_solutionX_<brief description>_by_<user_name>.cpp`，其中`X`为对应题目的解法序数，第一个解法为`1`；
- 解释命名方式：`<question_number#name>_explanationX_<brief description>_by_<user_name>.cpp`，其中`X`为对应题目的解法序数，第3个解法解法为`3`。

暂时先这样，有什么问题群里问！（叉腰）

## “跟进进度”

目前的主要参照书是[F书](https://github.com/labuladong/fucking-algorithm?from=from_parent_mindnote),**很不幸，这是一本以python为主要语言的入门书**（但我们主要用C++）。

- 所以，在跟进度的时候，我们会首先**利用F书的例题**，布置相应的算法题目；（祁唐会试着去其他OJ上面找对应的测试）
- 在结束例题部分，大家基本熟悉某类算法后，则**参考[LeetCode](https://leetcode-cn.com/problemset/all/)和[洛谷](https://www.luogu.com.cn/problem/list)**，布置相应类型的算法题目；
- 最后，**争取每个月或者总之一定期限内**，本小组在校内召开**算法专项讨论会**，对过去阶段中的算法题目做**总结分享和交流**。

> 祁唐：鸽鸽什么时候骗过你.jpg




