[让vc编译出的程序减小体积_24号杀手的博客-CSDN博客](https://blog.csdn.net/hpp24/article/details/53418163)

[VC编译出来的PE文件大小优化_jimoyangguang的博客-CSDN博客](https://blog.csdn.net/jimoyangguang/article/details/6319533)

## 去除清单文件

![image-20220724202629510](img/减少PE文件大小.assets/image-20220724202629510.png)

## 去除调试信息

![image-20220724202921989](img/减少PE文件大小.assets/image-20220724202921989.png)

## 更改对齐

```c
#pragma comment(linker,"/align:0x80") //定义最小节的大小,数值越小程序体积越小 ^_^
```

vs2019里允许的最小对齐是128，即0x80，不能比这还要小了

## 数据段和代码段放在一起

```c
#pragma comment(linker,"/merge:.data=.text") 
#pragma comment(linker,"/merge:.rdata=.text")
```



## 最大优化

![image-20220724204736523](img/减少PE文件大小.assets/image-20220724204736523.png)

## 取消一些检查和设置最小生成

![image-20220724204534969](img/减少PE文件大小.assets/image-20220724204534969.png)

## 更改main函数入口

![image-20220724205423653](img/减少PE文件大小.assets/image-20220724205423653.png)