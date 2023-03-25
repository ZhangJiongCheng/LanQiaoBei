/*
【问题描述】

首先定义折叠及其表示方法。

折叠：一张长方形纸，沿着和短边平行的方向折叠，可以向下折也可以向上折，
折完以后展开（不要展平，而是保持一个折角），沿着垂直于长边的方向看，其实就是一条折线。
接下来从长边的一头向另一头看，那么每一个折角处要么顺时针拐一下，要么是逆指针拐一下，分别用A和V表示。
如果要求折叠展开之后所有的折痕都是等间距的，那么每一段的长度都一样（称为条带），
只要一串A和V字符串就能完全表示这张纸折叠展开之后的情况了。

为了保证折叠完之后都是等间距的，折叠到最后展开之前一定是一个条带的大小。

你的任务就是计算最少的折叠次数，使得展开之后用AV字符串表示的纸张和输入的AV字符串一致。

【输入形式】
输入包含1组测试用例。每个测试用例占一行。每行是一个非空字符串，由A/V两个字母组成，
长度不超过200。描述的是纸的长边。输入终止为EOF。

【输出形式】
输出包含多行，每行对应一个测试用例，每行包含一个整数，为产生输入所描述的纸张折痕的最小折叠次数。

【样例输入】
AVV

【样例输出】
2
*/