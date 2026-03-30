//#include <stdio.h>
//int main()
//{
//    int a,b,c,m;
//    scanf("%d %d",&a,&b);
//    m = a * b; 
//    while (c = a % b)
//    {
//        a = b;
//        b = c;
//    }
//    printf("%d",m/b);
//
//
//    return 0;
//}

//#include <stdio.h>
//int main()
//{
//    int a,b;
//    scanf("%d %d",&a,&b);
//    if (a > b)
//    {
//        a ^= b;
//        b ^= a;
//        a ^= b;
//    }
//    for (int i = 1; i <= a; ++i)
//    {
//        if (a % i == 0 && b % i == 0)
//        {
//            printf("%d ", i);
//        }
//    }
//
//    return 0;
//}

//#include <stdio.h>
//int main()
//{
//    int n,i = 1;
//    scanf("%d", &n);
//    while(i <= n)
//    {
//        if (n % i == 0)
//            printf("%d ", i);
//        ++i;
//    }
//
//    return 0;
//}
//#include <stdio.h>
//#include <math.h>
//int main()
//{
//    int a,i = 2,flag = 1;
//    scanf("%d",&a);
//    if (a == 1)
//        printf("0");
//    else if (a <= 3)
//        printf("1");
//    else
//    {
//        while(i <= sqrt((double)a))
//        {
//            if (a % i == 0)
//                flag = 0;
//            ++i;
//        }
//        printf("%d",flag);
//    }
//    
//    return 0;
//}
//#include <stdio.h>
//int main()
//{
//  	float sum = 0.0f;
//  	int flag = 1;
//  	int n;
//  	scanf("%d",&n);
//  	for (int i = 0; i < n; ++i)
//    {
//      	sum += (float)1 / (2 * i + 1) * flag;
//      	flag = -flag;
//    }
//  	printf("%f",sum);
//  	return 0;
//}
#include <stdio.h>
int main()
{
    printf("%d", -73 % 2);

    return 0;
}