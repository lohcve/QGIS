#ifndef LOGMNR_PUB_H
#define LOGMNR_PUB_H

#include "dm.h"
#include "dmerr.h"
#include "dmstr.h"
#include "dop.h"
#include "rt_mo.h"
#include "ndct.h"

#define  LOGMNR_NEWFILE         1
#define  LOGMNR_REMOVEFILE      2
#define  LOGMNR_ADDFILE         3

/*
* START_LSN, COMMIT_LSN, CSCN, ROLLBACK, START_TS, COMMIT_TS
* �⼸�е�ֵ��������أ���dtab_logmnr_contents_build_data_low���ʱ���㣬
* ��Ϊ����Ҫ������־�ļ��еļ�¼���ҵ���¼��������ʼ�ͽ����ĵ�
*/
#define LOGMNR_BDTA_LSN             0
#define LOGMNR_BDTA_TIMESTAMP       1
#define LOGMNR_BDTA_START_LSN       2
#define LOGMNR_BDTA_COMMMIT_LSN     3
#define LOGMNR_BDTA_START_TS        4
#define LOGMNR_BDTA_COMMIT_TS       5
#define LOGMNR_BDTA_TRXID           6
#define LOGMNR_BDTA_OPER            7
#define LOGMNR_BDTA_OPER_CODE       8
#define LOGMNR_BDTA_SCHNAME         9
#define LOGMNR_BDTA_REC_ROWID       10
#define LOGMNR_BDTA_USERNAME        11
#define LOGMNR_BDTA_OBJID           12
#define LOGMNR_BDTA_OBJV            13
#define LOGMNR_BDTA_SQL_REDO        14
#define LOGMNR_BDTA_SQL_UNDO        15
#define LOGMNR_BDTA_RS_ID           16
#define LOGMNR_BDTA_SSN             17
#define LOGMNR_BDTA_CSF             18
#define LOGMNR_BDTA_STATUS          19
#define LOGMNR_BDTA_COL_DATAS       20
#define LOGMNR_BDTA_REDO_VALUE      21
#define LOGMNR_BDTA_UNDO_VALUE      22
#define LOGMNR_BDTA_TABLE_NAME      23
#define LOGMNR_BDTA_RBA_SEQ         24
#define LOGMNR_BDTA_RBA_BLK         25
#define LOGMNR_BDTA_RBA_OFFSET      26
#define LOGMNR_BDTA_TRXID_NUMBER    27
#define LOGMNR_BDTA_CSCN            28
#define LOGMNR_BDTA_ROLLBACK        29
#define LOGMNR_BDTA_TRX_INNER_SEQ   30
#define LOGMNR_BDTA_SESSION_INFO    31
#define LOGMNR_BDTA_SUBTAB_ID       32
#define LOGMNR_BDTA_SESSION_ID      33

//���Գ�ʼ��logmnr log�ϵ� bdta, �ֶ���ϢΪv$logmnr_contents���Ӽ� + ���ӵ�1���ֶ� COL_DATAS
#define  LOGMNR_MTABLE_COLS_NUM  34

#define LOGMNR_OP_INTERNAL   0
#define LOGMNR_OP_INSERT     1
#define LOGMNR_OP_DELETE     2
#define LOGMNR_OP_UPDATE     3
#define LOGMNR_OP_BUPD       4  // dm���еģ���������
#define LOGMNR_OP_DDL        5 
#define LOGMNR_OP_START      6
#define LOGMNR_OP_COMMIT     7
#define LOGMNR_OP_SEL_LOB    9
#define LOGMNR_OP_LOB_WRITE  10
#define LOGMNR_OP_LOB_TRIM   11
#define LOGMNR_OP_INSERT_FAST   12  // dm���еģ���������
#define LOGMNR_OP_LOB_NEW    13     // dm���еģ�������ֶ�LOB_NEW
#define LOGMNR_OP_LOB_DATA   14     // dm���еģ�������ֶ�LOB_DATA
#define LOGMNR_OP_SEL_UPD    25
#define LOGMNR_OP_LOB_ERASE  28
#define LOGMNR_OP_MIS_LSN    34
#define LOGMNR_OP_ROLLBACK   36
#define LOGMNR_OP_SEQ_MODIFY 37
#define LOGMNR_OP_XA_COMMIT  38
#define LOGMNR_OP_UNSUPPORT  255

