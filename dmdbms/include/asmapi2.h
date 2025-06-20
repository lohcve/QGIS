/******************************************************
file:
    asmapi.h
Notes:
    to define struct and interface for ASM DLL
history:
    Date        Who         RefDoc    Memo
    2015-07-20  ww/sn                      Created
*******************************************************/
#ifndef DMASM2_H
#define DMASM2_H

/* environment specific definitions */
#ifndef EXPORT
#define EXPORT   
#endif

#ifndef DllImport
#if defined (_WINDOWS) || defined (WIN32)
#define DllImport   __declspec( dllimport )
#define DllExport   __declspec( dllexport )
#else
#define DllImport 
#define DllExport 
#endif //DWINDOWS
#endif

#include "apitype.h"

#ifndef ASMAPI_PUB
#define ASMAPI_PUB

typedef udint4              asmbool;

/* function return type */
typedef sdint4              ASMRETURN;

#ifdef WIN32
typedef void*               asm_fhandle_t;
#else
typedef udint4              asm_fhandle_t;
#endif /* WIN32 */

typedef void*               asm_dhandle_t;

typedef void*               asmcon_handle;

#define INVALID_ASM_FILE_HANDLE 0xFFFFFFFFFFFFFFFF

/* define identifier */
#define ASM_NAMELEN             32
typedef sdbyte                  asm_name_t[ASM_NAMELEN + 1];

/* define file path */
#define ASM_MAX_PATH_LEN        256
typedef sdbyte                  asm_pathname_t[ASM_MAX_PATH_LEN + 1];

/* define time identifier */
#define ASM_TIMELEN             29
typedef sdbyte                  asm_time_t[ASM_TIMELEN + 1];

#define ASMAPI_ERR_MAX_LEN      512
typedef sdbyte                  asm_error_t[ASMAPI_ERR_MAX_LEN + 1];

#endif

/* dmasm_dir_get_firstʹ�ã�����ָ��Ŀ���ȡ�������� */
#define ASM_FILE_TYPE_UNDEFIND  0
#define ASM_FILE_TYPE_FILE      1
#define ASM_FILE_TYPE_DIR       2

typedef struct asm_file_attr_struct ASM_FILE_ATTR;
struct asm_file_attr_struct
{
    asm_fhandle_t   fil_id;
    sdbyte          type;       /* �ļ����ͣ�file/dir */
    asm_pathname_t  name;       /* �ļ����� */
    asm_pathname_t  full_path;  /* ����·�� */  
    udint8          size;       /* �ļ���С��byte��������Ŀ¼�����Դ��ֶ� */
    udint8          c_time;     /* ����ʱ�� */
    udint8          m_time;     /* �޸�ʱ�� */

    udint2          group_id;   /* ���ڴ������� */
    udint2          disk_id;    /* ���ڴ���ID */
    udint4          disk_auno;  /* ���ڴ���AU��� */
    udint4          offset;     /* AUƫ�� */
};


/*
���ܣ�ASM�ӿ�ģ���ʼ��
��������
���أ��ɹ�������0�����򣬴�����
*/
DllExport
ASMRETURN
dmasm_sys_init(
    sdbyte*         err_desc,
    udint4*         err_len,
    udint4          char_code,
    udint4          lang_id             /* ʹ��ָ����lang_id, == ULINT_UNDEFINED�Ŵ�ϵͳȥ�� */
);

/*
���ܣ�ASM�ӿ�ģ���ͷ�
��������
���أ���
*/
DllExport
void
dmasm_sys_deinit();

/*
���ܣ����벢��ʼ�����Ӷ���
������con �����������¼��������Ӷ���
���أ��ɹ�������0��ʧ�ܣ�������
*/
DllExport
ASMRETURN
dmasm_alloc_con(
    asmcon_handle*      con,
    sdbyte*             err_desc,
    udint4*             err_len
);

/*
���ܣ��ͷ����Ӷ���
������con ���룬���ͷ����Ӷ���
���أ���
*/
DllExport
void
dmasm_free_con(
    asmcon_handle  con
);

/*
���ܣ���������
������con ���������ʹ�ý������ӵĶ���
      username ���룬�û���
      password ���룬����
      hostname ���룬������
      portnum  ���룬�˿ں�
���أ��ɹ�������0��ʧ�ܣ�������
*/
DllExport
ASMRETURN
dmasm_connect(
    asmcon_handle   con,
    sdbyte*         username,
    sdbyte*         password,
    sdbyte*         hostname,
    udint2          portnum,
    asmbool*        con_is_local,
    sdbyte*         err_desc,
    udint4*         err_len
);

// bug665763������ԭ��dmasm_change_pwd��pwd�ؼ���Ӱ������飬�޸�����
DllExport
ASMRETURN
dmasm_change_passwd(
    asmcon_handle   con,
    sdbyte*         username,
    sdbyte*         password,
    sdbyte*         err_desc,
    udint4*         err_len
);

