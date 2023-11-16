#ifndef MYCOMPILER_H
#define MYCOMPILER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include<QMessageBox>
#include<QDebug>
#define bool int

#define true 1
#define false 0

#define norw 16       /* 保留字个数*/
#define txmax 100     /* 符号表容量 */
#define nmax 14       /* 数字的最大位数 */
#define al 10         /* 标识符的最大长度 */
#define maxerr 30     /* 允许的最多错误数 */
#define amax 2048     /* 地址上界*/
#define levmax 3      /* 最大允许嵌套的声明数*/
#define cxmax 200     /* 最多的虚拟机代码数 */
#define stacksize 500 /* 运行时数据栈元素最大数目 */

/* 符号表 */
enum symbol {
    nul,        ident,      number,     truesym,    falsesym,
    plus,       minus,      times,      slash,      lss,
    leq,        gtr,        geq,        eql,        neq,
    becomes,    orsym,      andsym,     notsym,        semicolon,
    lparen,     rparen,     lbrace,     rbrace,     mod,
    xorsym,     oddsym,     incre,      decre,      intsym,
    boolsym,    ifsym,      elsesym,    whilesym,   writesym,
    readsym,    forsym,     dosym,      constsym,   repeatsym,
    untilsym,   period,
};
#define symnum 42

/* 符号表中的类型 */
enum object {
    integer,
    booltype,
};

/* 虚拟机代码指令 */
enum fct {
    lit,     opr,     lod,
    sto,     ini,     jmp,
    jpc,     jeq,
};
#define fctnum 8

/* 虚拟机代码结构 */
struct instruction
{
    enum fct f; /* 虚拟机代码指令 */
    int l;      /* 引用层和声明层的层次差 */
    int a;      /* 根据法f的不同而不同 */
};



/* 符号表结构 */
struct tablestruct
{
    char name[al];	    /* 名字 */
    enum object kind;	/* 类型：interger 或 booltype */
    bool bconst;        /* 是否为const */
    int val;            /* 数值，仅const使用 */
    int level;          /* 所处层，仅const不使用 */
    int adr;            /* 地址，仅const不使用 */
};




void build(char* fname);
void error(int n);
void getsym();
void getch();
void init();
void gen(enum fct x, int y, int z);
void test(bool* s1, bool* s2, int n);
int inset(int e, bool* s);
int addset(bool* sr, bool* s1, bool* s2, int n);
int subset(bool* sr, bool* s1, bool* s2, int n);
int mulset(bool* sr, bool* s1, bool* s2, int n);
void block(int lev, int tx, bool* fsys);
void interpret();
void factor(bool* fsys, int* ptx, int lev);
void term(bool* fsys, int* ptx, int lev);
void condition(bool* fsys, int* ptx, int lev);
void expression(bool* fsys, int* ptx, int lev);
void statement(bool* fsys, int* ptx, int lev);
void listall();
void intdeclaration(int* ptx, int lev, int* pdx);
void booldeclaration(int* ptx, int lev, int* pdx);
void constdeclaration(int* ptx, int lev, int* pdx);
int position(char* idt, int tx);
void enter(bool bconst, enum object k, int* ptx, int lev, int* pdx);
int base(int l, int* s, int b);
#undef bool

#endif  // MYCOMPILER_H