#define LOGMNR_TYPE_ARCHIVED    1
#define LOGMNR_TYPE_ONLINE      2

#define LOGMNR_MAX_CACHE_ITEM   1000

#define  LOGMNR_UNDO 1
#define  LOGMNR_REDO 0

#define  LOGMNR_OPTION_COMMIT_ONLY     2
#define  LOGMNR_OPTION_SKIP_CORRUPTION 4
#define  LOGMNR_OPTION_DDL_TRACKING    8
#define  LOGMNR_OPTION_ONLINE_DICT     16
#define  LOGMNR_OPTION_REDOLOG_DICT    32
#define  LOGMNR_OPTION_NO_DELIMITER    64
#define  LOGMNR_OPTION_PRETTY_SQL      512
#define  LOGMNR_OPTION_CONTINUOUS      1024
#define  LOGMNR_OPTION_NO_ROWID        2048
#define  LOGMNR_OPTION_STRING_LITERALS 4096

#define LOGMNR_INTERNAL   "INTERNAL"
#define LOGMNR_INSERT     "INSERT"
#define LOGMNR_DELETE     "DELETE"
#define LOGMNR_UPDATE     "UPDATE"
#define LOGMNR_BUPD       "BATCH_UPDATE"
#define LOGMNR_DDL        "DDL"
#define LOGMNR_START      "START"
#define LOGMNR_COMMIT     "COMMIT"
#define LOGMNR_SEL_LOB    "SEL_LOB_LOCATOR"
#define LOGMNR_LOB_WRITE  "LOB_WRITE"
#define LOGMNR_LOB_TRIM   "LOB_TRIM"
#define LOGMNR_INSERT_FAST "INSERT_FAST"
#define LOGMNR_SEL_UPD    "SELECT_FOR_UPDATE"
#define LOGMNR_LOB_ERASE  "LOB_ERASE"
#define LOGMNR_MIS_LSN    "MISSING_SCN"
#define LOGMNR_ROLLBACK   "ROLLBACK"
#define LOGMNR_XA_COMMIT  "XA_COMMIT"
#define LOGMNR_UNSUPPORT  "UNSUPPORTED"
#define LOGMNR_START      "START"
#define LOGMNR_SEQ_MODIFY "SEQ MODIFY"
#define LOGMNR_LOB_NEW    "LOB_NEW"
#define LOGMNR_LOB_DATA   "LOB_DATA"

// rlog2��ѹ����־����������
#define LOGMNR_RLOG2_GET_PLSQL_TYPE(plsql_type)  ((usint)(plsql_type & 0x7F))
#define LOGMNR_RLOG2_GET_NULL_FLAG(plsql_type)   ((ulint)(plsql_type & 0x80) >> 7)

// ����ѹ����־����������
#define LOGMNR_INS_COMPRESS_PLSQL_TYPE(plsql_type) ((usint)(plsql_type & 0x3F))
#define LOGMNR_INS_COMPRESS_IS_APP(plsql_type)     ((ulint)(plsql_type & 0x40) >> 6)
#define LOGMNR_INS_COMPRESS_NULL_FLAG(plsql_type)  ((ulint)(plsql_type & 0x80) >> 7)

// �Ƿ�����ƴд�У��������ֶ����ͺ�������
#define LOGMNR_PUB_BUILD_SKIP_COL(col) (ntype_is_blob(col->ntype.sql_pl_type) || col->virtual_flag)
#define LOGMNR_CLIENT_BUILD_SKIP_COL(col) (col->type == ULINT_UNDEFINED || ntype_is_blob(col->type) || col->virtual_flag)

