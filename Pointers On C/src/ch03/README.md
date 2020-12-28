# 第三章：数据

第三章貌似没有作者给出的源码。

## 本章总结及注意点

![1](https://raw.githubusercontent.com/Y-puyu/picture/main/images/20201226212733.png)

![2](https://raw.githubusercontent.com/Y-puyu/picture/main/images/20201226212605.png)

---

## 部分课后习题解答

### 3.13 问题

1. 见 `demo01.c` 即可。包含了 `<limits.h>` 后自行查看即可。也可以直接去查看 `<limits.h>` 中到底是怎样定义的。

2. 见 `<float.h>` 中的定义即可。

3. 很实用啊，真正的见名知意。

    ![20201215172715](https://raw.githubusercontent.com/Y-puyu/img/main/images/20201215172715.png?token=AK7TQWQ4ZBH4RAIKVJUZHD273CA3G)

4. `warning` 警告。只要能放下也无所谓。否则，根据各个编译器自己的规矩来，可能溢出，可能直接丢弃高阶位，这些情况都是有可能的。

5. 精度丢失。`warning` 警告。对于整数，如果能装得下，那就直接装就行了。如果装不下，这就取决编译器是怎么实现该情况的了。对于浮点数，需要查看指数和尾数能否装得下，否则依旧看编译器是怎么处理的。

6. `enum Change { PENNY = 1, NICKEL = 5, DIME = 10, QUARTER = 25, HALF_DOLLAR = 50, DOLLAR = 100 };`

7. 不确定。枚举类型是拿整形来存储的，但是这里是 `%s` 格式化字符串打印，则输出是不确定的。如果是 `%d` 则输出 32 48。

8. 不允许。`vs2019` 应该可以看，`vscode` 还没摸索这个问题。

9. 适用于字符类型。显示定义字符变量，保证一致性。

10. 所能表示的数的范围都是一样的。只不过区别在于对于一半数是如何解释的。

11. `float` 作为浮点型范围比 `int` 大。`float` 长度 32 位，其中 1 位是符号位，8 位是幂，剩下的 23 位是尾数。如果位数相同，那么它们能表示的不同值的**数量应该也是相同**的。但是由于浮点数系统中一个数有多种表示方式。譬如，0 就有很多种表示方式，所以在表示不同值的数量上 `float` 比 `int` 少。

12. 没啥不同。显示初始化就是将两个合到一起罢了，在定义的时候隐式的插入了一条赋值语句而已。

13. 左边仍旧可以。右边错误，不能该一个常量赋值。

14. 错。若嵌套代码块中包含了同名变量，那么外层同名变量将被隐藏。

15. 错。代码块中的局部变量永远不能从其它代码块中按名称直接访问。

16. 错。`static` 延长所修饰变量的生命周期，更改其存储类，但并不会更改其作用域。答案仍旧错误。

17. 这就是全局变量。不需要做任何操作。

18. 不会。仍然有内部链接。本文件后的所有函数均可以访问。

19. `extern int x;` 见 `demo14.c、demo15.c`。

20. 会。`static` 和 `extern` 两者就是矛盾的。 `static` 修饰本文件内的变量，在函数中的是静态变量。而 `extern` 表示的是其他文件定义的变量，显然两者是矛盾的。且单单用 `static` 来声明，却想获取其他文件的全局变量是不可能的。

21. 可能相同。函数内自动变量在堆栈中用完即销毁。第二次调用可能仍分配同样地址造成结果相同。但是堆栈信息被破坏时，这些变量的信息也将被破坏。只是巧合而已。

22. 内部：自动变量，每次调用函数都将被重新初始化，作用域仅在该函数内部，无连接。外部：静态变量，只初始化一次，在程序开始之前，具有文件范围和外部链接。

23. 见 `demo20.c`。个人觉得，`static char b = 2;` 其链接属性应该是 `internal`。而不应该是 `none`，毕竟要求 `x` 和 `y` 都要能访问到。

24. 有一个错误：第 6 行中 `c` 的声明与函数参数 `c` 冲突编译器将第 24 行标记为错误，称其与中的声明冲突第 20 行。这不应该是一个错误，因为第 20 行中 `y` 的范围在第 22 行用完了，因此不是冲突。

### 随笔

1. 整形

    基本的数据类型仅有 4 种：整形、浮点型、指针和聚合类型（数组、结构体等）。

   - `char` 字符类型、`short` 短整型、`int` 整形、`long` 长整形。
   - 均有两个版本：`signed` 有符号，`unsigned` 无符号。
   - 各类型变量表示范围

        ![3](https://raw.githubusercontent.com/Y-puyu/picture/main/images/20201226213147.png)

   - 变量范围的限制

        ![4](https://raw.githubusercontent.com/Y-puyu/picture/main/images/20201226213247.png)

        也可见 `demo01.c`，在包含了 `limits.h` 头文件后，就能直接打印各个变量的数值范围。
   - `char` 类型是用途十分广，但针对不同编译器来讲，若不显示写出 `char` 是否有符号，则编译器会根据自己的来。那么这样就很不方便程序移植，尽量我们使用 `0~127` 之间的 `char` 变量，这是有符号和无符号的交集。

2. 字面值

     - 字面值是**字面值常量**的缩写。即该实体指定了自身值后不允许发生改变。即 `const` 变量和 `#define` 字面值常量等。一些简单的练习见 `demo02.c`。

3. 枚举类型

     - 枚举类型用的相当少。`enum` 关键字来定义一个常量集合。枚举类型的实际值是整型值，故枚举类型的 `sizeof` 都是 4。
     - 枚举类型常量从 0 开始自增加 1。也可以在定义时候进行初始化。
     - 枚举类型是预处理指令 `#define` 的代替。
     - 用的却是很少很少。[具体可以参考这篇博文](https://blog.csdn.net/seicany/article/details/19615397)。

4. 指针

     - 在本章只是简单的提了一下指针类型。对于指针，一定要牢记：**指针变量也是变量。** 变量就有地址，就有保存的值。那么指针变量有其自身的地址，保存的是另一个变量的地址。我们可以通过解引用的方式得到该地址的值。
     - 声明指针变量的常见问题：`char* a, b, c;`。这个是新手常见的错误。这个其实只是申请了 `char` 类型的指针变量 `a`。至于，`b`、`c` 变量都只不过是 `char` 类型的。故可以发现，`*` 这个操作符是作用到变量名的，而不是作用到类型名。这个还会在第 6 章详细被讲到。故，正确是声明方式是 `char *a, *b, *c;`。
     - 至于指针和字符串和数组名之间的关系，留到第六章再说吧。在这书中只是简单了解下而已，没有深入讲解。还有那个 `const` 修饰指针所存地址和值的区别，都在第六章指针专题学习。
  
5. 字符串

    - `C` 语言没有直接实现字符串这个类型，但是通常使用字符数组来存储字符串。
    - 字符串是双引号包含一串字符，以 `\0` 结尾，其也被称为 `NUL` 字符。字符串中间不能存在 `\0`，不然它就作为了字符串终结标志。且因为 `NUL` 是一个不可打印的字符，所有用其来做结尾标志。

6. 声明及初始化

    - 声明变量：`char a, b, c;` 这样。由类型名加变量名组成。
    - 大多需要注意的是如果不显示声明 `unsigned` 无符号的话，默认的变量都是有符号的。至于 `char` 类型这个特殊的角色，得看编译器是如何定义的。所以，为了高可移植性，一般针对于 `char` 类型的话显示写出是否有符号也是很重要的。
    - 数组的声明都很简单，不再多说。
    - 指针的声明在上面也都提到了。
    - 至于，**隐式声明** 这玩意确实没啥用。书上所讲：如果编译器可以得到充足的信息，推断出一条语句实际上是一个声明时，若缺少类型名，编译器会假定其为整形。就比如，函数不写类型名，靠 `return 1;` 这样的操作，让编译器推断得到是整形。写上它不香吗？

7. `typedef` 的使用

    - 为类型起别名。在 `pair<int, int>`，在 `long long`，在结构体或函数指针等应用的很广泛。
    - 以前一直没注意指针的 `typedef`。相关练习见 `demo04.c`。

8. 常量

    - 拿 `const` 关键字来声明一个常量。声明后则其值不能改变。所以一般在声明就直接初始化。
    - `const` 与指针的三种搭配：
       `char const *p;` 指针保存的地址可以改变，指向值不能变。

       `char * const p;` 指针保存的地址不能改变，指向值可以变。

       `char const * const p;` 指针保存的地址和指向值都不能改变。

      `const char *p` 和 `char const *p`是一样的。都是保证指针 `p` 指向的值不能改变。

      简单练习见 `demo05.c`。

9. 作用域

    - 以前只是简单知道一点。现在是系统化的整理。
    - 编译器可以确认 4 种不同类型的作用域：**文件作用域、函数作用域、代码块作用域、原型作用域。** 我确实没听过这些专有名词。
    - 一对大括号就是一个代码块。在其内部声明的变量的作用域即为代码块作用域。显然，可能会有作用域重叠，变量名相同的问题。这里采用的是就近原则，重名覆盖。
    - 函数形参变量的作用域已经被扩展到了整个函数体中。即在函数最外层的局部变量其不允许同名形参的变量。
    - 至于**原型作用域**，只适用于函数原型中声明的参数名。在 `C` 语言中貌似还不能只写参数类型，忽略参数名。在 `cpp` 中支持该点。只要形参名不重复，在原型作用域下就没啥问题了。
    - **函数作用域**，什么 `goto` 语句都扯上来了。简单的 `goto` 语句，见 `demo07.c`。

10. 链接属性

    - 在多个源文件进行编译的时候，若产生相同变量名。怎么办呢？到底都指的是同一个实体还是不同实体呢？**标识符的链接属性** 专门来处理该问题。标识符的作用域与它的链接属性有关。
    - 三种链接属性：`external`（外部）、`internal`（内部）、`none`（无）。详情见：!

        ![5](https://raw.githubusercontent.com/Y-puyu/picture/main/images/20201226213247.png)

    - 书上这个例子已经很完美了：

        ![6](https://raw.githubusercontent.com/Y-puyu/picture/main/images/20201226213522.png)

    - 至于 `static` 和 `extern` 这两个关键字，都可用于修改标识符的链接属性。详见：

        ![7](https://raw.githubusercontent.com/Y-puyu/picture/main/images/20201226213605.png)

    这个概念大多涉及多文件编译啥的。目前还是用的很少很少。

    - `extern` 关键字。在我印象中只有 `extern c`。。。这篇博文讲的蛮不错的：[extern关键字，C语言extern关键字用法详解](http://c.biancheng.net/view/404.html)。

        程序编译单位是源文件，源文件内包含函数，函数内包含局部变量，而在函数外定义的变量将其称为外部变量也是全局变量。外部变量为静态存储，生存周期为整个程序的生存周期，被所有函数所共用，有效范围为定义位置至本源文件结束。

        如果全局变量不在文件的开头定义，有效的作用范围将只限于其定义处到文件结束。如果在定义点之前的函数想引用该全局变量，则应该在引用之前用关键字 `extern` 对该变量作“外部变量声明”，表示该变量是一个已经定义的外部变量。有了此声明，就可以从“声明”处起，合法地使用该外部变量。见 `demo08.c`。

    - 如果在变量定义之前要使用该变量，则应在使用之前加 extern 声明变量，使作用域扩展到从声明开始到本文件结束。

    - 如果整个工程由多个源文件组成，在一个源文件中想引用另外一个源文件中已经定义的外部变量，同样只需在引用变量的文件中用 `extern` 关键字加以声明即可。见 `demo09.c、demo10.c` 的演示。

        对于多个文件的工程，都可以采用上面这种方法来操作。对于模块化的程序文件，可在其文件中预先留好外部变量的接口，也就是只采用 `extern` 声明变量，**而不定义变量**，`demo09.c` 文件中的 `X` 与 `Y` 就是如此操作的。

        通常，这些外部变量的接口都是在模块程序的头文件中声明的，当需要使用该模块时，只需要在使用时具体定义一下这些外部变量即可。`demo10.c` 里的 `X` 与 `Y` 则是相关示例。

        不过，需要特别注意的是，由于用 `extern` 引用外部变量，可以在引用的模块内修改其变量的值，因此，如果**有多个文件同时要对应用的变量进行操作，而且可能会修改该变量，那就会影响其他模块的使用**。因此，我们要慎重使用。

        以下引自：[C语言中关键字auto、static、register、const、volatile、extern的作用](https://www.cnblogs.com/myvic/p/8970733.html)

        3.`static`

        3.1 `static` 存储类指示编译器在程序的生命周期内保持局部变量的存在，而不需要在每次它进入和离开作用域时进行创建和销毁。因此，使用 `static` 修饰局部变量可以在函数调用之间保持局部变量的值。

        3.2  `static` 修饰符也可以应用于全局变量。当 `static` 修饰全局变量时，会使变量的作用域限制在声明它的文件内。

        3.3  `static` 是全局变量的默认存储类

        4.`extern`

        4.1 `extern` 存储类用于提供一个全局变量的引用，全局变量对所有的程序文件都是可见的。当您使用 `extern` 时，对于无法初始化的变量，会把变量名指向一个之前定义过的存储位置。

        4.2 当您有多个文件且定义了一个可以在其他文件中使用的全局变量或函数时，可以在其他文件中使用 `extern` 来得到已定义的变量或函数的引用。可以这么理解，`extern` 是用来在另一个文件中声明一个全局变量或函数。

        `extern` 修饰符通常用于当有两个或多个文件共享相同的全局变量或函数的时候

11. 存储类型
    - C语言中提供了存储说明符 `auto，register，extern，static` 说明的四种存储类别。四种存储类别说明符有两种存储期：自动存储期和静态存储期。其中 `auto` 和 `register` 对应自动存储期。具有自动存储期的变量在进入声明该变量的程序块是被建立，它在该程序块活动时存在，退出该程序块时撤销。
    - 三个地方可以用于存储变量：普通内存、运行堆栈、寄存器。代码块外定义的变量都存在静态内存中，称为**静态变量。** 初始化为 0。
    - `auto` 关键字修饰的变量称为 **自动变量**，这个不同于 `C++` 的 `auto` 关键字用法啊。缺省的变量类型可以拿 `auto` 修饰，但它并不具备变量类型推导的功能，只是将该变量类型填充为 `int`。
    - `static` 关键字可以延长局部变量的生命周期，使该变量的存储类型从自动变为静态。但并不改变该变量的作用域。**函数的形参不可以被声明为静态**，因为实参总是在堆栈中传给函数，用于支持递归。可见 `demo12.c`。
    - `register` 关键字大多都是寄存器优化啥的，这个编译器有自己的想法不用太在意。或许真的很注重性能，可以使用该关键字进行修饰变量。
    - 注意：`register` 修饰的变量不能取地址。可见 `demo13.c`。不管这个 `register` 建议成功与否，均不能取地址。主要原因在于许多机器其实并没有对寄存器地址作定义还有数据恢复啥的，可参考：

        ![11](https://raw.githubusercontent.com/Y-puyu/picture/main/images/20201227172053.png)

12. 初始化

    - 静态变量及全局变量若不显式初始化，则会默认初始化为 0。局部变量及自动变量若不在定义的时候初始化，那么里面存的值就是垃圾。
    - 显式初始化其实是插入了一条隐式的赋值语句。效率都是一样的。

13. `static` 关键字

    - 面试过程中被问到 `n` 次。

        ![12](https://raw.githubusercontent.com/Y-puyu/picture/main/images/20201227172145.png)
    - `static` 修饰函数或者外部变量的时候，会修改其链接属性。会从 `external` 属性修改为 `internal` 属性。那么就只能在声明他们的源文件中访问了。
    - `static` 修饰局部变量则会将自动变量修改为静态变量，延长变量的声明周期。在整个程序的运行期间该变量将一直存在。

14. 作用域、存储类型示例
    - 很不错的例子：

        ![12](https://raw.githubusercontent.com/Y-puyu/picture/main/images/20201227172243.png)
        ![13](https://raw.githubusercontent.com/Y-puyu/picture/main/images/20201227172315.png)
        针对变量 `c`，它被 `static` 修饰，链接属性由 `external` 属性修改为 `internal` 属性。使得它只能在该源文件下被访问。可见 `demo14.c、demo15.c`。

### 疑问

 1. 链接属性问题。三大链接属性的应用。

 2. 一大堆的概念...链接属性那块，以前的知识盲区。

 3. `static` 和 `extern` 关键字的作用和用途。面试中疯狂考。只不过，`extern` 通常去考 `extern c` 去了。像多程序编译，全局变量声明即链接属性哪块很少被问到。

 4. 涉及到存储的几大关键字 `auto、static、register、const、volatile、extern` 一大堆。其中 `volatile` 关键字在线程安全、多线程编程中很常用：保证内存可见性。