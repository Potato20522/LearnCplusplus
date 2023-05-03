视频教程：https://www.bilibili.com/video/BV1hp4y1k7SV

# 引入--猜数游戏

目标：

- 生成一个1到100间的随机数
- 提示玩家输入一个猜测猜完之后，程序会提示猜测是太小了还是太大了
- 如果猜测正确，那么打印出一个庆祝信息，程序退出

```rust
use std::io;//prelude是rust的默认导入库，类似于java.lang包

fn main() {
    println!("猜数!");
    println!("猜测一个数!");
    //声明一个可变的变量
    let mut guss = String::new();//::表示关联函数，类似java中的静态方法

    //&mut guss表示引用传参，引用默认也是不可变的，因此这里加了mut
    //read_line返回类型是io::Result这个枚举，有Ok和Err
    io::stdin().read_line(&mut guss).expect("无法读取行");
    println!("你猜测的数是:{}!", guss);
}

```

rust标准库并没有提供生成随机数的，需要引入三方库。

rust三方库网站是https://crates.io/，搜索rand就是了

-