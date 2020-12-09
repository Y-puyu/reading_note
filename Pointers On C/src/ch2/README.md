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

8. 这个就是书中所提及的问题，`gets` 可能接到一个很长的输入，导致 `input` 数组溢出。使用 `fgets` 函数，以数组长度作为参数传入，即可防止该问题发生。

### 2.8 编程

1. 见 `demo01.c`。你好，世界！

2. 见 `demo02.c`。`getline` 函数貌似可以直接搞定！？ 要么就循环判断 `EOF`。写的时候发现，`bool` 和 `getline` 都是 `C++` 标准里的。`EOF` 就是 -1，`End Of File`。

3. 见，`demo03.c`。问题是个简单问题，**有个细节必须注意**，即当输入的 `getchar()` 字符整形提升后，即八进制字符为 0377，即在十进制意义下为 255，在二进制表示下为 1111 1111。那么它赋给整数 int 类型就等于 -1，且又等于 `EOF`，使得循环终止。貌似是不可避免的一个问题。

    因为整数在内存中以补码进行存取，`getchar()` 1111 1111 在 `signed char` 类型下是有符号的，则最高位不变，其它位取反加 1，就是整形值的 -1。

4. 见 `demo04.c`。拿数组循环接收每行的输入，循环内利用 `strlen` 函数求得输入行的长度，当遇见更长的就 `strcpy` 拷贝到结果数组中即可。最后输出结果数组中的输入行，提前判断一下是不是空行。

5. 属实没看给的样例代码...本题略过。书后有解析答案，自行参考。

6. 同 5，貌似样例代码中有个 `if (num % 2 ！= 0)` 的操作。让把这个去了再....。没怎么读懂题。

---

### 随笔

简单看了看 `printf` 的格式化和骚操作，顺手找了两个官方文档：

- C++ 文档：[http://www.cplusplus.com/](http://www.cplusplus.com/reference/cstdio/printf/?kw=printf)
- C 文档，包含有 C++：[https://en.cppreference.com/](https://en.cppreference.com/mwiki/index.php?title=Special%3ASearch&search=printf&button=)

`printf` 的返回值是输出到屏幕的字符个数，故可以嵌套 `printf` 来输出一个整数的位数，很是秀...

`printf` 可以控制输出字符颜色，可以用这个功能实现一个简单的带颜色的日志系统，看着能养眼点。也是一个在黑框下独有的浪漫了。

至于后面就是简单的处理字符串相关函数，如： `strcpy`、`strncpy`、`strcat`、`strstr`、`strchr` 等等，只是简单的了解下。
