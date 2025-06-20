#ifndef _DM_ORACA_H
#define _DM_ORACA_H

typedef struct oraca_struct		oraca_t;
struct oraca_struct 
{
    char    oracaid[8];     //��ʼ��Ϊ"ORACA",��ʶoracleͨ������
    int     oracabc;        //����oraca���ݽṹ�ĳ���
    int     oracchf;        //�Ƿ����α껺���һ����
    int     oradbgf;        //�Ƿ��������е��Բ���
    int     orahchf;        //�Ƿ����ö�һ���Լ��
    int     orastxtf;       //��־��ʱ���浱ǰsql�����ı�
    struct  
    {
        unsigned short  orastxtl;
        char            orastxtc[70];
    } orastxt;              //���һ����sql����ı�
    struct  
    {
        unsigned short  orasfnml;
        char            orasfnmc[70];
    } orasfnm;              //������ǰsql�����ļ�
    int     oraslnr;        //�����ҵ���ǰsql������
    int     orahoc;         //max_open_cursor���õ����ֵ
    int     oramoc;         //���α�������Ŀ
    int     oracoc;         //���α�ĵ�ǰ����
    int     oranor;         //�α껺�����·���Ĵ���
    int     oranpr;         //sql����������
    int     oranex;         //sql���ִ�д���
};

#ifndef ORACA_NONE
#ifdef ORACA_STORAGE_CLASS
ORACA_STORGE_CLASS oraca_t oraca;
#else
oraca_t oraca;
#endif
#endif

#define     ORASTFNON 0     //������sql����ı�
#define     ORASTFERR 1     //ֻ�������err��sql���
#define     ORASTFWRN 2     //�������err��warn��sql���
#define     ORASTFANY 3     //ʼ�ձ���sql���

#endif //_DM_ORACA_H