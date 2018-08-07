//
// Created by DELL on 2018/7/26.
//
#include "native-struct.h"
#ifndef JNI_NATIVE_LIB_H
#define JNI_NATIVE_LIB_H
void test();
int max(int a,int b);
//void swap(int a,int b);
void swap(int *a,int *b);
void swap(int &a,int &b);

double getAverage(double param[],int size);
double * getRandom();
int & func();
void greeting();
void testString();
void getSeconds(unsigned long *sec);
void printBook(struct Books books);
void printBook1(struct Books *p);
struct Books set1(char *title,char *author,char *subject,int book_id);
#endif //JNI_NATIVE_LIB_H
