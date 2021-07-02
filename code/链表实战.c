#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stack>

using namespace std;
struct student{
  int num;//学号
  char name[20];//姓名
  int age;//年龄
  struct student *next;//指向下一个节点的指针
};

struct student *createList();//建立学生信息
void displayList(struct student *head);//按照建立顺序输出学生信息
struct student *reverseList(struct student *head);//与建立顺序相反,逆序顺序输出学生信息
struct student *deleteNodes(struct student *head);//删除某个学生信息
struct student *insertNodes(struct student *head);//插入某个学生的信息
void search_student_info(struct student *head);//查找对应学生信息
void modify_student_info(struct student *head);//修改学生信息
struct student *destroyList(struct student *head);//清空整个链表
struct student *head = NULL;

int main(){
  int select;//根据对应不同select的值,调用不同的函数
  do{
    printf("请输入select的值:");
    scanf("%d",&select);
    switch(select){
      case 1:
        head = createList();
        break;
      case 2:
        displayList(head);
        break;
      case 3:
        head = deleteNodes(head);
        break;
      case 4:
        head = insertNodes(head);
        break;
      case 5:
        search_student_info(head);
        break;
      case 6:
        modify_student_info(head);
        break;
      case 7:
        head = reverseList(head);
//        displayList(head);
        break;
      case 8:
        head = destroyList(head);
        break;
      
    }
  }while(select!=0);
  return 0;
}
//1. 建立学生信息
struct student *createList(){
  struct student *head;//头节点
  struct student *p1;//开辟新节点
  struct student *p2;//与p1连接
  int num1;
  char name1[20];
  int age1;
  head = NULL;
  int count = 1;
  
  printf("请输入第1个学生的学号、姓名、年龄(用空格分隔):");
  scanf("%d%s%d",&num1,&name1,&age1);
  while(age1>0){
    p1 = (struct student*)malloc(sizeof(struct student));
    p1->num = num1;
    strcpy(p1->name,name1);
    p1->age = age1;
    p1->next = NULL;
    if(head == NULL){
      head = p1;
    }else{
      p2->next = p1;
    }
    p2 = p1;
    printf("请输入第%d个学生的学号、姓名、年龄(用空格分隔):",++count);
    scanf("%d%s%d",&num1,&name1,&age1);
  }
  return head;
}

//2. 与建立顺序相同输出学生信息
void displayList(struct student *head){
  struct student *p;
  int n = 0;
  if(head!=NULL){
    printf("顺序输出链表中学生信息如下:\n");
    for(p=head;p!=NULL;p=p->next){
      printf("学号:%-6d 姓名:%-20s 年龄:%-6.1d\n",p->num,p->name,p->age);
      n++;
    }
    printf("学生总数:%d\n",n);
  }else{
    printf("空链表!\n");
  }
}

//3. 根据学号删除对应学生信息
struct student *deleteNodes(struct student *head){
  
  struct student *p1;
  struct student *p2;
  
  int num2;//要删除学生的学号
  printf("请输入要删除学生的学号:");
  scanf("%d",&num2);
  
  if(head == NULL){
    printf("链表为空\n");
    return head;
  }
  p2 = head;
  
  while(num2!=p2->num&&p2->next!=NULL){ //查找要删除的节点
    p1 = p2;
    p2 = p2->next;
  }
  
  if(num2 == p2->num){
    if(p2 == head){ //要删除的是头节点
      head = p2->next;
    }else{ //其他节点
      p1->next = p2->next;
    }
    free(p2);
    printf("删除了学号为%d的学生信息!\n",num2);
  }else{
    printf("该生不存在!\n");
  }
  return head;
}
  
