# 查看 C/C++代码对应的汇编指令

1. C/C++代码经过 gcc/g++编译之后，会有一定的目标指令模式
2. switch+case 在 case 数量大于 4 并且 case 枚举连贯的时候，会编译成汇编语言的查表（也就是数组映射）

## 如何使用

```bash
cd LinuxUnix/Demo/asm
make all
make clang
make cpplang
make clean
```
