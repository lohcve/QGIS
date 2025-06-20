
#ifndef _DWMON_DLL_H_
#define _DWMON_DLL_H_

#ifdef __cplusplus
extern "C" {
#endif

#ifdef WIN32
#define DllImport   __declspec( dllimport )
#define DllExport   __declspec( dllexport )
#else
#define DllImport
#define DllExport
#endif

/* data type */
typedef int                         DWMON_RETURN;

#ifndef _MON_COMM_DTYPE_
#define _MON_COMM_DTYPE_

typedef void*                       mhandle;
typedef signed char                 mschar;
typedef int                         mint4;
typedef unsigned int                muint4;
typedef unsigned short              msint2;
typedef unsigned int                mbool;
typedef unsigned char               mbyte;

#if defined(WIN32) || defined(WINDOWS)
typedef __int64                     mint8;
typedef unsigned __int64            muint8;
#else
typedef long long int               mint8;
typedef unsigned long long int      muint8;
#endif

#endif

//������
#define DWMON_SUCCESS               0
#define DWMON_ERROR                 (-1)
#define DWMON_INVALID_HANDLE        (-2)
#define DWMON_LOG_INIT_FAILED       (-3)
#define DWMON_SYS_INIT_FAILED       (-4)
#define DWMON_NOT_LOGIN             (-5)
#define DWMON_READ_INI_FAILED       (-6)
#define DWMON_INVALID_LOG_PATH      (-7)
#define DWMON_SET_EXECING_FAILED    (-8)
#define DWMON_RESET_EXECING_FAILED  (-9)
#define DWMON_INST_ERROR            (-10)
#define DWMON_SYS_NOT_OK            (-11)       /* tip�����鷵��ֵ��ϵͳ��������״̬ */
#define DWMON_MPPCTL_DIFF           (-12)       /* mpp�����ļ���һ�� */
#define DWMON_DWCTL_NO_ITEM         (-13)       /* dwctlû�нӹ����¼ */
#define DWMON_MULTI_CONFIRM_MON     (-14)       /* ���ڶ��ȷ�ϼ����� */
#define DWMON_WATCH_CONN_FAIL       (-15)       /* �����������ػ����̵�����ʧ�� */
#define DWMON_INVALID_ARGVAL        (-16)       /* �����Ƿ� */
#define DWMON_CODE_MSG_NOT_FOUND    (-17)       /* û���ҵ�code��Ӧ�Ĵ�����Ϣ */
#define DWMON_OUT_OF_MEMORY         (-18)       /* �ڴ治�� */
#define DWMON_REACH_TO_MAX_CONN     (-19)       /* �������Ѵﵽ���������(10��) */
#define DWMON_CHECK_RECOV_LATER     (-20)       /* ��ǰ�޷��жϱ����Ƿ����RECOVER����Ҫ�Ժ�����(�����м�������������ִ�С�ָ��ʵ����δ�ﵽ�ָ��������ָ��ʵ���ϵ�RLOG_BUF��δȫ��������ɵ����)*/
#define DWMON_STDBY_CANNOT_RECOVER  (-21)       /* ���ⲻ����recover���� */
#define DWMON_CHECK_OPEN_LATER      (-22)       /* ��ǰ�޷��ж�ʵ���Ƿ���Զ�OPEN����Ҫ�Ժ����ԣ������м�������������ִ�У�����ʵ����δ������MOUNT״̬�������*/
#define DWMON_INST_CANNOT_OPEN      (-23)       /* ʵ���޷��Զ�OPEN */
#define DWMON_DW_CANNOT_OPEN        (-24)       /* ʵ���Ѿ�����OPEN״̬����watch�޷��л�OPEN */
#define DWMON_PRIM_IS_OK            (-25)       /* ����ʵ��OPEN������watch OPEN�������������쳣ʵ�� */
#define DWMON_NEED_WAIT_DW          (-26)       /* û���������⣨ʵ����watch����OPEN״̬�� ���� ����ȫ����localʵ������������ʵ��û��OPEN����Ҫ�ȴ��ػ����̴������ */
#define DWMON_NEED_USER             (-27)       /* û���������⣨ʵ����watch����OPEN״̬�� ���� ����ȫ����localʵ������������ʵ��û��OPEN����Ҫ�û�ȷ���Ƿ��ֶ���Ԥ */
#define DWMON_NEED_DEINIT           (-28)       /* û��deinit��ֱ��free handle���� */
#define DWMON_INVALID_WALLET_PATH   (-29)       /* MON_WALLET_PATHΪ�գ����·����û�кϷ���wallet�ļ� */
#define DWMON_THRD_PTY_LIB_LOAD_FAILED  (-30)   /* ���������ܿ����ʧ�ܣ����߼�����������Կ��ʧ�ܣ���Ҫ�����������ܿ��ļ��Ƿ���� */
#define DWMON_MLOG_SIZE_TOO_SMALL   (-31)       /* ������־�ռ�̫С */
#define DWMON_INVALID_MON_NAME_LEN  (-32)       /* �����������ȷǷ� */
#define DWMON_NOT_MRAFT             (-33)       /* ��ǰ���Ƕ�ʵ�������� */
#define DWMON_CONN_GMON_FAIL        (-34)       /* �Ӽ����������������������ʧ�� */

#define DWMON_STR_LEN                   64      /* ��������β��'\0' */
#define DWMON_MAX_GROUP                 128     /* ����������������õ��������mpp���1024�飬local��������? */
#define DWMON_MAX_GROUP_NON_LOCAL_INST  9       /* ÿ�����ķǱ���ʵ������(1��8��)*/
#define DWMON_MAX_GROUP_LOCAL_INST      24      /* ÿ�����ı���ʵ������(8�챸+8ͬ��+8����ͨlocalʵ��)*/
#define DWMON_MAX_GROUP_IP              33      /* ÿ������������õ�IP������local��non local���� */

#define DWMON_MAX_TCP_CONN              10      /* ÿ���ػ������������ͬʱ���ӵļ���������(DW2_MAX_M_TCP_CONN) */

//������Эͬ�˳�����
/* ˵��:mraftû��raft��RRAFT_EXIT_ALL_PRE״̬,������Ϊ������leaderЭͬ�˳�ʱ����Ҫִ����ȫ����Ҳ����Ҫ�ȴ�����follower����,
        mraftЭͬ�˳�ֻ��Ҫһ��ͨ��,˵������:
        ��leader�յ�Эͬ�˳�ָ��,ֱ��֪ͨfollower�˳�,follower�յ���ֱ���˳�,����ȴ�������Ϣ
        ��follower�յ�Эͬ�˳�ָ��,ֱ��֪ͨleader�㲥����follower,Ȼ���Լ�ֱ���˳�,����ȴ�leader�㲥��Ϣ */
#define MRAFT_EXIT_ALL_NONE                 0   //δ����
#define MRAFT_EXIT_ALL_LEADER               1   //leaderЭͬ�˳��ĵ�1��״̬����leader��ִ��exit all�����յ�followerת����exit all����ʱ���ã�leader�����ô�״̬��������Эͬ�Ƴ���Ȼ����������ʽ�˳�������������������1��״̬
#define MRAFT_EXIT_ALL_NOTIFY_LEADER        2   //followerЭͬ�˳��ĵ�1��״̬(��follower��ִ��exit all�ĳ����²Ż���)��follower�����ô�״̬���ٽ�exit allת����leader --��������֪ͨ�쵼��
#define MRAFT_EXIT_ALL_FOLLOWER_SHUTDOWN    3   //followerЭͬ�˳��ĵ�3��״̬��follower�յ�leader����ʽ�˳�ָ����ҿ�ʼ�����˳�
#define MRAFT_EXIT_ALL_NORMAL               4   //��ͨ�˳������˳��Լ�

#define MRAFT_STAT_CANDIDATE    0           //��ѡ��
#define MRAFT_STAT_LEADER       1           //�쵼��
#define MRAFT_STAT_FOLLOWER     2           //������
#define MRAFT_STAT_NOT_LEADER   3           //��LEADER
#define MRAFT_STAT_UNKNOW       4           //δ֪

/********************************************************************************************/
/* ������ */
DllExport
DWMON_RETURN
dwmon_alloc_handle(
    mhandle*        mhdle
);

/* ���پ�� */
DllExport
DWMON_RETURN
dwmon_free_handle(
    mhandle         mhdle   //bug599409 �ӿ���ָ�뷽ʽ����ȷ��handle�ÿգ���ֹ�ظ�free��������
);

/*********************************************************************
Purpose :
    ���پ��
*********************************************************************/
DllExport
DWMON_RETURN
dwmon_free_handle_low(
    mhandle*        mhdle    /*IN: �����Ϣ */
);

/* ��ʼ������ */
DllExport
DWMON_RETURN
dwmon_init(
    mhandle         mhdle,      //������
    mschar*	        ini_path,   //ini�ļ�·��
    mschar*         log_path    //log�ļ�·��
);

/* ���ٻ��� */
DllExport
DWMON_RETURN
dwmon_deinit(
    mhandle         mhdle
);

/* ��������ִ�б���Լ���Ҫִ�е�������� */
DllExport
DWMON_RETURN
dwmon_set_cmd_execing_with_command(
    mhandle         mhdle,      /* ��������� */
    mschar*         command     /* �ϲ����ִ̨�е���� */
);

/* ��������ִ�б�� */
DllExport
DWMON_RETURN
dwmon_reset_cmd_execing(
    mhandle         mhdle
);

/* �ȴ���Ϣ�¼� */
DllExport
void
dwmon_msg_event_wait(
    mhandle         mhdle
);

/* ��ȡ�����Ϣ */
DllExport
DWMON_RETURN
dwmon_get_exec_msg(
    mhandle         mhdle,          //���������
    mschar*         buf_msg,        //�����������Ϣ��������ַ
    muint4          buf_len,        //���������in:��������Ϣbuf����󳤶�    
    muint4*         msg_len_out,    //�����������Ϣʵ��д�볤��
    muint4*         get_flag        //����������Ƿ���δ����Ϣ
);

/* ��ȡ�ϲ���Ϣ�߳��˳���� */
DllExport
mbool
dwmon_get_msg_exit_flag(
    mhandle         mhdle
);

/* �����ϲ���Ϣ�߳��˳��¼� */
DllExport
void
dwmon_set_msg_exit_event(
    mhandle         mhdle
);

/* ֪ͨ���ȴ��ϲ���Ϣ�߳��˳� */
DllExport
void
dwmon_msg_event_deinit(
    mhandle         mhdle
);

DllExport
DWMON_RETURN
dwmon_get_dw_confirm(
    mhandle         mhdle,
    mbool*          dw_confirm
);

DllExport
DWMON_RETURN
dwmon_get_mpp_flag(
    mhandle         mhdle,
    mbool*          mpp_flag
);

DllExport
DWMON_RETURN
dwmon_get_version(
    mhandle         mhdle,
    mschar*         version
);

/* ���ö�ʱ��ʾϵͳ״̬��� */
DllExport
DWMON_RETURN
dwmon_set_show_interval(
    mhandle         mhdle,
    muint4          show_interval
);

/* ��ȡ��ʱ��ʾϵͳ״̬��� */
DllExport
DWMON_RETURN
dwmon_get_show_interval(
    mhandle         mhdle,
    muint4*         show_interval
);

/* ������־�Զ���¼��� */
DllExport
DWMON_RETURN
dwmon_set_log_interval(
    mhandle         mhdle,
    muint4          log_interval
);

/* ��ȡ��־�Զ���¼��� */
DllExport
DWMON_RETURN
dwmon_get_log_interval(
    mhandle         mhdle,
    muint4*         log_interval
);

/* ���õ�����־�ļ���С */
DllExport
DWMON_RETURN
dwmon_set_log_file_size(
    mhandle         mhdle,
    muint4          log_file_size
);

/* ��ȡ������־�ļ���С */
DllExport
DWMON_RETURN
dwmon_get_log_file_size(
    mhandle         mhdle,
    muint4*         log_file_size
);

/* ��ȡ��־·�� */
DllExport
DWMON_RETURN
dwmon_get_log_path(
    mhandle         mhdle,
    mschar*         log_path    /* ����257����*/
);

/* ������־�ܿռ��С */
DllExport
DWMON_RETURN
dwmon_set_log_space_limit(
    mhandle         mhdle,
    muint4          log_space_limit
);

/* ��ȡ��־�ܿռ��С */
DllExport
DWMON_RETURN
dwmon_get_log_space_limit(
    mhandle         mhdle,
    muint4*         log_space_limit
);

/* ��¼������ */
DllExport
DWMON_RETURN
dwmon_login(
    mhandle         mhdle,
    mschar*         username,
    mschar*         password
);

/*********************************************************************
Purpose :
    ʹ��wallet��¼����������walletǮ���ж�ȡ�û����������¼��
*********************************************************************/
DllExport
DWMON_RETURN
dwmon_login_wallet(
    mhandle         mhdle,          /* IN����������� */
    mschar*         service_name    /* IN�������� */
);

/* �˳���¼ */
DllExport
DWMON_RETURN
dwmon_logout(
    mhandle         mhdle
);

DllExport
DWMON_RETURN
dwmon_startup_database_watch(
    mhandle         mhdle,
    mschar*         group_name,
    mschar*         db_name
);

DllExport
DWMON_RETURN
dwmon_startup_watch(
    mhandle         mhdle,
    mschar*         group_name
);

DllExport
DWMON_RETURN
dwmon_startup_watch_all(
    mhandle         mhdle
);

DllExport
DWMON_RETURN
dwmon_stop_database_watch(
    mhandle         mhdle,
    mschar*         group_name,
    mschar*         db_name
);

DllExport
DWMON_RETURN
dwmon_stop_watch(
    mhandle         mhdle,
    mschar*         group_name
);

DllExport
DWMON_RETURN
dwmon_stop_watch_all(
    mhandle         mhdle
);

DllExport
DWMON_RETURN
dwmon_startup_group(
    mhandle         mhdle,
    mschar*         group_name
);

DllExport
DWMON_RETURN
dwmon_startup_group_all(
    mhandle         mhdle
);

DllExport
DWMON_RETURN
dwmon_stop_group(
    mhandle         mhdle,
    mschar*         group_name
);

/* ��������£��޶�ֻ��MPP */
DllExport
DWMON_RETURN
dwmon_stop_group_all(
    mhandle         mhdle
);

/* ǿ��openָ�����ָ��ʵ����ֻ��һ��ʱ������ָ��group_name��inst_name������ΪNULL */
DllExport
DWMON_RETURN
dwmon_open_database(
    mhandle         mhdle,
    mschar*         group_name,
    mschar*         db_name
);

/* ��ȡ���л������ı���������ʵ�������飬ֻ��һ��ʱ������ָ��group_name */
DllExport
DWMON_RETURN
dwmon_get_switchover_standby(
    mhandle         mhdle,
    mschar*         group_name,
    muint4*         n_db,           /* ����������������룺�ɻ�ȡ�����ʵ�������������ʵ�ʻ�ȡ��ʵ������ */
    mschar**        db_name_arr     /* ���������ʵ�������飬��n_inst������Ӧ */
);

/* �л�������ʵ����ֻ��һ��ʱ������ָ��group_name��ֻ��һ������ʱ������ָ��inst_name */
DllExport
DWMON_RETURN
dwmon_switchover(
    mhandle         mhdle,
    mschar*         group_name,
    mschar*         db_name
);

/* ��ȡ�ɽӹܹ��������ı���������ʵ�������飬ֻ��һ��ʱ������ָ��group_name */
DllExport
DWMON_RETURN
dwmon_get_takeover_standby(
    mhandle         mhdle,
    mschar*         group_name,
    mbool           force_flag,
    muint4*         n_db,           /* ����������������룺�ɻ�ȡ�����ʵ�������������ʵ�ʻ�ȡ��ʵ������ */
    mschar**        db_name_arr     /* ���������ʵ�������飬��n_inst������Ӧ */
);

DllExport
DWMON_RETURN
dwmon_takeover(
    mhandle         mhdle,
    mschar*         group_name,
    mschar*         db_name
);

DllExport
DWMON_RETURN
dwmon_takeover_force(
    mhandle         mhdle,
    mschar*         group_name,
    mschar*         db_name
);

/* ��ȡ���������������� */
DllExport
DWMON_RETURN
dwmon_get_n_group(
    mhandle         mhdle,
    muint4*         n_group,        /* ����������������룺�ɻ�ȡ�����������������ʵ�ʻ�ȡ������� */
    mschar**        group_name_arr  /* ����������ػ��������飬��n_group������Ӧ */
);

/* ��ȡָ�����������������Ϣ�Լ������л�ģʽ��ֻ��һ��ʱ������ָ��group_name */
DllExport
DWMON_RETURN
dwmon_get_group_info(
    mhandle         mhdle,          /* ������������������ */
    mschar*         group_name,     /* ������������� */
    muint4*         oguid,          /* oguidֵ */
    muint4*         n_dw,           /* ����������������룺�ɻ�ȡ������ػ����̸����������ʵ�ʻ�ȡ���ػ����̸��� */
    mschar**        dw_ip_arr,      /* ���������watch ip���飬��n_dw������Ӧ */
    msint2*         port_arr,       /* watch port */
    mschar*         dw_type,        /* watch���õ�����rt/timely/mpp */
    mschar*         dw_mode,        /* watch���õĹ����л�ģʽauto/manual */
    mschar*         primary_name,   /* PRIMARYʵ���� */
    muint4*         n_split,        /* ����������������룺�ɻ�ȡ��������������������ʵ�ʻ�ȡ�ķ�������� */
    mschar**        split_iname_arr,/* ���������������ctl�ļ����µ�ʵ�������飬��n_split��Ӧ */
    muint4*         n_db,           /* �Ǳ��ؿ���� */
    mschar**        db_name_arr,    /* �Ǳ��ؿ������� */
    muint4*         n_local,        /* ����������������룺�ɻ�ȡ����󱾵�ʵ�������������ʵ�ʻ�ȡ��ʵ������ */
    mschar**        local_name_arr  /* �������������ʵ��������, ��n_local��Ӧ */
);

/* ��ȡָ�����з�������ʵ����Ϣ��ֻ��һ��ʱ������ָ��group_name */
DllExport
DWMON_RETURN
dwmon_get_split_sub_group_database(
    mhandle         mhdle,          /* ������������������ */
    mschar*         group_name,     /* ���������ָ������ */
    mschar*         db_name,        /* ���������������ctl�ļ����µĿ��� */
    muint4*         n_db,           /* �������������������db_name�Ŀ��������һ���Ǳ�����Ҳ�������������������������룺�ɻ�ȡ����������������ʵ�ʻ�ȡ�Ŀ���� */
    mschar**        db_name_arr     /* ���������������db_name�Ŀ������飬��n_db��Ӧ */
);

DllExport
DWMON_RETURN
dwmon_get_database_arch_info(
    mhandle         mhdle,          /* ������������������ */
    mschar*         group_name,     /* ������������������� */
    mschar*		    db_name,        /* ������������� */
    mschar*         arch_type,      /* ���õĹ鵵����rt/timely/mpp */
    muint4*         n_arch,         /* �����������������rt/timely/mpp�鵵�������룺�ɻ�ȡ�����鵵�����������ʵ�ʻ�ȡ�Ĺ鵵���� */
    mschar**        arch_dest,      /* ����������鵵Ŀ��ʵ�������飬��n_arch��Ӧ */
    mschar**        mal_sta,        /* ���������mal��·״̬���飬��n_arch��Ӧ */
    mschar**        arch_sta,       /* ����������鵵״̬���飬��n_arch��Ӧ */
    muint4*         n_async,        /* ����������������õ��첽�鵵�������룺�ɻ�ȡ������첽�鵵�����������ʵ�ʻ�ȡ���첽�鵵���� */
    mschar**        async_dest,     /* ����������첽�鵵Ŀ��ʵ�������飬��n_async��Ӧ */
    mschar**        async_mal_sta   /* ������������챸�Ĺ鵵״̬���飬��n_async��Ӧ */
);

/* ���mppctl�Ƿ���һ��״̬ */
DllExport
DWMON_RETURN
dwmon_check_mppctl(
    mhandle         mhdle
);

/* �ָ�mppctl��һ��״̬ */
DllExport
DWMON_RETURN
dwmon_recover_mppctl(
    mhandle         mhdle
);

/* ��ȡmpp�ڵ���Ϣ */
DllExport
DWMON_RETURN
dwmon_get_mpp_site_info(
    mhandle         mhdle,      /* ������������������ */
    muint4*         n_site,     /* �������������mppվ���������룺�ɻ�ȡ��վ������������ʵ�ʻ�ȡ��վ����� */
    muint4*         ep_seqno,   /* ���������mppվ������飬��n_site��Ӧ */
    mschar**        db_name,    /* ���������mppվ��ʵ�������飬��n_site��Ӧ */
    mschar**        db_ip,      /* ���������mppվ��ip���飬��n_site��Ӧ */
    muint4*         db_port     /* ���������mppվ��port���飬��n_site��Ӧ */
);

/* ��鵱ǰϵͳ����״�� */
DllExport
DWMON_RETURN
dwmon_tip(
    mhandle         mhdle
);

DllExport
DWMON_RETURN
dwmon_get_watch_ctl_info(
    mhandle         mhdle,          /* ������������������ */
    mschar*         group_name,     /* ���������ʵ���������� */
    mschar*         db_name,        /* ���������ʵ���� */
    mschar*         ctl_status,     /* ���������dwctl�ļ�״̬ */
    mschar*         desc            /* ���������dwctl����������Ϣ�����泤�Ȳ���С��513 */ 
);

DllExport
DWMON_RETURN
dwmon_get_database_open_history(
    mhandle         mhdle,          /* ������������������ */
    mschar*         group_name,     /* ���������ʵ���������� */
    mschar*         db_name,        /* ���������ʵ���� */
    muint4*         n_item          /* �������������ʵ��open��¼���� */
);

DllExport
DWMON_RETURN
dwmon_get_nth_open_history(
    mhandle         mhdle,          /* ������������������ */
    mschar*         group_name,     /* ������������������� */
    mschar*         db_name,        /* ������������� */
    muint4          nth,            /* ���������ָ����ȡ��nth��dwctl��¼�� */
    mschar*         tguid,          /* ���������tguid */
    muint8*         rowid,          /* ���������ϵͳ�������е�rowid */
    mschar*         time,           /* ���������ִ��ʱ�� */
    mschar*         sys_mode,       /* ���������OPENʱ������ϵͳģʽ��PRIMARY/NORMAL�� */
    mschar*         p_db_name,      /* �����������Ӧ�����ʵ���� */
    mschar*         c_db_name,      /* �����������ǰ���ʵ���� */
    muint4*         p_db_magic,     /* �����������Ӧ�����db_magic */
    muint4*         c_db_magic,     /* �����������ǰ���db_magic */
    msint2*         n_ep,           /* �������������ʵ���ڵ���� */
    muint8*         aseq_arr,       /* ���������aseq���� */
    muint8*         alsn_arr        /* ���������alsn���� */
);

DllExport
DWMON_RETURN
dwmon_get_monitor_info(
    mhandle         mhdle,          /* ������������������ */
    mschar*         group_name,     /* ���������ʵ������������ֻ��һ������ָ�� */
    mschar*         db_name,        /* �����������(���泤�Ȳ���С��17)��������������local�ػ����͵Ŀ⣬���û��ָ���򷵻�dmmonitor.ini�е�һ���watch��Ϣ���������Ӧ�Ŀ��� */
    muint4*         n_mon,          /* ����������������ӵ�inst_name��monitor���������룺�ɻ�ȡ�����monitor�����������ʵ�ʻ�ȡ��monitor���� */
    mschar**        conn_time_arr,  /* ���������monitor��������ʱ�����飬��n_mon��Ӧ */
    muint4*         confirm_arr,    /* ���������monitor��ȷ�ϼ�����������飬��n_mon��Ӧ */
    muint8*         mid_arr,        /* ���������monitorΨһID���飬��n_mon��Ӧ */
    mschar**        mon_ip_arr,     /* ���������monitor��IP��ַ���飬��n_mon��Ӧ*/
    mschar**        mon_version_arr /* ���������monitor�İ汾��Ϣ����n_mon��Ӧ */
);

DllExport
DWMON_RETURN
dwmon_get_error_msg_by_code(
    mhandle         mhdle,          /* ������������������ */
    mint4           code,           /* �������������code */
    mschar*         buf_msg,        /* ���������code��Ӧ�Ĵ���������Ϣ */
    muint4          buf_len,        /* ���������������buf�������󳤶ȣ����鲻С��4096 */
    muint4*         msg_len_out     /* ���������buf�����ʵ��д�볤�� */
);

/*********************************************************************
Purpose :
    ���������Զ��ӹ���
*********************************************************************/
DllExport
DWMON_RETURN
dwmon_set_group_auto_takeover_list(
    mhandle         mhdle,              /* IN����������� */
    mschar*         group_name,         /* IN������ */
    mschar*         list_str            /* IN���Զ��ӹ������ô� */
);

/*********************************************************************
Purpose :
    ����ȡ���Զ��ӹ���
*********************************************************************/
DllExport
DWMON_RETURN
dwmon_cancel_group_auto_takeover_list(
    mhandle         mhdle,              /* IN����������� */
    mschar*         group_name,         /* IN������ */
    mschar*         list_str            /* IN���Զ��ӹ������ô� */
);

/*********************************************************************
Purpose :
    ��ȡָ�����ָ������Զ��ӹܱ�ѡ���б������Ӧ���Զ��ӹ����ȼ�
*********************************************************************/
DllExport
DWMON_RETURN
dwmon_get_database_auto_takeover_list(
    mhandle         mhdle,          /* IN����������� */
    mschar*         group_name,     /* IN������ */
    mschar*         db_name,        /* IN�����ݿ��� */
    mschar**        takeover_list,  /* OUT���Զ��ӹܱ�ѡ�����б� */
    muint4*         priority_list,  /* OUT���Զ��ӹܱ�ѡ������ȼ��б���takeover_listһһ��Ӧ */
    muint4*         n_inst          /* IN/OUT������takeover_list���鳤�������ʵ�ʻ�ȡ����inst���� */
);

/*********************************************************************
Purpose :
    ���ñ�����Զ��ӹ����ȼ����˽ӿ���Ҫ��ȷ�ϼ�������ִ�У�
*********************************************************************/
DllExport
DWMON_RETURN
dwmon_set_database_auto_takeover_priority(
    mhandle         mhdle,          /* IN����������� */
    mschar*         group_name,     /* IN������ */
    mschar*         db_name,        /* IN����Ҫ�����Զ��ӹ����ȼ������ݿ��� */
    muint4          priority_level  /* IN���Զ��ӹ����ȼ� */
);

/* ���ñ���Ļָ����ʱ�� */
DllExport
DWMON_RETURN
dwmon_set_database_recover_time(
    mhandle         mhdle,          /* ������������������ */
    mschar*         group_name,     /* ����������ػ�������ֻ��һ��ʱ���Բ�ָ�� */
    mschar*         db_name,        /* �����������Ҫ���ûָ�ʱ�����ı����� */
    muint4          recover_time    /* �����������Ҫ���õĻָ�ʱ���� */
);

DllExport
DWMON_RETURN
dwmon_get_n_apply(
    mhandle         mhdle,              /* ������������������ */
    mschar*         group_name,         /* ����������ػ�������ֻ��һ��ʱ���Բ�ָ�� */
    mschar*         db_name,            /* �����������Ҫ��ȡ��־ͬ����Ϣ�ı����� */
    mschar*         ep_name,            /* �����������ȡapply�ı�����ep���� */
    msint2*         n_apply,            /* �����apply���� */
    mschar*         prim_name           /* ���⵱ǰ��Ӧ������ʵ���� */
);

/* ��ȡ����instʵ������ep��¼�ĵ�nth��apply_info�ϵ�lsn����Ϣ����show�����ӡ��ʾ�����ﲻ�����ϸͳ����Ϣ */
DllExport
DWMON_RETURN
dwmon_get_ep_nth_apply_info(
    mhandle         mhdle,              /* ������������������ */
    mschar*         group_name,         /* ����������ػ�������ֻ��һ��ʱ���Բ�ָ�� */
    mschar*         db_name,            /* �����������Ҫ��ȡapply��Ϣ�ı����� */
    muint4          nth,                /* �����������ȡinst_name���ϵ�nth��apply_info�ϵ�lsn�������Ϣ */
    mschar*         prim_name,          /* �����������nth��apply_info�ϼ�¼��pname��Ϣ������Ϊ�� */
    msint2*         dsc_seqno,          /* �������������ڵ�seqno */
    muint8*         sseq,               /* �����������������ݵ��������־����� */
    muint8*         slsn,               /* �����������������ݵ������LSN����Ӧ��־�����Ϊsseq����dsc_seqno��Ӧ��*/
    muint8*         kseq,               /* ������������Զ��л�ģʽ�£����Ᵽ�ֲ����ݵ���־����� */
    muint8*         klsn,               /* ������������Զ��л�ģʽ�£����Ᵽ�ֲ����ݵ����LSN����Ӧ����־�����Ϊkseq����dsc_seqno��Ӧ��*/
    muint8*         aseq,               /* ��������������Ѿ����ݵ�����־����ţ���dsc_seqno��Ӧ��*/
    muint8*         alsn,               /* ��������������Ѿ����ݵ���lsnֵ����Ӧ����־�����Ϊaseq����dsc_seqno��Ӧ��*/
    muint4*         n_task,             /* �����������ǰ��ʣ�����������������watch/monitor��ʹ�� */
    muint8*         tsk_mem_used        /* �����������ǰ�������ռ�õ����ڴ��С���ֽڣ�*/
);

/* �޸ı���Ĺ鵵״̬��Ч */
DllExport
DWMON_RETURN
dwmon_set_database_arch_invalid(
    mhandle         mhdle,          /* ������������������ */
    mschar*         group_name,     /* ����������ػ�������ֻ��һ��ʱ���Բ�ָ�� */
    mschar*         db_name         /* �����������Ҫ���ûָ�ʱ�����ı����� */
);

/*********************************************************************
Purpose :
	��ȡָ��ʵ�����ػ�����������Ϣ
*********************************************************************/
DllExport
DWMON_RETURN
dwmon_get_watch_config_info(
    mhandle         mhdle,              /* ������������������ */
    mschar*         group_name,         /* ��������������ػ�������ֻ��һ��ʱ���Բ�ָ�������û��ָ����������������������ΪNULL */
    mschar*         inst_name,          /* ���������ָ��ʵ���� */
    mschar*         dw_type,            /* dmwatcher.ini��dw_type����ֵ */
    mschar*         dw_mode,            /* dmwatcher.ini��dw_mode����ֵ */
    muint4*         dw_error_time,      /* dmwatcher.ini��dw_error_time����ֵ */
    muint4*         inst_oguid,         /* dmwatcher.ini��inst_oguid����ֵ */
    muint4*         inst_error_time,    /* dmwatcher.ini��inst_error_time����ֵ */
    muint4*         inst_recover_time,  /* dmwatcher.ini��inst_recover_time����ֵ */
    mschar*         inst_ini,               /* dmwatcher.ini��inst_ini����ֵ */
    mschar*         dcr_ini,                /* dmwatcher.ini��dcr_ini����ֵ */
    muint4*         inst_auto_restart,      /* dmwatcher.ini��inst_auto_restart����ֵ */
    mschar*         inst_startup_cmd,       /* dmwatcher.ini��inst_startup_cmd����ֵ */
    muint4*         inst_host_check,        /* dmwatcher.ini��inst_host_check����ֵ */
    muint4*         rlog_send_threshold,    /* dmwatcher.ini��rlog_send_threshold����ֵ */
    muint4*         rlog_apply_threshold,   /* dmwatcher.ini��rlog_apply_threshold����ֵ */
    mschar*         dcs_startup_cmd,        /* dmwatcher.ini��DCS_STARTUP_CMD����ֵ */
    mschar*         dcs_ini,                /* dmwatcher.ini��dcs_ini����ֵ */
    muint4*         dcs_port                /* dmwatcher.ini��dcs_port����ֵ */
);

/* ����ָ���������б���鵵��Ч�����û��ָ��group_name�����������ִ�� */
DllExport
DWMON_RETURN
dwmon_set_group_arch_invalid(
    mhandle         mhdle,              /* ������������������ */
    mschar*         group_name          /* ����������ػ���������ָ�����������ִ�� */
);

/* ����ָ���������б���Ļָ���������û��ָ��group_name�����������ִ�� */
DllExport
DWMON_RETURN
dwmon_set_group_recover_time(
    mhandle         mhdle,              /* ������������������ */
    mschar*         group_name,         /* ����������ػ���������ָ�����������ִ�� */
    muint4          recover_time        /* ����������ָ������ֻ�޸�����watch���ڴ�ֵ */
);

/*********************************************************************
Purpose :
    �ӱ����ػ������ϻ�ȡ�������ʷ��Ϣ
*********************************************************************/
DllExport
DWMON_RETURN
dwmon_get_primary_info(
    mhandle         mhdle,      /* IN����������� */
    mschar*         group_name  /* IN������ */
);

/* ����ָ�����������ػ����̲���ֵ�����û��ָ��group_name�����������ִ�� */
DllExport
DWMON_RETURN
dwmon_set_group_para_value(
    mhandle         mhdle,              /* ������������������ */
    mschar*         group_name,         /* ����������ػ���������ָ�����������ִ�� */
    mschar*         para_name,          /* ������������޸ĵĲ������� */
    mschar*         para_value          /* ������������޸ĵĲ���ֵ���޸�����watch���ڴ�ֵ��dmwatcher.ini�ļ�ֵ */
);

/* �����������ػ�ϵͳ */
DllExport
DWMON_RETURN
dwmon_detach_database(
    mhandle         mhdle,              /* ������������������ */
    mschar*         group_name,         /* ����������ػ�������ֻ��һ��ʱ���Բ�ָ�� */
    mschar*         db_name             /* ���������ָ�������� */
);

/* ����ά����ɺ����½�����ӻ� */
DllExport
DWMON_RETURN
dwmon_attach_database(
    mhandle         mhdle,              /* ������������������ */
    mschar*         group_name,         /* ����������ػ�������ֻ��һ��ʱ���Բ�ָ�� */
    mschar*         db_name             /* ���������ָ�������� */
);

/* ǿɱָ���������server */
DllExport
DWMON_RETURN
dwmon_kill_group(
    mhandle         mhdle,
    mschar*         group_name
);

/* ǿɱ�����������server */
DllExport
DWMON_RETURN
dwmon_kill_group_all(
    mhandle         mhdle
);

/* ���ָ��ʵ���Ƿ������Զ�recover���� */
DllExport
DWMON_RETURN
dwmon_check_recover(
    mhandle         mhdle,          /* ������������������ */
    mschar*         group_name,     /* ������������� */
    mschar*         db_name         /* ���������ʵ���� */
);

/* ��ȡ���е�nth�����ȫ����Ϣ */
DllExport
DWMON_RETURN
dwmon_get_nth_database_info(
    mhandle         mhdle,          /* ������������������ */
    mschar*         group_name,     /* ���������ʵ���������� */
    muint4          nth,            /* ���������ȡ��nth��ʵ����Ϣ */
    mschar*         dw_time,        /* �ػ����̵�ǰʱ�� */
    mschar*         dw_ip,          /* �ػ�����IP��ַ */
    msint2*         dw_port,        /* �ػ�����TCP�˿� */
    mschar*         dw_type,        /* �ػ����� */
    mschar*         dw_mode,        /* �����л�ģʽ */
    muint4*         dw_err_time,    /* Զ���ػ����̹����϶�ʱ���� */
    mschar*         dw_sta,         /* �ػ�����״̬ */
    mschar*         dw_sub_sta,     /* �ػ�������״̬ */
    mschar*         dw_ctl_sta,     /* �ػ����̿����ļ�״̬ */
    mschar*         db_name,        /* ʵ���� */
    mschar*         db_ok_str,      /* ʵ���Ƿ����� */
    mschar*         svr_mode,       /* ʵ��ģʽ */
    mschar*         svr_status,     /* ʵ��״̬ */
    mschar*         arch_type,      /* ������ep���õĹ鵵���� */
    mschar*         arch_status,    /* ��ǰ��Ϊrt/timely����ʱ�����⵽��ǰ����Ĺ鵵״̬ */
    muint4*         pmnt_magic,     /* ���ݿ�����ħ�� */
    muint4*         db_magic,       /* ���ݿ�ħ�� */
    msint2*         n_ep,           /* ����������������е�ep���� */
    msint2*         ep_seqno_arr,   /* ���е�ep seqno���� */
    mschar**        ep_name_arr,    /* ���е�epʵ�������� */
    msint2*         dsc_ctl_node,   /* ���п���ep��seqno */
    mschar*         dsc_status,     /* ���hpc״̬ */
    msint2*         n_ok_ep,        /* ����������������е�ok ep���� */
    msint2*         ok_ep_arr,      /* ���е�ok ep��seqno���� */
    msint2*         n_break_ep,     /* ���������������ǰ���ڹ��ϴ���Ľڵ���*/
    msint2*         break_ep_arr    /* �����������ǰ���ڹ��ϴ����ep seqno���� */
);

/*********************************************************************
Purpose:
    ���ָ�����Ƿ��Ѿ���detach����Ⱥ
*********************************************************************/
DllExport
DWMON_RETURN
dwmon_check_db_detached(
    mhandle             mhdle,          /* IN����������� */
    mschar*             group_name,     /* IN��ʵ���������� */
    mschar*             db_name,        /* IN��ʵ���� */
    mbool*              detached        /* OUT���Ƿ�detach����Ⱥ */
);

/*********************************************************************
Purpose :
    ��ȡָ��ʵ�������ڿ��ȫ����Ϣ
*********************************************************************/
DllExport
DWMON_RETURN
dwmon_get_database_info_by_name(
    mhandle         mhdle,          /* ������������������ */
    mschar*         group_name,     /* ���������ʵ���������� */
    mschar*         db_name,        /* ���������ʵ���� */
    mschar*         dw_time,        /* ���ػ����̵�ǰʱ�� */
    mschar*         dw_ip,          /* ���ػ�����IP��ַ */
    msint2*         dw_port,        /* ���ػ�����TCP�˿� */
    mschar*         dw_type,        /* ���ػ����� */
    mschar*         dw_mode,        /* ���ػ��������õĹ����л�ģʽ */
    muint4*         dw_err_time,    /* Զ�����ػ����̹����϶�ʱ���� */
    mschar*         dw_sta,         /* ���ػ�����״̬ */
    mschar*         dw_sub_sta,     /* ���ػ�������״̬ */
    mschar*         dw_ctl_sta,     /* �ػ����̿����ļ�״̬ */
    mschar*         dbt_ok_str,     /* ���Ƿ����� */
    mschar*         svr_mode,       /* ��ģʽ */
    mschar*         svr_status,     /* ��״̬ */
    mschar*         arch_type,      /* ������ep���õĹ鵵���� */
    mschar*         arch_status,    /* ��ǰ��Ϊrt/timely����ʱ�����⵽��ǰ����Ĺ鵵״̬ */
    muint4*         pmnt_magic,     /* ���ݿ�����ħ�� */
    muint4*         db_magic,       /* ���ݿ�ħ�� */
    msint2*         n_ep,           /* ���е�ep���� */
    msint2*         ep_seqno_arr,   /* ���е�ep seqno���� */
    mschar**        ep_name_arr,    /* ���е�epʵ�������� */
    msint2*         dsc_ctl_node,   /* ���п���ep��seqno */
    mschar*         dsc_status,     /* ���hpc״̬ */
    msint2*         n_ok_ep,        /* ���е�ok ep������ȡ��master ep����hpc_master != 0xFFʱ��Ч */
    msint2*         ok_ep_arr,      /* ���е�ok ep��seqno���飬ȡ��master ep����hpc_master != 0xFFʱ��Ч */
    msint2*         n_break_ep,     /* ���������������ǰ���ڹ��ϴ���Ľڵ���*/
    msint2*         break_ep_arr    /* �����������ǰ���ڹ��ϴ����ep seqno���� */
);

DllExport
DWMON_RETURN
dwmon_get_database_info(
    mhandle         mhdle,          /* ������������������ */
    mschar*         group_name,     /* ���������ʵ���������� */
    mschar*         db_name,        /* ���������ʵ������������� */
    msint2*         n_ep,           /* ����������������ep���� */
    msint2*         ep_seqno_arr,   /* ����������������ep��seqno���� */
    mschar**        ep_name_arr,    /* ����������������epʵ�������� */
    msint2*         dsc_ctl_node,   /* ���������������п���ep��seqno */
    mschar*         dsc_status,     /* ���hpc״̬ */
    msint2*         n_ok_ep,        /* ��������������������ok ep���� */
    msint2*         ok_ep_arr,      /* ����������������ok ep��seqno���� */
    msint2*         n_break_ep,     /* ���������������ǰ���ڹ��ϴ���Ľڵ��� */
    msint2*         break_ep_arr    /* �����������ǰ���ڹ��ϴ����ep seqno���� */
);

DllExport
DWMON_RETURN
dwmon_get_ep_info_by_name(
    mhandle         mhdle,          /* ������������������ */
    mschar*         group_name,     /* ���������ʵ���������� */
    mschar*         ep_name,        /* ���������epʵ���� */
    muint4*         ep_port,        /* ʵ���˿ں� */
    mschar*         ep_ok_str,      /* ʵ���Ƿ����� */
    mschar*         svr_mode,       /* ʵ��ģʽ */
    mschar*         svr_status,     /* ʵ��״̬ */
    mschar*         prim_inst,      /* ��ӦPRIMARYʵ���� */
    mschar*         prim_mal_sta,   /* ��ӦPRIMARYʵ������ʵ����MAL��·״̬  ֻ�Ա�����Ч�����������ep��ep_name���ڵı�����ep��mal��·״̬ */
    mschar*         prim_arch_type, /* ��ӦPRIMARYʵ������ʵ���Ĺ鵵���� */
    mschar*         prim_arch_sta,  /* ��ӦPRIMARYʵ������ʵ���Ĺ鵵״̬��ֻ�Ա�����Ч�����������ep��ep_name���ڵı�����ep�Ĺ鵵״̬ */
    muint8*         fseq,           /* ��д��������־��rlog_pkg����� */
    muint8*         flsn,           /* ��д��������־��flsnֵ����Ӧ�İ����Ϊfseq */
    muint8*         cseq,           /* ϵͳ��ǰ�Ѿ���������RLOG_PKG����� */
    muint8*         clsn,           /* ϵͳ��ǰ�Ѿ���������LSNֵ����Ӧ�İ����Ϊcseq */
    mschar*         arch_type,      /* ʵ���������õĹ鵵����rt/timely */
    muint4*         n_arch,         /* ʵ���������õ�rt/timely�鵵�� */
    muint4*         n_async,        /* ʵ���������õ��첽�鵵�� */
    muint4*         n_subscb,       /* ʵ���������õĶ��Ĺ鵵�� 0 or 1*/
    msint2*         dsc_seqno,      /* ʵ����seqno */
    mschar*         g_dw_status,    /* ep�����õ�ȫ��״̬��� */
    mbyte*          mpp_flag_mem,   /* �ڴ��е�mpp_ini*/
    mbyte*          mpp_flag_file   /* ini�ļ��е�mpp_ini*/
);

DllExport
DWMON_RETURN
dwmon_get_nth_ep_info(
    mhandle         mhdle,          /* ������������������ */
    mschar*         group_name,     /* ���������ʵ���������� */
    mschar*         db_name,        /* ���������ʵ�������Ŀ��� */
    muint4          nth,            /* ���������ȡinst_name���ϵĵ�nth��ʵ����Ϣ */
    mschar*         ep_name,        /* ���������epʵ���� */
    muint4*         ep_port,        /* ʵ���˿ں� */
    mschar*         ep_ok_str,      /* ʵ���Ƿ����� */
    mschar*         svr_mode,       /* ʵ��ģʽ */
    mschar*         svr_status,     /* ʵ��״̬ */
    mschar*         prim_inst,      /* ��ӦPRIMARYʵ���� */
    mschar*         prim_mal_sta,   /* ��ӦPRIMARYʵ������ʵ����MAL��·״̬  ֻ�Ա�����Ч�����������ep��ep_name���ڵı�����ep��mal��·״̬ */
    mschar*         prim_arch_type, /* ��ӦPRIMARYʵ������ʵ���Ĺ鵵���� */
    mschar*         prim_arch_sta,  /* ��ӦPRIMARYʵ������ʵ���Ĺ鵵״̬��ֻ�Ա�����Ч�����������ep��ep_name���ڵı�����ep�Ĺ鵵״̬ */
    muint8*         fseq,           /* ��д��������־��rlog_pkg����� */
    muint8*         flsn,           /* ��д��������־��flsnֵ����Ӧ�İ����Ϊfseq */
    muint8*         cseq,           /* ϵͳ��ǰ�Ѿ���������RLOG_PKG����� */
    muint8*         clsn,           /* ϵͳ��ǰ�Ѿ���������LSNֵ����Ӧ�İ����Ϊcseq */
    mschar*         arch_type,      /* ʵ���������õĹ鵵����rt/timely */
    muint4*         n_arch,         /* ʵ���������õ�rt/timely�鵵�� */
    muint4*         n_async,        /* ʵ���������õ��첽�鵵�� */
    muint4*         n_subscb,       /* ʵ���������õĶ��Ĺ鵵�� 0 or 1*/
    msint2*         dsc_seqno,      /* ʵ����seqno */
    mschar*         g_dw_status,    /* ep�����õ�ȫ��״̬��� */
    mbyte*          mpp_flag_mem,   /* �ڴ��е�mpp_ini*/
    mbyte*          mpp_flag_file   /* ini�ļ��е�mpp_ini*/
);

/* ���ָ��ʵ���Ƿ������Զ�OPEN���� */
DllExport
DWMON_RETURN
dwmon_check_open(
    mhandle         mhdle,          /* ������������������ */
    mschar*         group_name,     /* ������������� */
    mschar*         db_name         /* ���������ʵ���� */
);

/* ����ָ��ʵ���Ĺ鵵����ͳ����Ϣ */
DllExport
DWMON_RETURN
dwmon_clear_database_arch_send_info(
    mhandle         mhdle,
    mschar*         group_name,
    mschar*         db_name
);

DllExport
DWMON_RETURN
dwmon_clear_group_arch_send_info(
    mhandle         mhdle,              /* ������������������ */
    mschar*         group_name          /* ����������ػ���������ָ�����������ִ�� */
);

/* ����ָ��ʵ����RAPPLY_INFO */
DllExport
DWMON_RETURN
dwmon_clear_database_rapply_stat(
    mhandle         mhdle,
    mschar*         group_name,
    mschar*         db_name
);

DllExport
DWMON_RETURN
dwmon_clear_group_rapply_stat(
    mhandle         mhdle,              /* ������������������ */
    mschar*         group_name          /* ����������ػ���������ָ�����������ִ�� */
);

/* �ҳ�ָ�������Դ������ */
DllExport
DWMON_RETURN
dwmon_get_source_database_name(
    mhandle         mhdle,          /* ������������������ */
    mschar*         group_name,     /* ����������ػ�������ֻ��һ��ʱ���Բ�ָ�� */
    mschar*         db_name,        /* ���������������Դ��ı���ʵ���� */
    mschar*         source_name     /* ������������Դ��ʵ���������inst_name���첽���⣬Դ�����Ҳ��STANDBYģʽ��*/
);

/* ��ȡԴep��Ŀ��ʵ��inst_name�Ĺ鵵������Ϣ */
DllExport
DWMON_RETURN
dwmon_get_ep_arch_send_info(
    mhandle         mhdle,          /* ������������������ */
    mschar*         group_name,     /* ����������ػ�������ֻ��һ��ʱ���Բ�ָ�� */
    mschar*         source_name,    /* ���������Դ���ĳ��epʵ������������첽���⣬Դ�����Ҳ��STANDBYģʽ�� */
    mschar*         db_name,        /* �����������Ҫ��ȡ��־ͬ����Ϣ�ı����� */
    muint4*         time_in_ini,        /* �����������dmwatcher.ini�����õĻָ�ʱ����(inst_recover_time)����local�ػ�������Ч */
    muint4*         time_in_mem,        /* �����������dmwatcher�ڴ��е�ǰ���õĻָ�ʱ��������local�ػ�������Ч */
    mschar*         last_recover_time,  /* �����������dmwatcher�ϴλָ�ʱ�䣬��local�ػ�������Ч */
    mint4*          last_recover_code,  /* �����������dmwatcher�ϴλָ�code����local�ػ�������Ч */
    mschar*         arch_type,          /* ���������source_name��inst_name�Ĺ鵵����rt/timely/async */
    mschar*         mal_sta,            /* ���������source_name��inst_name������ep��mal��·״̬ */
    mschar*         arch_sta,           /* ���������source_name��inst_name������ep�Ĺ鵵״̬ */
    mschar*         send_type,          /* ���������source_name��inst_name�����һ��arch�������ͣ�ʵʱͬ����watch�����recoveryͬ���� */
    mschar*         last_start_time,    /* ���������source_name��inst_name�����һ��arch������ʼʱ�� */
    mschar*         last_end_time,      /* ���������source_name��inst_name�����һ��arch���ͽ���ʱ�� */
    mint8*          last_send_time,     /* ���������source_name��inst_name�����һ��arch���ͺ�ʱ��΢�룩 */
    muint8*         last_start_lsn,     /* ���������source_name��inst_name�����һ��arch������ʼlsn */
    muint8*         last_end_lsn,       /* ���������source_name��inst_name�����һ��arch���ͽ���lsn */
    muint4*         last_send_len,      /* ���������source_name��inst_name�����һ��arch���ͳ��ȣ��ֽڣ� */
    muint4*         last_send_ptx,      /* ���������source_name��inst_name�����һ��arch���͵�ptx���� */
    mint4*          code,               /* ���������source_name��inst_name�����һ��arch����code */
    mschar*         desc_info,          /* ���������source_name��inst_name�����һ��arch����������Ϣ */
    mint4*          recnt_cnt,          /* ���������source_name��inst_name������ʹ�����Nֵ */
    mint8*          recnt_send_len,     /* ���������source_name��inst_name���N���ۼ���־���ͳ��ȣ��ֽڣ���Nֵȡ��recnt_cnt�� */
    mint8*          recnt_ptx_cnt,      /* ���������source_name��inst_name���N���ۼ���־����ptx���� */
    mint8*          recnt_send_time,    /* ���������source_name��inst_name���N���ۼ���־���ͺ�ʱ��΢�룩  */
    mint8*          max_send_time,      /* ���������source_name��inst_name����ͺ�ʱ��΢�룩*/
    mschar*         max_end_time,       /* ���������source_name��inst_name����ͺ�ʱ�Ľ���ʱ�� */
    muint4*         max_ptx_cnt,        /* ���������source_name��inst_name����͵�ptx����*/
    muint4*         max_send_len,       /* ���������source_name��inst_name����͵���־���ȣ��ֽڣ�*/
    mint8*          max_send_lsn,       /* ���������source_name��inst_name����͵���־lsnֵ */
    mint8*          total_send_cnt,     /* ���������source_name��inst_name�ۼƷ��ʹ���*/
    mint8*          total_send_len,     /* ���������source_name��inst_name�ۼƷ�����־���ȣ��ֽڣ�*/
    mint8*          total_ptx_cnt,      /* ���������source_name��inst_name�ۼƷ���ptx����*/
    mint8*          total_send_time     /* ���������source_name��inst_name�ۼƷ��ͺ�ʱ��΢�룩*/
);

DllExport
DWMON_RETURN
dwmon_get_ep_nth_apply_stat(
    mhandle         mhdle,              /* ������������������ */
    mschar*         group_name,         /* ����������ػ�������ֻ��һ��ʱ���Բ�ָ�� */
    mschar*         db_name,            /* �����������Ҫ��ȡ��־ͬ����Ϣ�ı����� */
    muint4          nth,                /* �����������ȡinst_name�ĵ�nth��apply_info��Ϣ */
    mschar*         prim_name,          /* �����������nth��apply_info�ϼ�¼������ڵ����� */
    msint2*         dsc_seqno,          /* �������������ڵ�seqno */
    muint8*         sseq,               /* �����������������ݵ��������־�����  */
    muint8*         slsn,               /* �����������������ݵ������LSN����Ӧ����־�����Ϊsseq����dsc_seqno��Ӧ��*/
    muint8*         kseq,               /* ������������Զ��л�ģʽ�£����Ᵽ�ֲ����ݵ���־����� */
    muint8*         klsn,               /* ������������Զ��л�ģʽ�£����Ᵽ�ֲ����ݵ����LSN����Ӧ��־�����Ϊkseq����dsc_seqno��Ӧ��*/
    muint8*         aseq,               /* ��������������Ѿ����ݵ�����־����� */
    muint8*         alsn,               /* ��������������Ѿ����ݵ���lsnֵ����Ӧ��־�����Ϊaseq����dsc_seqno��Ӧ��*/
    muint4*         n_task,             /* �����������ǰ��ʣ�����������������watch/monitor��ʹ�� */
    muint8*         tsk_mem_used,       /* �����������ǰ�������ռ�õ����ڴ��С���ֽڣ�*/    
    mint4*          recnt_apply_num,    /* �������������ۼ����ݵĴ���N */
    muint4*         last_recved_len,    /* ������������һ���յ�����־���ȣ��ֽڣ�*/
    mint8*          last_res_time,      /* ������������һ����Ϣ��Ӧʱ�䣨΢�룩*/
    mint8*          last_wait_time,     /* ������������һ������ȴ�ʱ�䣨΢�룩*/
    muint4*         last_apply_len,     /* ������������һ�����ݵ���־���ȣ��ֽڣ�*/
    mint8*          last_apply_time,    /* ������������һ�����ݺ�ʱ��΢�룩*/
    mint8*          recnt_recved_len,   /* ������������N���ۼƽ��ճ��ȣ�Nֵȡ��recnt_apply_num�� */
    mint8*          recnt_res_time,     /* ������������N���ۼ���Ӧʱ�䣨΢�룩 */
    mint8*          recnt_wait_time,    /* ������������N���ۼƵȴ�ʱ�䣨΢�룩 */
    mint8*          recnt_apply_len,    /* ������������N���ۼ����ݳ��ȣ��ֽڣ� */
    mint8*          recnt_apply_time,   /* ������������N���ۼ�����ʱ�䣨΢�룩 */
    mint8*          max_res_time,       /* ��������������Ϣ��Ӧʱ�䣨΢�룩 */
    mint8*          max_wait_time,      /* ����������������ȴ�ʱ�䣨΢�룩 */
    mint8*          max_apply_time,     /* ��������������������ʱ�䣨΢�룩 */
    muint4*         max_apply_len,      /* �����������max_apply_time��Ӧ����־���ȣ��ֽڣ� */
    mint8*          total_recved_num,   /* ����������ۼ��յ���־���������� */
    mint8*          total_recved_len,   /* ����������ۼ��յ���־�����ֽڣ�*/
    mint8*          total_apply_num,    /* ����������ۼ�������־���� */
    mint8*          total_apply_len,    /* ����������ۼ�������־�����ֽڣ�*/
    mint8*          total_res_time,     /* ����������ۼ���Ϣ��Ӧʱ�䣬�յ���Ϣ����Ӧ��Ϣ��΢�룩 */
    mint8*          total_wait_time,    /* ����������ۼ�����ȴ�ʱ�䣨΢�룩 */
    mint8*          total_apply_time    /* ����������ۼ���־����ʱ�䣨΢�룩*/
);

/*********************************************************************
Purpose :
    ��ȡapply info����������Ϣ  
*********************************************************************/
DllExport
DWMON_RETURN
dwmon_get_ep_nth_apply_with_parallel_info(
    mhandle         mhdle,              /* IN: ��������� */
    mschar*         group_name,         /* IN: �ػ�������ֻ��һ��ʱ���Բ�ָ�� */
    mschar*         db_name,            /* IN: ��Ҫ��ȡ��־ͬ����Ϣ�ı����� */
    muint4          nth,                /* IN: ��ȡinst_name�ĵ�nth��apply_statͳ����Ϣ */
    mschar*         prim_name,          /* OUT:��nth��apply_info�ϼ�¼��pname��Ϣ������Ϊ�� */
    msint2*         dsc_seqno,          /* OUT:����ڵ�seqno */
    muint8*         sseq,               /* OUT:��������ݵ��������־����� */
    muint8*         slsn,               /* OUT:��������ݵ������LSN����Ӧ��־�����Ϊsseq����dsc_seqno��Ӧ��*/
    muint8*         kseq,               /* OUT:���Զ��л�ģʽ�£����Ᵽ�ֲ����ݵ���־����� */
    muint8*         klsn,               /* OUT:���Զ��л�ģʽ�£����Ᵽ�ֲ����ݵ����LSN����Ӧ����־�����Ϊkseq����dsc_seqno��Ӧ��*/
    muint8*         rseq,               /* OUT:�����Ѿ����ݵ�����־����ţ���dsc_seqno��Ӧ��*/
    muint8*         rlsn,               /* OUT:�����Ѿ����ݵ���lsnֵ����Ӧ����־�����Ϊaseq����dsc_seqno��Ӧ��*/
    msint2*         n_pll,              /* OUT:���ж���Ϣ */
    muint8*         redo_lsn_arr,       /* OUT:redo lsn��Ϣ����plog redo struct�ϻ�ȡ */
    muint4*         n_task,             /* OUT:��ǰ��ʣ�����������������watch/monitor��ʹ�� */
    muint8*         tsk_mem_used        /* OUT:Z��ǰ�������ռ�õ����ڴ��С���ֽڣ�*/    
);

DllExport
DWMON_RETURN
dwmon_stop_database(
    mhandle         mhdle,          /* ������������������ */
    mschar*         group_name,     /* ����������ػ�������ֻ��һ��ʱ���Բ�ָ�� */
    mschar*         db_name         /* ������������� */
);

DllExport
DWMON_RETURN
dwmon_startup_database(
    mhandle         mhdle,          /* ������������������ */
    mschar*         group_name,     /* ����������ػ�������ֻ��һ��ʱ���Բ�ָ�� */
    mschar*         db_name         /* ������������� */
);

DllExport
DWMON_RETURN
dwmon_kill_database(
    mhandle         mhdle,          /* ������������������ */
    mschar*         group_name,     /* ����������ػ�������ֻ��һ��ʱ���Բ�ָ�� */
    mschar*         db_name         /* ������������� */
);

/* ��ȡָ��ʵ����DMCSS������Ϣ */
DllExport
DWMON_RETURN
dwmon_get_css_config_info(
    mhandle         mhdle,              /* ������������������ */
    mschar*         group_name,         /* ��������������ػ�������ֻ��һ��ʱ���Բ�ָ�������û��ָ����������������������ΪNULL */
    mschar*         inst_name,          /* ���������ָ��ʵ���� */
    muint4*         asm_restart_itvl,   /* ���������dmdcr.ini��asm_restart_itvl����ֵ */
    muint4*         db_restart_itvl     /* ���������dmdcr.ini��db_restart_itvl����ֵ */
);

/* ��ָ����������RAC�ڵ���Զ������� */
DllExport
DWMON_RETURN
dwmon_set_group_auto_restart_on(
    mhandle         mhdle,          /* ������������������ */
    mschar*         group_name      /* ����������ػ���������ָ�����������ִ�� */
);

/* �ر�ָ����������RAC�ڵ���Զ������� */
DllExport
DWMON_RETURN
dwmon_set_group_auto_restart_off(
    mhandle         mhdle,          /* ������������������ */
    mschar*         group_name      /* ����������ػ���������ָ�����������ִ�� */
);

DllExport
DWMON_RETURN
dwmon_get_takeover_time(
    mhandle         mhdle
);

/*********************************************************************
Purpose :
    ��ȡָ���ػ����Զ��ӹ�ʱ��
*********************************************************************/
DllExport
DWMON_RETURN
dwmon_get_takeover_time_by_group_name(
    mhandle         mhdle,          /* IN:  ���������*/
    mschar*         group_name,     /* IN:  �ػ�������ֻ��һ��ʱ���Բ�ָ�� */
    muint4*         remain_time,    /* OUT: �Զ��ӹ�ʱ�� */
    mschar*         inst_name       /* OUT: �ӹ�ʵ����   */
);

/************************************************************************
purpose:
��ȡ������״̬
/************************************************************************/
DllExport
DWMON_RETURN
dwmon_get_monitor_state(
    mhandle             mhdle,          /* ������������������ */
    muint4*             n_mon,          /* �������, ���������� */
    mschar**            mon_name_arr,   /* ���������monitor��������, ��n_mon��Ӧ */
    muint4*             mon_state_arr,  /* ���������monitor�ļ�����״̬����, ��n_mon��Ӧ */
    muint4*             mon_id_arr,     /* ���������monitorID����, ��n_mon��Ӧ */
    muint4*             mon_role_arr,   /* �������, monitor��ɫ����, ��n_mon��Ӧ */
    mschar**            mon_ip_arr,     /* ���������monitor��IP��ַ���飬��n_mon��Ӧ*/
    muint4*             mon_port_arr,   /* ���������monitor�Ķ˿ں���Ϣ����n_mon��Ӧ */
    muint4*             mon_bro,        /* �������, monitor�Ĺ㲥��ʱ */
    muint4*             mon_vote        /* �������, monitor��ͶƱ��ʱ */
);

/***********************************************************************
Purpose:
    monitor�������첽��������ʱ���ӿ�
***********************************************************************/
DllExport
DWMON_RETURN
dwmon_set_database_until_time(
    mhandle         mhdle,          /* ������������������ */
    mschar*         group_name,     /* ����������ػ�������ֻ��һ��ʱ���Բ�ָ�� */
    mschar*         db_name,        /* �����������Ҫ��������ʱ���ı����� */
    mschar*         until_time      /* �����������Ҫ���õ��첽��������ʱ��� */
);

/***********************************************************************
Purpose:
    monitor���ȡ�첽��������ʱ���ӿ�
***********************************************************************/
DllExport
DWMON_RETURN
dwmon_get_database_until_time(
    mhandle         mhdle,          /* ������������������ */
    mschar*         group_name,     /* ����������ػ�������ֻ��һ��ʱ���Բ�ָ�� */
    mschar*         db_name,        /* �����������Ҫ��ȡ����ʱ���ı����� */
    mschar*         until_time,     /* ����������첽���������ʱ��� */
    mbool*          apply_over      /* ���������TRUE/FALSE�������Ƿ������ݵ�ָ����until_timeʱ��� */
);

/***********************************************************************
Purpose:
monitor���ȡrfile��n_max_ep seq lsn
***********************************************************************/
DllExport
DWMON_RETURN
dwmon_get_database_rfil_lsn(
    mhandle         mhdle,          /* ������������������ */
    mschar*         group_name,     /* ����������ػ�������ֻ��һ��ʱ���Բ�ָ�� */
    mschar*         db_name,        /* �����������Ҫ��ȡ����ʱ���ı����� */
    muint4*         n_max_ep,        /* �����������Ҫ��ȡ����ʱ���ı����� */
    muint8*         keep_seq,       /* ���������monitor�ļ�����״̬����, ��n_mon��Ӧ */
    muint8*         keep_lsn        /* ���������monitor�ļ�����״̬����, ��n_mon��Ӧ */
);

/***********************************************************************
Purpose:
monitor���ȡep subscb_mode
***********************************************************************/
DllExport
DWMON_RETURN
dwmon_get_database_subscb_mode(
    mhandle         mhdle,          /* ������������������ */
    mschar*         group_name,     /* ����������ػ�������ֻ��һ��ʱ���Բ�ָ�� */
    mschar*         db_name,        /* �����������Ҫ��ȡ����ʱ���ı����� */
    muint4*         subscb_mode        /* ���������monitor�ļ�����״̬����, ��n_mon��Ӧ */
);

/***********************************************************************
Purpose:
    ��ȡָ��ep��IP��ַ
***********************************************************************/
DllExport
DWMON_RETURN
dwmon_get_ep_host(
    mhandle         mhdle,          /* IN: ��������� */
    mschar*         group_name,     /* IN: ʵ���������� */
    mschar*         ep_name,        /* IN: epʵ���� */
    mschar*         ep_host         /* OUT: ���ep��IP��ַ���������������IP�����������IP�������������IP */
);

/***********************************************************************
Purpose:
    ��������ȡָ�������APPLY_WAIT��ǣ�������ڱ�ʾ�����Ƿ�������һ�µ�
***********************************************************************/
DllExport
DWMON_RETURN
dwmon_get_database_apply_wait(
    mhandle         mhdle,          /* ������������������ */
    mschar*         group_name,     /* ����������ػ�������ֻ��һ��ʱ���Բ�ָ�� */
    mschar*         db_name,        /* ��������������� */
    mbool*          apply_wait      /* ���������TRUE/FALSE������һ�±�־ */
);

/*********************************************************************
Purpose :
    ��ȡָ���������õ�ͬ���鵵��Ϣ
*********************************************************************/
DllExport
DWMON_RETURN
dwmon_get_database_sync_arch_info(
    mhandle         mhdle,          /* IN: ������������������ */
    mschar*         group_name,     /* IN: ������������������� */
    mschar*         db_name,        /* IN: ������������� */
    muint4*         n_sync,         /* IN/OUT: ����Ҫ��ȡ��sync�鵵���������ʵ������sync�鵵�� */
    mschar**        sync_dest,      /* OUT: ͬ���鵵Ŀ��ʵ�������� */
    mschar**        sync_mal_sta,   /* OUT: ��ͬ�������mal��·״̬���� */
    mschar**        sync_arch_sta   /* OUT: ��ͬ������Ĺ鵵״̬���� */
);

/*********************************************************************
Purpose :
    ��ʵ������������������־�ļ�
*********************************************************************/
DllExport
DWMON_RETURN
dwmon_create_mlog(
    mhandle         mhdle,      /* IN: ��������� */
    mschar*         file_path,  /* IN: �ļ�·��   */
    muint8          file_size,  /* IN: �ļ���С   */
    mschar*         mon_name,   /* IN: ��������   */
    muint4          mon_magic,  /* IN: ������ħ�� */
    muint4          overwrite   /* IN: �������ļ� */
);

/*********************************************************************
Purpose :
    ��ȡЭͬ�˳����
*********************************************************************/
DllExport
DWMON_RETURN
dwmon_get_exit_all(
    mhandle         mhdle,    /* IN: ��������� */
    muint4*         exit_all    /* OUT: Эͬ�˳���� */
);

/*********************************************************************
Purpose :
    ��ȡ��ʵ�������������Ϣ
*********************************************************************/
DllExport
DWMON_RETURN
dwmon_get_mraft_info(
    mhandle         mhdle,    /* IN: ��������� */
    muint4*         n_dest,   /* OUT:��������Ŀ */
    mbyte*          vote_stat,/* OUT:ѡ�ٽ�ɫ   */
    muint4*         leader_id, /* OUT: leader_id */
    mbool*          hp_flag,  /* OUT:�ѻ����   */
    muint4*         l_term_id, /* OUT: ��ǰ���ں� */
    muint8*         c_seqno,  /* OUT:c_seqno    */
    muint8*         f_seq_arr, /* OUT: f_seqno_arr */
    muint4*         term_id_arr /* OUT: term_id_arr */
);

/*********************************************************************
Purpose :
    ���ݽ�ɫ����Эͬ�˳����
*********************************************************************/
DllExport
DWMON_RETURN
dwmon_set_exit_all();

/*********************************************************************
Purpose :
    ��ȡ�������ѻ����
*********************************************************************/
DllExport
DWMON_RETURN
dwmon_get_hp_flag(
    mhandle         mhdle,     /* IN:  ���������    */
    mbool*          hp_flag    /* OUT: ��������־�ѻ���� */
);

/*********************************************************************
Purpose:
    �����û�����������Ϳ�����������ʵ�������Ϳ���
*********************************************************************/
DllExport
DWMON_RETURN
dwmon_get_real_group_db_name(
    mhandle         mhdle,          /* IN����������� */
    mschar*         group_name,     /* IN���û����������������Ϊ�� */
    mschar*         db_name,        /* IN���û������ʵ����������Ϊ�� */
    mschar*         real_grpname,   /* OUT����ʵ���� */
    mschar*         real_dbname     /* OUT����ʵ���� */
);

/*********************************************************************
Purpose :
	KEY��֤��ʽ��¼������
*********************************************************************/
DllExport
DWMON_RETURN
dwmon_login_with_key(
    mhandle         mhdle,      /* ��������� */
    mschar*         login_str   /* ��¼��     */
);

/************************************************************************
purpose:
    ͨ�����������������ȡ������Ϣ������
************************************************************************/
DllExport
DWMON_RETURN
dwmon_init_by_gmon(
    mhandle             mhdle,          /* IN:��������� */
    msint2              gport,          /* IN:��������˿� */
    muint4              oguid           /* IN:������oguid */
);

#ifdef __cplusplus
}
#endif

#endif

