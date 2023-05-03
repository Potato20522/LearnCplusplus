# 学习资源

- [Rust Crates 实践指南 - Rust Crates 实践指南 - The Guide to Rust Crates (gitcode.host)](https://mirrors.gitcode.host/zzy/rust-crate-guide/index.html)

- https://www.runoob.com/rust/rust-setup.html
- https://www.bilibili.com/video/BV1hp4y1k7SV

# 环境搭建



- 下载安装
- 使用VSCode
- 安装插件：rust-analyzer和Native Debug 

# HelloWorld

新建文件hello.rs

```rust
fn main() {
    println!("Hello, world!");
}
```

rust程序也是以main函数作为入口，println!是一个rust macro（宏），不是函数

使用rustc命令进行编译：

```cmd
rustc hello.rs
```

生成了hello.exe、hello.pdb（包含调试信息）文件

运行hello.exe，得到输出：

```
Hello, world!
```

# 使用cargo创建rust项目

cargo类似于java中的maven，负责构建系统和依赖管理

安装rust环境时会自带cargo

相关教程参考：https://www.runoob.com/rust/cargo-tutorial.html

创建rust项目：cargo new hello

会在当前目录生成hello目录，里面有：

- src/main.rs
- Cargo.toml

```cmd
cd hello
cargo build 
cargo run 
```

这就构建并运行成功了



## toml文件介绍

toml(Tom's Obvious,Minimal Language)格式，是Cargo的配置格式

```toml
[package]
name = "hello"
version = "0.1.0"
edition = "2021"

# See more keys and their definitions at https://doc.rust-lang.org/cargo/reference/manifest.html

[dependencies]
```

[package]表示下方内容是用来配置包的

[dependencies]下面会列出项目的依赖项

在rust里面，代码的包成为crate

如果创建项目时没有使用 cargo，也可以把项目转化为使用 cargo:把源代码文件移动到src下创建 Cargo.toml并填写相应的配置

## cargo命令

**cargo build 创建可执行文件**，在target目录下。

第一次运行cargo build 会在顶层目录生成cargo.lock文件，该文件负责追踪项目依赖的精确版本，不需要手动修改该文件



**cargo run 构建并运行项目**

- 如果之前编译成功过，并且源码没有改变，那么就会直接运行二进制文件



**cargo check 检查代码，确保能通过编译，但是不产生任何可执行文件**

- cargo check 比 cargo buil快得多，编写代码的时候，可以连续反复的使用cargo check检查代码，提高效率



**cargo build --release 为发布构建**

- 编译时会进行优化代码会运行的更快，但是编译时间更长
- 会在 target/ release而不是 target/debug生成可执行文件

# 配置 Rust 工具链的国内源
