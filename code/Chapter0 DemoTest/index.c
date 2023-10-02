/*
    1. 求阶乘 
*/
//#include<stdio.h>
//#define NUM 6
//
//int main(){
//    int temp = 1;
//    for (int i = 1; i <= NUM ; i++) {
//        temp = temp * i;
//    }
//    printf("阶乘值为%d\n",temp);
//
//    return 0;
//}

/*
    2. 判断闰年
        (1) 可以被4整除且不能被100整除
        (2) 可以被400整除
*/

//#include<stdio.h>
//int main(){
//    for(int a = 2000;a <= 2500;a++){
//        if((a%4==0&&a%100!=0)||(a%400==0)){
//            printf("%d\n",a);
//        }
//    }
//    return 0;
//}


/*
    3. 杨辉三角形
*/
#include<stdio.h>
#define LINE 7

int main(){
    int array[LINE][LINE] = {0};
    int i = 0,j = 0;
    for (i = 0; i < LINE; i++) {
        for (j = 0; j <= i; j++) {
            if(j==0||j==i){
                array[i][j] = 1;
            }else{
                array[i][j] = array[i-1][j-1]+array[i-1][j];
            }
        }
    }
    for (i = 0; i < LINE; i++) {
        for (j = 0 ; j <= i; j++) {
            printf("%3d ",array[i][j]);
        }
        printf("\n");
    }
    return 0;
}
