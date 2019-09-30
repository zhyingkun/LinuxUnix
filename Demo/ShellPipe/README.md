# 测试命令行管道

## 操作与说明

1. 命令`./cmd.sh | ./sleep_cmd.sh`

具体操作和对应输出如下：

```bash
$ ./cmd.sh | ./sleep_cmd.sh
In sleep_cmd.sh
  501 24754 24276   0  5:23PM ttys003    0:00.01 /bin/sh ./sleep_cmd.sh
$ echo ${PIPESTATUS[@]}
0 0
```

由于 cmd.sh 命令启动之后输出内容到管道就立即结束了，因此，sleep_cmd.sh 在休眠了 1 秒之后检索的进程中就不包含 cmd.sh。
此时查看两个进程的退出码，均为 0，符合预期。

2. 命令`./sleep_cmd.sh | ./cmd.sh`

具体操作和对应输出如下：

```bash
$ ./sleep_cmd.sh | ./cmd.sh
In cmd.sh
  501 24772 24276   0  5:29PM ttys003    0:00.01 /bin/sh ./sleep_cmd.sh
  501 24773 24276   0  5:29PM ttys003    0:00.01 /bin/sh ./cmd.sh
In sleep_cmd.sh
$ echo ${PIPESTATUS[@]}
141 0
$ kill -l | grep SIGPIPE
13) SIGPIPE     14) SIGALRM     15) SIGTERM     16) SIGURG
```

sleep_cmd.sh 进程启动之后，会等待一秒再向标准输出打印进程信息，这个时候其标准输出通过管道连接到 cmd.sh 的标准输入，但是，cmd.sh 在启动之后打印完信息就立刻退出了，显然 cmd.sh 的标准输入也已经关闭，所以，sleep_cmd.sh 就变成往读端已经关闭的管道写数据，会触发 SIGPIPE 信号，我们通过命令查看 SIGPIPE 信号的值，为 13，128+13=141，这刚好是 sleep_cmd.sh 的退出码，验证了 sleep_cmd.sh 是由于 SIGPIPE 信号退出进程的。（进程由于信号的终止，其 8 位退出码为 128+信号值，也就是无符号的 141）

3. 命令`./sleep_cmd.sh | ./myecho Test`

具体操作和对应输出如下：

```bash
$ make
gcc -o myecho --std=c11 myecho.c
$ ./sleep_cmd.sh | ./myecho Test
Test
In sleep_cmd.sh
In myecho, pid:24869  ppid:24276
$ echo ${PIPESTATUS[@]}
141 0
$ make clean
```

我们在 myecho 刚启动的时候，先打印关闭其标准输入并打印 Test，之后等待两秒再输出 pid 信息，保证了 myecho 在 sleep_cmd.sh 之后结束进程，查看结果我们可以知道，确实是管道的读端被关闭导致的 sleep_cmd.sh 异常退出
