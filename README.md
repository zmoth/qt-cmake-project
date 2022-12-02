<h1 align="center">QT CMAKE DEMO</h1>

[**中文**](./README.md) | [**English**](./README_EN.md)<br/>

<!-- 目录 -->
# 目录
- [目录](#目录)
- [说明](#说明)
- [编译安装](#编译安装)
  - [依赖](#依赖)
  - [编译](#编译)
- [例程](#例程)
- [参考来源](#参考来源)

# 说明

本项目是一个基于cmake的qt工程模板，默认是生成一个动态链接库

example文件夹里生成可执行文件，并会调用构建的动态链接库


# 编译安装
## 依赖

Qt 5.15.2

## 编译

> 不要出现中文路径！

```bash
git clone --recurse-submodules git@github.com:QianMoth/qt-cmake-project.git
cd nodeeditor-p
mkdir build

# Release
cmake -S . -Bbuild -DCMAKE_BUILD_TYPE=Release
cmake --build build --config Release

# Debug
cmake -S . -Bbuild -DCMAKE_BUILD_TYPE=Debug
cmake --build build --config Debug
```

# 例程

exedemo 是一个可执行文件。

会创建一个基本的`QMainWindow`窗口，并会调用动态链接库中的`DebugDemo`类打印信息


# 参考来源