//4. 根据学号的大小插入某个学生的信息
struct student *insertNodes(struct student *head){
  struct student *p;//待插入节点
  struct student *p1;//待插入节点的前驱节点
  struct student *p2;//待插入节点的后继节点
  p2 = head;
  p = (struct student *)malloc(sizeof(struct student));
  printf("请输入要加入学生的学号、姓名、年龄:");
  scanf("%d%s%d",&p->num,&p->name,&p->age);
  if(head == NULL){ //若为空链表,则相当于创建一个新节点
    head = p;
    p->next = NULL;
  }else{
    while(p->num > p2->num&&p2->next!=NULL){ //查找待插入的位置
      p1 = p2;
      p2 = p2->next;
    }
    if(p->num < p2->num){ //头节点和中间任意节点的插入
      if(p == head){ //头节点
        head = p;
        p->next = p1;
      }else{ // 中间任意节点
        p1->next = p;
        p->next = p2;
      }
    }else{//尾节点的插入
      p2->next = p;
      p->next = NULL;
    }
  }
   return head;
}

//5. 根据学号查找对应学生的其他信息
void search_student_info(struct student *head){
  struct student *p;
  int num;//要查找对应学生的学号信息
  printf("请输入要查找学生的学号:");
  scanf("%d",&num);
  p = head;
  //非空链表的情况下
  if(head != NULL){
    while(p->num!=num&&p->next!=NULL){
      p=p->next;
    }
    //不满足while循环的第一个条件
    if(p->num==num){
      printf("你所查找的学号为%d的学生信息如下:\n",num);
      printf("学号:%-6d 姓名:%-20s 年龄:%-6.1d\n",p->num,p->name,p->age);
    }else{
      //不满足while循环的最后一个条件
      printf("没有找到学号为%d的学生信息,请确认学号是否正确!\n",num);
    }
  }else{//空链表的情况
    printf("空链表!");
  }
}

//6. 根据学号修改学生信息
void modify_student_info(struct student *head){
  struct student *p;
  int num;
  char name[20];
  int age;
  printf("请输入您要修改学生的学号:");
  scanf("%d",&num);
  p = head;
  if(head!=NULL){
    while(p->num!=num&&p->next!=NULL){
      p = p->next;
    }
    if(p->num==num){
      printf("请输入您要更改后的信息:\n");
      scanf("%d%s%d",&num,&name,&age);
      p->num = num;
      strcpy(p->name,name);
      p->age = age;
    }else{
      printf("没有找到学号为%d的学生信息,请确认学号信息是否正确!\n");
    }
  }else{
    printf("空链表\n");
  }
  
  
}
 
//7. 与建立顺序相反输出学生信息
struct student *reverseList(struct student *head){
  /*
    1. 借助递归
  */
  /*
  struct student *p;
  p = head;
  if(p!=NULL){
    reverseList(p->next);
    printf("学号:%-6d 姓名:%-20s 年龄:%-6.1d\n",p->num,p->name,p->age);
  }
  */
  
  /*
    2. 借助栈
  */
  struct student *p;
  p = head;
  stack<int> s;
  while(p!=NULL){
    s.push(p->num);
    p = p->next;
  }
  while(!s.empty()){
    p = head;
    while(s.top()!=p->num){
      p = p->next;
    }
    if(s.top()==p->num){
      printf("学号:%-6d 姓名:%-20s 年龄:%-6.1d\n",p->num,p->name,p->age);
    }
    s.pop();
  }
  return head;
   
  /*
    3. 改变单链表指针指向
    改变指针指向后，原链表也会被修改
  */
  
  /*
  struct student *pre;
  struct student *post;
  struct student *p;
  pre = NULL;
  post = NULL;
  while(head!=NULL){
    post = head->next;
    head->next = pre;
    pre = head;
    head = post;
  }
  return pre;
  */
  
}
 
//8. 清空整个链表
struct student *destroyList(struct student *head){
  struct student *p;
  p = head;
  if(p==NULL){
    printf("空链表!\n");
  }
  while(p!=NULL&&p->next!=NULL){
    p = p->next;
    free(p);
  }
  printf("信息删除完毕!\n");
  head = NULL;
  return head;
}
