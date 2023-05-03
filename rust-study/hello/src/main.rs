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
