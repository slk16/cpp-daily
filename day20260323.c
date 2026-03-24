//#include <stdio.h>
//
//int main()
//{
//    char ch;
//    scanf("%c",&ch);
//    if (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z')
//    {
//        ch ^= 32;
//        printf("%c", ch);
//    }
//    else
//    {
//        printf("%c",ch);
//    }
//
//    return 0;
//}

//#include <stdio.h>
//int main()
//{
//    char a,b,c;
//    scanf("%c%c%c",&a,&b,&c);
//    a -= '0';
//    b -= '0';
//    c -= '0';
//    printf("%d",100*a+10*b+c == a*a*a + b*b*b + c*c*c);


//    return 0;
//}

//#include <stdio.h>
//int main()
//{
//    char arr[5] = { 0 };
//    scanf("%c%c%c%c%c",arr,arr+1,arr+2,arr+3,arr+4);
//    printf("%d",arr[0] == arr[4] && arr[1] == arr[3]);
//    return 0;
//}


//#include <stdio.h>

//int main()
//{
//    int score;
//    scanf("%d",&score);
//    if (score >= 90)
//        printf("A");
//    else if(score >= 80)
//        printf("B");
//    else if (score >= 70)
//        printf("C");
//    else if (score >= 60)
//        printf("D");
//    else
//        printf("E");

//    return 0;
//}


//#include <stdio.h>
//
//int main()
//{
//    int year,month;
//    scanf("%d %d",&year,&month);
//    if (month % 2 == 1 && month <8 || month >7 && month%2 == 0)
//    {
//        printf("31");
//    }
//    else if (month == 2)
//    {
//        if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
//            printf("29");
//        else
//            printf("28");
//    }
//    else
//    {
//        printf("30");
//    }
//
//    return 0;
//}


//#include <stdio.h>
//
//int main()
//{
//
//    float w,m,sum = .0f;
//    scanf("%f %f",&w,&m);
//    if (w > 50)
//    {
//        sum = w - 50 + 66;
//    }
//    else if (w > 20)
//    {
//        sum = 1.2 * (w - 20) + 30;
//    }
//    else if (w > 10)
//    {
//        sum = 1.4 * (w - 10) + 16;
//    }
//    else
//    {
//        sum = 1.6 * w;
//    }
//    printf("应付=%.2f 找零=%.2f\n", sum,m-sum);
//
//
//
//    return 0;
//}
//
//#include <stdio.h>
//
//int main()
//{
//    int a;
//    scanf("%d",&a);
//    if (a < 0)
//    {
//        printf("%d", -a);
//    }
//    else
//    {
//        printf("%d", a);
//    }
//
//    return 0;
//}
//#include <stdio.h>
//#include <stdlib.h>  // 包含 abs 函数
//
//int main() {
//    int num;
//    scanf("%d", &num);          // 从键盘读取整数
//    printf("%d\n", abs(num));   // 输出绝对值
//    return 0;
//
//}
//#include <stdio.h>
//
//int main() {
//    double weight, money, price, cost, change;
//    
//    // 读取西瓜重量和顾客付款
//    scanf("%lf %lf", &weight, &money);
//    
//    // 根据重量确定单价
//    if (weight >= 50) {
//        price = 1.0;
//    } else if (weight >= 20) {
//        price = 1.2;
//    } else if (weight >= 10) {
//        price = 1.4;
//    } else {
//        price = 1.6;
//    }
//    
//    // 计算应付金额和找零
//    cost = weight * price;
//    change = money - cost;
//    
//    // 输出结果，保留两位小数
//    printf("应付=%.2f 找零=%.2f\n", cost, change);
//    
//    return 0;
//}
//#include <stdio.h>
//
//int main() {
//    float weight, money;
// 	scanf("%f %f",&weight,&money);
//  	printf("应付=%.2f 找零=%.2f",weight,money -weight);
//
//    return 0;
//
//}

//#include <stdio.h>
//int main()
//{
//    int min,temp;
//    int arr[5] = {0};
//    for (int i = 0; i < 5; ++i)
//    {
//        scanf("%d",arr+i);
//    }
//    for (int i = 0;i < 4; ++i)
//    {
//        min = i;
//        for (int j = i;j < 5; ++j)
//        {
//            if (arr[min] > arr[j])
//            {
//                min = j;
//            }
//        }
//        temp = arr[i];
//        arr[i] = arr[min];
//        arr[min] = temp;
//    }
//    for (int i = 0; i < 5;++i)
//    {
//        printf("%d ",arr[i]);
//    }
//
//    return 0;
//}
//#include <stdio.h>
//
//int main() {
//    char ch, y;
//    scanf("%c", & ch);
//    if (ch >= 'a' && ch <= 'z') {
//        y = ch - 'a' + 'A';
//        printf("%c%c", ch, y);
//        return 0;
//    } else {
//        printf("%c", ch);
//    }
//}
//#include <stdio.h>
//
//#define min(a, b)((a) < (b) ? (a) : (b))
//int main() {
//    float a, b, c, d;
//    scanf("%f，%f，%f，%f", & a, & b, & c, & d);
//    printf("最小值是：%.2f", min(min(a, b), min(c, d)));
//    return 0;
//
//}
#include <stdio.h>

int main() {
   	float a,b,c,d;
  	float min = a;
  	scanf("%f，%f，%f，%f",&a,&b,&c,&d);
	if (min > c)
      	min = c;
  	if (min > b)
      	min = b;
  	if (min >d)
      	min = d;
  	printf("最小值是：%.2f",min);
    return 0;
}