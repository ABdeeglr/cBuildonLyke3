# README

## `.gitignore` Using Example

/bin -> folder:bin
bin/ -> files in bin

## Basic Skeleton of a Project

- LICENSE 如果你在项目中发布源码，你会希望包含一份协议。如果你不这么多，虽然你有代码的版权，但是通常没有人有权使用。
- Makefile 这个项目的主要构建文件。
- README.md 对你项目的简要说明。它以.md结尾，所以应该作为Markdown来解析。

- bin/ 放置可运行程序的地方。这里通常是空的，Makefile会在这里生成程序。
- build/ 当值库和其它构建组件的地方。通常也是空的，Makefile会在这里生成这些东西。
- src/ 放置源码的地方，通常是.c和.h文件。
- tests/ 放置自动化测试的地方。

src/dbg.h
