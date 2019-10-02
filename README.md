# Linux 和 Unix 测试工程

此工程专门为测试 Linux 和 Unix 系统编程而建

## 如何编译

##### 1. 在 Mac 上采用 Xcode 编译

```bash
cd LinuxUnix
mkdir buildXcode && cd buildXcode
cmake -G "Xcode" ..
```

此时已经在 buildXcode 文件夹下生成了 Xcode 工程，直接打开并编译即可

##### 2. 直接命令行编译（支持 Mac 和 Linux）

```bash
cd LinuxUnix/
mkdir build && cd build
cmake .. # default is Debug
# for Debug: cmake -DCMAKE_BUILD_TYPE=Debug ..
# for Release: cmake -DCMAKE_BUILD_TYPE=Release ..
make
# for more details: make VERBOSE=1
```

make 命令会自动编译好各个模块

##### 3. 在 Windows 上使用 Cygwin + Visual Studio 2017 进行编译

```bash
cd LinuxUnix/
mkdir buildVS && cd buildVS
cmake -G "Visual Studio 15 2017 Win64" ..
```

此时已经在 buildVS 文件夹下生成了 Visual Studio 工程，双击打开并编译即可

## 文件夹描述

1. apue：Unix 环境高级编程，示例代码
2. ComputerLab：CSAPP 中的几个计算机实验，包含解答方法和结论
3. csapp2e-code：CSAPP 第二版示例代码，x86 32 位版本
4. csapp3e-code：CSAPP 第三版示例代码，x64 64 位版本
5. Cstdlib：C 语言标准库，包含标准库函数的基本用法
6. CTrapsAndPitfalls：C 陷阱与缺陷，测试代码
7. Demo：这是存放测试代码的主要路径
8. ExpertCProgramming：C 专家编程，测试代码
9. FlexBison：Flex 与 Bison，测试和示例代码
10. mcic：现代编译原理-C 语言描述，示例代码
11. ProgrammingPearls：编程珠玑，示例代码
12. SelfCultivation：程序员的自我修养，测试代码
13. Shell：shell 脚本测试代码
14. tlpi：Linux 系统编程手册，示例代码
15. unp：Unix 网络编程，示例代码
16. xlibprgs3：Xlib 相关示例代码
17. 所有 CMakeLists.txt：用于构建所有可执行文件