typedef struct logmnr_tid_lsn_struct logmnr_tid_lsn_t;
typedef DM_LIST_BASE_NODE_T(logmnr_tid_lsn_t) logmnr_trxid_lst_t;

#define logmnr_tid_lsn_MAGIC   76876619
struct logmnr_tid_lsn_struct
{
    ulint64           trx_id; 
    ulint64           lsn;
    ulint             type;
    dmtime_t          time;
    ulint             seq; 

    hash_node_t       hash; 

    DM_LIST_NODE_T(logmnr_tid_lsn_t) 
        link;

    MAGIC_DECLARE
};

/* �����⹫������Ϣ
* ��logmnr_client.h���Ƴ���logmnr_pub.h
*/
#define logmnr_col_item_MAGIC   76876640
typedef struct logmnr_col_item_struct logmnr_col_item_t;
struct logmnr_col_item_struct
{
	usint		colid; //��id��
	sysname_t	name;  //����
	ulint		type;  //������
    byte        virtual_flag;   // �Ƿ�Ϊ������

    MAGIC_DECLARE
};

/* �����⹫������Ϣ
* ��logmnr_client.h���Ƴ���logmnr_pub.h
*/
#define logmnr_client_dict_item_MAGIC   76876641
typedef struct logmnr_client_dict_item_struct logmnr_client_dict_item_t;
struct logmnr_client_dict_item_struct
{
    ulint				obj_id;	            //����id��
    sysname_t			obj_name;           //������
	ulint				obj_type;			//�������ͣ���ģʽ���û�

	//ֻ�б��ʱ����õ����漸������
	usint               n_col_space;
	usint               cols_num;       //����
	logmnr_col_item_t** cols_arr;       //����Ϣ
    dmtime_t            create_time;    //�����Ĵ���ʱ��

	ulint				n_fixed;		//��ǰ�����ж��ٸ��߳�ռ�иö���
	byte				valid_flag;		//��ʾ�����Ƿ���Ч

    hash_node_t     hash;

    DM_LIST_NODE_T(logmnr_client_dict_item_t) 
                    link;

    MAGIC_DECLARE
};

// ����logmnr_extra_info_t�д洢����Ϣ
#define logmnr_row_info_MAGIC   76876643
typedef struct logmnr_row_info_struct logmnr_row_info_t;
struct logmnr_row_info_struct
{
    sdint8                  sess_id;                // �洢session_id
    dmrd_t                  dmrd;                   // �洢rowid
    ulint                   subtab_id;              // �ӱ�id

    MAGIC_DECLARE
};

// logmnrƴдsqlʱ�������߼���־�е����ݣ���Ҫ�Ķ�����Ϣ
#define logmnr_extra_info_MAGIC   76876642
typedef struct logmnr_extra_info_struct logmnr_extra_info_t;
struct logmnr_extra_info_struct
{
    dmbool                  no_delimiter;           // �Ƿ����β�ָ���
    dmbool                  no_rowid;               // �Ƿ����ROWID
    lint                    cvt_mode;               // �Ƿ���Ҫ����ת��

    //����2��������Ϣ�汾��С��dm_comm_ver_9ʱ��Ч,�����ϰ汾��rowid����
    udint4                  rowid_max_hpno;         //����ˮƽ������
    udint2                  rowid_max_epno;         //���վ���
    udint2                  rowid_n_bits_epno;      //վ���ռ�õ�����λ��
    udint2                  rowid_n_bits_real;      //����ʵrowidֵʹ�õ�λ��������48��DPCΪ44

    dmbool                  parse_lob;              // �Ƿ�������ֶ�
    dmbool                  gen_undo;               // �Ƿ�ƴдundo���

    MAGIC_DECLARE
};


enum
{
   logmnr_dml = 0, /*insert, delete, update*/
   logmnr_ddl,
   logmnr_trx,     /*commit��rollback*/
   logmnr_start,   
   logmnr_seq,     /*seq*/   

