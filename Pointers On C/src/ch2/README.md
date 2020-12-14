# 第二章：基本概念

有关于 `ch2` 中给的打印歌词的 **神一样的** 样例程序源码，在 `supporting_src` 文件夹中的 `ch2` 的 `mystery.c` 文件即是，我在后面附上了代码运行结果。

## 本章总结及注意点

![20201209202608](https://raw.githubusercontent.com/Y-puyu/picture/main/images/20201209202608.png)

---

## 部分课后习题解答

### 2.7 问题

1. `i` 未定义就使用。编译不会通过。

2. 来自英文答案：

    Advantages:

    a. When you want to modify a function, it is easy to determine which file it is in.

    b. You can safely use longer function names. Depending on the limits of your particular system, internal must be distinct from one another somewhere in the first 31 characters or more, whereas external names must be distinct from one another in the first six characters.

    Disadvantages:

    a. Depending on how powerful your editor is, it may be harder to locate a particular piece of code in a large file than a small one.

    b. Depending on your operating system, the type of editor you are using, and the size of the file, it may be more time consuming to edit a large file than a small one.

    c. If you make a mistake in your editor, it is easy to lose the whole program.

    d. Even if you change only one function, the entire program must be recompiled, which takes longer than recompiling only the modified function.

    e. It is harder to reuse general purpose functions from the program if they are buried in with all the code that is specific to that problem.

    优势：

   - a、 当您想修改函数时，很容易确定它在哪个文件中。
   - b、 您可以安全地使用较长的函数名。根据特定系统的限制，内部名称必须在前31个字符或更多字符中彼此不同，而外部名称必须在前6个字符中彼此不同。

    缺点：

   - a、 根据编辑器的强大程度，在一个大文件中定位特定的代码段可能比在小文件中定位要困难。
   - b、 根据您的操作系统、所使用的编辑器的类型以及文件的大小，编辑大文件可能比编辑小文件更耗时。
   - c、 如果在编辑器中出错，很容易丢失整个程序。
   - d、 即使只更改一个函数，也必须重新编译整个程序，这比只重新编译修改过的函数所需的时间长。
   - e、 如果程序中的通用函数与特定于该问题的所有代码一起使用，则很难重用这些函数。

3. "\"Blunder\?\?!??\"" 。见 `demo03.c`

4. 了解即可
    ![20201213192326](https://raw.githubusercontent.com/Y-puyu/picture/main/images/20201213192326.png)

5. 预处理器将注释替换为一个空格，从而生成结果语句非法的。（涨知识了）

6. 没问题。`stop` 不是 `C` 里面的保留字，注意下即可。

7. 无关紧要？

8. `while` 循环括号不匹配。体现了缩进的价值。

9. 这个看系统吧。`unix` 就是 `cc main.c list.c report.c`。

10. `cc main.c list.c report.c -lparse`。

11. 简单了解。`make` 工具使用和 `makefile` 编写也是基础中的基础了。![20201213193457](https://raw.githubusercontent.com/Y-puyu/picture/main/images/20201213193457.png)

### 2.8 编程

1. 见 `increment.c`，`negate.c`，`main.c` 三个文件。`gcc main.c increment.c  negate.c -o main.exe` 函数文件就不需要写头文件了。主要练习单独编译，是 `C` 语言提高效率的一个做法。

2. 经典问题了，括号匹配问题。对每种括号开个计数器，遇见左括号则 +1，遇见右括号则 -1。若期间任一计数器为负值或者最终计数器不为 0，则不匹配。

---

### 随笔

1. 编译过程及 Linux 编译器 gcc 的使用
    - 预处理（进行宏替换）
      - 预处理功能主要包括宏定义，文件包含，条件编译，去注释等。
      - 预处理指令是以#号开头的代码行。
      - 实例: gcc –E hello.c –o hello.i
      - 选项“-E”，该选项的作用是让 gcc 在预处理结束后停止编译过程。
      - 选项“-o”是指目标文件，“.i”文件为已经过预处理的C原始程序。
    - 编译（生成汇编）
      - 在这个阶段中，gcc 首先要检查代码的规范性、是否有语法错误等，以确定代码的实际要做的工作，在检查无误后，gcc 把代码翻译成汇编语言。
      - 用户可以使用“-S”选项来进行查看,该选项只进行编译而不进行汇编,生成汇编代码。
      - 实例: gcc –S hello.i –o hello.s
    - 汇编（生成机器可识别代码）
      - 汇编阶段是把编译阶段生成的“.s”文件转成目标文件。
      - 读者在此可使用选项“-c”就可看到汇编代码已转化为“.o”的二进制目标代码了。
      - 实例: gcc –c hello.s –o hello.o
    - 链接（生成可执行文件或库文件）
      - 在成功编译之后,就进入了链接阶段
      - 实例: gcc hello.o –o hello
    - gcc 选项
      - -E 只激活预处理,这个不生成文件,你需要把它重定向到一个输出文件里面
      - -S 编译到汇编语言不进行汇编和链接
      - -c 编译到目标代码
      - -o 文件输出到 文件
      - -static 此选项对生成的文件采用静态链接
      - -g 生成调试信息。GNU 调试器可利用该信息。
      - -shared 此选项将尽量使用动态库，所以生成文件比较小，但是需要系统由动态库.
      - -O0
      - -O1
      - -O2
      - -O3 编译器的优化选项的4个级别，-O0表示没有优化,-O1为缺省值，-O3优化级别最高
      - -w 不生成任何警告信息。
      - -Wall 生成所有警告信息。

    故，简单阐述编译过程就是：预处理，展开所有代码。编译，进行语义语法检测，将 `C` 语言代码解释成为汇编代码。汇编，将汇编代码解释成为二进制机器指令。链接，将当前代码以及函数库还有其它文件代码打包生成可执行程序。

2. 字符

    发展到如今，`C` 语言版本也已经更新迭代了很多版。字符集这些常用的也就是换行、制表、转义字符之类的。**关于三字母词可见demo01.c** 还是挺有意思的。

    关于转义字符占位问题，应该是占一位。且一定需要注意 `\` 后加数字的转义，可能是八进制、十六进制的转义。也再注意下 `char* a = "\u771a";printf("c = %s   %d\n", a, sizeof a); // c = 眚   8` 能够发现，`Unicode` 在这是 2 个字节。

    尤其是针对于十六进制的转义字符，`\x23` 这类的，在 `vscode` 下只是占后面的两个数字。许多博客也是这样讲的：8 进制占后面三个数字，16 进制占后面两个数字。但是，在 `vs2019` 下它占后面 4 个数字，且必须在 16 进制后面加个空格，否则不打印后面的字符串...我也搞不懂是啥情况。

3. 代码风格

    至于代码风格可以和程序员自身长相挂钩！

### 疑问

 1. 随笔第 2 项。末尾，针对 16 进制转义字符问题。

 2. 单独编译问题。编译这块还是理解的不够透彻和深入。
