# 主线程先于其他线程退出

1. 测试用例用于说明主线程先于其他线程结束执行状态
2. 可参考[我的博客](https://www.zhyingkun.com/markdown/linuxnote/)

## 操作与结果

```bash
$ cd MainThreadExit
$ make
$ ./main
In Main Thread, create thread now
In Main Thread, pthread_create ret: 0
In Main Thread, main thread exit now
In thread: ./main TERM_PROGRAM=vscode 42
At Exit Now
```

结果一目了然：

1. 处于主线程栈顶的参数和环境变量依然可用
2. 主线程栈局部变量依旧可以访问
3. 其他线程都退出之后，atexit 注册的函数才会被回调，最后进程退出
