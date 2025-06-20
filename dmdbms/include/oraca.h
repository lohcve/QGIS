#ifndef _DM_ORACA_H
#define _DM_ORACA_H

typedef struct oraca_struct		oraca_t;
struct oraca_struct 
{
    char    oracaid[8];     //初始化为"ORACA",标识oracle通信区域
    int     oracabc;        //保存oraca数据结构的长度
    int     oracchf;        //是否检查游标缓存的一致性
    int     oradbgf;        //是否启用所有调试操作
    int     orahchf;        //是否启用堆一致性检查
    int     orastxtf;       //标志何时保存当前sql语句的文本
    struct  
    {
        unsigned short  orastxtl;
        char            orastxtc[70];
    } orastxt;              //最后一条的sql语句文本
    struct  
    {
        unsigned short  orasfnml;
        char            orasfnmc[70];
    } orasfnm;              //包含当前sql语句的文件
    int     oraslnr;        //可以找到当前sql语句的行
    int     orahoc;         //max_open_cursor设置的最大值
    int     oramoc;         //打开游标的最大数目
    int     oracoc;         //打开游标的当前数量
    int     oranor;         //游标缓存重新分配的次数
    int     oranpr;         //sql语句解析次数
    int     oranex;         //sql语句执行次数
};

#ifndef ORACA_NONE
#ifdef ORACA_STORAGE_CLASS
ORACA_STORGE_CLASS oraca_t oraca;
#else
oraca_t oraca;
#endif
#endif

#define     ORASTFNON 0     //不保存sql语句文本
#define     ORASTFERR 1     //只保存出现err的sql语句
#define     ORASTFWRN 2     //保存出现err或warn的sql语句
#define     ORASTFANY 3     //始终保存sql语句

#endif //_DM_ORACA_H