   logmnr_max
};

// logmnr_client.h�Ƕ����ṩͷ�ļ������ܷ��ڲ���Ϣ���ƶ���logmnr_pub.h
/*---------------------Charset code convert--------------------*/
#define LOGMNR_CVT_NONE                 0           /* Client is the same charset code as server */
#define LOGMNR_CVT_L2U                  1           /* Client(utf) is not the same charset code as server(gbk)  */
#define LOGMNR_CVT_U2L                  2           /* Client(gbk) is not the same charset code as server(utf) */

DllExport
//���ò������͵��ַ���
dmcode_t
logmnr_set_op(
    usint           llog_type,
    ulint*	        op_code,
    schar*          op_str
);

DllExport
void
logmnr_add_trx_info(
    dmenv_t         env,    /*IN:�������*/
    rt_memobj_t*    memobj,
	hash_table_t*   hash_tab,
	logmnr_trxid_lst_t* trxid_lst,
    os_mutex_t*     mutex,  /*IN:������ʵĻ�����*/
    ulint64         trx_id, 
    ulint           trx_seq,
    ulint           type,
    dmtime_t        time,
    ulint64         lsn
);

DllExport
void
logmnr_get_obj_sql(
    dmenv_t         env,    /*IN:�������*/	
    rt_memobj_t*    memobj,
    dmstr_t*        dmstr,
    schar*			sch_name,
    ulint           schid,
    schar*			table_name,
    ulint           tabid
);

DllExport
void
logmnr_get_col_sql(
    dmenv_t         env,    /*IN:�������*/
    rt_memobj_t*    memobj,
    dmstr_t*        dmstr,
    schar*          col_name
);

DllExport
void
logmnr_data_calc_offset(
    byte*           data_p, 
    ulint*          offset_out
);

DllExport
byte
logmnr_op_type(
    ulint           op_code
);

//����llog�����ֶε���Ϣ,��ԭ�ɶ�Ӧ��ʽ���ַ��������ӵ�dmstr��
DllExport
dmcode_t
logmnr_get_data_from_llog(
    dmenv_t         env,    /*IN:�������*/
    rt_memobj_t*	memobj,
    dmstr_t*		dmstr,
    byte*           data_p, 
    ulint*          offset_out,
    dmbool          mine_flag /*�ھ�ʱ���ַ�����ʽ���ؽ�������ǲ��ü�����*/
);

/*���ݵ�ǰ��sql������ͣ���ȡ��Ӧ��undo����*/
DllExport
usint
logmnr_get_undo_op(
    usint           oracle_op_code
);

DllExport
dmcode_t
logmnr_pub_build_ddl_sql(
    dmenv_t         env,    /*IN:�������*/
    rt_memobj_t*    memobj,
    byte*           llog, 
    dmstr_t*        buf, 
    logmnr_extra_info_t* extra_info      /* IN: ������Ϣ */
);

DllExport
dmcode_t
logmnr_pub_build_seq_sql(
    dmenv_t         env,    /*IN:�������*/
    rt_memobj_t*    memobj,
    byte*           llog, 
    dmstr_t*        buf
);

/***********************************************
Purpose:
    logmnr����LOB_DATA��־
***********************************************/
DllExport
dmcode_t        // ������
logmnr_pub_build_lob_data(
    dmenv_t                 env,            /* IN: ������� */
    rt_memobj_t*            memobj,         /* IN: �ڴ�ռ� */
    byte*                   llog,           /* IN: �߼���־ */
    dmstr_t*                dmstr           /* OUT: dmstr */
);

DllExport
dmcode_t
logmnr_pub_build_seq_sql_for_rlog2(
    dmenv_t         env,    /*IN:�������*/
    rt_memobj_t*    memobj,
    byte*           llog, 
    dmstr_t*        buf,
    logmnr_row_info_t*   row_info       /* OUT: ����Ϣ*/
);

