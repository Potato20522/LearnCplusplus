//函数的实现
//初始化环境句柄
int socketclient_init(void** handle) {
    return 0;
}

//发送信息
int socketclient_send(void* handle, void* buf, int* len) {
    return 0;
}

//接收信息
int socketclient_recv(void* handle, void* buf, int* len) {
    return 0;
}

//释放资源
int socketclient_destory(void* handle) {
    return 0;
}

//第二套接口
//初始化环境句柄
int socketclient_init2(void **handle){
    return 0;
}

//发送信息
int socketclient_send2(void *handle, void *buf, int *len){
    return 0;
}

//接收信息
int socketclient_recv2(void *handle, void **buf, int *len){
    return 0;
}

int socketclient_free2(void **buf){
    return 0;
}

//释放资源
int socketclient_destory2(void **handle){
    return 0;
}