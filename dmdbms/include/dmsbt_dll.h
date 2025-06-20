/********************************************************************
file: 
    dmsbt_dll.h
Notes:
    sbt interface 
History:
    Date         Who         RefDoc         Memo
    2016-09-05   shenning                   create
********************************************************************/
#ifndef DMSBT_DLL_H
#define DMSBT_DLL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef __cplusplus
extern "C" { 			/* Assume C declarations for C++   */
#endif  /* __cplusplus */

typedef int                     sbtcode_t;
typedef int                     sbtbool;
typedef unsigned char           sbtbyte;
typedef signed char             sbtchar;
typedef signed short            sbtint2;
typedef unsigned short          sbtuint2;
typedef int                     sbtint4;
typedef unsigned int            sbtuint4;

#if defined(WIN32) || defined(WINDOWS)
typedef __int64                 sbtint8;
typedef unsigned __int64        sbtuint8;
#else
typedef long long int           sbtint8;
typedef unsigned long long int  sbtuint8;
#endif

#ifdef DM64
typedef sbtuint8        sbtuint3264;
typedef sbtint8         sbtint3264;
#else
typedef sbtuint4        sbtuint3264;
typedef sbtint4         sbtint3264;
#endif

#define SBT_SUCCESS(code)   ((sbtint4)code >= 0)

#define SBT_RET_IF_ERR(c) \
    { if (!SBT_SUCCESS(c)) return (c);}

#ifdef WIN32
#define SBT_DIR_CHAR        '\\'
#define SBT_DIR_STR         "\\"
#define SBT_DIR_STR_LEN     1
#else
#define SBT_DIR_CHAR        '/'
#define SBT_DIR_STR         "/"
#define SBT_DIR_STR_LEN     1
#endif

/************************************************************************ 
 DMSBT�ӿڰ汾�ţ���ֵSBTINIT_MMS_VSNʱ����16�������ַ��أ����汾�ź�С�汾�ţ���ռ��λ����1.0����Ϊ0x0100
 0x0201 ����ȫ�ֱ���gvar,
        ����sbtversion�ӿڣ�
        ������֮ǰ�汾��
 0x0202 ����extern "C"������C++����ĵ������⣻
        ����ǰ��汾��
************************************************************************/
#define DMSBT_DLL_VERSION       0x0202          //"2.2"

#define SBT_FEATURE_UNIX        1   //֧��Unix����ļ�·��
#define SBT_FEATURE_OPEN        2   //֧��sbtopen�ӿ�

/************************************************************************
 * SBT_CODE = 0: ��ʾִ�гɹ���
 * SBT_CODE > 0: ��ʾ������Ϣ��
 * SBT_CODE < 0: ��ʾ������Ϣ��
************************************************************************/
#define SBT_WARN                (sbtint4)1
#define SBT_EC_SUCCESS          (sbtint4)0
#define SBT_EC_FAIL             (sbtint4)-1

/************************************************************************ 
 * SBT_EC_DM_RESERVED: ֮ǰΪ����Ԥ�������룬��������չ��Ӵ�ֵ֮��ʼ����-10001
************************************************************************/
#define SBT_EC_DM_RESERVED      (sbtint4)-10000

/***********************************************************************/
/* SBT size limits.  When the object is a  */
/* character string, the maximum length does not include the terminating null. */
/***********************************************************************/

#define SBT_ERROR_MAX           512         /* error string returned by sbterror */
#define SBT_FILE_MAX            256         /* backup file name */
#define SBT_MMSDESC_MAX         64          /* SBT_MMS_DESC returned by sbtinit */
#define SBT_DBNAME_MAX          128         /* SBTINIT2_DBNAME */
#define SBT_COMMENT_MAX         80          /* SBTBFINFO_COMMENT */
#define SBT_LABEL_MAX           64          /* SBTBFINFO_LABEL */
#define SBT_COMMAND_MAX         1024        /* command passed to sbtcommand */
#define SBT_KEY_MAX             128         /* encryption key */

/************************************************************************
/* SBTINIT�ӿ��������ݽṹ����������
/************************************************************************/
typedef struct  sbtinit_input_struct    sbtinit_input_t;
struct sbtinit_input_struct
{
    sbtuint4        i_type;         /* Type of the object */
#define SBTINIT_TRACE_NAME          1       /* Trace File Name */
#define SBTINIT_LANGUAGE_TYPE       2       /* Language type used by API client */
#define SBTINIT_CODE_IS_UNICODE     3       /* Whether the CODE used by API client is UTF-8,FALSE by default. */
#define SBTINIT_ENV_HANDLE          4       /* Environment handle, only used by DM. */
#define SBTINIT_INEND               9999    /* end of the array */

    void*           i_obj;          /* Initialization Object */

// values for SBTINIT_LANGUAGE_TYPE
#define SBTINIT_LANGUAGE_CN         1       /* Chinese */
#define SBTINIT_LANGUAGE_EN         2       /* English */
#define SBTINIT_LANGUAGE_CNT_HK     3       /* HK Traditional Chinese */
};

/************************************************************************
/* SBTINIT�ӿ�������ݽṹ����������
/************************************************************************/
typedef struct  sbtinit_output_struct   sbtinit_output_t;
struct sbtinit_output_struct
{
    sbtuint4        o_type;         /* Type of the object */
#define SBTINIT_MAXSIZE             1       /* maximum backup piece size */
#define SBTINIT_MMS_APIVSN          2       /* Version Number of Tape API */
#define SBTINIT_MMS_DESC            3       /* vendor description */
#define SBTINIT_MMS_VSN             4       /* Version Number of MM Software */
#define SBTINIT_FEATURE             5       /* Feature Supported */
#define SBTINIT_OUTEND              9999    /* end of the array*/

    void*           o_obj;          /* Initialization Object */
};

/************************************************************************
/* SBTINIT2�ӿ��������ݽṹ����������
/************************************************************************/
typedef struct sbtinit2_input_struct    sbtinit2_input_t;
struct sbtinit2_input_struct
{
    sbtuint4        i_type;         /* Type of the object */
#define SBTINIT2_TRACE_LEVEL        1       /* Trace level */
#define SBTINIT2_MAXSIZE            2       /* maximum size of backup file API client specified, less than output by sbtinit */
#define SBTINIT2_DBNAME             3       /* Database Name */
#define SBTINIT2_DBMAGIC            4       /* Database DB MAGIC NUMBER */
#define SBTINIT2_BACKUPSET          5       /* Directory for which backupset to backup or restore,specified by BACKUPSET */
#define SBTINIT2_BACKUPDIRS         6       /* Directories for backupset searched if the member in array is null or empty string,then end.*/
#define SBTINIT2_BASEON_BACKUPSET   7       /* Base backupset directory specified by BASE ON */
#define SBTINIT2_BACKUPSETS_INFO    8       /* Need backupsets information, and need all if SBTINIT2_BACKUPDIRS not set */
#define SBTINIT2_IS_BACKUP          9       /* Tell current operation is backup */
#define SBTINIT2_IS_INCREMENT       10      /* Tell current backup is incremental,only valid when SBTINIT2_IS_BACKUP is set */
#define SBTINIT2_BACKUPNAME         11      /* Name of backupset, valid only when backup */
#define SBTINIT2_DEF_BAKDIR         12      /* The default directory where backupset be located */
#define SBTINIT2_DIRECT_IO          13      /* Whether to enable direct io during backup */
#define SBTINIT2_PARMS              14      /* Parameters specified by users in device type clause */
#define SBTINIT2_ENCRYPT_ID         15      /* Encryption ID */
#define SBTINIT2_ENCRYPT_KEY        16      /* Encrypt Key */
#define SBTINIT2_ENCRYPT_KEY_LEN    17      /* Encrypt Key */
#define SBTINIT2_INEND              9999    /* null entry - end of list */

    /* values for SBTINIT2_TRACE_LEVEL */
#define SBTINIT2_TRACE_LEVEL_NONE   1  /* nothing wrote to trace file */
#define SBTINIT2_TRACE_LEVEL_LOG    2  /* wrote log info to trace file */

    void*           i_obj;          /* Initialization Object */
};

/************************************************************************
/* SBTINIT2�ӿ�������ݽṹ����������
/************************************************************************/
typedef struct sbtinit2_output_struct   sbtinit2_output_t;
struct sbtinit2_output_struct
{
    sbtuint4    o_type;             /* Type of the object */
#define SBTINIT2_BACKUPSET          5       /* Directory for which backupset to backup or restore,specified by BACKUPSET */
#define SBTINIT2_BASEON_BACKUPSET   7       /* Base backupset directory specified by BASE ON */
#define SBTINIT2_BACKUPDIRS         6       /* backupsets searched to return */

#define SBTINIT2_OUTEND             9999    /* null entry - end of list */

    void*       o_obj;              /* Initialization Object */
};

/************************************************************************
/*  sbtinit2_output_struct��������ݼ���Ϣ�ṹ
/***********************************************************************/
typedef struct sbtbackupset_obj_struct      sbtbakset_obj_t;
struct sbtbackupset_obj_struct
{    
    sbtchar             meta_file_name[SBT_FILE_MAX + 1];     /* absolute path name for meta file */
    sbtuint4            bakset_type;       /* This backupset is increment/full */    

    sbtbool             is_invalid;           /* is_invalid = TRUE��end of the baksets array */

    sbtbakset_obj_t*    p_next;             /* pointer to next valid backupset obj */
    sbtbakset_obj_t*    p_prev;             /* pointer to prev valid backupset obj */

// values for bakset_type
#define SBTBAKSET_TYPE_UNKNOWN      0       /* unknown,used for disk backup */
#define SBTBAKSET_TYPE_FULL         1       /* full */
#define SBTBAKSET_TYPE_INCRMENT     2       /* increment */
};

/************************************************************************
/* SBTBACKUP�ӿڱ����ļ����ͳ�������
/************************************************************************/
#define SBTBFILE_DATAFILE           1       /* datafile */
#define SBTBFILE_ARCHLOG            2       /* archived redo log */
#define SBTBFILE_METAFILE           3       /* meta file */
#define SBTBFILE_OTHER              4       /* neither datafile nor archived log */

/************************************************************************
/* SBTINFO�ӿ����ݽṹ����������
/************************************************************************/
typedef struct sbtbfinfo_struct     sbtbfinfo_t;
struct sbtbfinfo_struct
{
    sbtuint4    sbtbfinfo_type;             /* Type of the object */
#define SBTBFINFO_NAME              1       /* name of backup file */
#define SBTBFINFO_CRETIME           2       /* file creation date/time */
#define SBTBFINFO_EXPTIME           3       /* file expiration date/time */
#define SBTBFINFO_LABEL             4       /* Volume label */
#define SBTBFINFO_COMMENT           5       /* vendor-defined comment string */
#define SBTBFINFO_END               9999    /* null entry - end of list */

    void*       sbtbinfo_value;             /* value of the object */
};

/************************************************************************/
/* ���ܣ�  ȡ��̬��汾
/* ������  version�������������̬��İ汾
/* ����ֵ�����ظýӿ�ִ���Ƿ�ɹ����ɹ�����SBT_EC_SUCCESS�����򣬷��ؾ��������
/************************************************************************/
sbtcode_t 
sbtversion(
    sbtuint2*       version
);

/************************************************************************/
/* ���ܣ�  ��ʼ��ϵͳ
/* ������  gvar_out,����������ɵ������Լ����룬��¼ȫ����Ϣ���������ӿ�ʹ�ã�ʵ���ļ���.c���в����ٳ���ȫ�ֱ���
           initin������������ɿͻ������������������
           initout������������ɵ�����������ͻ������           
/* ����ֵ�����ظýӿ�ִ���Ƿ�ɹ����ɹ�����SBT_EC_SUCCESS�����򣬷��ؾ��������
/************************************************************************/
sbtcode_t 
sbtinit(
    void**              gvar_out,
    sbtinit_input_t*    in,
    sbtinit_output_t**  out
);

/************************************************************************/
/* ���ܣ�  ��������
/* ������  gvar_in,����������ɵ�����ͨ��sbtinit����ļ�¼ȫ����Ϣ�ı���    
           in������������ɿͻ���������������������ò���
           out������������ɵ�����������ͻ��������������           
/* ����ֵ�����ظýӿ�ִ���Ƿ�ɹ����ɹ�����SBT_EC_SUCCESS�����򣬷��ؾ��������
/************************************************************************/
sbtcode_t
sbtinit2(
    void*               gvar_in,
    sbtinit2_input_t*   in,
    sbtinit2_output_t** out
);

/************************************************************************/
/* ���ܣ�  ׼��ָ�������ļ�����ʼ����
/* ������  gvar_in,����������ɵ�����ͨ��sbtinit����ļ�¼ȫ����Ϣ�ı���    
           bfile_type�����������ָ�������ļ�����
           bfile_name�����������ָ�������ļ����֣���Ҫ�������ʵ��ͨ��SBTINFO(SBTBFINFO_NAME)����һ�����ļ���
/* ����ֵ�����ظýӿ�ִ���Ƿ�ɹ����ɹ�����SBT_EC_SUCCESS�����򣬷��ؾ��������
/************************************************************************/
sbtcode_t
sbtbackup(
    void*           gvar_in,
    sbtint4         bfile_type,
    sbtchar*        bfile_name
);

/************************************************************************/
/* ���ܣ�  д�뱸�����ݵ���ǰ�����ļ���
/* ������  gvar_in,����������ɵ�����ͨ��sbtinit����ļ�¼ȫ����Ϣ�ı���    
           buf�������������д�����ݻ��棻
           buf_len�������������д�����ݳ��ȣ�һ��Ҫȫ��д�룬����ԭʱʧ��
/* ����ֵ�����ظýӿ�ִ���Ƿ�ɹ����ɹ�����SBT_EC_SUCCESS�����򣬷��ؾ��������
/************************************************************************/
sbtcode_t
sbtwrite(
    void*           gvar_in,
    sbtbyte*        buf,
    sbtuint4        buf_len
);

/************************************************************************/
/* ���ܣ�  �رյ�ǰ�����ļ���д
/* ������  gvar_in,����������ɵ�����ͨ��sbtinit����ļ�¼ȫ����Ϣ�ı���    
/* ����ֵ����
/************************************************************************/
sbtcode_t
sbtclose(
    void*           gvar_in
);

/************************************************************************/
/* ���ܣ�  �������һ���������ݵı����ļ���Ϣ
/* ������  gvar_in,����������ɵ�����ͨ��sbtinit����ļ�¼ȫ����Ϣ�ı���    
           bak_file_info��������������������ʽ���ر����ļ���Ϣ
/* ����ֵ�����ظýӿ�ִ���Ƿ�ɹ����ɹ�����SBT_EC_SUCCESS�����򣬷��ؾ��������
/************************************************************************/
sbtcode_t
sbtinfo(
    void*           gvar_in,
    sbtbfinfo_t**   bak_file_info
);

/************************************************************************/
/* ���ܣ�  һ�����ݼ����ݻ�ԭ���̽�����������ʵ���ͷ���Դ
/* ������  gvar_in,����������ɵ�����ͨ��sbtinit����ļ�¼ȫ����Ϣ�ı���������ʹ�ý������ͷţ���sbtinit�����Ӧ    
           del_flag,�����������ʾ��ǰ���ݻ�ԭ���̽������Ƿ���������н��������ɵ��ļ���
           ���ݹ�����del_flag=TRUE��˵�����ݹ���ʧ�ܣ���ԭ���̣�def_flagȫ��ΪFALSE��
/* ����ֵ�����ظýӿ�ִ���Ƿ�ɹ����ɹ�����SBT_EC_SUCCESS�����򣬷��ؾ��������
/************************************************************************/
sbtcode_t
sbtend(
    void*          gvar_in,
    sbtbool        del_flag
);

/************************************************************************/
/* ���ܣ�  ׼��ָ�����Ƶı����ļ�����ʼ��ԭ
/* ������  gvar_in,����������ɵ�����ͨ��sbtinit����ļ�¼ȫ����Ϣ�ı���    
           filename�����������ͨ������SBTINFO��ȡ�ı����ļ�����(SBTBFINFO_NAME)
/* ����ֵ�����ظýӿ�ִ���Ƿ�ɹ����ɹ�����SBT_EC_SUCCESS�����򣬷��ؾ��������
/************************************************************************/
sbtcode_t
sbtrestore(
    void*           gvar_in,
    sbtchar*        filename
);

/************************************************************************/
/* ���ܣ� �ӱ����ļ��ж�ȡ��������
/* ������  gvar_in,����������ɵ�����ͨ��sbtinit����ļ�¼ȫ����Ϣ�ı���    
           buf�������������ȡ���ݻ��棻
           buf_len�������������ȡ���ݳ��ȣ�һ��Ҫ����ô�࣬����ԭ�����
/* ����ֵ�����ظýӿ�ִ���Ƿ�ɹ����ɹ�����SBT_EC_SUCCESS�����򣬷��ؾ��������
/************************************************************************/
sbtcode_t
sbtread(
    void*           gvar_in,
    sbtbyte*        buf,
    sbtuint4        buf_len
);

/************************************************************************/
/* ���ܣ� ��ȡ�ϴ�ִ�й����У�ִ��ʧ�ܵ�������Ϣ
/* ������  gvar_in,����������ɵ�����ͨ��sbtinit����ļ�¼ȫ����Ϣ�ı���                           
           errdesc_utf8�������������API�ӿ�Ҫ�����Ժͱ��뷽ʽ��Ӧ�ĵ�����ʵ���д���������Ϣ.
           ������Ϣ���Ⱦ����ܳ���SBT_ERROR_MAX�������Զ��ضϡ�
/* ����ֵ������ִ��ʧ�ܵĴ�����
/************************************************************************/
sbtcode_t
sbterror(
    void*           gvar,
    sbtchar*        err_desc,
    sbtuint4        err_buf_len,
    sbtuint4*       err_len
);

/************************************************************************/
/* ���ܣ� ����������������ַ���
/* ������ gvar_in,����������ɵ�����ͨ��sbtinit����ļ�¼ȫ����Ϣ�ı���     
          cmdstr����������������û�ͨ�����ݻ�ԭ���ָ���ĵ����������ַ������ϲ���ýӿڣ������κδ���
/* ����ֵ�����ظýӿ�ִ���Ƿ�ɹ����ɹ�����SBT_EC_SUCCESS�����򣬷��ؾ��������
/************************************************************************/
sbtcode_t
sbtcommand(
    void*           gvar_in,
    sbtchar*        cmdstr
);

/************************************************************************/
/* ���ܣ� ɾ����ǰ���ݼ�����ӦSBTINIT2_BACKUPSETָ�����ݼ�
/* ������ gvar_in,����������ɵ�����ͨ��sbtinit����ļ�¼ȫ����Ϣ�ı���    
          filename�����������ͨ������SBTINFO��ȡ�ı����ļ�����(SBTBFINFO_NAME)
/* ����ֵ�����ظýӿ�ִ���Ƿ�ɹ����ɹ�����SBT_EC_SUCCESS�����򣬷��ؾ��������
/************************************************************************/
sbtcode_t
sbtdelete(
    void*           gvar_in,
    sbtchar*        filename
);

/*********************************************************************
Purpose :
����ָ�����ȵı����ļ�
*********************************************************************/
sbtcode_t
sbtopen(
    void*           gvar,       /* IN��SBT��� */
    sbtint4         bfile_type, /* IN�������ļ����� */
    sbtchar*        bfile_name, /* IN�������ļ��� */
    sbtuint8        bfile_length/* IN���ļ����� */
);

#ifdef __cplusplus
}                                    /* End of extern "C" { */
#endif  /* __cplusplus */
#endif