/***********************************************
Purpose:
�����߼���־llog����sql�����䵽dmstr��
***********************************************/
DllExport
dmcode_t // ִ�д�����
logmnr_pub_build_sql(
    dmenv_t                     env,            /* IN: ������� */
    rt_memobj_t*                memobj,         /* IN: �ڴ�ռ� */
    byte*                       llog,           /* IN: �߼���־ */
    dmstr_t*                    buf,            /* OUT: dmstr */
    schar*                      sch_name,       /* IN: ģʽ�� */
    ulint                       schema_id,      /* IN: ģʽid */
    ndct_table_t*               table,          /* IN: ����� */
    ulint                       table_id,       /* IN: ��id */
    usint                       op_code,        /* IN: �������� */
    dmbool                      is_undo,        /* IN: �Ƿ�ƴдundo��� */
    logmnr_row_info_t*          row_info,       /* OUT: ����Ϣ*/
    logmnr_extra_info_t*        extra_info      /* IN: ������Ϣ */
);

/************************************************************************
purpose:
    ����xid����Ϣ
************************************************************************/
DllExport
dmcode_t    /*����code*/
logmnr_pub_build_xid_for_rlog2(
    dmenv_t             env,        /*IN:�������*/
    rt_memobj_t*        memobj,     /*IN:�ڴ�*/
    byte*               llog,       /*IN:�߼���־*/
    dmstr_t*            sql_redo,   /*OUT:sql����*/
    logmnr_row_info_t*  row_info    /*OUT:row_info */
);

/***********************************************
Purpose:
�����߼���־llog����sql�����䵽dmstr��
***********************************************/
DllExport
dmcode_t // ִ�д�����
logmnr_pub_build_sql_for_rlog2(
    dmenv_t                     env,            /* IN: ������� */
    rt_memobj_t*                memobj,         /* IN: �ڴ�ռ� */
    byte*                       llog,           /* IN: �߼���־ */
    dmstr_t*                    buf,            /* OUT: dmstr */
    dmstr_t**                   bufs,           /* OUT: ���fast insert����Ҫƴ�ɶ����߼���־ */
    schar*                      sch_name,       /* IN: ģʽ�� */
    ulint                       schema_id,      /* IN: ģʽid */
    ndct_table_t*               table,          /* IN: ����� */
    ulint                       table_id,       /* IN: ��id */
    usint                       op_code,        /* IN: �������� */
    logmnr_row_info_t*          row_info,       /* OUT: ����Ϣ*/
    logmnr_extra_info_t*        extra_info      /* IN: ������Ϣ */
);

DllExport
void
logmnr_binary_assign_from_lint64(
    nstr_t*         dst,
	lint64          v
);

DllExport
dmcode_t
logmnr_get_data_from_llog_for_rlog2(
    dmenv_t         env,    /*IN:�������*/
    rt_memobj_t*    memobj,
    dmstr_t*        dmstr,
    byte*           data_p, 
    ulint*          offset_out,
    dmbool          mine_flag, /*�ھ�ʱ���ַ�����ʽ���ؽ�������ǲ��ü�����*/
    dmbool          parse_lob       /* IN: �Ƿ�������ֶ� */
);

/*********************************************************************************
Purpose:
    �Ӿ����߼���־�ж�ȡ����
*********************************************************************************/
DllExport
dmcode_t        //ִ�д�����
logmnr_get_data_from_compressed_llog_for_rlog2(
    dmenv_t                     env,            /*IN:�������*/
    rt_memobj_t*                memobj,         /*IN:�ڴ����*/
    nrec_t*                     nrec,           /*IN:��¼*/
    usint                       nrec_tail_len,  /*IN:��¼β���ֶεĳ��ȣ�ֻ��V4���У�V3��USINT_UNDEFINED*/
    usint                       col_num,        /*IN:������������rowid��*/
    byte*                       types,          /*IN:������*/
    usint*                      type_len,       /*IN:�еĳ��ȣ���Ϊnrec��û�ж����еĳ���ͷ��Ŀǰֻ��char��binary���õ�*/
    dmbool                      mine_flag,      /*IN:�ھ�ʱ���ַ�����ʽ���ؽ�������ǲ��ü�����*/
    dmbool                      parse_lob,      /*IN:�Ƿ�������ֶ� */
    dmstr_t**                   tmp_dmstr,      /*IN:��������*/
    lint*                       types_map,      /*IN:����ӳ������*/
    ulint                       offset          /*IN:����ƫ���� */
);