/*
���ܣ��ر�����
������con ������������رյ����Ӷ���
���أ���
*/
DllExport
void
dmasm_close_con(
    asmcon_handle  con
);

/*********************************************************************
Purpose:
    ��ȡasmmal_ini��������
Notes:
    ��ȡasmmal_ini��������
*********************************************************************/
DllExport
ASMRETURN
dmasm_get_asmmal_ini(
    asmcon_handle   con_in,         /*IN:Ŀ������*/
    void*           mal_cfg_arr,    /*OUT:������ID���飬��Чֵ����ȡnum�������id_arr�Ľ�С��*/
    udint2*         num,            /*OUT:ʵ��asmmal�����*/
    sdbyte*         err_desc,       /*OUT:����������Ϣ*/
    udint4*         err_len         /*OUT:����������Ϣ����*/
);

/*********************************************************************
Purpose:
    ��ȡasmmal_sys��������
Notes:
    ��ȡasmmal_sys��������
*********************************************************************/
DllExport
ASMRETURN
dmasm_get_asmmal_sys(
    asmcon_handle   con_in,                      //IN:Ŀ������
    udint4*         check_interval,             //OUT:���MAL��·�����S��
    udint4*         conn_fail_interval,         //OUT:�϶����ӶϿ��ļ��
    udint4*         check_timeout,              //OUT: ping check_ip��ʱʱ�� 
    sdbyte*         check_ip,                   //OUT:mal_check_ip��������ip 
    udint4*         login_timeout,              //OUT:mpp��¼ʱ�ĳ�ʱ���ʱ��
    udint4*         mal_buf_size,               //OUT:����mal��buffer����
    udint4*         sys_buf_size,               //OUT:malϵͳbuffer���ƣ�Ĭ��0����ʾbuffer���ܵ�����
    udint4*         mal_vpool_size,             //OUT:MALϵͳʹ�õ��ڴ��ʼ����С
    udbyte*         message_check,              //OUT:�Ƿ����ϢУ����
    udbyte*         cpr_level,                  //OUT:ѹ���ȼ���ȡֵ0-10��0��ѹ����1��ʾѹ���ٶ���죬10ѹ������ߣ�
    udbyte*         user_rdma,                  //OUT:MAL�Ƿ�ʹ��RDMAͨѶ��ʽ
    sdbyte*         err_desc,                   /*OUT:����������Ϣ*/
    udint4*         err_len                     /*OUT:����������Ϣ����*/
);

/*
���ܣ���ȡ������ĸ���
������conn ���룬Ŀ������
      num ����������������δָ��(null)��ֱ�ӷ���      
���أ��ɹ�������0��ʧ�ܣ�������
*/
DllExport
ASMRETURN
dmasm_get_n_group(
    asmcon_handle   con,
    udint2*         num,
    sdbyte*         err_desc,
    udint4*         err_len
);

/*
���ܣ���ȡ������ID����
������conn ���룬Ŀ������
      num �����ʵ�ʴ��������
      id_arr �����������ID���飬��Чֵ����ȡnum�������id_arr�Ľ�С��      
      arr_size ���룬id_arr�Ĵ�С
���أ��ɹ�������0��ʧ�ܣ�������
*/
DllExport
ASMRETURN
dmasm_get_group_id_arr(
    asmcon_handle   con_in,    
    udint2*         id_arr,
    udint4*         au_size_arr,
    udint4*         ex_size_arr,
    udint2          arr_size,
    udint2*         num,
    sdbyte*         err_desc,
    udint4*         err_len
);

/*
���ܣ���ȡһ�����������Ϣ
������conn ���룬Ŀ������
      group_id ���룬Ŀ�������ID
      group_name ��������������ƣ����128�ֽڣ��������ַ�����β��
      status ����������������豸���״̬,��ASM_GROUP_STA_NORMAL      
      n_disk ������������а������̵ĸ���
      *����ĳ�����ΪNULL������Ӧ�ֶβ�ȡ
���أ��ɹ�������0��ʧ�ܣ�������
*/
DllExport
ASMRETURN
dmasm_get_group_info_by_id(
    asmcon_handle   con,
    udint2          group_id,
    sdbyte*         group_name,
    udint2          name_buflen,
    udint2*         status,
    udint2*         n_disk,
    udint4*         total_size,
    udint4*         free_size,
    udint4*         au_size,
    sdbyte*         n_copy,
    udint4*         redo_size,
    udint2*         rbl_stat,
    udint2*         rbl_pwr,
    sdbyte*         err_desc,
    udint4*         err_len
);

