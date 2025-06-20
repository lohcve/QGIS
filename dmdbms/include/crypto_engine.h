/********************************************************************
file:
	crypto_engine.h
purpose:
    provide all the function entries that a crypto engine should provide

interface:

History
    Date        Who         RefDoc     Memo
	2007-12-27  NL                     CREATE
*******************************************************/

#ifndef CRYPTO_ENGINE_H
#define CRYPTO_ENGINE_H

#ifndef dm_h

typedef int   lint;

typedef short sint;

typedef signed char tint;

typedef unsigned int ulint;   

typedef unsigned short usint;

typedef unsigned char byte;

#ifdef _WIN64
#define dm_int3264 __int64
#define dm_uint3264 unsigned __int64
#else
#define dm_int3264 long
#define dm_uint3264 unsigned long
#endif

#endif //#ifndef dm_h

#ifdef WIN32
#define DllImport __declspec( dllimport )
#define DllExport __declspec( dllexport )
#else
#define DllImport 
#define DllExport 
#endif

#define  MIN_EXTERNAL_CIPHER_ID         5000
#define  CYT_TYPE_UNKNOWN               0           //����, δ֪�㷨
#define	 CYT_TYPE_SYM_BLOCK_ENCRYPT     1           //����, ����ԳƼ����㷨
#define  CYT_TYPE_SYM_STREAM_ENCRYPT    2           //����, ��ʽ�ԳƼ����㷨
#define  CYT_TYPE_ASYM_ENCRYPT          3           //����, �ǶԳƼ����㷨, ����
#define  CYT_TYPE_HASH                  4           //����, ɢ���㷨
#define  CYT_TYPE_HASH_MAC              5           //����, hmac�㷨

#define DM_UKEY_FLAG_NONE                 0      // ��ʹ��UKEY��֤
#define DM_UKEY_FLAG_CERT                 1      // UKEY֤����֤
#define DM_UKEY_FLAG_ZB                   2      // UKEY������֤

// �����������������͡�0������������ܣ�1��������Ӳ�����ܣ�2��ukey��
#define CRYPTO_TYPE_SOFT    0
#define CRYPTO_TYPE_HARD    1
#define CRYPTO_TYPE_UKEY    2