/*********************************************************************************
Purpose:
    ���������л�ȡ����ӳ�������Լ�������־�����ݵ�ƫ����
*********************************************************************************/
DllExport
dmcode_t    //ִ�д�����
logmnr_calc_types_map(
    byte*           types,          /*IN:������*/
    usint           col_num,        /*IN:������������rowid��*/
    lint*           types_map,      /*OUT:����ӳ������*/
    ulint*          data_offset     /*OUT:������־�����ݵ�ƫ����*/
);

DllExport
void
logmnr_data_calc_offset_for_rlog2(
    byte*           data_p, 
    ulint*          offset_out
);

DllExport
dmcode_t
logmnr_pub_build_trunc_tab_sql_for_rlog2(
    dmenv_t             env,    /*IN:�������*/
    rt_memobj_t*        memobj,
    byte*               llog, 
    dmstr_t*            buf, 
    logmnr_row_info_t*   row_info,       /* OUT: ����Ϣ*/
    logmnr_extra_info_t* extra_info      /* IN: ������Ϣ */
);

DllExport
dmcode_t
logmnr_pub_build_ddl_sql_for_rlog2(
    dmenv_t         env,    /*IN:�������*/
    rt_memobj_t*    memobj,
    byte*           llog, 
    dmstr_t*        buf, 
    logmnr_row_info_t*   row_info,       /* OUT: ����Ϣ*/
    logmnr_extra_info_t* extra_info      /* IN: ������Ϣ */
);

/********************************************
Purpose:
    �Ƴ���DDL������ķָ���
********************************************/
DllExport
dmcode_t      /* ִ�д����� */
logmnr_pub_build_ddl_remove_delimiter(
    byte*           sql,            /* IN: ��־�м�¼��ddl��� */
    ulint*          sql_len_io      /* IN/OUT: dll���ĳ��� */
);

/***********************************************
Purpose:
��ȡ�߼���־�м�¼��rowid
***********************************************/
DllExport
dmcode_t
logmnr_pub_build_sql_get_rowid(
    byte*                       llog,               /*IN:�߼���־��¼*/
    ulint*                      offset_inout,       /*INOUT:��־ƫ��*/
    logmnr_row_info_t*          row_info,           /* OUT: ����Ϣ*/
    logmnr_extra_info_t*        extra_info          /*IN:������Ϣ */
);

/*********************************************************************
Purpose :
    ��ʼ��row_info
*********************************************************************/
DllExport
dmcode_t                            //����code
logmnr_pub_extra_row_info_init(
    logmnr_row_info_t* row_info     /*IN:row_info���*/
);

/***********************************************
Purpose:
    �����߼���־llog����sql�����䵽dmstr��
Notes:
    ֧��ƴдinsert��delete��update��fast insert���͵�undo���
    ���޸�row_info��extra_info
***********************************************/
DllExport
dmcode_t // ִ�д�����
logmnr_pub_build_sql_undo_for_rlog2(
    dmenv_t                     env,            /* IN: ������� */
    rt_memobj_t*                memobj,         /* IN: �ڴ�ռ� */
    byte*                       llog,           /* IN: �߼���־ */
    dmstr_t*                    buf,            /* OUT: dmstr */
    dmstr_t**                   bufs,           /* OUT: ���fast insert����Ҫƴ�ɶ����߼���־ */
    schar*                      sch_name,       /* IN: ģʽ�� */
    ulint                       schema_id,      /* IN: ģʽid */
    ndct_table_t*               table,          /* IN: ����� */
    ulint                       table_id,       /* IN: ��id */
    usint                       op_code,        /* IN: �������� */
    logmnr_row_info_t*          row_info,       /* IN: ����Ϣ*/
    logmnr_extra_info_t*        extra_info      /* IN: ������Ϣ */
);