/*
���ܣ���ȡһ�����������Ϣ
������conn ���룬Ŀ������
      group_id �����Ŀ�������ID
      group_name ���룬���������ƣ����128�ֽڣ��������ַ�����β��
      status ����������������豸���״̬,��ASM_GROUP_STA_NORMAL      
      n_disk ������������а������̵ĸ���
      *����ĳ�����ΪNULL������Ӧ�ֶβ�ȡ
���أ��ɹ�������0��ʧ�ܣ�������
*/
DllExport
ASMRETURN
dmasm_get_group_info_by_name(
    asmcon_handle   con_in,
    sdbyte*         group_name,
    udint2*         group_id,
    udint2*         status,    
    udint2*         n_disk,
    udint4*         total_size,
    udint4*         free_size,
    sdbyte*         err_desc,
    udint4*         err_len        
);

/*
���ܣ���ȡһ���������д���ID����
������conn ���룬Ŀ������
      group_id ���룬ָ���������ID
      n_disk �����ʵ�ʴ��ڵĴ��̵ĸ���
      id_arr ������������ID�����飬��Чֵ����ȡn_disk���ֵ��arr_size�н�С��
      arr_size ���룬id_arr�Ĵ�С
���أ��ɹ�������0��ʧ�ܣ�������
*/
DllExport
ASMRETURN
dmasm_get_disk_id_arr_by_group(
    asmcon_handle   con_in,
    udint2          group_id,    
    udint2*         id_arr,
    udint2          arr_size,
    udint2*         n_disk,
    sdbyte*         err_desc,
    udint4*         err_len
);

/***********************************************************************************
purpose:
    ����low�ӿڻ�ȡһ�����̵���Ϣ
NOTES:
    v$asmdisk��ȡ������Ϣʹ�øýӿڣ���ֹ�ⲿֱ�ӵ���dmasm_get_disk_info��ɴ���
***********************************************************************************/
DllExport
ASMRETURN
dmasm_get_disk_info_low(
    asmcon_handle       conn_in,
    udint2              group_id,
    udint4              disk_id,
    sdbyte*             path,
    udint2              path_buflen,
    sdbyte*             name,
    udint2              name_buflen,
    sdbyte*             frp_name,       /*OUT:�����������������������°��ã�*/
    udint2              frp_buflen,     /*IN:��Ŵ���������������buf���ȣ������°��ã�*/
    sdbyte*             status_name,    /*OUT:����״̬�������°��ã�*/
    udint2              status_buflen,  /*IN:��Ŵ���״̬buf���ȣ������°��ã�*/
    udint4*             size,
    udint4*             free_auno,
    sdbyte*             create_time,
    sdbyte*             modify_time,
    udint4*             version,            /* OUT: ���̰汾�� */
    asmbool*            destroyed,          /* OUT: ��������Ƿ��� */
    udint4*             asm_trim,       /*OUT:����dmdcr_asm_trim�����Ƿ���Ч*/
    sdbyte*             err_desc,
    udint4*             err_len
);

/*
���ܣ���ȡһ�����̵���Ϣ
������conn ���룬Ŀ������
      group_id ���룬ָ���������ID
      disk_id ���룬ָ�����̵�ID
      path ���������·�����256���ֽڣ��������ַ�����β��
      name ������������֣��128���ֽڣ��������ַ�����β��
      size ��������̴�С����MΪ��λ
      free_auno ��������̿���AU��ƫ��
      create_time ��������̴���ʱ��
      modity_time ����������޸�ʱ��
���أ��ɹ�������0��ʧ�ܣ�������
*/
DllExport
ASMRETURN
dmasm_get_disk_info(
    asmcon_handle   con,
    udint2          group_id,
    udint4          disk_id,
    sdbyte*         path,
    udint2          path_buflen,
    sdbyte*         name,
    udint2          name_buflen,
    sdbyte*         frp_name,       /*OUT:�����������������������°��ã�*/
    udint2          frp_buflen,     /*IN:��Ŵ���������������buf���ȣ������°��ã�*/
    sdbyte*         status_name,    /*OUT:����״̬�������°��ã�*/
    udint2          status_buflen,  /*IN:��Ŵ���״̬buf���ȣ������°��ã�*/
    udint4*         size,
    udint4*         free_auno,
    sdbyte*         create_time,
    sdbyte*         modify_time,
    sdbyte*         err_desc,
    udint4*         err_len
);

