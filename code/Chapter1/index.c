//
//  Created by 石璞东 on 2023/10/3.
//

/*
    1. 求两数之和
*/

// #include <stdio.h>
// int main() {
//     int a,b,sum = 0;
//     printf("请输入a和b的值：");
//     scanf("%d %d",&a,&b);
//     sum = a + b;
//     printf("两数之和为：%d\n",sum);
//     return 0;
// }

/*
    2. 求两数中的较大者
*/
#include <stdio.h>
int main() {
    int a,b;
    // 函数声明
    printf("请输入a、b的值：");
    scanf("%d %d",&a,&b);
    // 函数调用
    if(a>b){
        printf("较大者为%d\n",a);
    }else{
        printf("较大者为%d\n",b);
    }
    return 0;
}
