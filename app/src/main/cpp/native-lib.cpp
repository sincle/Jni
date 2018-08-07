#include <jni.h>
#include <string>
#include <iostream>
#include<Android/log.h>
#include "native-lib.h"
#include <cstdlib>
#include <ctime>

#define TAG "android_jni" // 这个是自定义的LOG的标识
#define LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,TAG,__VA_ARGS__) // 定义LOGD类型
#define random(x)(rand()%x)
using namespace std;
extern "C" JNIEXPORT jstring

JNICALL
Java_com_haieros_jni_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    string hello = "Hello from C++";
    cout << hello << endl;

    //test();
    int a = 10;
    int b = 20;
    int ret = max(a, b);
    LOGE("the max is %d", ret);
    swap(a, b);
    LOGE("%d,%d", a, b);
    int a1 = 100;
    int a2 = 200;
    swap(&a1, &a2);
    LOGE("%d,%d", a1, a2);
    LOGE("%p,%p", &a1, &a2);
    for (int i = 0; i < 10; ++i) {
        LOGE("%d", random(100));
    }

    int array[2][2] = {{1, 1},
                       {2, 2}};
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            LOGE("%d", array[i][j]);
        }
    }
    double arr[] = {1000.0, 2.0, 3.4, 17.0, 50.0};
    for (int i = 0; i < 5; ++i) {
        LOGE("%.1f", *(arr + i));
    }
    double d = getAverage(arr, 5);
    LOGE("%.3f", d);

    double *re = getRandom();
    double average = getAverage(re, 3);
    LOGE("%.2f", average);
    greeting();
    testString();

    const char *names[3] = {
            "1zzz", "2zzz", "zzz3"
    };
    for (int i = 0; i < 3; ++i) {
        LOGE("result is %c", *names[i]);
        LOGE("result is %p", names[i]);
    }

    int var[3] = {100, 200, 300};
    for (int i = 0; i < 3; ++i) {

        LOGE("%d", var[i]);
        LOGE("%d", *(var + i));
    }

    int var1 = 3000;
    // 获取 var 的地址
    int *pvar = &var1;
    // 使用运算符 & 获取 ptr 的地址
    int **ppvar = &pvar;
    LOGE("var1 address %p", &var1);
    LOGE("pvar %p", pvar);
    LOGE("*pvar %d", *pvar);
    LOGE("ppvar %p", ppvar);
    LOGE("*ppvar %p", *ppvar);
    LOGE("**ppvar %d", **ppvar);

    unsigned long *sec;
    unsigned long a11;
    sec = &a11;
    getSeconds(sec);
    LOGE("%d", sizeof(sec));
    LOGE("%p", sec);
    LOGE("%lu", *sec);

    int refren = 10;
    int &refrenRe = refren;

    LOGE("%d", refren);
    LOGE("%d", refrenRe);

    int &func1 = func();
    LOGE("%d", func1);

    Books books1;
    //Books books2;
    strcpy(books1.auther, "作者1");
    strcpy(books1.title1, "标题1");
    strcpy(books1.subject, "主题1");
    books1.book_id = 123;

    struct Books books = set1("作者2", "标题3","主题4",1);


    struct Books *bookp;
    bookp = &books1;
    printBook1(bookp);
    printBook(books1);

    printBook(books);
    printBook1(&books);

    Box box1;
    box1.length = 1.0;
    box1.width =2.0;

    LOGE("%.2f",box1.length);
    LOGE("%.2f",box1.width);


    return env->NewStringUTF(hello.c_str());
}

void test() {
    int a = 10;
    int *p;
    p = &a;
    int *p1 = &a;
    LOGE("result is %d", a);
    LOGE("result is %d", *p);
    LOGE("result is %d", *p1);
    LOGE("result is %p", p);
    LOGE("result is %p", &p);
    LOGE("result is %p", p1);
    LOGE("result is %p", &p1);
    int &r = a;
    LOGE("result is%d", r);
    LOGE("result is %p", &r);
    a = 20;
    LOGE("result is%d", r);
    LOGE("result is %p", &r);
}

int max(int a, int b) {

    if (a > b) {
        return a;
    } else {
        return b;
    }
}

//void swap(int a,int b){
//    int temp;
//    temp = a;
//    a = b;
//    b = temp;
//    return;
//}
void swap(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
    return;
}

void swap(int &a, int &b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
}

double getAverage(double param[], int size) {

    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += *(param + i);
    }
    double avg = sum / size;

    return avg;
}

double *getRandom() {
    static double arr[3] = {1, 2, 3};
    return arr;
}

int &func() {
    static int q = 10000;
    return q;
}

void greeting() {
    char greet[] = "Hello";
    int a = strlen(greet);
    LOGE("re %s %d", greet, a);
}

void testString() {
    string str1 = "hello";
    string str2 = "world";
    string str3;
    str3 = str1;
    LOGE("%s", str3.c_str());
    str3 = str1 + str2;
    LOGE("%s", str3.c_str());
    int len = str3.size();
    LOGE("%d", len);
}

void getSeconds(unsigned long *sec) {
    *sec = time(NULL);
}
void printBook(struct Books books1){
    LOGE("%s %s %s %d",books1.title1,books1.auther,books1.subject,books1.book_id);
}
void printBook1(struct Books *p){
    LOGE("%s %s %s %d",p->title1,p->auther,p->subject,p->book_id);
}
struct Books set1(char *title,char *author,char *subject,int book_id){
    //Books books2;
    struct Books books1;
    strcpy(books1.auther,title);
    strcpy(books1.title1, author);
    strcpy(books1.subject, subject);
    books1.book_id = book_id;
    return books1;
}