/***********************************************************************************
purpose:
    ����low�ӿڻ�ȡһ�����̵���Ϣ
NOTES:
    v$asmdisk��ȡ������Ϣʹ�øýӿڣ���ֹ�ⲿֱ�ӵ���dmasm_get_disk_info��ɴ���
***********************************************************************************/
DllExport
ASMRETURN
dmasm_get_disk_info_low(
    asmcon_handle   conn_in,        //IN: Ŀ������
    udint2          group_id,       //IN: ָ���������ID
    udint4          disk_id,        //IN: ָ�����̵�ID
    sdbyte*         path,           //OUT: ����·�����256���ֽڣ��������ַ�����β��
    udint2          path_buflen,    //IN: ����·��
    sdbyte*         name,           //OUT: �������֣��128���ֽڣ��������ַ�����β��
    udint2          name_buflen,    //IN: ��������
    sdbyte*         frp_name,       /*OUT: �����������������������°��ã�*/
    udint2          frp_buflen,     /*IN: ��Ŵ���������������buf���ȣ������°��ã�*/
    sdbyte*         status_name,    /*OUT: ����״̬�������°��ã�*/
    udint2          status_buflen,  /*IN: ��Ŵ���״̬buf���ȣ������°��ã�*/
    udint4*         size,           //OUT: ���̴�С����MΪ��λ
    udint4*         free_auno,      //OUT: ���̿���AU��ƫ��
    sdbyte*         create_time,    //OUT: ���̴���ʱ��
    sdbyte*         modify_time,    //OUT: �����޸�ʱ��
    udint4*         version,        /*OUT:���̰汾��*/
    asmbool*        is_ok,          /*OUT:��������Ƿ���*/
    udint4*         asm_trim,       /*OUT:����dmdcr_asm_trim�����Ƿ���Ч*/
    sdbyte*         err_desc,       //OUT: ��������
    udint4*         err_len         //OUT: ������������
);

/*
���ܣ���ȡ���������ļ�����
������conn ���룬Ŀ������
      group_id ���룬ָ��������ID
      num ��������������ļ�����      
���أ��ɹ�������0��ʧ�ܣ�������
*/
DllExport
ASMRETURN
dmasm_get_file_num_by_group(
    asmcon_handle   con,
    udint2          group_id,
    udint4*         num,
    sdbyte*         err_desc,
    udint4*         err_len
);

/*
���ܣ���ȡ���������ļ�ID����
������conn ���룬Ŀ������
      group_id ���룬ָ��������ID
      real_num �����ʵ�ʴ��ڵĴ�����ID����
      id_arr ������ļ�ID���飬��Чֵ���������arr_sizeһ�£���real_numС��arr_size����Ϊreal_num
      arr_size ���룬ָ��id_arr�Ĵ�С
���أ��ɹ�������0��ʧ�ܣ�������
*/
DllExport
ASMRETURN
dmasm_get_file_id_arr_by_group(
    asmcon_handle       conn_in,
    udint2              group_id,    
    asm_fhandle_t*      id_arr,
    udint4              arr_size,
    udint4*             real_num,
    sdbyte*             err_desc,
    udint4*             err_len
);

/*
���ܣ���ȡһ���ļ���Ϣ
������conn ���룬Ŀ������
      file_id ���룬Ŀ���ļ�ID
      filepath �����Ŀ�����ļ������256���ֽڣ��������ַ�����β��
      filesize �����Ŀ���ļ���С����λBYTE��ʵ�ʴ�С
      createtime �����Ŀ���ļ�����ʱ��
      modifytime �����Ŀ���ļ�����޸�ʱ��
���أ��ɹ�������0��ʧ�ܣ�������
*/
DllExport
ASMRETURN
dmasm_file_attributes_get_by_handle(
    asmcon_handle   conn,
    asm_fhandle_t   file_id,
    void*           fattr_out,
    sdbyte*         err_desc,
    udint4*         err_len
);

/*
���ܣ��������Ƿ����
������conn ���룬Ŀ������
      filepath ���룬Ŀ�����ļ������256���ֽڣ��������ַ�����β��
      filesize ���룬Ŀ�����С����λBYTE��ʵ�ʴ�С
���أ��ɹ�������0��ʧ�ܣ�������
*/
DllExport
ASMRETURN
dmasm_check_disk_space(
    asmcon_handle   conn,
    sdbyte*         filepath,
    udbyte          n_copy,
    udint8          filesize,
    asmbool*        overflow,
    sdbyte*         err_desc,
    udint4*         err_len
);

/*
���ܣ�����asm�ļ�
������conn ���룬Ŀ������
      filepath ���룬Ŀ�����ļ������256���ֽڣ��������ַ�����β��      
      filesize ���룬�����ļ���С��ʵ�ʴ�С����λBYTE     
      fhandle �ļ������ɹ���������
���أ��ɹ�������0��ʧ�ܣ�������
*/
DllExport
ASMRETURN
dmasm_file_create(
    asmcon_handle   conn,    
    asmbool         p_flag,
    sdbyte*         filepath,    
    udint8          filesize,
    asm_fhandle_t*  fil_handle,
    asmbool         init_flag,
    udint2          striping_size,      /* IN�����������ͣ��´�����ݲ��� */
    udbyte          redundancy_type,    /* IN���������ͣ��´�����ݲ��� */
    sdbyte*         err_desc,
    udint4*         err_len
);