/*********************************************************************
Purpose :
    ��NULL׷��ADD COL��
*********************************************************************/
DllExport
dmcode_t    /* ִ�д����� */
logmnr_pub_insert_get_add_col_null_sql(
    dmenv_t         env,        /*IN:�������*/
    rt_memobj_t*    memobj,     /*IN: �ڴ�ռ�*/
    dmstr_t*        dmstr,      /*IN: dmstr*/
    usint           col_num     /* IN: ׷�ӵ����� */
);

/***********************************************
Purpose:
    V1��־��ȡ�߼���־�м�¼��rowid
***********************************************/
DllExport
dmcode_t    /* ִ�д����� */
logmnr_pub_build_sql_get_rowid_v1(
    byte*                       llog,               /*IN:�߼���־��¼*/
    ulint*                      offset_inout,       /*INOUT:��־ƫ��*/
    logmnr_row_info_t*          row_info,           /* OUT: ����Ϣ*/
    logmnr_extra_info_t*        extra_info          /*IN:������Ϣ */
);

/*********************************************************************
Purpose :
    ƴдSQL��׺:ROWID = XXX
*********************************************************************/
DllExport
dmcode_t    /* ִ�д����� */
logmnr_pub_build_where_rowid_postfix(
    dmenv_t             env,                /* IN: ������� */
    rt_memobj_t*        memobj,             /* IN: �ڴ�ռ� */
    dmrd_t              dmrd,               /* IN: rowid��Ϣ*/
    dmstr_t*            dmstr_undo          /* OUT: dmstr */
);

/*********************************************************************
Purpose :
    ��ȡDEL/UPD�߼���־������������������
*********************************************************************/
DllExport
dmcode_t    /* ִ�д����� */
logmnr_pub_del_upd_get_key_num(
    byte*                       llog,           /* IN: �߼���־ */
    ulint*                      offset_io,      /* IN/OUT: ƫ����*/
    usint*                      n_cols,         /* OUT: ��־��������*/
    usint*                      key_num,        /* OUT: ��־������*/
    ulint*                      key_col_off     /* OUT: ��־����ƫ����*/
);

/*********************************************************************
Purpose :
    ����ռ�洢������
*********************************************************************/
DllExport
dmcode_t    //ִ�д�����
logmnr_pub_alloc_tmp_dmstr(
    dmenv_t                     env,                /* IN: ������� */
    rt_memobj_t*                memobj,             /* IN: �ڴ�ռ� */
    ulint                       alloc_num,          /* IN: ������� */
    ulint                       alloc_size,         /* IN: ����ռ��С */
    dmstr_t***                  tmp_dmstr           /* OUT: ����ֵ����*/
);

/*********************************************************************
Purpose :
    ��������������ռ�
*********************************************************************/
DllExport
dmcode_t    //ִ�д�����
logmnr_pub_reinit_tmp_dmstr(
    dmenv_t                     env,                /* IN: ������� */
    rt_memobj_t*                memobj,             /* IN: �ڴ�ռ� */
    ulint                       alloc_num,          /* IN: ������� */
    dmstr_t**                   tmp_dmstr           /* IN: ����ֵ����*/
);

/*********************************************************************
Purpose :
    �ͷ�����������ռ�
*********************************************************************/
DllExport
dmcode_t    //ִ�д�����
logmnr_pub_free_tmp_dmstr(
    dmenv_t                     env,                /* IN: ������� */
    rt_memobj_t*                memobj,             /* IN: �ڴ�ռ� */
    ulint                       alloc_num,          /* IN: ������� */
    dmstr_t**                   tmp_dmstr           /* IN: ����ֵ����*/
);

