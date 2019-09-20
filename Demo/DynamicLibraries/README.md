# 测试 7 种库文件

## MacOSX 4 种

```bash
cd DynamicLibraries
mkdir buildXcode && cd buildXcode
cmake -G "Xcode" ..
open DynamicLibraries.xcodeproj
# 在Xcode中执行ALL_BUILD目标
cd Debug
otool -hv libhello.so
otool -hv hello.bundle/Contents/MacOS/hello
otool -hv libhello.1.0.dylib
otool -hv hello.framework/hello
```

## Linux 1 种

```bash
cd DynamicLibraries
mkdir build && cd build
cmake ..
make
file libhello.so.1.0
```

## Windows 1 种

```bash
cd DynamicLibraries
mkdir buildVS && cd buildVS
cmake -G "Visual Studio 15 2017 Win64" ..
file Debug/hello.dll
```

## C# dll 库 1 种

```bash
cd DynamicLibraries/CSharp
xbuild hello.sln
# msbuild hello.sln
file lib/Debug/hello.dll
```