/*
���ܣ�����·����ɾ��asm�ļ�
������conn ���룬Ŀ������
      filepath ���룬Ŀ�����ļ������256���ֽڣ��������ַ�����β��
���أ��ɹ�������0��ʧ�ܣ�������
*/
DllExport
ASMRETURN
dmasm_file_delete(
    asmcon_handle   conn,    
    sdbyte*         filepath,    
    sdbyte*         err_desc,
    udint4*         err_len
);

/*
���ܣ���asm�ļ�
������conn ���룬Ŀ������
      filepath ���룬Ŀ�����ļ������256���ֽڣ��������ַ�����β�� 
      fhandle ������򿪵��ļ����
���أ��ɹ�������0��ʧ�ܣ�������
*/
DllExport
ASMRETURN
dmasm_file_open(
    asmcon_handle   conn,    
    sdbyte*         filepath,
    asm_fhandle_t*  fhandle,
    sdbyte*         err_desc,
    udint4*         err_len
);

/*
���ܣ��ر�asm�ļ�
������conn ���룬Ŀ������      
      fhandle ���룬���رյ��ļ����
���أ��ɹ�������0��ʧ�ܣ�������
*/
DllExport
ASMRETURN
dmasm_file_close(
    asmcon_handle   conn,        
    asm_fhandle_t   fhandle
);


/*
���ܣ���չasm�ļ�
������conn ���룬Ŀ������      
      fhandle ���룬����չ���ļ����
      offset ���룬�ļ�ƫ��
      extend_size ���룬ƫ��֮������չ�Ĵ�С����λB��ʵ�ʴ�С
���أ�true �ɹ���false ʧ��
*/
DllExport
ASMRETURN
dmasm_file_extend(
    asmcon_handle   conn,        
    asm_fhandle_t   fhandle,
    udint8          offset,
    udint8          extend_size,
    udint4          need_init,
    sdbyte*         err_desc,
    udint4*         err_len
);

/*
���ܣ��ض�asm�ļ�
������conn ���룬Ŀ������      
      fhandle ���룬���ضϵ��ļ����      
      truncate_size ���룬�ضϺ�ĳ��ȣ���λBYTE
      real_size ������ضϺ��ʵ�ʳ��ȣ���truncate_size����ʵ�ʳ��ȣ��򲻽ضϣ����ʵ�ʳ��ȣ�������truncate_size���
���أ��ɹ�������0��ʧ�ܣ�������
*/
DllExport
ASMRETURN
dmasm_file_trunc(
    asmcon_handle   conn,        
    asm_fhandle_t   fhandle,    
    udint8          truncate_size,
    udint8*         real_size,
    sdbyte*         err_desc,
    udint4*         err_len
);

/*
���ܣ���asm�ļ�
������conn ���룬Ŀ������      
      fhandle ���룬�����ļ����
      offset ���룬���ļ�����ʼƫ��
      buffer �����������ȡ�ļ����ݵĴ�Ż���
      bytes_to_read ���룬Ҫ���ȡ�ֽڸ���      
���أ��ɹ�������0��ʧ�ܣ�������
*/
DllExport
ASMRETURN
dmasm_file_read_by_offset(
    asmcon_handle       conn,
    asm_fhandle_t       fhandle,
    udint8              offset,
    sdbyte*             buffer,
    udint4              bytes_to_read,
    sdbyte*             err_desc,
    udint4*             err_len
);

/*
���ܣ���asm�ļ�
������conn ���룬Ŀ������      
      fhandle ���룬�����ļ����
      offset ���룬���ļ�����ʼƫ��
      buffer �����������ȡ�ļ����ݵĴ�Ż���
      bytes_to_read ���룬Ҫ���ȡ�ֽڸ���      
���أ��ɹ�������0��ʧ�ܣ�������
*/
DllExport
ASMRETURN
dmasm_file_read_by_offset_inner(
    void*               env,
    asmcon_handle       conn,
    asm_fhandle_t       fhandle,
    udint8              offset,
    sdbyte*             buffer,
    udint4              bytes_to_read,
    sdbyte*             err_desc,
    udint4*             err_len
);

/*
���ܣ���asm�ļ�
������conn ���룬Ŀ������      
      fhandle ���룬�����ļ����
      offset ���룬���ļ�����ʼƫ��
      buffer �����������ȡ�ļ����ݵĴ�Ż���
      bytes_to_read ���룬Ҫ���ȡ�ֽڸ���      
���أ��ɹ�������0��ʧ�ܣ�������
*/
DllExport
ASMRETURN
dmasm_file_read_by_offset_normal(
    asmcon_handle   conn,     
    asm_fhandle_t   fhandle,
    udint8          offset,
    sdbyte*         buffer,
    udint4          bytes_to_read,
    sdbyte*         err_desc,
    udint4*         err_len
);