/***********************************************
Purpose:
    ƴдinsert��redo���
***********************************************/
DllExport
dmcode_t    //ִ�д�����
logmnr_pub_build_ins_redo_for_compress(
    dmenv_t                     env,            /*IN:�������*/
    rt_memobj_t*                memobj,         /*IN:�ڴ����*/
    usint                       rec_col_num,    /*IN:������������rowid��*/
    dmstr_t**                   dmstr_col_arr,  /*IN:����������*/
    dmstr_t*                    dmstr_redo,     /*OUT:redo���*/
    dmbool                      add_col,        /*IN:����׷����*/
    byte*                       virtual_arr     /*IN:��־����������Ϣ*/
);

/***********************************************
Purpose:
    ��V3/V4�汾insert��־�л�ȡ����
***********************************************/
DllExport
dmcode_t    /* ִ�д����� */
logmnr_pub_ins_get_data_for_rlog2_compress(
    dmenv_t                     env,            /*IN:�������*/
    rt_memobj_t*                memobj,         /*IN:�ڴ����*/
    byte*                       llog,           /* IN: �߼���־ */
    dmstr_t**                   tmp_dmstr,      /* OUT: dmstr */
    logmnr_row_info_t*          row_info,       /* OUT: ����Ϣ*/
    logmnr_extra_info_t*        extra_info      /* IN: ������Ϣ */
);

/***********************************************
Purpose:
    fast inser��ȡ������Ϣ
***********************************************/
DllExport
dmcode_t    // ִ�д�����
logmnr_pub_fins_calc_info_for_rlog2(
    dmenv_t                     env,            /* IN: ������� */
    rt_memobj_t*                memobj,         /* IN: �ڴ�ռ� */
    byte*                       llog,           /* IN: �߼���־ */
    dmstr_t**                   dmstrs,         /* OUT: dmstrs��ÿ��dmstr��һ���߼���־ */
    logmnr_row_info_t*          row_info,       /* OUT: ����Ϣ*/
    logmnr_extra_info_t*        extra_info,     /* IN: ������Ϣ */
    byte*                       plsql_type,     /*OUT:������*/
    usint*                      type_len,       /*OUT:�еĳ��ȣ���Ϊnrec��û�ж����еĳ���ͷ��Ŀǰֻ��char��binary���õ�*/
    lint*                       types_map,      /*OUT:����ӳ������*/
    ulint*                      data_offset,     /*OUT:����ƫ���� */
    usint*                      col_num_out,        /* IN: ���� */
    usint*                      nrec_tail_len_out  /*OUT:��¼β���ֶεĳ��ȣ�ֻ��V4���У�V3��USINT_UNDEFINED*/
);

/***********************************************
Purpose:
    insert������־��ȡ������¼
***********************************************/
DllExport
dmcode_t    // ִ�д�����
logmnr_pub_ins_get_nrec_for_compress(
    dmenv_t                     env,                /* IN: ������� */
    rt_memobj_t*                memobj,             /* IN: �ڴ�ռ� */
    byte*                       llog,               /* IN: �߼���־ */
    ulint                       llog_len,           /* IN: �߼���־���� */
    ulint*                      rrec_offset_io,     /* IN/OUT: �߼���־ƫ�� */
    nrec_t**                    nrec_out            /* OUT: �����¼ */
);

/***********************************************
Purpose:
    V5��־��ȡ��������Ϣ
***********************************************/
DllExport
dmcode_t    // ִ�д�����
logmnr_pub_get_virtual_arr(
    byte*                   llog,           /* IN: �߼���־ */
    usint                   rec_col_num,    /* IN: ��־����*/
    ulint*                  offset,         /* IN/OUT: ƫ����*/
    byte*                   virtual_arr     /* OUT:��������Ϣ*/
);

#endif

