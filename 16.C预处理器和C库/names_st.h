// names_st.h -- names_st结构的头文件

#ifndef NAMES_H_
#define NAMES_H_

// 常量
#define SLEN 32

// 结构声明
struct names_st {
    char first[SLEN];
    char last[SLEN];
};

// 类型定义
typedef struct names_st names;

// 函数原型
void get_names(names *);
void show_names(const names *);

#endif