/*
���ܣ��첽��asm�ļ����ڲ���ѭ�����������ز��������ô�ȷ��һ�ε��õĶ�ȡ�ĳ��ȣ����������򱨴������������bytes_read�����ܹ���ȡ�ĳ���
������conn ���룬Ŀ������      
      fhandle ���룬�����ļ����
      asmdisk ������ļ���������asmdisk���
      offset ���룬���ļ�����ʼƫ��
      buffer �����������ȡ�ļ����ݵĴ�Ż���
      bytes_to_read ���룬Ҫ���ȡ�ֽڸ���
      bytes_read �����ʵ�ʶ���������
      ctl�����룬windowsƽ̨����overlapped����winsƽ̨��ֱ�Ӵ���NULL
      os_err�������os��������ֵĴ�����
���أ��ɹ�������0��ʧ�ܣ�������
*/
DllExport
ASMRETURN
dmasm_file_async_read_by_offset(
    void*                   env,
    asmcon_handle           conn_in,
    asm_fhandle_t           fhandle,
    asm_fhandle_t*          asmdisk,
    udint8                  offset,
    sdbyte*                 buffer,
    udint4                  bytes_to_read,
    udint4*                 bytes_read,
    void*                   ctl,
    udint4                  flag,               /*IN:ASM�������� */
    ASMRETURN*              os_err,
    sdbyte*                 err_desc,
    udint4*                 err_len
);

/*
���ܣ�дasm�ļ�
������conn ���룬Ŀ������      
      fhandle ���룬��д�ļ����
      offset ���룬д�ļ�����ʼƫ��
      buffer ���룬д���ļ����ݵĴ�Ż���
      bytes_to_write ���룬��д���ֽڸ���      
���أ��ɹ�������0��ʧ�ܣ�������
*/
DllExport
ASMRETURN
dmasm_file_write_by_offset(
    asmcon_handle   conn,
    asm_fhandle_t   fhandle,
    udint8          offset,
    sdbyte*         buffer,
    udint4          bytes_to_write,
    sdbyte*         err_desc,
    udint4*         err_len
);

/*
���ܣ�дasm�ļ�
������conn ���룬Ŀ������      
      fhandle ���룬��д�ļ����
      offset ���룬д�ļ�����ʼƫ��
      buffer ���룬д���ļ����ݵĴ�Ż���
      bytes_to_write ���룬��д���ֽڸ���      
���أ��ɹ�������0��ʧ�ܣ�������
*/
DllExport
ASMRETURN
dmasm_file_write_by_offset_inner(
    void*           env,
    asmcon_handle   conn,
    asm_fhandle_t   fhandle,
    udint8          offset,
    sdbyte*         buffer,
    udint4          bytes_to_write,
    sdbyte*         err_desc,
    udint4*         err_len
);

/*
���ܣ�дasm�ļ�
������conn ���룬Ŀ������      
      fhandle ���룬��д�ļ����
      offset ���룬д�ļ�����ʼƫ��
      buffer ���룬д���ļ����ݵĴ�Ż���
      bytes_to_write ���룬��д���ֽڸ���      
���أ��ɹ�������0��ʧ�ܣ�������
*/
DllExport
ASMRETURN
dmasm_file_write_by_offset_normal(
    asmcon_handle   conn,        
    asm_fhandle_t   fhandle,    
    udint8          offset,
    sdbyte*         buffer,
    udint4          bytes_to_write,
    sdbyte*         err_desc,
    udint4*         err_len
);

/*
���ܣ��첽дasm�ļ����ڲ���ѭ�����������ز��������ô�ȷ��һ�ε��õ�д��ĳ��ȣ����������򱨴������������bytes_written�����ܹ�д��ĳ���
������conn ���룬Ŀ������      
      fhandle ���룬��д�ļ����
      asmdisk �����fhandle��д������asmdisk���
      offset ���룬д�ļ�����ʼƫ��
      buffer ���룬д���ļ����ݵĴ�Ż���
      bytes_to_write ���룬��д���ֽڸ���
      bytes_written�����ʵ��д��ĸ���
      ctl    ���룬windowsƽ̨overlapped��������winsֱ�Ӵ���NULL
      os_err�������os��������ֵĴ�����
���أ��ɹ�������0��ʧ�ܣ�������
*/
DllExport
ASMRETURN
dmasm_file_async_write_by_offset(
    void*                   env,
    asmcon_handle           conn_in,
    asm_fhandle_t           fhandle,
    asm_fhandle_t*          asmdisk,
    udint8                  offset,
    sdbyte*                 buffer,
    udint4                  bytes_to_write,
    udint4*                 bytes_written,
    void*                   ctl,
    ASMRETURN*              os_err,
    sdbyte*                 err_desc,
    udint4*                 err_len
);