#ifdef __cplusplus
extern "C" {
#endif

#ifdef WIN32
#define dm_bool long
#else
#define dm_bool unsigned int
#endif

#define DM_FALSE    0
#define DM_TRUE     1

#define CYT_PARA_WORKMODE    0
#define CYT_PARA_EXTENDSIZE  1

#define WORK_MODE_ECB           (ulint)0x1
#define WORK_MODE_CBC           (ulint)0x2
#define WORK_MODE_CFB           (ulint)0x4
#define WORK_MODE_OFB           (ulint)0x8
#define WORK_MODE_CBC_NOPAD     (ulint)0x10
#define WORK_MODE_ECB_NOPAD     (ulint)0x20
#define WORK_MODE_EXTKEY        (ulint)0x40
#define WORK_MODE_STORE         (ulint)0x41     //zb����洢����ģʽ, ��ԭ�ĳ���������
#define WORK_MODE_TRANS         (ulint)0x42     //zb���䴫�����ģʽ
#define WORK_MODE_KID           (ulint)0x43
#define WORK_MODE_AUTH          (ulint)0x44
#define WORK_MODE_LOG           (ulint)0x45     //zb������־����ģʽ, ��ԭ�ĳ���û������

DllExport	
ulint
cipher_get_count(
);

DllExport
dm_bool
cipher_get_info(
    ulint       seqno,
    ulint*      cipher_id,
    byte**      cipher_name,
    byte*       type,
    ulint*      blk_size,
    ulint*      kh_size 
);

DllExport
dm_bool
cipher_get_info_ex(
    ulint       seqno,
    ulint*      cipher_id,
    byte**      cipher_name,
    byte*       type,
    ulint*      blk_size,
    ulint*      kh_size,
    byte*       work_mode 
);

DllExport
dm_bool
cipher_get_para(
    ulint       cipher_id,
    ulint       para_id,
    void*       value
);

DllExport
dm_bool
cipher_get_key_id(
    ulint   cipher_id,
    byte*   key_id,
    ulint   key_id_size,
    ulint*  key_size
);

DllExport
dm_bool
cipher_free_key_id(
    ulint   cipher_id,
    byte*   key_id,
    ulint   key_id_size
);

DllExport
dm_bool
cipher_encrypt_init(
    ulint       inner_id,
    byte*       key,
    ulint       key_size,
    void**      encrypt_para
);

DllExport
lint
cipher_get_cipher_text_size(
    ulint       inner_id,
    void*       cipher_para,
    lint        plain_text_size
);

DllExport
lint
cipher_encrypt(
    ulint       inner_id,
    void*       encrypt_para,
    byte*       plain_text,
    ulint       plain_text_size,
    byte*       cipher_text,
    ulint       cipher_text_buf_size
);

DllExport
dm_bool
cipher_decrypt_init(
    ulint       inner_id,
    byte*       key,
    ulint       key_size,
    void**      decrypt_para
);

DllExport
lint
cipher_decrypt(
   ulint        inner_id,
   void*        decrypt_para,
   byte*        cipher_text,
   ulint        cipher_text_size,
   byte*        plain_text,
   ulint        plain_text_buf_size
);

DllExport
dm_bool
cipher_hash_init(
    ulint       inner_id,
    void**      hash_para
);

DllExport
dm_bool
cipher_hash_mac_init(
	ulint 		inner_id,
	byte* 		key,
	ulint 		key_len,
	void**      cipher_para
);

DllExport
void
cipher_hash_update(
    ulint       inner_id,
    void*       hash_para,
    byte*       msg,
    ulint       msg_size
);

DllExport
dm_bool
cipher_hash_mac_update(
	ulint 		inner_id,
	byte* 		msg,
	ulint 		msg_len,
    void*       cipher_para
);

DllExport
lint
cipher_hash_final(
    ulint       inner_id,
    void*       hash_para,
    byte*       digest,
    ulint       digest_buf_size
);
DllExport
lint
cipher_hash_mac_final(
	ulint 		inner_id,
	void*       cipher_para,
	byte* 		mac,
	ulint  		mac_len
);

DllExport
void
cipher_cleanup(
    ulint       inner_id,
    void*       hash_para
);

DllExport
dm_bool
cipher_asym_sign(
    ulint       inner_id,
    byte*       prikey,     //˽Կǩ��
    ulint       prikey_size,
    byte*       data,
    ulint       data_size,
    byte*       signdata,
    ulint*      signdata_buf_size
);

DllExport
dm_bool
cipher_asym_verify(
    ulint       inner_id,
    byte*       pubkey,     //��Կ��ǩ
    ulint       pubkey_size,
    byte*       data,
    ulint       data_size,
    byte*       signdata,
    ulint       signdata_size
);

DllExport
dm_bool
crypto_login(
    void**      cipher_para,
    byte*       pin,
    ulint       pin_len
);

DllExport
dm_bool
crypto_logout(
    void*       cipher_para
);

DllExport
dm_bool
crypto_read_cert(
    void*       cipher_para,
    byte*       cert,
    ulint *     cert_len
);

DllExport
dm_bool
cipher_gen_random(
    byte*       random,
    ulint       random_length
);

DllExport
dm_bool
crypto_get_name(
    byte**      crypto_name,
    ulint*      len
);

DllExport
dm_bool
crypto_get_type(
    ulint*      crypto_type
);

DllExport
lint
crypto_encrypt(
    byte*       plain_text,
    ulint       plain_text_size,
    byte*       cipher_text,
    ulint       cipher_text_buf_size
);

DllExport
lint
crypto_decrypt(
    byte*       cipher_text,
    ulint       cipher_text_size,
    byte*       plain_text,
    ulint       plain_text_buf_size
);

/************************************************************************
Purpose:
�������, ���ɹ�˽��Կ��
/************************************************************************/
DllExport
dm_bool
cipher_gen_respective_key(
    void**       pSession,      /* OUT: �Ự���� */
    byte*        pubkey,        /* OUT: ��Կ, �ϲ�Ԥ����ռ� */
    ulint*       pubkeyLen,     /* OUT: ��Կ���ֽڳ��ȣ����128�ֽ� */
    byte*        prikey,        /* OUT: ˽Կ, �ϲ�Ԥ����ռ� */
    ulint*       prikeyLen      /* OUT: ˽Կ���ֽڳ��ȣ����128�ֽ� */
);

/************************************************************************
Purpose:
�������, ���ɴ��������Կ
/************************************************************************/
DllExport
dm_bool
cipher_gen_common_key(
    void*        pSession,      /* IN: ���λỰ���� */
    byte*        pubkey,        /* IN: �Է���Կ */
    ulint        pubkeyLen,     /* IN: �Է���Կ���ֽڳ��ȣ����128�ֽ� */
    byte*        prikey,        /* IN: �Լ�˽Կ */
    ulint        prikeyLen,     /* IN: �Լ�˽Կ���ֽڳ��ȣ����128�ֽ� */
    byte*        commkey,       /* OUT: ������Կ, �ϲ�Ԥ����ռ� */
    ulint*       commkeyLen     /* OUT: ������Կ�ĳ��ȳ��ȣ����128�ֽ� */
);

/************************************************************************
Purpose:
�������, ����psess(zb����)
/************************************************************************/
DllExport
dm_bool
cipher_trans_destroy_key(
    void*        pSession   /* IN: ���λỰ���� */
);

/*******************************************
Purpose:
�������ݿ������Կ
Notes:
ZB����[ZB-des-8]-[ZB-des-12]
/*******************************************/
DllExport
lint
cipher_encrypt_update_init(
    ulint       inner_id,       /* IN: �㷨id */
    void**      encrypt_para,   /* OUT: para */
    byte*       key_old,        /* IN: ��key */
    ulint       key_old_size,   /* IN: ��key���� */
    byte*       key_new,        /* IN: ��key */
    ulint       key_new_size    /* IN: ��key���� */
);

/****************************************
Purpose:
�������ݿ������Կ
Notes:
ZB����[ZB-des-8]-[ZB-des-12]
/****************************************/
DllExport
lint
cipher_encrypt_update(
    ulint       inner_id,       /* IN: �㷨id */
    void*       encrypt_para,   /* IN: para */
    byte*       orl_data,       /* IN: ԭʼ���� */
    ulint       orl_data_len,   /* IN: ԭʼ���ݳ��� */
    byte*       updated_data    /* OUT: ���º�����(���Ȳ���) */
);

/*****************************************
Purpose:
����L1
Notes:
ZB����[ZB-des-4]��¼��֤
/*****************************************/
DllExport
dm_bool
cipher_user_auth_gen_key(
    ulint       inner_id,       /* IN: �㷨id */
    void**      pSession,       /* IN: ���λỰ���� */
    byte*       pUserL1,        /* OUT: L1, �ϲ�Ԥ����ռ� */
    ulint*      pUserL1Len      /* OUT: L1���ֽڳ��ȣ����128�ֽ� */
);

/*****************************************
Purpose:
����pSession
Notes:
ZB����[ZB-des-4]��¼��֤
/*****************************************/
DllExport
dm_bool
cipher_user_auth_destroy_key(
    ulint       inner_id,       /* IN: �㷨id */
    void*       pSession        /* IN: ���λỰ���� */
);

/*****************************************
Purpose:
����L3
Notes:
ZB����[ZB-des-4]��¼��֤
/*****************************************/
DllExport
dm_bool
cipher_user_auth_sign(
    ulint       inner_id,       /* IN: �㷨id */
    void*       pSession,       /* IN: ���λỰ���� */
    byte*       UserName,       /* IN: �û���, ���ݿ����� */
    ulint       UserNameLen,    /* IN: �û������ֽڳ��ȣ����128�ֽ� */
    byte*       pUserPwd,       /* IN: �û�����*/
    ulint       UserPwdLen,     /* IN: �û�������ֽڳ��ȣ����512�ֽ� */
    byte*       pUserL2,        /* IN: L2 */
    ulint       UserL2Len,      /* IN: L2���ֽڳ��ȣ����128�ֽ� */
    byte*       pUserL3,        /* OUT: L3, �ϲ�Ԥ����ռ� */
    ulint*      pUserL3Len      /* OUT: L3���ֽڳ��ȣ����4096�ֽ� */
);

/*****************************************
Purpose:
У��L3��U1�Ƿ�ƥ��
Notes:
ZB����[ZB-des-4]��¼��֤
/*****************************************/
DllExport
dm_bool
cipher_user_auth_verify(
    ulint       inner_id,       /* IN: �㷨id */
    void*       pSession,       /* IN: ���λỰ���� */
    byte*       UserName,       /* IN: �û���, ���ݿ�����*/
    ulint       UserNameLen,    /* IN: �û������ֽڳ��ȣ����128�ֽ� */
    byte*       pUserU1,        /* IN: �û����� */
    ulint       UserU1Len,      /* IN: �û�������ֽڳ��ȣ����512�ֽ� */
    byte*       pUserL1,        /* IN: L1 */
    ulint       UserL1Len,      /* IN: L1���ֽڳ��ȣ����128�ֽ� */
    byte*       pUserL3,        /* IN: L3 */
    ulint       UserL3Len       /* IN: L3���ֽڳ��ȣ����4096�ֽ� */
);

/*****************************************
Purpose:
����msg��У����ϢL4
Notes:
ZB����[ZB-des-4]��¼��֤
/*****************************************/
DllExport
dm_bool
cipher_user_auth_gen_digest(
    ulint       inner_id,       /* IN: �㷨id */
    void*       pSession,       /* IN: ���λỰ���� */
    byte*       msg,            /* IN: ��Ϣ */
    ulint       msgLen,         /* IN: ��Ϣ���ֽڳ���*/
    byte*       pUserL4,        /* OUT: L4, �ϲ�Ԥ����ռ�*/
    ulint*      pUserL4Len      /* OUT: L4���ֽڳ��ȣ����256�ֽ� */
);

/*****************************************
Purpose:
У��msg��L4�Ƿ�ƥ��
Notes:
ZB����[ZB-des-4]��¼��֤
/*****************************************/
DllExport
dm_bool
cipher_user_auth_check_digest(
    ulint       inner_id,       /* IN: �㷨id */
    void*       pSession,       /* IN: ���λỰ���� */
    byte*       pUserL4,        /* IN: L4 */
    ulint       UserL4Len,      /* IN: L4���ֽڳ��ȣ����256�ֽ� */
    byte*       msg,            /* IN: ��Ϣ */
    ulint       msgLen          /* IN: ��Ϣ���ֽڳ���*/
);

/*****************************************
Purpose:
�ͻ����޸��û��������L5
Notes:
ZB����[ZB-des-4]��¼��֤
/*****************************************/
DllExport
dm_bool
cipher_user_auth_update(
    ulint       inner_id,       /* IN: �㷨id */
    void*       pSession,       /* IN: ���λỰ���� */
    byte*       pUserPwd,       /* IN: �û��Ͽ��� */
    ulint       UserPwdLen,     /* IN: �Ͽ�����ֽڳ��ȣ����512�ֽ� */
    byte*       pUserPwdNew,    /* IN: �û��¿���*/
    ulint       UserPwdNewLen,  /* IN: �¿�����ֽڳ��ȣ����512�ֽ� */
    byte*       pUserL5,        /* OUT: L5, �ϲ�Ԥ����ռ�*/
    ulint*      pUserL5Len      /* OUT: L5���ֽڳ��ȣ����256�ֽ� */
);

/*****************************************
Purpose:
������޸��û����ʹ��L5������U1
Notes:
ZB����[ZB-des-4]��¼��֤
/*****************************************/
DllExport
dm_bool
cipher_user_auth_final(
    ulint       inner_id,       /* IN: �㷨id */
    void*       pSession,       /* IN: ���λỰ���� */
    byte*       UserName,       /* IN: �û���, ���ݿ�����*/
    ulint       UserNameLen,    /* IN: �û������ֽڳ��ȣ����128�ֽ�*/
    byte*       pUserL5,        /* IN: L5 */
    ulint       UserL5Len,      /* IN: L5���ֽڳ��ȣ����256�ֽ� */
    byte*       pUserU1,        /* OUT: U1, �ϲ�Ԥ����ռ� */
    ulint*      pUserU1Len      /* OUT: U1���ֽڳ��ȣ����256�ֽ� */
);

/************************************************************************
Purpose:
��ȡ�����û���֤����
Notes:
(1)ZB����[ZB-des-4]��¼��֤
(2)
DM_UKEY_FLAG_NONE                 0      // ��ʹ��UKEY��֤
DM_UKEY_FLAG_CERT                 1      // UKEY֤����֤
DM_UKEY_FLAG_ZB                   2      // UKEY������֤
/************************************************************************/
DllExport
lint
cipher_get_auth_type(
);

#ifdef __cplusplus
}
#endif

#endif
