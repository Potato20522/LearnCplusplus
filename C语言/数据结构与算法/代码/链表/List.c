#include <stdio.h>
#include <stdlib.h>
#define uint unsigned int
//节点结构体
typedef struct NODE
{
    int data;           // 数据
    struct NODE *next;  // 节点指针
} Node;

Node *headNode = NULL;  // 头节点
Node *endNode = NULL;   // 尾节点

//函数声明 自定义函数函数名首字母大写，以免和库函数冲突
Node* CreateNode(int data);             // 创建节点
void AddNode(int data);                 // 增加节点
uint GetListSize(void);                 // 获取大小
Node* FindNode(uint index);             // 查找节点
void ReadNode(uint index);              // 读取节点
void ReadList(void);                    // 读取链表
void SetNode(uint index, int data);     // 设置节点
void DeleteList(void);                  // 删除链表
void DeleteNode(uint index);            // 删除节点
void InsertNode(uint index, int data);  // 插入节点

//创建节点
Node* CreateNode(int data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;

    return node;
}

//增加节点
void AddNode(int data)
{
    Node *node = CreateNode(data);

    if (headNode == NULL)   //链表为空
    {
        headNode = node;
    }
    else  //链表已存在节点
    {
        endNode->next = node;
    }
    
    endNode = node;
}

//获取大小 通过index找到节点并返回
uint GetListSize(void)
{
    Node *node = headNode;
    uint size = 0;

    while (node != NULL)
    {
        node = node->next;
        size++;
    }
    
    return size;
}

//查找节点
Node* FindNode(uint index)
{
    Node *node = headNode;
    uint currentIndex = 0;

    if (node == NULL)
    {
        printf("链表为空！\n");
        return NULL;
    }        

    while (node != NULL)
    {
        if (index == currentIndex)
        {
            return node;
        }
        
        node = node->next;
        currentIndex++;
    }

    return NULL;
}      

//读取节点 通过index读取节点的数据并打印出来。
void ReadNode(uint index)
{
    Node *node = FindNode(index);   // 查找节点

    if (node == NULL)
    {
        printf("无此节点！\n");
    }        
	else
	{
		printf("%s: Node%d's data = %d\n\n", __FUNCTION__, index, node->data);
	}    
}  

//读取链表 遍历整个单链表并打印出来。
void ReadList(void)              
{
    Node *node = headNode;
    if (node == NULL)
    {
        printf("链表为空！\n");
    }
    else
    {
        for (int index = 0; index < GetListSize(); index++)
        {
            printf("%s: Node%d's data = %d\n", __FUNCTION__, index, node->data);
            node = node->next;
        }
        printf("\n");
    }
}

//设置节点
void SetNode(uint index, int data)
{
    Node *node = FindNode(index);   // 查找节点 

    if (node == NULL)
    {
        printf("无此节点！\n");
        return;
    }        

    node->data = data;
}

//删除链表 删除整个单链表。
void DeleteList(void)
{
    Node *node = headNode;

    if (node == NULL)
    {
        printf("链表为空！\n");
        return;
    }

    while (node != NULL)
    {
        Node *temp = node;
        node = node->next;
        free(temp);
    }

    headNode = NULL;
    endNode = NULL;
        
    printf("%s: The LINKED LIST has cleaned.\n", __FUNCTION__);
}    

//删除节点  通过index删除节点
void DeleteNode(uint index)
{
    Node *foundNode = FindNode(index);   // 查找节点

    if (foundNode == NULL)  // 无此节点
    {
        return;
    }
    else
    {
        Node *node = headNode;

        if (headNode == endNode)    // 只有一个节点
        {
            free(headNode);
            headNode = NULL;
            endNode = NULL;
        }
        else    // 大于一个节点
        {

            if (foundNode == headNode) // 删除头节点
            {
                Node *oldHeadNode = headNode;   // 暂存旧节点
                headNode = headNode->next;      // 将第二个节点设置为新头节点
                free(oldHeadNode);              // 释放头旧节点的内存
            }
            else if (foundNode == endNode)   // 删除尾节点
            {
                while (node->next != foundNode) // 找到要删除的节点
                {
                    node = node->next;
                }

                // 将倒数第二个节点的next置为NULL后就相当于设置为尾节点
                node->next = NULL;  
                free(foundNode);    //释放被删节点的内存
            }
            else    // 删除中间个某节点
            {
                while (node->next != foundNode) // 找到要删除的节点
                {
                    node = node->next;
                }

                // 将 被删节点 的 上一个节点的next 设置为 被删节点 的 下一个节点
                node->next = foundNode->next;   
                free(foundNode);    //释放被删节点的内存
            }
        }
    }

    printf("Node%d has deleted!\n\n", index);
}

//插入节点
void InsertNode(uint index, int data)
{
    Node *newNode = CreateNode(data);
    Node *insertNode = FindNode(index);

    if (headNode == NULL)
    {
        printf("链表为空！\n");
        return;
    }
    else if (insertNode == NULL)
    {
        printf("无此节点！\n");
        return;
    }
    else
    {
        // 将新节点的next 设置为 当前插入位置节点 的 下一个节点
        newNode->next = insertNode->next; 
        
        // 将 当前插入位置节点的next 设置为 newNode
        insertNode->next = newNode;
    }
}      
       
int main() 
{
    // 增加节点
    AddNode(11);
    AddNode(22);
    AddNode(33);
    AddNode(44);
    AddNode(55);
    AddNode(66);

    // 设置节点
    SetNode(3, 99);

    // 获取大小
    printf("Linked list size: %d\n\n", GetListSize());

    // 读取链表
    ReadList();

    // 读取节点
    ReadNode(2);    

    // 删除节点
    DeleteNode(0);  // 头节点
    DeleteNode(2);  // 中间节点
    DeleteNode(GetListSize() - 1);  // 尾节点

    // 获取大小
    printf("Linked list Size: %d\n\n", GetListSize());

    // 插入节点
    InsertNode(0, 7);    // 头节点后插入
    InsertNode(2, 8);    // 中间节点后插入
    InsertNode(GetListSize() - 1, 9);    // 尾节点后插入

    // 读取链表
    ReadList();

    // 删除链表
    DeleteList();

    return 0;
}