/*
���ܣ�����ASM�ļ�Ŀ¼
������conn ���룬Ŀ������      
      source ���룬Դ�ļ�����֧�ֱ����ļ�����ASM�ļ�
      dest ���룬Ŀ���ļ�����֧�ֱ����ļ�����ASM�ļ�
      bFailIfExists ���룬������ڣ��Ƿ񸲸�
���أ��ɹ�������0��ʧ�ܣ�������
*/
DllExport
ASMRETURN
dmasm_file_copy(
    asmcon_handle   conn,
    sdbyte*         source,
    sdbyte*         dest,
    asmbool         bOverwriteIfExists,
    sdbyte*         err_desc,
    udint4*         err_len
);

DllExport
ASMRETURN
dmasm_file_copy_low(
    asmcon_handle   conn,
    sdbyte*         source,
    sdbyte*         dest,
    asmbool         bOverwriteIfExists,             //�ļ����ڣ��Ƿ񸲸�
    asmbool         recursion_flag,                 //Ŀ¼���Ƿ�ݹ鿽��
    asmbool         fast_flag,                      //�Ƿ��Ż�
    sdbyte*         err_desc,
    udint4*         err_len
);

/*
���ܣ�������ASM�ļ�����Ŀ¼
������conn ���룬Ŀ������
      source ���룬Դ�ļ�����֧��ASM�ļ�
      dest ���룬Ŀ���ļ�����֧��ASM�ļ�
���أ��ɹ�������0��ʧ�ܣ�������
*/
DllExport
ASMRETURN
dmasm_file_rename(
    asmcon_handle   conn_in,
    sdbyte*         source,
    sdbyte*         dest,
    sdbyte*         err_desc,
    udint4*         err_len
);

DllExport
ASMRETURN
dmasm_file_compare(
    asmcon_handle   conn,
    sdbyte*         source,
    sdbyte*         dest,
    sdbyte*         err_desc,
    udint4*         err_len
);

/*
���ܣ�����ASM�ļ�Ŀ¼
������conn ���룬Ŀ������      
      fdir ���룬���������ļ�Ŀ¼·��
���أ��ɹ�������0��ʧ�ܣ�������
*/
DllExport
ASMRETURN
dmasm_dir_create(
    asmcon_handle   conn,        
    asmbool         p_flag,
    sdbyte*         fdirectory,
    sdbyte*         err_desc,
    udint4*         err_len
);

/*
���ܣ�ɾ��ASM�ļ�Ŀ¼
������conn ���룬Ŀ������      
      fdir ���룬��ɾ�����ļ�Ŀ¼·��
���أ��ɹ�������0��ʧ�ܣ�������
*/
DllExport
ASMRETURN
dmasm_dir_delete(
    asmcon_handle   conn,        
    sdbyte*         fdirectory,
    sdbyte*         err_desc,
    udint4*         err_len
);

/*
���ܣ�����������
������conn ���룬Ŀ������      
      group_name ���룬���������֣����128�ֽڣ��������ַ�����β��
      disk_path ���룬���������ڳ�ʼ���̵�·��
���أ��ɹ� 0��ʧ�ܣ�������
*/
DllExport 
ASMRETURN
dmasm_create_diskgroup(
    asmcon_handle   conn,        
    sdbyte*         group_name,
    sdbyte*         disk_path,
    sdbyte*         err_desc,
    udint4*         err_len
);

/*
���ܣ��������ƣ�ɾ��������
������conn ���룬Ŀ������      
      group_name ���룬����������      
���أ��ɹ� 0��ʧ�ܣ�������
*/
DllExport 
ASMRETURN
dmasm_drop_diskgroup_by_name(
    asmcon_handle   conn,        
    sdbyte*         group_name,
    sdbyte*         err_desc,
    udint4*         err_len
);

/*
���ܣ�����������Ӵ���
������conn ���룬Ŀ������      
      group_name ���룬����������
      disk_path ���룬��Ӵ��̵�·��
���أ��ɹ�������0��ʧ�ܣ�������
*/
DllExport 
ASMRETURN
dmasm_add_disk_to_diskgroup(
    asmcon_handle   conn,        
    sdbyte*         group_name,
    sdbyte*         disk_path,
    sdbyte*         err_desc,
    udint4*         err_len
);

DllExport
ASMRETURN
dmasm_get_asmapi_sys_info(
    asmcon_handle       conn_in,        /*IN:Ŀ������*/
    udint4*             au_size,
    udint4*             extent_size,
    udint4*             extent_arr_size,
    sdint4*             local_coding,
    sdint4*             local_langid,
    asmbool*            shm_inited,
    udint4*             free_extents,   /*OUT:���дظ���*/
    udint4*             lru_extents,    /*OUT:LRU�ظ���*/
    sdbyte*             err_desc,
    udint4*             err_len
);

