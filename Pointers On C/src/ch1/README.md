# 第一章：快速上手

简单看了看 `printf` 的格式化和骚操作，顺手找了两个官方文档：

- C++ 文档：[http://www.cplusplus.com/](http://www.cplusplus.com/reference/cstdio/printf/?kw=printf)
- C 文档，包含有 C++：[https://en.cppreference.com/](https://en.cppreference.com/mwiki/index.php?title=Special%3ASearch&search=printf&button=)

`printf` 的返回值是输出到屏幕的字符个数，故可以嵌套 `printf` 来输出一个整数的位数，很是秀...

`printf` 可以控制输出字符颜色，可以用这个功能实现一个简单的带颜色的日志系统，看着能养眼点。也是一个在黑框下独有的浪漫了。

---

至于后面就是简单的处理字符串相关函数，如： `strcpy`、`strncpy`、`strcat`、`strstr`、`strchr` 等等，只是简单的了解下。

有关于 `ch1` 中一开始给的样例程序源码，在 `supporting_src` 文件夹中的 `ch1` 的 `rearrang.c` 文件即是。
