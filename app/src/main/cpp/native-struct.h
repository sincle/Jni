//
// Created by DELL on 2018/8/2.
//

#ifndef JNI_NATIVE_STRUCT_H
#define JNI_NATIVE_STRUCT_H
struct Books {
    char auther[50];
    char title1[50];
    char subject[50];
    int book_id;
};

class Box {
public:
    double length;
    double width;
};

#endif //JNI_NATIVE_STRUCT_H
