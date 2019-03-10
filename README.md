# Linux和Unix测试工程

此工程专门为测试Linux和Unix系统编程而建

## 如何编译

1. 在Mac上采用Xcode编译
```bash
cd LinuxUnix
mkdir buildXcode && cd buildXcode
cmake -G "Xcode" ..
```
此时已经在buildXcode文件夹下生成了Xcode工程，直接打开并编译即可

2. 直接命令行编译（支持Mac和Linux）
```bash
cd LinuxUnix/
mkdir build && cd build
cmake .. # default is Debug
# for Debug: cmake -DCMAKE_BUILD_TYPE=Debug ..
# for Release: cmake -DCMAKE_BUILD_TYPE=Release ..
make
# for more details: make VERBOSE=1 
```
make命令会自动编译好各个模块

3. 在Windows上使用Cygwin + Visual Studio 2017进行编译
```bash
cd LinuxUnix/
mkdir buildVS && cd buildVS
cmake -G "Visual Studio 15 2017 Win64" ..
```
此时已经在buildVS文件夹下生成了Visual Studio工程，双击打开并编译即可

## 文件夹描述

1. apue：Unix环境高级编程，示例代码

2. ComputerLab：CSAPP中的几个计算机实验，包含解答方法和结论

3. csapp2e-code：CSAPP第二版示例代码，x86 32位版本

4. csapp3e-code：CSAPP第三版示例代码，x64 64位版本

5. Cstdlib：C语言标准库，包含标准库函数的基本用法

6. Demo：这是存放测试代码的主要路径

7. ExpertCProgramming：C专家编程，测试代码

8. FlexBison：Flex与Bison，测试和示例代码

9. SelfCultivation：程序员的自我修养，测试代码

10. tlpi：Linux系统编程手册，示例代码

11. unp：Unix网络编程，示例代码

12. 所有CMakeLists.txt：用于构建所有可执行文件
