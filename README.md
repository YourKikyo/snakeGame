## 这是一个用C语言写的贪吃蛇小游戏，使用的IDE是Dev-c++。

项目起始时间为 **2024.11.8**，结束时间为 **2024.11.10**，实际耗时10h左右。

大一上快结束了，如果你们的结课作业是这个，可以参考一下。

*并非完全由个人独立制作，原视频：[【C语言项目-贪吃蛇】期末大作业 | 实训小项目 【零基础可上手】](https://www.bilibili.com/video/BV12k4y1W7rp/?share_source=copy_web&vd_source=6609934db88434b0e35e722c658a5f29)*

*原视频代码有几处bug，我对其进行了完善。*

- bug 1 :
> - 当食物刷新在蛇身上：
> 
>   `creatFood()`函数进行递归时，未return结束上一个，导致指针索引时出错程序崩溃。
>
> - 解决方案1：
> 
>   放弃递归，改为循环(代码位于main.c注释部分中)
> 
> - 解决方案2：
> 
>   递归后加上`return`来结束上次递归，例：
>   ```
>   creatFood();
>   return;
>   ```


- bug 2 :
> - 当蛇上一次游戏结束时移动方向朝向初始移动方向的反向时开始游戏，会直接触发`biteSelf()`函数导致死亡
> 
> - 解决方案：
> 
>   在`initSnake()`函数中初始化蛇的移动方向为 R (向右)

- 改进 1 :
> - 游戏所有菜单界面均改为`_getch()`函数，便于操作

---

*接下来看看游戏内容的一些截图吧：*

- 游戏说明：

![](http://kikyopicbed.site/i/2024/11/28/67480c4f0c8d7.png)

- 游戏进行时界面：

![](http://kikyopicbed.site/i/2024/11/28/67480c50c80e9.png)

- 撞墙失败界面：

![](http://kikyopicbed.site/i/2024/11/28/67480d0818ecb.png)

- 咬到自己失败界面：

![](http://kikyopicbed.site/i/2024/11/28/67480d2031b8f.png)

# The END.




# This is a Snake game written in C language, using the IDE Dev-C++.

The project started on **2024.11.8** and ended on **2024.11.10**, taking about 10 hours in total.

The first semester of freshman year is coming to an end, if your final course project is this, you can refer to it.

*Not entirely made by myself, original video: [C Language Project - Snake Game](https://www.bilibili.com/video/BV12k4y1W7rp/?share_source=copy_web&vd_source=6609934db88434b0e35e722c658a5f29)*

*There were several bugs in the original video's code, which I have improved.*

- Bug 1:
> - When the food refreshes on the snake:
> 
>   The `creatFood()` function was recursive without a return to end the previous one, causing an index error and program crash.
> 
> - Solution 1:
> 
>   Abandon recursion and switch to a loop (code located in the commented section of main.c)
> 
> - Solution 2:
> 
>   After recursion, add a `return` to end the previous recursion, for example:
>   ```
>   creatFood();
>   return;
>   ```


- bug 2 :
> - When the snake's last game ended with the movement direction facing the opposite of the initial movement direction,starting the game would directly trigger the`biteSelf()`function,causing death.
> 
> - Solution：
> 
>   Initialize the snake's movement direction to R(right)in the`initSnake()`function.

- Improvement 1 :
> - All game menu interfaces have been changed to use the`_getch()`function for easier operation.

---

*Now let's see some shots in the game:*

- Game explainations:

![](http://kikyopicbed.site/i/2024/11/28/67480c4f0c8d7.png)

- Game in progress:

![](http://kikyopicbed.site/i/2024/11/28/67480c50c80e9.png)

- When hit the wall:

![](http://kikyopicbed.site/i/2024/11/28/67480d0818ecb.png)

- When bite itself:

![](http://kikyopicbed.site/i/2024/11/28/67480d2031b8f.png)

# The END.