/***********************************************************************************
purpose:
    ����low�ӿڻ�ȡһ��δʹ�ô��̵���Ϣ
NOTES:
    v$asmdisk��ȡ������Ϣʹ�øýӿڣ���ֹ�ⲿֱ�ӵ���dmasm_get_unused_disk_info��ɴ���
***********************************************************************************/
DllExport
ASMRETURN
dmasm_get_unused_disk_info_low(
    asmcon_handle       conn_in,
    asm_pathname_t*     disk_path,      /* ����·�� */
    asm_name_t*         disk_name,      /* �������� */
    udint4*             disk_size,      /* ���̴�С */
    udint2*             disk_au_size,   /* ����au��С */
    udint4              max_n_disk,     /* �ռ����̵ĸ������� */
    udint4*             real_n_disk,    /* ʵ���ռ��Ĵ��̸���  */
    udint4*             version,        /*OUT:���̰汾  */
    asmbool*            is_ok,          /*OUT:��������Ƿ���*/
    sdbyte*             err_desc,
    udint4*             err_len
);

DllExport
ASMRETURN
dmasm_get_unused_disk_info(
    asmcon_handle       conn_in, 
    asm_pathname_t*     disk_path,      /* ����·�� */
    asm_name_t*         disk_name,      /* �������� */
    udint4*             disk_size,      /* ���̴�С */
    udint2*             disk_au_size,   /* ����au��С */
    udint4              max_n_disk,     /* �ռ����̵ĸ������� */
    udint4*             real_n_disk,    /* ʵ���ռ��Ĵ��̸���  */
    sdbyte*             err_desc, 
    udint4*             err_len    
);

DllExport
ASMRETURN
dmasm_get_unused_disk_cnt(
    asmcon_handle       conn_in,     
    udint4*             cnt,    /* ���̸��� */
    sdbyte*             err_desc, 
    udint4*             err_len    
);

DllExport
ASMRETURN
dmasm_dir_get_first(
    asmcon_handle       conn_in,
    sdbyte*             path,           /* dir name */
    sdbyte*             suffix,         /* file suffix used as the filter, such as ".log" */    
    asm_dhandle_t*      dir_handle_out,
    ASM_FILE_ATTR*      fattr_out,
    asmbool*            exist_flag,
    sdbyte*             err_desc, 
    udint4*             err_len 
);

DllExport
ASMRETURN
dmasm_dir_get_next(
    asmcon_handle       conn_in,
    asm_dhandle_t       dir_handle,
    sdbyte*             path,           /* dir name */
    sdbyte*             suffix,         /* file suffix used as the filter, such as ".log" */    
    ASM_FILE_ATTR*      fattr_out,
    asmbool*            exist_flag,
    sdbyte*             err_desc, 
    udint4*             err_len 
);

DllExport
ASMRETURN
dmasm_dir_close(
    asmcon_handle       conn_in,
    asm_dhandle_t       dir_handle,
    sdbyte*             err_desc, 
    udint4*             err_len 
);

// bug665763������ԭ��dmasm_pwd��pwd�ؼ���Ӱ������飬�޸�����
DllExport
ASMRETURN
dmasm_get_cur_path(
    asmcon_handle       conn_in,
    sdbyte*             cur_path,
    sdbyte*             err_desc, 
    udint4*             err_len 
);

DllExport
asmbool
dmasm_dhandle_check(
    asm_dhandle_t       dhandle
);

DllExport
ASMRETURN
dmasm_file_attributes_get(
    asmcon_handle       conn_in,
    sdbyte*             path,
    ASM_FILE_ATTR*      fattr_out,
    sdbyte*             err_desc, 
    udint4*             err_len 
);

DllExport
ASMRETURN
dmasm_get_file_info(
    asmcon_handle   conn,
    asm_fhandle_t   file_id,
    ASM_FILE_ATTR*  fattr_out,
    sdbyte*         err_desc,
    udint4*         err_len
);

DllExport
asmbool
dmasm_path_is_asmdisk(
    asmcon_handle   conn,
    sdbyte*         path,
    sdbyte*         err_desc,
    udint4*         err_len
);

DllExport
asmbool
dmasm_file_is_exist(
    asmcon_handle   conn_in,
    sdbyte*         path,
    sdbyte*         err_desc,
    udint4*         err_len
);

DllExport
asmbool
dmasm_file_flush(
    asmcon_handle   conn_in,
    asm_fhandle_t   fhandle,
    sdbyte*         err_desc,
    udint4*         err_len
);

DllExport
ASMRETURN
dmasm_conn_check(
    asmcon_handle   conn_in,
    sdbyte*         err_desc,
    udint4*         err_len
);

DllExport
asmbool
dmasm_path_is_valid(
    sdbyte*         path
);

DllExport
asmbool
dmasm_disk_info(
    asmcon_handle*  con,
    sdbyte*         path,
    udint8*         totalsize,
    udint8*         freesize
);

#endif
