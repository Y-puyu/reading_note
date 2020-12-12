# 第一章：快速上手

有关于 `ch2` 中给的打印歌词的 **神一样的** 样例程序源码，在 `supporting_src` 文件夹中的 `ch2` 的 `mystery.c` 文件即是，我在后面附上了代码运行结果。

## 本章总结及注意点

![20201209202608](https://raw.githubusercontent.com/Y-puyu/picture/main/images/20201209202608.png)
---

## 部分课后习题解答

### 2.7 问题

1. 提高程序可读性

2. 方便修改、维护。如果在不同文件均独立存在一个拷贝，代码修改后都得一一修改，太麻烦。

3. 见名知意。且规范使用大写命名格式，很容易知道这就是个 `#define` 常量。

4. %d %s %lf，貌似浮点数也可以使用 %g。个人没这样使用过。

5. `scanf("%d%d%s", &quantity, &price, department);`

6. `C` 性能至上。下标检查完全是程序员的事情，并且不是所有场景都适用于下标检查。要是担心下标问题，程序员添
加代码自行检查即可。

7. 没读那个程序，没搞懂是啥意思。简单猜一下？内存覆盖？内存越界hh

    **英文原答案：**
    More characters would be copied than are actually needed; however, the output_col would be updated properly, so the next range of characters would be copied into the output array at the proper place, replacing any extra characters from the preceding operation. The only potential problem is that the unbounded strcpy might copy more characters into the output array than it has room to hold, destroying some other variables.

    **翻译：** 将复制比实际需要更多的字符；但是，输出列将被正确更新，因此下一个字符范围将被复制到输出数组的适当位置，替换前面操作中的任何额外字符。唯一的潜在问题是无限strcpy可能会将更多的字符复制到输出数组中有足够的空间，破坏其他一些变量。

### 2.8 编程

1. 见 `demo01.c`。你好，世界！

2. 见 `demo02.c`。`getline` 函数貌似可以直接搞定！？ 要么就循环判断 `EOF`。写的时候发现，`bool` 和 `getline` 都是 `C++` 标准里的。`EOF` 就是 -1，`End Of File`。

3. 见，`demo03.c`。问题是个简单问题，**有个细节必须注意**，即当输入的 `getchar()` 字符整形提升后，即八进制字符为 0377，即在十进制意义下为 255，在二进制表示下为 1111 1111。那么它赋给整数 int 类型就等于 -1，且又等于 `EOF`，使得循环终止。貌似是不可避免的一个问题。

    因为整数在内存中以补码进行存取，`getchar()` 1111 1111 在 `signed char` 类型下是有符号的，则最高位不变，其它位取反加 1，就是整形值的 -1。

---

### 随笔