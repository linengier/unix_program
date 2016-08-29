/*************************************************************************
    > File Name: gettime.c
    > Author: linengier
    > Mail: linengier@126.com 
    > Created Time: 2016年08月29日 星期一 11时07分20秒
 ************************************************************************/

#include <stdio.h>
#include <time.h>

#include <unistd.h>
#include <sys/time.h>

int main()
{
    struct tm * pt1, * pt2;
    time_t t;
    time(&t);
    pt1 = gmtime(&t);
    pt2 = localtime(&t);
    t =  mktime(pt1);
    printf("%d-%d-%d %d-%d-%d\r\n", pt1->tm_year+1900, pt1->tm_mon+1, pt1->tm_mday, pt1->tm_hour, pt1->tm_min, pt1->tm_sec);
    printf("%d-%d-%d %d-%d-%d\r\n", pt2->tm_year+1900, pt2->tm_mon+1, pt2->tm_mday, pt2->tm_hour, pt2->tm_min, pt2->tm_sec);

    
    struct timeval tv;
    struct tm pt3;
    gettimeofday(&tv, NULL);
    pt3 = (*localtime(&tv.tv_sec));
    printf("%d-%d-%d %d-%d-%d\r\n", pt3.tm_year+1900, pt3.tm_mon+1, pt3.tm_mday, pt3.tm_hour, pt3.tm_min, pt3.tm_sec);

    
    return 0;
}
