/**********************************************************
file: 
    nci.h
Notes:
    NCI Interface public definitions
Legal Notices£º
Legal Notices:
Dameng Database
Copyright(C) 2000-2022 DM and/or its affiliates. All rights reserved.
http://www.dameng.com
*******************************************************/
#ifndef _NCI_H
#define _NCI_H

#include <limits.h>
#include <sys/types.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifdef WIN32
#define NCI_API   __declspec( dllexport )
#else
#define NCI_API 
#endif 

#define SQLT_CHR                        1               /* (ORANET TYPE) character string */
#define SQLT_NUM                        2               /* (ORANET TYPE) oracle numeric */
#define SQLT_INT                        3               /* (ORANET TYPE) integer */
#define SQLT_FLT                        4               /* (ORANET TYPE) Floating point number */
#define SQLT_STR                        5               /* zero terminated string */
#define SQLT_VNU                        6               /* NUM with preceding length byte */
#define SQLT_PDN                        7               /* (ORANET TYPE) Packed Decimal Numeric */
#define SQLT_LNG                        8               /* long */
#define SQLT_VCS                        9               /* Variable character string */
#define SQLT_NON                        10              /* Null/empty PCC Descriptor entry */
#define SQLT_RID                        11              /* rowid */
#define SQLT_DAT                        12              /* date in oracle format */
#define SQLT_VBI                        15              /* binary in VCS format */
#define SQLT_BFLOAT                     21              /* Native Binary float*/
#define SQLT_BDOUBLE                    22              /* NAtive binary double */
#define SQLT_BIN                        23              /* binary data(DTYBIN) */
#define SQLT_LBI                        24              /* long binary */
#define SQLT_UIN                        68              /* unsigned integer */
#define SQLT_SLS                        91              /* Display sign leading separate */
#define SQLT_LVC                        94              /* Longer longs (char) */
#define SQLT_LVB                        95              /* Longer long binary */ 
#define SQLT_AFC                        96              /* Ansi fixed char */
#define SQLT_AVC                        97              /* Ansi Var char */
#define SQLT_IBFLOAT                    100             /* binary float canonical */
#define SQLT_IBDOUBLE                   101             /* binary double canonical */
#define SQLT_CUR                        102             /* cursor  type */
#define SQLT_RDD                        104             /* rowid descriptor */
#define SQLT_LAB                        105             /* label type */
#define SQLT_OSL                        106             /* oslabel type */
#define SQLT_NTY                        108             /* named object type */
#define SQLT_REF                        110             /* ref type */
#define SQLT_CLOB                       112             /* character lob */
#define SQLT_BLOB                       113             /* binary lob */
#define SQLT_BFILEE                     114             /* binary file lob */
#define SQLT_CFILEE                     115             /* character file lob */
#define SQLT_RSET                       116             /* result set type */
#define SQLT_NCO                        122             /* named collection type (varray or nested table) */
#define SQLT_VST                        155             /* NCIString type */
#define SQLT_ODT                        156             /* NCIDate type */
#define SQLT_DATE                       184             /* ANSI Date */
#define SQLT_TIME                       185             /* TIME */
#define SQLT_TIME_TZ                    186             /* TIME WITH TIME ZONE */
#define SQLT_TIMESTAMP                  187             /* TIMESTAMP */
#define SQLT_TIMESTAMP_TZ               188             /* TIMESTAMP WITH TIME ZONE */
#define SQLT_INTERVAL_YM                189             /* INTERVAL YEAR TO MONTH */
#define SQLT_INTERVAL_DS                190             /* INTERVAL DAY TO SECOND */
#define SQLT_TIMESTAMP_LTZ              232             /* TIMESTAMP WITH LOCAL TZ */
#define SQLT_PNTY                       241             /* pl/sql representation of named types */
#define SQLT_FILE                       SQLT_BFILEE     /* binary file lob */
#define SQLT_CFILE                      SQLT_CFILEE
#define SQLT_BFILE                      SQLT_BFILEE
#define SQLT_BOL                        252             /* pl/sql 'boolean' */


#define NCI_TYPECODE_REF                SQLT_REF            /* SQL/OTS OBJECT REFERENCE */
#define NCI_TYPECODE_DATE               SQLT_DAT            /* SQL DATE  OTS DATE */
#define NCI_TYPECODE_SIGNED8            27                  /* SQL SIGNED INTEGER(8)  OTS SINT8 */
#define NCI_TYPECODE_SIGNED16           28                  /* SQL SIGNED INTEGER(16)  OTS SINT16 */
#define NCI_TYPECODE_SIGNED32           29                  /* SQL SIGNED INTEGER(32)  OTS SINT32 */
#define NCI_TYPECODE_REAL               21                  /* SQL REAL  OTS SQL_REAL */
#define NCI_TYPECODE_DOUBLE             22                  /* SQL DOUBLE PRECISION  OTS SQL_DOUBLE */
#define NCI_TYPECODE_FLOAT              SQLT_FLT            /* SQL FLOAT(P)  OTS FLOAT(P) */
#define NCI_TYPECODE_NUMBER             SQLT_NUM            /* SQL NUMBER(P S)  OTS NUMBER(P S) */
#define NCI_TYPECODE_DECIMAL            SQLT_PDN            /* SQL DECIMAL(P S)  OTS DECIMAL(P S) */
#define NCI_TYPECODE_UNSIGNED8          SQLT_BIN            /* SQL UNSIGNED INTEGER(8)  OTS UINT8 */
#define NCI_TYPECODE_UNSIGNED16         25                  /* SQL UNSIGNED INTEGER(16)  OTS UINT16 */
#define NCI_TYPECODE_UNSIGNED32         26                  /* SQL UNSIGNED INTEGER(32)  OTS UINT32 */
#define NCI_TYPECODE_BFLOAT             SQLT_IBFLOAT        /* Binary float */
#define NCI_TYPECODE_BDOUBLE            SQLT_IBDOUBLE       /* Binary double */
#define NCI_TYPECODE_OCTET              245                 /* SQL ???  OTS OCTET */
#define NCI_TYPECODE_SMALLINT           246                 /* SQL SMALLINT  OTS SMALLINT */
#define NCI_TYPECODE_INTEGER            SQLT_INT            /* SQL INTEGER  OTS INTEGER */
#define NCI_TYPECODE_RAW                SQLT_LVB            /* SQL RAW(N)  OTS RAW(N) */
#define NCI_TYPECODE_PTR                32                  /* SQL POINTER  OTS POINTER */
#define NCI_TYPECODE_VARCHAR2           SQLT_VCS            /* SQL VARCHAR2(N)  OTS SQL_VARCHAR2(N) */
#define NCI_TYPECODE_CHAR               SQLT_AFC            /* SQL CHAR(N)  OTS SQL_CHAR(N) */
#define NCI_TYPECODE_VARCHAR            SQLT_CHR            /* SQL VARCHAR(N)  OTS SQL_VARCHAR(N) */
#define NCI_TYPECODE_MLSLABEL           SQLT_LAB            /* OTS MLSLABEL */
#define NCI_TYPECODE_VARRAY             247                 /* SQL VARRAY  OTS PAGED VARRAY */
#define NCI_TYPECODE_TABLE              248                 /* SQL TABLE  OTS MULTISET */
#define NCI_TYPECODE_OBJECT             SQLT_NTY            /* SQL/OTS NAMED OBJECT TYPE */
#define NCI_TYPECODE_OPAQUE             58                  /* SQL/OTS Opaque Types */
#define NCI_TYPECODE_NAMEDCOLLECTION    SQLT_NCO            /* SQL/OTS NAMED COLLECTION TYPE */
#define NCI_TYPECODE_BLOB               SQLT_BLOB           /* SQL/OTS BINARY LARGE OBJECT */
#define NCI_TYPECODE_BFILE              SQLT_BFILE          /* SQL/OTS BINARY FILE OBJECT */
#define NCI_TYPECODE_CLOB               SQLT_CLOB           /* SQL/OTS CHARACTER LARGE OBJECT */
#define NCI_TYPECODE_CFILE              SQLT_CFILE          /* SQL/OTS CHARACTER FILE OBJECT */
#define NCI_TYPECODE_TIME               SQLT_TIME           /* SQL/OTS TIME */
#define NCI_TYPECODE_TIME_TZ            SQLT_TIME_TZ        /* SQL/OTS TIME_TZ */
#define NCI_TYPECODE_TIMESTAMP          SQLT_TIMESTAMP      /* SQL/OTS TIMESTAMP */
#define NCI_TYPECODE_TIMESTAMP_TZ       SQLT_TIMESTAMP_TZ   /* SQL/OTS TIMESTAMP_TZ */
#define NCI_TYPECODE_TIMESTAMP_LTZ      SQLT_TIMESTAMP_LTZ  /* TIMESTAMP_LTZ */
#define NCI_TYPECODE_INTERVAL_YM        SQLT_INTERVAL_YM    /* SQL/OTS INTRVL YR-MON */
#define NCI_TYPECODE_INTERVAL_DS        SQLT_INTERVAL_DS    /* SQL/OTS INTRVL DAY-SEC */
#define NCI_TYPECODE_OTMFIRST           228                 /* first Open Type Manager typecode */
#define NCI_TYPECODE_OTMLAST            320                 /* last OTM typecode */
#define NCI_TYPECODE_SYSFIRST           228                 /* first OTM system type (internal) */
#define NCI_TYPECODE_SYSLAST            235                 /* last OTM system type (internal) */
#define NCI_TYPECODE_PLS_INTEGER        266                 /* type code for PLS_INTEGER */
/* NOTE : The following NCHAR related codes are just short forms for saying
   NCI_TYPECODE_VARCHAR2 with a charset form of SQLCS_NCHAR. These codes are
   intended for use in the NCIAnyData API only and nowhere else. */
#define NCI_TYPECODE_NCHAR              286
#define NCI_TYPECODE_NVARCHAR2          287
#define NCI_TYPECODE_NCLOB              288


#ifndef TRUE
#define TRUE        1
#define FALSE       0
#endif

typedef unsigned char                   ub1;
typedef signed char                     sb1;

#define UB1MAXVAL                       ((ub1)UCHAR_MAX)
#define UB1MINVAL                       ((ub1)        0)
#define SB1MAXVAL                       ((sb1)SCHAR_MAX)
#define SB1MINVAL                       ((sb1)SCHAR_MIN)
#define MINUB1MAXVAL                    ((ub1)  255)
#define MAXUB1MINVAL                    ((ub1)    0)
#define MINSB1MAXVAL                    ((sb1)  127)
#define MAXSB1MINVAL                    ((sb1) -127)

typedef unsigned short                  ub2;
typedef signed short                    sb2;

#define UB2MAXVAL                       ((ub2)USHRT_MAX)
#define UB2MINVAL                       ((ub2)        0)
#define SB2MAXVAL                       ((sb2) SHRT_MAX)
#define SB2MINVAL                       ((sb2) SHRT_MIN)
#define MINUB2MAXVAL                    ((ub2) 65535)
#define MAXUB2MINVAL                    ((ub2)     0)
#define MINSB2MAXVAL                    ((sb2) 32767)
#define MAXSB2MINVAL                    ((sb2)-32767)

typedef unsigned int                    ub4;
typedef signed int                      sb4;

#ifndef INT_MAX
#define INT_MIN                         (-2147483647 - 1)   /* minimum (signed) int value */
#define INT_MAX                         2147483647          /* maximum (signed) int value */
#endif

#define UB4MAXVAL                       ((ub4)UINT_MAX)
#define UB4MINVAL                       ((ub4)        0)
#define SB4MAXVAL                       ((sb4) INT_MAX)
#define SB4MINVAL                       ((sb4) INT_MIN)
#define MINUB4MAXVAL                    ((ub4) 4294967295)
#define MAXUB4MINVAL                    ((ub4)          0)
#define MINSB4MAXVAL                    ((sb4) 2147483647)
#define MAXSB4MINVAL                    ((sb4)-2147483647)

#define UB8MINVAL                       ((ub8)0)
#define UB8MAXVAL                       ((ub8)18446744073709551615)
#define SB8MINVAL                       ((sb8)-9223372036854775808)
#define SB8MAXVAL                       ((sb8) 9223372036854775807)

#define MAXUB8MINVAL                    ((ub8)0)
#define MINUB8MAXVAL                    ((ub8)18446744073709551615)
#define MAXSB8MINVAL                    ((sb8)-9223372036854775807)
#define MINSB8MAXVAL                    ((sb8) 9223372036854775807)

#define UB1BITS                         CHAR_BIT
#define UB1MASK                         ((1 << ((uword)CHAR_BIT)) - 1)

typedef unsigned char                   text;
typedef text                            oratext;
typedef text                            OraText;
typedef text                            NCIText; 

typedef char                            eb1;
typedef short                           eb2;
typedef int                             eb4;

#define EB1MAXVAL                       ((eb1)SCHAR_MAX)
#define EB1MINVAL                       ((eb1)        0)
#define MINEB1MAXVAL                    ((eb1)  127)
#define MAXEB1MINVAL                    ((eb1)    0)
#define EB2MAXVAL                       ((eb2) SHRT_MAX)
#define EB2MINVAL                       ((eb2)        0)
#define MINEB2MAXVAL                    ((eb2) 32767)
#define MAXEB2MINVAL                    ((eb2)     0)
#define EB4MAXVAL                       ((eb4) INT_MAX)
#define EB4MINVAL                       ((eb4)        0)
#define MINEB4MAXVAL                    ((eb4) 2147483647)
#define MAXEB4MINVAL                    ((eb4)          0)

typedef sb1                             b1;

#define B1MAXVAL                        SB1MAXVAL
#define B1MINVAL                        SB1MINVAL

typedef sb2                             b2;

#define B2MAXVAL                        SB2MAXVAL
#define B2MINVAL                        SB2MINVAL

typedef sb4                             b4;

#define B4MAXVAL                        SB4MAXVAL
#define B4MINVAL                        SB4MINVAL

typedef int                             eword;
typedef unsigned int                    uword;
typedef signed int                      sword;

#define EWORDMAXVAL                     ((eword) INT_MAX)
#define EWORDMINVAL                     ((eword)       0)
#define UWORDMAXVAL                     ((uword)UINT_MAX)
#define UWORDMINVAL                     ((uword)       0)
#define SWORDMAXVAL                     ((sword) INT_MAX)
#define SWORDMINVAL                     ((sword) INT_MIN)
#define MINEWORDMAXVAL                  ((eword)  2147483647)
#define MAXEWORDMINVAL                  ((eword)      0)
#define MINUWORDMAXVAL                  ((uword)  4294967295)
#define MAXUWORDMINVAL                  ((uword)           0)
#define MINSWORDMAXVAL                  ((sword)  2147483647)
#define MAXSWORDMINVAL                  ((sword) -2147483647)

/* --- Signed/Unsigned eight-byte scalar (sb8/ub8) --- */
#ifndef __GNUC__
#ifdef __BORLANDC__
typedef unsigned __int64                ub8;
typedef signed __int64                  sb8;
#else
typedef unsigned _int64                 ub8;
typedef signed _int64                   sb8;
#endif /* __BORLANDC__ */
#else
typedef unsigned long long              ub8;
typedef signed long long                sb8;
#endif /*__GNUC__*/

#undef CONST
#define CONST                           const

#define dvoid                           void

//typedef void (*dlgenfp_t)( void );

#ifndef boolean
#define boolean                         int
#endif

typedef unsigned int                    cbool;

#ifdef sparc
#define SIZE_TMAXVAL                     SB4MAXVAL
#else
#define SIZE_TMAXVAL                     UB4MAXVAL
#endif

#define MINSIZE_TMAXVAL                  (size_t)4294967295

#define NCI_NUMBER_UNSIGNED             0                           /* Unsigned type -- ubX */
#define NCI_NUMBER_SIGNED               2                           /* Signed type -- sbX */

/* CHAR/NCHAR/VARCHAR2/NVARCHAR2/CLOB/NCLOB char set "form" information */
#define SQLCS_IMPLICIT                  1               /* for CHAR, VARCHAR2, CLOB w/o a specified set */
#define SQLCS_NCHAR                     2               /* for NCHAR, NCHAR VARYING, NCLOB */
#define SQLCS_EXPLICIT                  3               /* for CHAR, etc, with "CHARACTER SET ..." syntax */
#define SQLCS_FLEXIBLE                  4               /* for PL/SQL "flexible" parameters */
#define SQLCS_LIT_NULL                  5               /* for typecheck of NULL and empty_clob() lits */

/*--------------------------------------------------------------------------- 
                     PUBLIC TYPES AND CONSTANTS 
  ---------------------------------------------------------------------------*/

/*-----------------------------Handle Types----------------------------------*/
/* handle types range from 1 - 49 */
#define NCI_HTYPE_FIRST                 1                       /* start value of handle type */
#define NCI_HTYPE_ENV                   1                       /* environment handle */
#define NCI_HTYPE_ERROR                 2                       /* error handle */
#define NCI_HTYPE_SVCCTX                3                       /* service handle */
#define NCI_HTYPE_STMT                  4                       /* statement handle */
#define NCI_HTYPE_BIND                  5                       /* bind handle */
#define NCI_HTYPE_DEFINE                6                       /* define handle */
#define NCI_HTYPE_DESCRIBE              7                       /* describe handle */
#define NCI_HTYPE_SERVER                8                       /* server handle */
#define NCI_HTYPE_SESSION               9                       /* authentication handle */
#define NCI_HTYPE_AUTHINFO              NCI_HTYPE_SESSION       /* SessionGet auth handle */
#define NCI_HTYPE_TRANS                 10                      /* transaction handle */
#define NCI_HTYPE_COMPLEXOBJECT         11                      /* complex object retrieval handle */
#define NCI_HTYPE_SECURITY              12                      /* security handle */
#define NCI_HTYPE_SUBSCRIPTION          13                      /* subscription handle */
#define NCI_HTYPE_DIRPATH_CTX           14                      /* direct path context */
#define NCI_HTYPE_DIRPATH_COLUMN_ARRAY  15                      /* direct path column array */
#define NCI_HTYPE_DIRPATH_STREAM        16                      /* direct path stream */
#define NCI_HTYPE_PROC                  17                      /* process handle */
#define NCI_HTYPE_DIRPATH_FN_CTX        18                      /* direct path function context */
#define NCI_HTYPE_DIRPATH_FN_COL_ARRAY  19                      /* dp object column array */
#define NCI_HTYPE_XADSESSION            20                      /* access driver session */
#define NCI_HTYPE_XADTABLE              21                      /* access driver table */
#define NCI_HTYPE_XADFIELD              22                      /* access driver field */
#define NCI_HTYPE_XADGRANULE            23                      /* access driver granule */
#define NCI_HTYPE_XADRECORD             24                      /* access driver record */
#define NCI_HTYPE_XADIO                 25                      /* access driver I/O */
#define NCI_HTYPE_CPOOL                 26                      /* connection pool handle */
#define NCI_HTYPE_SPOOL                 27                      /* session pool handle */
#define NCI_HTYPE_ADMIN                 28                      /*administration handle*/
#define NCI_HTYPE_LAST                  28                      /* last value of a handle type */
/*---------------------------------------------------------------------------*/


/*-------------------------Descriptor Types----------------------------------*/
/* descriptor values range from 50 - 255 */
#define NCI_DTYPE_FIRST                 50                      /* start value of descriptor type */
#define NCI_DTYPE_LOB                   50                      /* lob  locator */
#define NCI_DTYPE_SNAP                  51                      /* snapshot descriptor */
#define NCI_DTYPE_RSET                  52                      /* result set descriptor */
#define NCI_DTYPE_PARAM                 53                      /* a parameter descriptor obtained from ncigparm */
#define NCI_DTYPE_ROWID                 54                      /* rowid descriptor */
#define NCI_DTYPE_COMPLEXOBJECTCOMP     55                      /* complex object retrieval descriptor */
#define NCI_DTYPE_FILE                  56                      /* File Lob locator */
#define NCI_DTYPE_AQENQ_OPTIONS         57                      /* enqueue options */
#define NCI_DTYPE_AQDEQ_OPTIONS         58                      /* dequeue options */
#define NCI_DTYPE_AQMSG_PROPERTIES      59                      /* message properties */
#define NCI_DTYPE_AQAGENT               60                      /* aq agent */
#define NCI_DTYPE_LOCATOR               61                      /* LOB locator */
#define NCI_DTYPE_INTERVAL_YM           62                      /* Interval year month */
#define NCI_DTYPE_INTERVAL_DS           63                      /* Interval day second */
#define NCI_DTYPE_AQNFY_DESCRIPTOR      64                      /* AQ notify descriptor */
#define NCI_DTYPE_DATE                  65                      /* Date */
#define NCI_DTYPE_TIME                  66                      /* Time */
#define NCI_DTYPE_TIME_TZ               67                      /* Time with timezone */
#define NCI_DTYPE_TIMESTAMP             68                      /* Timestamp */
#define NCI_DTYPE_TIMESTAMP_TZ          69                      /* Timestamp with timezone */
#define NCI_DTYPE_TIMESTAMP_LTZ         70                      /* Timestamp with local tz */
#define NCI_DTYPE_UCB                   71                      /* user callback descriptor */
#define NCI_DTYPE_SRVDN                 72                      /* server DN list descriptor */
#define NCI_DTYPE_SIGNATURE             73                      /* signature */
#define NCI_DTYPE_RESERVED_1            74                      /* reserved for internal use */
#define NCI_DTYPE_LAST                  74                      /* last value of a descriptor type */
/*---------------------------------------------------------------------------*/

/*--------------------------------LOB types ---------------------------------*/
#define NCI_TEMP_BLOB                   1                       /* LOB type - BLOB ------------------ */
#define NCI_TEMP_CLOB                   2                       /* LOB type - CLOB ------------------ */

/*---------------------------------------------------------------------------*/

/*-------------------------Object Ptr Types----------------------------------*/
#define NCI_OTYPE_NAME                  1                       /* object name */
#define NCI_OTYPE_REF                   2                       /* REF to TDO */
#define NCI_OTYPE_PTR                   3                       /* PTR to TDO */
/*---------------------------------------------------------------------------*/

/*=============================Attribute Types===============================*/
/* 
   Note: All attributes are global.  New attibutes should be added to the end
   of the list. Before you add an attribute see if an existing one can be 
   used for your handle. 

   If you see any holes please use the holes first. 
 
*/
/*===========================================================================*/

#define NCI_ATTR_FNCODE                     1                           /* the NCI function code */
#define NCI_ATTR_OBJECT                     2                           /* is the environment initialized in object mode */
#define NCI_ATTR_NONBLOCKING_MODE           3                           /* non blocking mode */
#define NCI_ATTR_SQLCODE                    4                           /* the SQL verb */
#define NCI_ATTR_ENV                        5                           /* the environment handle */
#define NCI_ATTR_SERVER                     6                           /* the server handle */
#define NCI_ATTR_SESSION                    7                           /* the user session handle */
#define NCI_ATTR_TRANS                      8                           /* the transaction handle */
#define NCI_ATTR_ROW_COUNT                  9                           /* the rows processed so far */
#define NCI_ATTR_SQLFNCODE                  10                          /* the SQL verb of the statement */
#define NCI_ATTR_PREFETCH_ROWS              11                          /* sets the number of rows to prefetch */
#define NCI_ATTR_NESTED_PREFETCH_ROWS       12                          /* the prefetch rows of nested table*/
#define NCI_ATTR_PREFETCH_MEMORY            13                          /* memory limit for rows fetched */
#define NCI_ATTR_NESTED_PREFETCH_MEMORY     14                          /* memory limit for nested rows */
#define NCI_ATTR_CHAR_COUNT                 15                          /* this specifies the bind and define size in characters */
#define NCI_ATTR_PDSCL                      16                          /* packed decimal scale */
#define NCI_ATTR_FSPRECISION                NCI_ATTR_PDSCL              /* fs prec for datetime data types */
#define NCI_ATTR_PDPRC                      17                          /* packed decimal format */
#define NCI_ATTR_LFPRECISION                NCI_ATTR_PDPRC              /* fs prec for datetime data types */
#define NCI_ATTR_PARAM_COUNT                18                          /* number of column in the select list */
#define NCI_ATTR_ROWID                      19                          /* the rowid */
#define NCI_ATTR_CHARSET                    20                          /* the character set value */
#define NCI_ATTR_NCHAR                      21                          /* NCHAR type */
#define NCI_ATTR_USERNAME                   22                          /* username attribute */
#define NCI_ATTR_PASSWORD                   23                          /* password attribute */
#define NCI_ATTR_STMT_TYPE                  24                          /* statement type */
#define NCI_ATTR_INTERNAL_NAME              25                          /* user friendly global name */
#define NCI_ATTR_EXTERNAL_NAME              26                          /* the internal name for global txn */
#define NCI_ATTR_XID                        27                          /* XOPEN defined global transaction id */
#define NCI_ATTR_TRANS_LOCK                 28                          /* */
#define NCI_ATTR_TRANS_NAME                 29                          /* string to identify a global transaction */
#define NCI_ATTR_HEAPALLOC                  30                          /* memory allocated on the heap */
#define NCI_ATTR_CHARSET_ID                 31                          /* Character Set ID */
#define NCI_ATTR_CHARSET_FORM               32                          /* Character Set Form */
#define NCI_ATTR_MAXDATA_SIZE               33                          /* Maximumsize of data on the server  */
#define NCI_ATTR_CACHE_OPT_SIZE             34                          /* object cache optimal size */
#define NCI_ATTR_CACHE_MAX_SIZE             35                          /* object cache maximum size percentage */
#define NCI_ATTR_PINOPTION                  36                          /* object cache default pin option */
#define NCI_ATTR_ALLOC_DURATION             37                          /* object cache default allocation duration */
#define NCI_ATTR_PIN_DURATION               38                          /* object cache default pin duration */
#define NCI_ATTR_FDO                        39                          /* Format Descriptor object attribute */
#define NCI_ATTR_POSTPROCESSING_CALLBACK    40                          /* Callback to process outbind data */
#define NCI_ATTR_POSTPROCESSING_CONTEXT     41                          /* Callback context to process outbind data */
#define NCI_ATTR_ROWS_RETURNED              42                          /* Number of rows returned in current iter - for Bind handles */
#define NCI_ATTR_FOCBK                      43                          /* Failover Callback attribute */
#define NCI_ATTR_IN_V8_MODE                 44                          /* is the server/service context in V8 mode */
#define NCI_ATTR_LOBEMPTY                   45                          /* empty lob ? */
#define NCI_ATTR_SESSLANG                   46                          /* session language handle */
#define NCI_ATTR_VISIBILITY                 47                          /* visibility */
#define NCI_ATTR_RELATIVE_MSGID             48                          /* relative message id */
#define NCI_ATTR_SEQUENCE_DEVIATION         49                          /* sequence deviation */
#define NCI_ATTR_CONSUMER_NAME              50                          /* consumer name */
#define NCI_ATTR_DEQ_MODE                   51                          /* dequeue mode */
#define NCI_ATTR_NAVIGATION                 52                          /* navigation */
#define NCI_ATTR_WAIT                       53                          /* wait */
#define NCI_ATTR_DEQ_MSGID                  54                          /* dequeue message id */
#define NCI_ATTR_PRIORITY                   55                          /* priority */
#define NCI_ATTR_DELAY                      56                          /* delay */
#define NCI_ATTR_EXPIRATION                 57                          /* expiration */
#define NCI_ATTR_CORRELATION                58                          /* correlation id */
#define NCI_ATTR_ATTEMPTS                   59                          /* # of attempts */
#define NCI_ATTR_RECIPIENT_LIST             60                          /* recipient list */
#define NCI_ATTR_EXCEPTION_QUEUE            61                          /* exception queue name */
#define NCI_ATTR_ENQ_TIME                   62                          /* enqueue time (only NCIAttrGet) */
#define NCI_ATTR_MSG_STATE                  63                          /* message state (only NCIAttrGet) */
#define NCI_ATTR_AGENT_NAME                 64                          /* agent name */
#define NCI_ATTR_AGENT_ADDRESS              65                          /* agent address */
#define NCI_ATTR_AGENT_PROTOCOL             66                          /* agent protocol */
#define NCI_ATTR_USER_PROPERTY              67                          /* user property */
#define NCI_ATTR_SENDER_ID                  68                          /* sender id */
#define NCI_ATTR_ORIGINAL_MSGID             69                          /* original message id */
#define NCI_ATTR_QUEUE_NAME                 70                          /* queue name */
#define NCI_ATTR_NFY_MSGID                  71                          /* message id */
#define NCI_ATTR_MSG_PROP                   72                          /* message properties */
#define NCI_ATTR_NUM_DML_ERRORS             73                          /* num of errs in array DML */
#define NCI_ATTR_DML_ROW_OFFSET             74                          /* row offset in the array */
#define NCI_ATTR_AQ_NUM_ERRORS              NCI_ATTR_NUM_DML_ERRORS
#define NCI_ATTR_AQ_ERROR_INDEX             NCI_ATTR_DML_ROW_OFFSET
#define NCI_ATTR_DATEFORMAT                 75                          /* default date format string */
#define NCI_ATTR_BUF_ADDR                   76                          /* buffer address */
#define NCI_ATTR_BUF_SIZE                   77                          /* buffer size */
#define NCI_ATTR_DIRPATH_MODE               78                          /* mode of direct path operation */
#define NCI_ATTR_DIRPATH_NOLOG              79                          /* nologging option */
#define NCI_ATTR_DIRPATH_PARALLEL           80                          /* parallel (temp seg) option */
#define NCI_ATTR_NUM_ROWS                   81                          /* number of rows in column array NOTE that NCI_ATTR_NUM_COLS is a column array attribute too*/
#define NCI_ATTR_COL_COUNT                  82                          /* columns of column array processed so far.       */
#define NCI_ATTR_STREAM_OFFSET              83                          /* str off of last row processed */
#define NCI_ATTR_SHARED_HEAPALLOC           84                          /* Shared Heap Allocation Size */
#define NCI_ATTR_SERVER_GROUP               85                          /* server group name */
#define NCI_ATTR_MIGSESSION                 86                          /* migratable session attribute */
#define NCI_ATTR_NOCACHE                    87                          /* Temporary LOBs */
#define NCI_ATTR_MEMPOOL_SIZE               88                          /* Pool Size */
#define NCI_ATTR_MEMPOOL_INSTNAME           89                          /* Instance name */
#define NCI_ATTR_MEMPOOL_APPNAME            90                          /* Application name */
#define NCI_ATTR_MEMPOOL_HOMENAME           91                          /* Home Directory name */
#define NCI_ATTR_MEMPOOL_MODEL              92                          /* Pool Model (proc,thrd,both)*/
#define NCI_ATTR_MODES                      93                          /* Modes */
#define NCI_ATTR_SUBSCR_NAME                94                          /* name of subscription */
#define NCI_ATTR_SUBSCR_CALLBACK            95                          /* associated callback */
#define NCI_ATTR_SUBSCR_CTX                 96                          /* associated callback context */
#define NCI_ATTR_SUBSCR_PAYLOAD             97                          /* associated payload */
#define NCI_ATTR_SUBSCR_NAMESPACE           98                          /* associated namespace */
#define NCI_ATTR_PROXY_CREDENTIALS          99                          /* Proxy user credentials */
#define NCI_ATTR_INITIAL_CLIENT_ROLES       100                         /* Initial client role list */
#define NCI_ATTR_UNK                        101                         /* unknown attribute */
#define NCI_ATTR_NUM_COLS                   102                         /* number of columns */
#define NCI_ATTR_LIST_COLUMNS               103                         /* parameter of the column list */
#define NCI_ATTR_RDBA                       104                         /* DBA of the segment header */
#define NCI_ATTR_CLUSTERED                  105                         /* whether the table is clustered */
#define NCI_ATTR_PARTITIONED                106                         /* whether the table is partitioned */
#define NCI_ATTR_INDEX_ONLY                 107                         /* whether the table is index only */
#define NCI_ATTR_LIST_ARGUMENTS             108                         /* parameter of the argument list */
#define NCI_ATTR_LIST_SUBPROGRAMS           109                         /* parameter of the subprogram list */
#define NCI_ATTR_REF_TDO                    110                         /* REF to the type descriptor */
#define NCI_ATTR_LINK                       111                         /* the database link name */
#define NCI_ATTR_MIN                        112                         /* minimum value */
#define NCI_ATTR_MAX                        113                         /* maximum value */
#define NCI_ATTR_INCR                       114                         /* increment value */
#define NCI_ATTR_CACHE                      115                         /* number of sequence numbers cached */
#define NCI_ATTR_ORDER                      116                         /* whether the sequence is ordered */
#define NCI_ATTR_HW_MARK                    117                         /* high-water mark */
#define NCI_ATTR_TYPE_SCHEMA                118                         /* type's schema name */
#define NCI_ATTR_TIMESTAMP                  119                         /* timestamp of the object */
#define NCI_ATTR_NUM_ATTRS                  120                         /* number of sttributes */
#define NCI_ATTR_NUM_PARAMS                 121                         /* number of parameters */
#define NCI_ATTR_OBJID                      122                         /* object id for a table or view */
#define NCI_ATTR_PTYPE                      123                         /* type of info described by */
#define NCI_ATTR_PARAM                      124                         /* parameter descriptor */
#define NCI_ATTR_OVERLOAD_ID                125                         /* overload ID for funcs and procs */
#define NCI_ATTR_TABLESPACE                 126                         /* table name space */
#define NCI_ATTR_TDO                        127                         /* TDO of a type */
#define NCI_ATTR_LTYPE                      128                         /* list type */
#define NCI_ATTR_PARSE_ERROR_OFFSET         129                         /* Parse Error offset */
#define NCI_ATTR_IS_TEMPORARY               130                         /* whether table is temporary */
#define NCI_ATTR_IS_TYPED                   131                         /* whether table is typed */
#define NCI_ATTR_DURATION                   132                         /* duration of temporary table */
#define NCI_ATTR_IS_INVOKER_RIGHTS          133                         /* is invoker rights */
#define NCI_ATTR_OBJ_NAME                   134                         /* top level schema obj name */
#define NCI_ATTR_OBJ_SCHEMA                 135                         /* schema name */
#define NCI_ATTR_OBJ_ID                     136                         /* top level schema object id */
#define NCI_ATTR_DIRPATH_SORTED_INDEX       137                         /* index that data is sorted on */
#define NCI_ATTR_DIRPATH_INDEX_MAINT_METHOD 138
#define NCI_ATTR_DIRPATH_FILE               139                         /* DB file to load into */
#define NCI_ATTR_DIRPATH_STORAGE_INITIAL    140                         /* initial extent size */
#define NCI_ATTR_DIRPATH_STORAGE_NEXT       141                         /* next extent size */
#define NCI_ATTR_TRANS_TIMEOUT              142                         /* transaction timeout */
#define NCI_ATTR_SERVER_STATUS              143                         /* state of the server handle */
#define NCI_ATTR_STATEMENT                  144                         /* statement txt in stmt hdl */
#define NCI_ATTR_DIRPATH_SKIPINDEX_METHOD   145
#define NCI_ATTR_DEQCOND                    146                         /* dequeue condition */
#define NCI_ATTR_RESERVED_2                 147                         /* reserved */
#define NCI_ATTR_SUBSCR_RECPT               148                         /* recepient of subscription */
#define NCI_ATTR_SUBSCR_RECPTPROTO          149                         /* protocol for recepient */
#define NCI_ATTR_DIRPATH_EXPR_TYPE          150                         /* expr type of NCI_ATTR_NAME */
#define NCI_ATTR_DIRPATH_INPUT              151                         /* input in text or stream format */
#define NCI_DIRPATH_INPUT_TEXT              0x01
#define NCI_DIRPATH_INPUT_STREAM            0x02
#define NCI_DIRPATH_INPUT_UNKNOWN           0x04
#define NCI_ATTR_LDAP_HOST                  153                         /* LDAP host to connect to */
#define NCI_ATTR_LDAP_PORT                  154                         /* LDAP port to connect to */
#define NCI_ATTR_BIND_DN                    155                         /* bind DN */
#define NCI_ATTR_LDAP_CRED                  156                         /* credentials to connect to LDAP */
#define NCI_ATTR_WALL_LOC                   157                         /* client wallet location */
#define NCI_ATTR_LDAP_AUTH                  158                         /* LDAP authentication method */
#define NCI_ATTR_LDAP_CTX                   159                         /* LDAP adminstration context DN */
#define NCI_ATTR_SERVER_DNS                 160                         /* list of registration server DNs */
#define NCI_ATTR_DN_COUNT                   161                         /* the number of server DNs */
#define NCI_ATTR_SERVER_DN                  162                         /* server DN attribute */
#define NCI_ATTR_MAXCHAR_SIZE               163                         /* max char size of data */
#define NCI_ATTR_CURRENT_POSITION           164                         /* for scrollable result sets*/
#define NCI_ATTR_RESERVED_3                 165                         /* reserved */
#define NCI_ATTR_RESERVED_4                 166                         /* reserved */
#define NCI_ATTR_DIRPATH_FN_CTX             167                         /* fn ctx ADT attrs or args */
#define NCI_ATTR_DIGEST_ALGO                168                         /* digest algorithm */
#define NCI_ATTR_CERTIFICATE                169                         /* certificate */
#define NCI_ATTR_SIGNATURE_ALGO             170                         /* signature algorithm */
#define NCI_ATTR_CANONICAL_ALGO             171                         /* canonicalization algo. */
#define NCI_ATTR_PRIVATE_KEY                172                         /* private key */
#define NCI_ATTR_DIGEST_VALUE               173                         /* digest value */
#define NCI_ATTR_SIGNATURE_VAL              174                         /* signature value */
#define NCI_ATTR_SIGNATURE                  175                         /* signature */
#define NCI_ATTR_STMTCACHESIZE              176                         /* size of the stm cache */
#define NCI_ATTR_CONN_NOWAIT                178
#define NCI_ATTR_CONN_BUSY_COUNT            179
#define NCI_ATTR_CONN_OPEN_COUNT            180
#define NCI_ATTR_CONN_TIMEOUT               181
#define NCI_ATTR_STMT_STATE                 182
#define NCI_ATTR_CONN_MIN                   183
#define NCI_ATTR_CONN_MAX                   184
#define NCI_ATTR_CONN_INCR                  185
#define NCI_ATTR_DIRPATH_OID                187                         /* loading into an OID col */
#define NCI_ATTR_NUM_OPEN_STMTS             188                         /* open stmts in session */
#define NCI_ATTR_DESCRIBE_NATIVE            189                         /* get native info via desc */
#define NCI_ATTR_BIND_COUNT                 190                         /* number of bind postions */
#define NCI_ATTR_HANDLE_POSITION            191                         /* pos of bind/define handle */
#define NCI_ATTR_RESERVED_5                 192                         /* reserverd */
#define NCI_ATTR_SERVER_BUSY                193                         /* call in progress on server*/
#define NCI_ATTR_DIRPATH_SID                194                         /* loading into an SID col */
#define NCI_ATTR_SUBSCR_RECPTPRES           195
#define NCI_ATTR_TRANSFORMATION             196                         /* AQ message transformation */
#define NCI_ATTR_ROWS_FETCHED               197                         /* rows fetched in last call */
#define NCI_ATTR_SCN_BASE                   198                         /* snapshot base */
#define NCI_ATTR_SCN_WRAP                   199                         /* snapshot wrap */
#define NCI_ATTR_RESERVED_6                 200                         /* reserved */
#define NCI_ATTR_READONLY_TXN               201                         /* txn is readonly */
#define NCI_ATTR_RESERVED_7                 202                         /* reserved */
#define NCI_ATTR_ERRONEOUS_COLUMN           203                         /* position of erroneous col */
#define NCI_ATTR_RESERVED_8                 204                         /* reserved */
#define NCI_ATTR_DIRPATH_OBJ_CONSTR         206                         /* obj type of subst obj tbl */
#define NCI_ATTR_INST_TYPE                  207                         /* instance type */
/******USED attribute 208 for  NCI_ATTR_SPOOL_STMTCACHESIZE*******************/
#define NCI_ATTR_ENV_UTF16                  209                         /* is env in utf16 mode? */
#define NCI_ATTR_RESERVED_9                 210                         /* reserved for TMZ */
#define NCI_ATTR_RESERVED_10                211                         /* reserved */
#define NCI_ATTR_DIRPATH_STREAM_VERSION     212                         /* version of the stream*/
#define NCI_ATTR_DIRPATH_VARRAY_INDEX       213                         /* varray index column */
#define NCI_ATTR_RESERVED_12                214                         /* reserved */
#define NCI_ATTR_RESERVED_13                215                         /* reserved */
#define NCI_ATTR_IS_EXTERNAL                216                         /* whether table is external */
#define NCI_ATTR_RESERVED_15                217                         /* reserved */
#define NCI_ATTR_STMT_IS_RETURNING          218                         /* stmt has returning clause */
#define NCI_ATTR_RESERVED_16                219                         /* reserved */
#define NCI_ATTR_RESERVED_17                220                         /* reserved */
#define NCI_ATTR_RESERVED_18                221                         /* reserved */
#define NCI_ATTR_RESERVED_19                222                         /* reserved */
#define NCI_ATTR_LIST_TYPE                  223                         /*attributes of list,designates list type*/
#define NCI_ATTR_DRIVER_NAME                424                         /* Specifies the name of the driver layer using NCI. (Such as JDBC, ODBC, PHP, SQL*Plus, and so on. */
#define NCI_ATTR_ENV_CHARSET_ID             NCI_ATTR_CHARSET_ID         /* charset id in env */
#define NCI_ATTR_ENV_NCHARSET_ID            NCI_ATTR_NCHARSET_ID        /* ncharset id in env */

/**************************EXTENDED ATTRIBUTES FOR DM****************************/
#define NCI_ATTR_PORT                       1000                    /* DM login port	 */
#define NCI_ATTR_DIRPATH_SET_IDENTITY       2000                    /* DRIPATH INPUT ENABLE SET IDENTITY COLUMN*/
#define NCI_ATTR_SSL_PATH                   10000                   /*attributes of SSL_PATH*/
#define NCI_ATTR_SSL_PWD                    10001
#define NCI_ATTR_MPP_LOGIN                  10002
#define NCI_ATTR_RW_SEPARATE                10003
#define NCI_ATTR_RW_SEPARATE_PERCENT        10004
#define NCI_ATTR_CONN_TYPE                  10005
#define NCI_ATTR_LOGIN_CERTIFICATE          10006

/*------------- Supported Values for Direct Path Stream Version -------------*/
#define NCI_DIRPATH_STREAM_VERSION_1            100
#define NCI_DIRPATH_STREAM_VERSION_2            200
#define NCI_DIRPATH_STREAM_VERSION_3            300                 /* default */

/* ----------------------- row callback attributes ------------------------- */
#define NCI_ATTR_BIND_ROWCBK                    301                 /* bind row callback */
#define NCI_ATTR_BIND_ROWCTX                    302                 /* ctx for bind row callback */
#define NCI_ATTR_SKIP_BUFFER                    303                 /* skip buffer in array ops */

/* ----- Temporary attribute value for UCS2/UTF16 character set ID -------- */ 
#define NCI_UCS2ID                              1000                /* UCS2 charset ID */
#define NCI_UTF16ID                             1000                /* UTF16 charset ID */

/*============================== End NCI Attribute Types ====================*/

/*---------------- Session Handle Attribute Values for DM only---------------------------*/
/* NCI_ATTR_MPP_LOGIN*/
#define NCI_MPP_LOGIN_GLOBAL                    0
#define NCI_MPP_LOGIN_LOCAL                     1

/* NCI_ATTR_RW_SEPARATE*/
#define NCI_RW_SEPARATE_OFF                     0
#define NCI_RW_SEPARATE_ON                      1

/* NCI_ATTR_CONN_TYPE*/
#define NCI_CONN_TCP                            0
#define NCI_CONN_UDP                            1
#define NCI_CONN_IPC                            2
#define NCI_CONN_RDMA                           3
#define NCI_CONN_UNIXSOCKET                     4

/*---------------- Server Handle Attribute Values ---------------------------*/
/* NCI_ATTR_SERVER_STATUS */
#define NCI_SERVER_NOT_CONNECTED                0x0
#define NCI_SERVER_NORMAL                       0x1

/*---------------------------------------------------------------------------*/

/*------------------------- Supported Namespaces  ---------------------------*/
#define NCI_SUBSCR_NAMESPACE_ANONYMOUS          0                   /* Anonymous Namespace */
#define NCI_SUBSCR_NAMESPACE_AQ                 1                   /* Advanced Queues */
#define NCI_SUBSCR_NAMESPACE_MAX                2                   /* Max Name Space Number */

/*-------------------------Credential Types----------------------------------*/
#define NCI_CRED_RDBMS                          1                   /* database username/password */
#define NCI_CRED_EXT                            2                   /* externally provided credentials */
#define NCI_CRED_PROXY                          3                   /* proxy authentication */
#define NCI_CRED_RESERVED_1                     4                   /* reserved */
#define NCI_CRED_RESERVED_2                     5                   /* reserved */
/*---------------------------------------------------------------------------*/

/*------------------------Error Return Values--------------------------------*/
#define NCI_SUCCESS                             0                   /* maps to SQL_SUCCESS of SAG CLI */
#define NCI_SUCCESS_WITH_INFO                   1                   /* maps to SQL_SUCCESS_WITH_INFO */
#define NCI_RESERVED_FOR_INT_USE                200                 /* reserved */ 
#define NCI_NO_DATA                             100                 /* maps to SQL_NO_DATA */
#define NCI_ERROR                               -1                  /* maps to SQL_ERROR */
#define NCI_INVALID_HANDLE                      -2                  /* maps to SQL_INVALID_HANDLE */
#define NCI_NEED_DATA                           99                  /* maps to SQL_NEED_DATA */
#define NCI_STILL_EXECUTING                     -3123               /* NCI would block error */
/*---------------------------------------------------------------------------*/

/*--------------------- User Callback Return Values -------------------------*/
#define NCI_CONTINUE                            -24200                  /* Continue with the body of the NCI function */
#define NCI_ROWCBK_DONE                         -24201                  /* done with user row callback */
/*---------------------------------------------------------------------------*/

/*------------------DateTime and Interval check Error codes------------------*/

/* DateTime Error Codes used by NCIDateTimeCheck() */
#define NCI_DT_INVALID_DAY                      0x1                     /* Bad day */
#define NCI_DT_DAY_BELOW_VALID                  0x2                     /* Bad DAy Low/high bit (1=low)*/
#define NCI_DT_INVALID_MONTH                    0x4                     /*  Bad MOnth */
#define NCI_DT_MONTH_BELOW_VALID                0x8                     /* Bad MOnth Low/high bit (1=low) */
#define NCI_DT_INVALID_YEAR                     0x10                    /* Bad YeaR */
#define NCI_DT_YEAR_BELOW_VALID                 0x20                    /*  Bad YeaR Low/high bit (1=low) */
#define NCI_DT_INVALID_HOUR                     0x40                    /*  Bad HouR */
#define NCI_DT_HOUR_BELOW_VALID                 0x80                    /* Bad HouR Low/high bit (1=low) */
#define NCI_DT_INVALID_MINUTE                   0x100                   /* Bad MiNute */
#define NCI_DT_MINUTE_BELOW_VALID               0x200                   /*Bad MiNute Low/high bit (1=low) */
#define NCI_DT_INVALID_SECOND                   0x400                   /*  Bad SeCond */
#define NCI_DT_SECOND_BELOW_VALID               0x800                   /*bad second Low/high bit (1=low)*/
#define NCI_DT_DAY_MISSING_FROM_1582            0x1000                  /*  Day is one of those "missing" from 1582 */
#define NCI_DT_YEAR_ZERO                        0x2000                  /* Year may not equal zero */
#define NCI_DT_INVALID_TIMEZONE                 0x4000                  /*  Bad Timezone */
#define NCI_DT_INVALID_FORMAT                   0x8000                  /* Bad date format input */

/* Interval Error Codes used by NCIInterCheck() */
#define NCI_INTER_INVALID_DAY                   0x1                     /* Bad day */
#define NCI_INTER_DAY_BELOW_VALID               0x2                     /* Bad DAy Low/high bit (1=low) */
#define NCI_INTER_INVALID_MONTH                 0x4                     /* Bad MOnth */
#define NCI_INTER_MONTH_BELOW_VALID             0x8                     /*Bad MOnth Low/high bit (1=low) */
#define NCI_INTER_INVALID_YEAR                  0x10                    /* Bad YeaR */
#define NCI_INTER_YEAR_BELOW_VALID              0x20                    /*Bad YeaR Low/high bit (1=low) */
#define NCI_INTER_INVALID_HOUR                  0x40                    /* Bad HouR */
#define NCI_INTER_HOUR_BELOW_VALID              0x80                    /*Bad HouR Low/high bit (1=low) */
#define NCI_INTER_INVALID_MINUTE                0x100                   /* Bad MiNute */
#define NCI_INTER_MINUTE_BELOW_VALID            0x200                   /*Bad MiNute Low/high bit(1=low) */
#define NCI_INTER_INVALID_SECOND                0x400                   /* Bad SeCond */
#define NCI_INTER_SECOND_BELOW_VALID            0x800                   /*bad second Low/high bit(1=low) */
#define NCI_INTER_INVALID_FRACSEC               0x1000                  /* Bad Fractional second */
#define NCI_INTER_FRACSEC_BELOW_VALID           0x2000                  /* Bad fractional second Low/High */

/* --------------------END DateTime and Interval Constants ------------------*/

/*------------------------Parsing Syntax Types-------------------------------*/
#define NCI_V7_SYNTAX                           2                       /* V815 language - for backwards compatibility */
#define NCI_V8_SYNTAX                           3                       /* V815 language - for backwards compatibility */
#define NCI_NTV_SYNTAX                          1                       /* Use what so ever is the native lang of server */
/*---------------------------------------------------------------------------*/

/*------------------------Scrollable Cursor Fetch Options------------------- 
 * For non-scrollable cursor, the only valid (and default) orientation is 
 * NCI_FETCH_NEXT
 */
#define NCI_FETCH_CURRENT                       0x01                    /* refetching current position  */
#define NCI_FETCH_NEXT                          0x02                    /* next row */
#define NCI_FETCH_FIRST                         0x04                    /* first row of the result set */
#define NCI_FETCH_LAST                          0x08                    /* the last row of the result set */
#define NCI_FETCH_PRIOR                         0x10                    /* the previous row relative to current */
#define NCI_FETCH_ABSOLUTE                      0x20                    /* absolute offset from first */
#define NCI_FETCH_RELATIVE                      0x40                    /* offset relative to current */
#define NCI_FETCH_RESERVED_1                    0x80                    /* reserved */

/*---------------------------------------------------------------------------*/

/*------------------------Bind and Define Options----------------------------*/
#define NCI_SB2_IND_PTR                         0x00000001              /* unused */
#define NCI_DATA_AT_EXEC                        0x00000002              /* data at execute time */
#define NCI_DYNAMIC_FETCH                       0x00000002              /* fetch dynamically */
#define NCI_PIECEWISE                           0x00000004              /* piecewise DMLs or fetch */
#define NCI_DEFINE_RESERVED_1                   0x00000008              /* reserved */
#define NCI_BIND_RESERVED_2                     0x00000010              /* reserved */
#define NCI_DEFINE_RESERVED_2                   0x00000020              /* reserved */
#define NCI_BIND_SOFT                           0x00000040              /* soft bind or define */
#define NCI_DEFINE_SOFT                         0x00000080              /* soft bind or define */
#define NCI_IOV                                 0x00000200           /* For scatter gather bind/define */
/*---------------------------------------------------------------------------*/

/*-----------------------------  Various Modes ------------------------------*/
#define NCI_DEFAULT                             0x00000000              /* the default value for parameters and attributes */

/*-------------NCIInitialize Modes / NCICreateEnvironment Modes -------------*/
#define NCI_THREADED                            0x00000001              /* appl. in threaded environment */
#define NCI_OBJECT                              0x00000002              /* application in object environment */
#define NCI_EVENTS                              0x00000004              /* application is enabled for events */
#define NCI_RESERVED1                           0x00000008              /* reserved */
#define NCI_SHARED                              0x00000010              /* the application is in shared mode */
#define NCI_RESERVED2                           0x00000020              /* reserved */
/* The following *TWO* are only valid for NCICreateEnvironment call */
#define NCI_NO_UCB                              0x00000040              /* No user callback called during ini */
#define NCI_NO_MUTEX                            0x00000080              /* the environment handle will not be 
                                                                           protected by a mutex internally*/
#define NCI_SHARED_EXT                          0x00000100              /* Used for shared forms */
/************************** 0x00000200 free **********************************/
#define NCI_ALWAYS_BLOCKING                     0x00000400              /* all connections always blocking */
/************************** 0x00000800 free **********************************/
#define NCI_USE_LDAP                            0x00001000              /* allow  LDAP connections */
#define NCI_REG_LDAPONLY                        0x00002000              /* only register to LDAP */
#define NCI_UTF16                               0x00004000              /* mode for all UTF16 metadata */
#define NCI_AFC_PAD_ON                          0x00008000              /* turn on AFC blank padding when rlenp present */
#define NCI_ENVCR_RESERVED3                     0x00010000              /* reserved */
#define NCI_NEW_LENGTH_SEMANTICS                0x00020000              /* adopt new length semantics 
                                                                           the new length semantics, always bytes, is used by NCIEnvNlsCreate */
#define NCI_NO_MUTEX_STMT                       0x00040000              /* Do not mutex stmt handle */
#define NCI_MUTEX_ENV_ONLY                      0x00080000              /* Mutex only the environment handle */
#define NCI_NCHAR_LITERAL_REPLACE_ON            0x00400000              /* nchar literal replace on */
#define NCI_NCHAR_LITERAL_REPLACE_OFF           0x00800000              /* nchar literal replace off*/
#define NCI_STM_RESERVED4                       0x00100000              /* reserved */

/*---------------------------------------------------------------------------*/
/*------------------------NCIConnectionpoolCreate Modes----------------------*/

#define NCI_CPOOL_REINITIALIZE                  0x111

/*---------------------------------------------------------------------------*/
/*--------------------------------- NCILogon2 Modes -------------------------*/

#define NCI_LOGON2_SPOOL                        0x0001                  /* Use session pool */
#define NCI_LOGON2_CPOOL                        NCI_CPOOL               /* Use connection pool */
#define NCI_LOGON2_STMTCACHE                    0x0004                  /* Use Stmt Caching */
#define NCI_LOGON2_PROXY                        0x0008                  /* Proxy authentiaction */

/*---------------------------------------------------------------------------*/
/*------------------------- NCISessionPoolCreate Modes ----------------------*/

#define NCI_SPC_REINITIALIZE                    0x0001                  /* Reinitialize the session pool */
#define NCI_SPC_HOMOGENEOUS                     0x0002                  /* Session pool is homogeneneous */
#define NCI_SPC_STMTCACHE                       0x0004                  /* Session pool has stmt cache */
#define NCI_SPC_NO_RLB                          0x0008                  /* Do not enable Runtime load balancing. */ 

/*---------------------------------------------------------------------------*/
/*--------------------------- NCISessionGet Modes ---------------------------*/

#define NCI_SESSGET_SPOOL                       0x0001                  /* SessionGet called in SPOOL mode */
#define NCI_SESSGET_CPOOL                       NCI_CPOOL               /* SessionGet called in CPOOL mode */
#define NCI_SESSGET_STMTCACHE                   0x0004                  /* Use statement cache */
#define NCI_SESSGET_CREDPROXY                   0x0008                  /* SessionGet called in proxy mode */
#define NCI_SESSGET_CREDEXT                     0x0010
#define NCI_SESSGET_SPOOL_MATCHANY              0x0020
/*---------------------------------------------------------------------------*/
/*------------------------ATTR Values for Session Pool-----------------------*/
/* Attribute values for NCI_ATTR_SPOOL_GETMODE */
#define NCI_SPOOL_ATTRVAL_WAIT                  0                       /* block till you get a session */
#define NCI_SPOOL_ATTRVAL_NOWAIT                1                       /* error out if no session avaliable */
#define NCI_SPOOL_ATTRVAL_FORCEGET              2                       /* get session even if max is exceeded */

/*---------------------------------------------------------------------------*/
/*--------------------------- NCISessionRelease Modes -----------------------*/

#define NCI_SESSRLS_DROPSESS                    0x0001                  /* Drop the Session */
#define NCI_SESSRLS_RETAG                       0x0002                  /* Retag the session */

/*---------------------------------------------------------------------------*/
/*----------------------- NCISessionPoolDestroy Modes -----------------------*/

#define NCI_SPD_FORCE                           0x0001                  /* Force the sessions to terminate. 
                                                                           Even if there are some busy sessions close them */

/*---------------------------------------------------------------------------*/
/*----------------------------- Statement States ----------------------------*/

#define NCI_STMT_STATE_INITIALIZED              0x0001
#define NCI_STMT_STATE_EXECUTED                 0x0002
#define NCI_STMT_STATE_END_OF_FETCH             0x0003

/*---------------------------------------------------------------------------*/

/*----------------------------- NCIMemStats Modes ---------------------------*/
#define NCI_MEM_INIT                            0x01
#define NCI_MEM_CLN                             0x02
#define NCI_MEM_FLUSH                           0x04
#define NCI_DUMP_HEAP                           0x80

#define NCI_CLIENT_STATS                        0x10
#define NCI_SERVER_STATS                        0x20

/*----------------------------- NCIEnvInit Modes ----------------------------*/
/* NOTE: NO NEW MODES SHOULD BE ADDED HERE BECAUSE THE RECOMMENDED METHOD 
 * IS TO USE THE NEW NCICreateEnvironment MODES.
 */
#define NCI_ENV_NO_UCB                          0x01                    /* A user callback will not be called in NCIEnvInit() */
#define NCI_ENV_NO_MUTEX                        0x08                    /* the environment handle will not be protected by a mutex internally */

/*---------------------------------------------------------------------------*/

/*------------------------ Prepare Modes ------------------------------------*/
#define NCI_NO_SHARING                          0x01                    /* turn off statement handle sharing */
#define NCI_PREP_RESERVED_1                     0x02                    /* reserved */
#define NCI_PREP_AFC_PAD_ON                     0x04                    /* turn on blank padding for AFC */
#define NCI_PREP_AFC_PAD_OFF                    0x08                    /* turn off blank padding for AFC */
/*---------------------------------------------------------------------------*/

/*----------------------- Execution Modes -----------------------------------*/
#define NCI_BATCH_MODE                          0x01                    /* batch the nci statement for execution */
#define NCI_EXACT_FETCH                         0x02                    /* fetch the exact rows specified */
#define NCI_KEEP_FETCH_STATE                    0x04                    /* unused */
#define NCI_STMT_SCROLLABLE_READONLY            0x08                    /* if result set is scrollable */
#define NCI_DESCRIBE_ONLY                       0x10                    /* only describe the statement */
#define NCI_COMMIT_ON_SUCCESS                   0x20                    /* commit, if successful execution */
#define NCI_NON_BLOCKING                        0x40                    /* non-blocking */
#define NCI_BATCH_ERRORS                        0x80                    /* batch errors in array dmls */
#define NCI_PARSE_ONLY                          0x100                   /* only parse the statement */
#define NCI_EXACT_FETCH_RESERVED_1              0x200                   /* reserved */
#define NCI_SHOW_DML_WARNINGS                   0x400                   /* return NCI_SUCCESS_WITH_INFO for delete/update w/no where clause */
#define NCI_EXEC_RESERVED_2                     0x800                   /* reserved */
#define NCI_DESC_RESERVED_1                     0x1000                  /* reserved */
#define NCI_EXEC_RESERVED_3                     0x2000                  /* reserved */
#define NCI_EXEC_RESERVED_4                     0x4000                  /* reserved */

/*---------------------------------------------------------------------------*/

/*------------------------Authentication Modes-------------------------------*/
#define NCI_MIGRATE                             0x0001                  /* migratable auth context */
#define NCI_SYSDBA                              0x0002                  /* for SYSDBA authorization */
#define NCI_SYSOPER                             0x0004                  /* for SYSOPER authorization */
#define NCI_PRELIM_AUTH                         0x0008                  /* for preliminary authorization */
#define NCIP_ICACHE                             0x0010                  /* Private NCI cache mode to notify cache */
#define NCI_AUTH_RESERVED_1                     0x0020                  /* reserved */
#define NCI_STMT_CACHE                          0x0040                  /* enable NCI Stmt Caching */

/*---------------------------------------------------------------------------*/

/*------------------------Session End Modes----------------------------------*/
#define NCI_SESSEND_RESERVED_1                  0x0001                  /* reserved */
/*---------------------------------------------------------------------------*/

/*------------------------Attach Modes---------------------------------------*/
#define NCI_FASTPATH                            0x0010                  /* Attach in fast path mode */
#define NCI_ATCH_RESERVED_1                     0x0020                  /* reserved */
#define NCI_ATCH_RESERVED_2                     0x0080                  /* reserved */
#define NCI_ATCH_RESERVED_3                     0x0100                  /* reserved */
#define NCI_CPOOL                               0x0200                  /* Attach using server handle from pool */
#define NCI_ATCH_RESERVED_4                     0x0400                  /* reserved */

/*---------------------NCIStmtPrepare2 Modes---------------------------------*/
#define NCI_PREP2_CACHE_SEARCHONLY              0x0010                  /* ONly Search */
#define NCI_PREP2_GET_PLSQL_WARNINGS            0x0020                  /* Get PL/SQL warnings  */

/*---------------------NCIStmtRelease Modes----------------------------------*/
#define NCI_STRLS_CACHE_DELETE                  0x0010                  /* Delete from Cache */

/*-----------------------------End Various Modes ----------------------------*/

/*------------------------Piece Information----------------------------------*/
#define NCI_PARAM_IN                            0x01                    /* in parameter */
#define NCI_PARAM_OUT                           0x02                    /* out parameter */
/*---------------------------------------------------------------------------*/

/*------------------------ Transaction Start Flags --------------------------*/
/* NOTE: NCI_TRANS_JOIN and NCI_TRANS_NOMIGRATE not supported in 8.0.X       */
#define NCI_TRANS_NEW                           0x00000001              /* starts a new transaction branch */
#define NCI_TRANS_JOIN                          0x00000002              /* join an existing transaction */
#define NCI_TRANS_RESUME                        0x00000004              /* resume this transaction */
#define NCI_TRANS_STARTMASK                     0x000000ff
#define NCI_TRANS_READONLY                      0x00000100              /* starts a readonly transaction */
#define NCI_TRANS_READWRITE                     0x00000200              /* starts a read-write transaction */
#define NCI_TRANS_SERIALIZABLE                  0x00000400              /* starts a serializable transaction */
#define NCI_TRANS_ISOLMASK                      0x0000ff00
#define NCI_TRANS_LOOSE                         0x00010000              /* a loosely coupled branch */
#define NCI_TRANS_TIGHT                         0x00020000              /* a tightly coupled branch */
#define NCI_TRANS_TYPEMASK                      0x000f0000
#define NCI_TRANS_NOMIGRATE                     0x00100000              /* non migratable transaction */
#define NCI_TRANS_SEPARABLE                     0x00200000              /* separable transaction (8.1.6+) */

/*---------------------------------------------------------------------------*/

/*------------------------ Transaction End Flags ----------------------------*/
#define NCI_TRANS_TWOPHASE                      0x01000000              /* use two phase commit */
/*---------------------------------------------------------------------------*/

/*------------------------- AQ Constants ------------------------------------
 * NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE
 * The following constants must match the PL/SQL dbms_aq constants
 * NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE
 */
/* ------------------------- Visibility flags -------------------------------*/
#define NCI_ENQ_IMMEDIATE                       1                       /* enqueue is an independent transaction */
#define NCI_ENQ_ON_COMMIT                       2                       /* enqueue is part of current transaction */

/* ----------------------- Dequeue mode flags -------------------------------*/
#define NCI_DEQ_BROWSE                          1                       /* read message without acquiring a lock */
#define NCI_DEQ_LOCKED                          2                       /* read and obtain write lock on message */
#define NCI_DEQ_REMOVE                          3                       /* read the message and delete it */
#define NCI_DEQ_REMOVE_NODATA                   4                       /* delete message w'o returning payload */
#define NCI_DEQ_GETSIG                          5                       /* get signature only */

/* ----------------- Dequeue navigation flags -------------------------------*/
#define NCI_DEQ_FIRST_MSG                       1                       /* get first message at head of queue */
#define NCI_DEQ_NEXT_MSG                        3                       /* next message that is available */
#define NCI_DEQ_NEXT_TRANSACTION                2                       /* get first message of next txn group */
#define NCI_DEQ_MULT_TRANSACTION                5                       /* array dequeue across txn groups */

/* ----------------- Dequeue Option Reserved flags ------------------------- */
#define NCI_DEQ_RESERVED_1                      0x000001

/* --------------------- Message states -------------------------------------*/
#define NCI_MSG_WAITING                         1                       /* the message delay has not yet completed */
#define NCI_MSG_READY                           0                       /* the message is ready to be processed */
#define NCI_MSG_PROCESSED                       2                       /* the message has been processed */
#define NCI_MSG_EXPIRED                         3                       /* message has moved to exception queue */

/* --------------------- Sequence deviation ---------------------------------*/
#define NCI_ENQ_BEFORE                          2                       /* enqueue message before another message */
#define NCI_ENQ_TOP                             3                       /* enqueue message before all messages */

/* ------------------------- Visibility flags -------------------------------*/
#define NCI_DEQ_IMMEDIATE                       1                       /* dequeue is an independent transaction */
#define NCI_DEQ_ON_COMMIT                       2                       /* dequeue is part of current transaction */

/* ------------------------ Wait --------------------------------------------*/
#define NCI_DEQ_WAIT_FOREVER                    -1                      /* wait forever if no message available */
#define NCI_DEQ_NO_WAIT                         0                       /* do not wait if no message is available */

/* ------------------------ Delay -------------------------------------------*/
#define NCI_MSG_NO_DELAY                        0                       /* message is available immediately */

/* ------------------------- Expiration -------------------------------------*/
#define NCI_MSG_NO_EXPIRATION                   -1                      /* message will never expire */

/* ------------------------- Reserved ---------------------------------------*/
#define NCI_AQ_RESERVED_1                       0x0002
#define NCI_AQ_RESERVED_2                       0x0004
#define NCI_AQ_RESERVED_3                       0x0008

/* -------------------------- END AQ Constants ----------------------------- */

/*-----------------------Object Types----------------------------------------*/
/*-----------Object Types **** Not to be Used **** --------------------------*/
/* Deprecated */
#define NCI_OTYPE_UNK                           0
#define NCI_OTYPE_TABLE                         1
#define NCI_OTYPE_VIEW                          2
#define NCI_OTYPE_SYN                           3
#define NCI_OTYPE_PROC                          4
#define NCI_OTYPE_FUNC                          5
#define NCI_OTYPE_PKG                           6
#define NCI_OTYPE_STMT                          7
/*---------------------------------------------------------------------------*/

/*=======================Describe Handle Parameter Attributes ===============*/
/* 
   These attributes are orthogonal to the other set of attributes defined 
   above.  These attrubutes are tobe used only for the desscribe handle 
*/
/*===========================================================================*/
/* Attributes common to Columns and Stored Procs */
#define NCI_ATTR_DATA_SIZE                      1                       /* maximum size of the data */
#define NCI_ATTR_DATA_TYPE                      2                       /* the SQL type of the column/argument */
#define NCI_ATTR_DISP_SIZE                      3                       /* the display size */
#define NCI_ATTR_NAME                           4                       /* the name of the column/argument */
#define NCI_ATTR_PRECISION                      5                       /* precision if number type */
#define NCI_ATTR_SCALE                          6                       /* scale if number type */
#define NCI_ATTR_IS_NULL                        7                       /* is it null ? */
#define NCI_ATTR_TYPE_NAME                      8                       /* name of the named data type or a package name for package private types */
#define NCI_ATTR_SCHEMA_NAME                    9                       /* the schema name */
#define NCI_ATTR_SUB_NAME                       10                      /* type name if package private type */
#define NCI_ATTR_POSITION                       11                      /* relative position of col/arg in the list of cols/args */

/* complex object retrieval parameter attributes */
#define NCI_ATTR_COMPLEXOBJECTCOMP_TYPE         50
#define NCI_ATTR_COMPLEXOBJECTCOMP_TYPE_LEVEL   51
#define NCI_ATTR_COMPLEXOBJECT_LEVEL            52
#define NCI_ATTR_COMPLEXOBJECT_COLL_OUTOFLINE   53

/* Only Columns */
#define NCI_ATTR_DISP_NAME                      100                     /* the display name */
#define NCI_ATTR_ENCC_SIZE                      101                     /* encrypted data size */
#define NCI_ATTR_COL_ENC                        102                     /* column is encrypted ? */
#define NCI_ATTR_COL_ENC_SALT                   103                     /* is encrypted column salted ? */

/*Only Stored Procs */
#define NCI_ATTR_OVERLOAD                       210                     /* is this position overloaded */
#define NCI_ATTR_LEVEL                          211                     /* level for structured types */
#define NCI_ATTR_HAS_DEFAULT                    212                     /* has a default value */
#define NCI_ATTR_IOMODE                         213                     /* in, out inout */
#define NCI_ATTR_RADIX                          214                     /* returns a radix */
#define NCI_ATTR_NUM_ARGS                       215                     /* total number of arguments */

/* only named type attributes */
#define NCI_ATTR_TYPECODE                       216                     /* object or collection */
#define NCI_ATTR_COLLECTION_TYPECODE            217                     /* varray or nested table */
#define NCI_ATTR_VERSION                        218                     /* user assigned version */
#define NCI_ATTR_IS_INCOMPLETE_TYPE             219                     /* is this an incomplete type */
#define NCI_ATTR_IS_SYSTEM_TYPE                 220                     /* a system type */
#define NCI_ATTR_IS_PREDEFINED_TYPE             221                     /* a predefined type */
#define NCI_ATTR_IS_TRANSIENT_TYPE              222                     /* a transient type */
#define NCI_ATTR_IS_SYSTEM_GENERATED_TYPE       223                     /* system generated type */
#define NCI_ATTR_HAS_NESTED_TABLE               224                     /* contains nested table attr */
#define NCI_ATTR_HAS_LOB                        225                     /* has a lob attribute */
#define NCI_ATTR_HAS_FILE                       226                     /* has a file attribute */
#define NCI_ATTR_COLLECTION_ELEMENT             227                     /* has a collection attribute */
#define NCI_ATTR_NUM_TYPE_ATTRS                 228                     /* number of attribute types */
#define NCI_ATTR_LIST_TYPE_ATTRS                229                     /* list of type attributes */
#define NCI_ATTR_NUM_TYPE_METHODS               230                     /* number of type methods */
#define NCI_ATTR_LIST_TYPE_METHODS              231                     /* list of type methods */
#define NCI_ATTR_MAP_METHOD                     232                     /* map method of type */
#define NCI_ATTR_ORDER_METHOD                   233                     /* order method of type */

/* only collection element */
#define NCI_ATTR_NUM_ELEMS                      234                     /* number of elements */

/* only type methods */
#define NCI_ATTR_ENCAPSULATION                  235                     /* encapsulation level */
#define NCI_ATTR_IS_SELFISH                     236                     /* method selfish */
#define NCI_ATTR_IS_VIRTUAL                     237                     /* virtual */
#define NCI_ATTR_IS_INLINE                      238                     /* inline */
#define NCI_ATTR_IS_CONSTANT                    239                     /* constant */
#define NCI_ATTR_HAS_RESULT                     240                     /* has result */
#define NCI_ATTR_IS_CONSTRUCTOR                 241                     /* constructor */
#define NCI_ATTR_IS_DESTRUCTOR                  242                     /* destructor */
#define NCI_ATTR_IS_OPERATOR                    243                     /* operator */
#define NCI_ATTR_IS_MAP                         244                     /* a map method */
#define NCI_ATTR_IS_ORDER                       245                     /* order method */
#define NCI_ATTR_IS_RNDS                        246                     /* read no data state method */
#define NCI_ATTR_IS_RNPS                        247                     /* read no process state */
#define NCI_ATTR_IS_WNDS                        248                     /* write no data state method */
#define NCI_ATTR_IS_WNPS                        249                     /* write no process state */
#define NCI_ATTR_DESC_PUBLIC                    250                     /* public object */

/* Object Cache Enhancements : attributes for User Constructed Instances     */
#define NCI_ATTR_CACHE_CLIENT_CONTEXT           251
#define NCI_ATTR_UCI_CONSTRUCT                  252
#define NCI_ATTR_UCI_DESTRUCT                   253
#define NCI_ATTR_UCI_COPY                       254
#define NCI_ATTR_UCI_PICKLE                     255
#define NCI_ATTR_UCI_UNPICKLE                   256
#define NCI_ATTR_UCI_REFRESH                    257

/* for type inheritance */
#define NCI_ATTR_IS_SUBTYPE                     258
#define NCI_ATTR_SUPERTYPE_SCHEMA_NAME          259
#define NCI_ATTR_SUPERTYPE_NAME                 260

/* for schemas */
#define NCI_ATTR_LIST_OBJECTS                   261                     /* list of objects in schema */

/* for database */
#define NCI_ATTR_NCHARSET_ID                    262                     /* char set id */
#define NCI_ATTR_LIST_SCHEMAS                   263                     /* list of schemas */
#define NCI_ATTR_MAX_PROC_LEN                   264                     /* max procedure length */
#define NCI_ATTR_MAX_COLUMN_LEN                 265                     /* max column name length */
#define NCI_ATTR_CURSOR_COMMIT_BEHAVIOR         266                     /* cursor commit behavior */
#define NCI_ATTR_MAX_CATALOG_NAMELEN            267                     /* catalog namelength */
#define NCI_ATTR_CATALOG_LOCATION               268                     /* catalog location */
#define NCI_ATTR_SAVEPOINT_SUPPORT              269                     /* savepoint support */
#define NCI_ATTR_NOWAIT_SUPPORT                 270                     /* nowait support */
#define NCI_ATTR_AUTOCOMMIT_DDL                 271                     /* autocommit DDL */
#define NCI_ATTR_LOCKING_MODE                   272                     /* locking mode */

/* for externally initialized context */
#define NCI_ATTR_APPCTX_SIZE                    273                     /* count of context to be init*/
#define NCI_ATTR_APPCTX_LIST                    274                     /* count of context to be init*/
#define NCI_ATTR_APPCTX_NAME                    275                     /* name  of context to be init*/
#define NCI_ATTR_APPCTX_ATTR                    276                     /* attr  of context to be init*/
#define NCI_ATTR_APPCTX_VALUE                   277                     /* value of context to be init*/

/* for client id propagation */
#define NCI_ATTR_CLIENT_IDENTIFIER              278                     /* value of client id to set*/

/* for inheritance - part 2 */
#define NCI_ATTR_IS_FINAL_TYPE                  279                     /* is final type ? */
#define NCI_ATTR_IS_INSTANTIABLE_TYPE           280                     /* is instantiable type ? */
#define NCI_ATTR_IS_FINAL_METHOD                281                     /* is final method ? */
#define NCI_ATTR_IS_INSTANTIABLE_METHOD         282                     /* is instantiable method ? */
#define NCI_ATTR_IS_OVERRIDING_METHOD           283                     /* is overriding method ? */

/* slot 284 available */

#define NCI_ATTR_CHAR_USED                      285                     /* char length semantics */
#define NCI_ATTR_CHAR_SIZE                      286                     /* char length */

/* SQLJ support */
#define NCI_ATTR_IS_JAVA_TYPE                   287                     /* is java implemented type ? */

/* N-Tier support */
#define NCI_ATTR_DISTINGUISHED_NAME             300                     /* use DN as user name */
#define NCI_ATTR_KERBEROS_TICKET                301                     /* Kerberos ticket as cred. */

/* for multilanguage debugging */
#define NCI_ATTR_ORA_DEBUG_JDWP                 302                     /* ORA_DEBUG_JDWP attribute */
#define NCI_ATTR_RESERVED_14                    303                     /* reserved */

/* TDE attributes on the Table */
#define NCI_ATTR_TABLE_ENC                      417                     /* does table have any encrypt columns */
#define NCI_ATTR_TABLE_ENC_ALG                  418                     /* Table encryption Algorithm */
#define NCI_ATTR_TABLE_ENC_ALG_ID               419                     /* Internal Id of encryption Algorithm*/

/*---------------------------End Describe Handle Attributes -----------------*/

/*------------- Supported Values for Direct Path Date cache -----------------*/
#define NCI_ATTR_DIRPATH_DCACHE_NUM             303                     /* date cache entries */
#define NCI_ATTR_DIRPATH_DCACHE_SIZE            304                     /* date cache limit */
#define NCI_ATTR_DIRPATH_DCACHE_MISSES          305                     /* date cache misses */
#define NCI_ATTR_DIRPATH_DCACHE_HITS            306                     /* date cache hits */
#define NCI_ATTR_DIRPATH_DCACHE_DISABLE         307                     /* on set: disable datecache 
                                                                         * on overflow.
                                                                         * on get: datecache disabled? 
                                                                         * could be due to overflow
                                                                         * or others                  */

/* ----------------------- Session Pool Attributes ------------------------- */
#define NCI_ATTR_SPOOL_TIMEOUT                  308                     /* session timeout */
#define NCI_ATTR_SPOOL_GETMODE                  309                     /* session get mode */
#define NCI_ATTR_SPOOL_BUSY_COUNT               310                     /* busy session count */
#define NCI_ATTR_SPOOL_OPEN_COUNT               311                     /* open session count */
#define NCI_ATTR_SPOOL_MIN                      312                     /* min session count */
#define NCI_ATTR_SPOOL_MAX                      313                     /* max session count */
#define NCI_ATTR_SPOOL_INCR                     314                     /* session increment count */
#define NCI_ATTR_SPOOL_STMTCACHESIZE            208                     /*Stmt cache size of pool  */
/*------------------------------End Session Pool Attributes -----------------*/
/*---------------------------- For XML Types ------------------------------- */
/* For table, view and column */
#define NCI_ATTR_IS_XMLTYPE                     315                     /* Is the type an XML type? */
#define NCI_ATTR_XMLSCHEMA_NAME                 316                     /* Name of XML Schema */
#define NCI_ATTR_XMLELEMENT_NAME                317                     /* Name of XML Element */
#define NCI_ATTR_XMLSQLTYPSCH_NAME              318                     /* SQL type's schema for XML Ele */
#define NCI_ATTR_XMLSQLTYPE_NAME                319                     /* Name of SQL type for XML Ele */
#define NCI_ATTR_XMLTYPE_STORED_OBJ             320                     /* XML type stored as object? */

/*---------------------------- For Subtypes ------------------------------- */
/* For type */
#define NCI_ATTR_HAS_SUBTYPES                   321                     /* Has subtypes? */
#define NCI_ATTR_NUM_SUBTYPES                   322                     /* Number of subtypes */
#define NCI_ATTR_LIST_SUBTYPES                  323                     /* List of subtypes */

/* XML flag */
#define NCI_ATTR_XML_HRCHY_ENABLED              324                     /* hierarchy enabled? */

/* Method flag */
#define NCI_ATTR_IS_OVERRIDDEN_METHOD           325                     /* Method is overridden? */

/*------------- Attributes for 10i Updates to the DirPath API ---------------*/
#define NCI_ATTR_DIRPATH_RESERVED_7             326                     /* reserved */
#define NCI_ATTR_DIRPATH_RESERVED_8             327                     /* reserved */
#define NCI_ATTR_DIRPATH_CONVERT                328                     /* stream conversion needed? */
#define NCI_ATTR_DIRPATH_BADROW                 329                     /* info about bad row */
#define NCI_ATTR_DIRPATH_BADROW_LENGTH          330                     /* length of bad row info */
#define NCI_ATTR_DIRPATH_WRITE_ORDER            331                     /* column fill order */
#define NCI_ATTR_DIRPATH_GRANULE_SIZE           332                     /* granule size for unload */
#define NCI_ATTR_DIRPATH_GRANULE_OFFSET         333                     /* offset to last granule */
#define NCI_ATTR_DIRPATH_RESERVED_1             334                     /* reserved */
#define NCI_ATTR_DIRPATH_RESERVED_2             335                     /* reserved */

/*------------- Attributes for 10i Distributed Objects ----------------------*/
#define NCI_ATTR_OBJ_SUBS                       336                     /* obj col/tab substitutable */

/*------ Attributes for 10i DirPathAPI conversion (NLS lang, terr, cs) ------*/
#define NCI_ATTR_DIRPATH_RESERVED_3             337                     /* reserved */
#define NCI_ATTR_DIRPATH_RESERVED_4             338                     /* reserved */

/*---------- Attributes for 10i XADFIELD (NLS language, territory -----------*/
#define NCI_ATTR_XADFIELD_RESERVED_1            339                     /* reserved */
#define NCI_ATTR_XADFIELD_RESERVED_2            340                     /* reserved */

/*------------- Kerberos Secure Client Identifier ---------------------------*/
#define NCI_ATTR_KERBEROS_CID                   341                     /* Kerberos db service ticket*/

/*------------------------ Attributes for Rules objects ---------------------*/
#define NCI_ATTR_CONDITION                      342                     /* rule condition */
#define NCI_ATTR_COMMENT                        343                     /* comment */
#define NCI_ATTR_VALUE                          344                     /* Anydata value */
#define NCI_ATTR_EVAL_CONTEXT_OWNER             345                     /* eval context owner */
#define NCI_ATTR_EVAL_CONTEXT_NAME              346                     /* eval context name */
#define NCI_ATTR_EVALUATION_FUNCTION            347                     /* eval function name */
#define NCI_ATTR_VAR_TYPE                       348                     /* variable type */
#define NCI_ATTR_VAR_VALUE_FUNCTION             349                     /* variable value function */
#define NCI_ATTR_VAR_METHOD_FUNCTION            350                     /* variable method function */
#define NCI_ATTR_ACTION_CONTEXT                 351                     /* action context */
#define NCI_ATTR_LIST_TABLE_ALIASES             352                     /* list of table aliases */
#define NCI_ATTR_LIST_VARIABLE_TYPES            353                     /* list of variable types */
#define NCI_ATTR_TABLE_NAME                     356                     /* table name */
#define NCI_ATTR_DIRPATH_RESERVED_5             357                     /* reserved */
#define NCI_ATTR_DIRPATH_RESERVED_6             358                     /* reserved */
#define NCI_ATTR_DIRPATH_LOCK_WAIT              359                     /* wait for lock in dpapi */
#define NCI_ATTR_MESSAGE_CSCN                   360                     /* message cscn */
#define NCI_ATTR_MESSAGE_DSCN                   361                     /* message dscn */

/*--------------------- Audit Session ID ------------------------------------*/
#define NCI_ATTR_AUDIT_SESSION_ID               362                     /* Audit session ID */

/*--------------------- Kerberos TGT Keys -----------------------------------*/
#define NCI_ATTR_KERBEROS_KEY                   363                     /* n-tier Kerberos cred key */
#define NCI_ATTR_KERBEROS_CID_KEY               364                     /* SCID Kerberos cred key */
#define NCI_ATTR_TRANSACTION_NO                 365                     /* AQ enq txn number */

/*----------------------- Attributes for End To End Tracing -----------------*/
#define NCI_ATTR_MODULE                         366                     /* module for tracing */
#define NCI_ATTR_ACTION                         367                     /* action for tracing */
#define NCI_ATTR_CLIENT_INFO                    368                     /* client info */
#define NCI_ATTR_COLLECT_CALL_TIME              369                     /* collect call time */
#define NCI_ATTR_CALL_TIME                      370                     /* extract call time */
#define NCI_ATTR_ECONTEXT_ID                    371                     /* execution-id context */
#define NCI_ATTR_ECONTEXT_SEQ                   372                     /*execution-id sequence num */

/*---------------- Describe Handle Parameter Attribute Values ---------------*/

/* NCI_ATTR_CURSOR_COMMIT_BEHAVIOR */
#define NCI_CURSOR_OPEN                         0
#define NCI_CURSOR_CLOSED                       1

/* NCI_ATTR_CATALOG_LOCATION */
#define NCI_CL_START                            0
#define NCI_CL_END                              1

/* NCI_ATTR_SAVEPOINT_SUPPORT */
#define NCI_SP_SUPPORTED                        0
#define NCI_SP_UNSUPPORTED                      1

/* NCI_ATTR_NOWAIT_SUPPORT */
#define NCI_NW_SUPPORTED                        0
#define NCI_NW_UNSUPPORTED                      1

/* NCI_ATTR_AUTOCOMMIT_DDL */
#define NCI_AC_DDL                              0
#define NCI_NO_AC_DDL                           1

/* NCI_ATTR_LOCKING_MODE */
#define NCI_LOCK_IMMEDIATE                      0
#define NCI_LOCK_DELAYED                        1

/* ------------------- Instance type attribute values -----------------------*/
#define NCI_INSTANCE_TYPE_UNKNOWN               0
#define NCI_INSTANCE_TYPE_RDBMS                 1
#define NCI_INSTANCE_TYPE_OSM                   2

/*---------------------------------------------------------------------------*/

/*---------------------------NCIPasswordChange-------------------------------*/
#define NCI_AUTH                                0x08                    /* Change the password but do not login */

/*------------------------Other Constants------------------------------------*/
#define NCI_MAX_FNS                             100                     /* max number of NCI Functions */
#define NCI_SQLSTATE_SIZE                       5
#define NCI_ERROR_MAXMSG_SIZE                   1024                    /* max size of an error message */
#define NCI_LOBMAXSIZE                          MINUB4MAXVAL            /* maximum lob data size */
#define NCI_ROWID_LEN                           23
/*---------------------------------------------------------------------------*/

/*------------------------ Fail Over Events ---------------------------------*/
#define NCI_FO_END                              0x00000001
#define NCI_FO_ABORT                            0x00000002
#define NCI_FO_REAUTH                           0x00000004
#define NCI_FO_BEGIN                            0x00000008
#define NCI_FO_ERROR                            0x00000010
/*---------------------------------------------------------------------------*/

/*------------------------ Fail Over Callback Return Codes ------------------*/
#define NCI_FO_RETRY                            25410
/*---------------------------------------------------------------------------*/

/*------------------------- Fail Over Types ---------------------------------*/
#define NCI_FO_NONE                             0x00000001
#define NCI_FO_SESSION                          0x00000002
#define NCI_FO_SELECT                           0x00000004
#define NCI_FO_TXNAL                            0x00000008
/*---------------------------------------------------------------------------*/

/*-----------------------Function Codes--------------------------------------*/
#define NCI_FNCODE_INITIALIZE                   1                       /* NCIInitialize */
#define NCI_FNCODE_HANDLEALLOC                  2                       /* NCIHandleAlloc */
#define NCI_FNCODE_HANDLEFREE                   3                       /* NCIHandleFree */
#define NCI_FNCODE_DESCRIPTORALLOC              4                       /* NCIDescriptorAlloc */
#define NCI_FNCODE_DESCRIPTORFREE               5                       /* NCIDescriptorFree */
#define NCI_FNCODE_ENVINIT                      6                       /* NCIEnvInit */
#define NCI_FNCODE_SERVERATTACH                 7                       /* NCIServerAttach */
#define NCI_FNCODE_SERVERDETACH                 8                       /* NCIServerDetach */
/* unused         9 */ 
#define NCI_FNCODE_SESSIONBEGIN                 10                      /* NCISessionBegin */
#define NCI_FNCODE_SESSIONEND                   11                      /* NCISessionEnd */
#define NCI_FNCODE_PASSWORDCHANGE               12                      /* NCIPasswordChange */
#define NCI_FNCODE_STMTPREPARE                  13                      /* NCIStmtPrepare */
/* unused       14- 16 */
#define NCI_FNCODE_BINDDYNAMIC                  17                      /* NCIBindDynamic */
#define NCI_FNCODE_BINDOBJECT                   18                      /* NCIBindObject */
/* 19 unused */
#define NCI_FNCODE_BINDARRAYOFSTRUCT            20                      /* NCIBindArrayOfStruct */
#define NCI_FNCODE_STMTEXECUTE                  21                      /* NCIStmtExecute */
/* unused 22-24 */
#define NCI_FNCODE_DEFINEOBJECT                 25                      /* NCIDefineObject */
#define NCI_FNCODE_DEFINEDYNAMIC                26                      /* NCIDefineDynamic */
#define NCI_FNCODE_DEFINEARRAYOFSTRUCT          27                      /* NCIDefineArrayOfStruct */
#define NCI_FNCODE_STMTFETCH                    28                      /* NCIStmtFetch */
#define NCI_FNCODE_STMTGETBIND                  29                      /* NCIStmtGetBindInfo */
/* 30, 31 unused */
#define NCI_FNCODE_DESCRIBEANY                  32                      /* NCIDescribeAny */
#define NCI_FNCODE_TRANSSTART                   33                      /* NCITransStart */
#define NCI_FNCODE_TRANSDETACH                  34                      /* NCITransDetach */
#define NCI_FNCODE_TRANSCOMMIT                  35                      /* NCITransCommit */
/* 36 unused */
#define NCI_FNCODE_ERRORGET                     37                      /* NCIErrorGet */
#define NCI_FNCODE_LOBOPENFILE                  38                      /* NCILobFileOpen */
#define NCI_FNCODE_LOBCLOSEFILE                 39                      /* NCILobFileClose */
/* 40 was LOBCREATEFILE, unused */
/* 41 was NCILobFileDelete, unused  */
#define NCI_FNCODE_LOBCOPY                      42                      /* NCILobCopy */
#define NCI_FNCODE_LOBAPPEND                    43                      /* NCILobAppend */
#define NCI_FNCODE_LOBERASE                     44                      /* NCILobErase */
#define NCI_FNCODE_LOBLENGTH                    45                      /* NCILobGetLength */
#define NCI_FNCODE_LOBTRIM                      46                      /* NCILobTrim */
#define NCI_FNCODE_LOBREAD                      47                      /* NCILobRead */
#define NCI_FNCODE_LOBWRITE                     48                      /* NCILobWrite */
/* 49 unused */
#define NCI_FNCODE_SVCCTXBREAK                  50                      /* NCIBreak */
#define NCI_FNCODE_SERVERVERSION                51                      /* NCIServerVersion */
#define NCI_FNCODE_KERBATTRSET                  52                      /* NCIKerbAttrSet */
/* unused 53 */
#define NCI_FNCODE_ATTRGET                      54                      /* NCIAttrGet */
#define NCI_FNCODE_ATTRSET                      55                      /* NCIAttrSet */
#define NCI_FNCODE_PARAMSET                     56                      /* NCIParamSet */
#define NCI_FNCODE_PARAMGET                     57                      /* NCIParamGet */
#define NCI_FNCODE_STMTGETPIECEINFO             58                      /* NCIStmtGetPieceInfo */
#define NCI_FNCODE_LDATOSVCCTX                  59                      /* NCILdaToSvcCtx */
/* 60 unused */
#define NCI_FNCODE_STMTSETPIECEINFO             61                      /* NCIStmtSetPieceInfo */
#define NCI_FNCODE_TRANSFORGET                  62                      /* NCITransForget */
#define NCI_FNCODE_TRANSPREPARE                 63                      /* NCITransPrepare */
#define NCI_FNCODE_TRANSROLLBACK                64                      /* NCITransRollback */
#define NCI_FNCODE_DEFINEBYPOS                  65                      /* NCIDefineByPos */
#define NCI_FNCODE_BINDBYPOS                    66                      /* NCIBindByPos */
#define NCI_FNCODE_BINDBYNAME                   67                      /* NCIBindByName */
#define NCI_FNCODE_LOBASSIGN                    68                      /* NCILobAssign */
#define NCI_FNCODE_LOBISEQUAL                   69                      /* NCILobIsEqual */
#define NCI_FNCODE_LOBISINIT                    70                      /* NCILobLocatorIsInit */
#define NCI_FNCODE_LOBENABLEBUFFERING           71                      /* NCILobEnableBuffering */
#define NCI_FNCODE_LOBCHARSETID                 72                      /* NCILobCharSetID */
#define NCI_FNCODE_LOBCHARSETFORM               73                      /* NCILobCharSetForm */
#define NCI_FNCODE_LOBFILESETNAME               74                      /* NCILobFileSetName */
#define NCI_FNCODE_LOBFILEGETNAME               75                      /* NCILobFileGetName */
#define NCI_FNCODE_LOGON                        76                      /* NCILogon */
#define NCI_FNCODE_LOGOFF                       77                      /* NCILogoff */
#define NCI_FNCODE_LOBDISABLEBUFFERING          78                      /* NCILobDisableBuffering */
#define NCI_FNCODE_LOBFLUSHBUFFER               79                      /* NCILobFlushBuffer */
#define NCI_FNCODE_LOBLOADFROMFILE              80                      /* NCILobLoadFromFile */
#define NCI_FNCODE_LOBOPEN                      81                      /* NCILobOpen */
#define NCI_FNCODE_LOBCLOSE                     82                      /* NCILobClose */
#define NCI_FNCODE_LOBISOPEN                    83                      /* NCILobIsOpen */
#define NCI_FNCODE_LOBFILEISOPEN                84                      /* NCILobFileIsOpen */
#define NCI_FNCODE_LOBFILEEXISTS                85                      /* NCILobFileExists */
#define NCI_FNCODE_LOBFILECLOSEALL              86                      /* NCILobFileCloseAll */
#define NCI_FNCODE_LOBCREATETEMP                87                      /* NCILobCreateTemporary */
#define NCI_FNCODE_LOBFREETEMP                  88                      /* NCILobFreeTemporary */
#define NCI_FNCODE_LOBISTEMP                    89                      /* NCILobIsTemporary */
#define NCI_FNCODE_AQENQ                        90                      /* NCIAQEnq */
#define NCI_FNCODE_AQDEQ                        91                      /* NCIAQDeq */
#define NCI_FNCODE_RESET                        92                      /* NCIReset */
#define NCI_FNCODE_SVCCTXTOLDA                  93                      /* NCISvcCtxToLda */
#define NCI_FNCODE_LOBLOCATORASSIGN             94                      /* NCILobLocatorAssign */
#define NCI_FNCODE_UBINDBYNAME                  95
#define NCI_FNCODE_AQLISTEN                     96                      /* NCIAQListen */
#define NCI_FNCODE_SVC2HST                      97                      /* reserved */
#define NCI_FNCODE_SVCRH                        98                      /* reserved */
#define NCI_FNCODE_TRANSMULTIPREPARE            99                      /* NCITransMultiPrepare */
#define NCI_FNCODE_CPOOLCREATE                  100                     /* NCIConnectionPoolCreate */
#define NCI_FNCODE_CPOOLDESTROY                 101                     /* NCIConnectionPoolDestroy */
#define NCI_FNCODE_LOGON2                       102                     /* NCILogon2 */
#define NCI_FNCODE_ROWIDTOCHAR                  103                     /* NCIRowidToChar */
#define NCI_FNCODE_SPOOLCREATE                  104                     /* NCISessionPoolCreate */
#define NCI_FNCODE_SPOOLDESTROY                 105                     /* NCISessionPoolDestroy */
#define NCI_FNCODE_SESSIONGET                   106                     /* NCISessionGet */
#define NCI_FNCODE_SESSIONRELEASE               107                     /* NCISessionRelease */
#define NCI_FNCODE_STMTPREPARE2                 108                     /* NCIStmtPrepare2 */
#define NCI_FNCODE_STMTRELEASE                  109                     /* NCIStmtRelease */
#define NCI_FNCODE_AQENQARRAY                   110                     /* NCIAQEnqArray */
#define NCI_FNCODE_AQDEQARRAY                   111                     /* NCIAQDeqArray */
#define NCI_FNCODE_LOBCOPY2                     112                     /* NCILobCopy2 */
#define NCI_FNCODE_LOBERASE2                    113                     /* NCILobErase2 */
#define NCI_FNCODE_LOBLENGTH2                   114                     /* NCILobGetLength2 */
#define NCI_FNCODE_LOBLOADFROMFILE2             115                     /* NCILobLoadFromFile2 */
#define NCI_FNCODE_LOBREAD2                     116                     /* NCILobRead2 */
#define NCI_FNCODE_LOBTRIM2                     117                     /* NCILobTrim2 */
#define NCI_FNCODE_LOBWRITE2                    118                     /* NCILobWrite2 */
#define NCI_FNCODE_LOBGETSTORAGELIMIT           119                     /* NCILobGetStorageLimit */
#define NCI_FNCODE_MAXFCN                       119                     /* maximum NCI function code */
/*---------------------------------------------------------------------------*/

/*-----------------------Handle Definitions----------------------------------*/
typedef struct NCIEnv           NCIEnv;            /* NCI environment handle */
typedef struct NCIError         NCIError;                /* NCI error handle */
typedef struct NCISvcCtx        NCISvcCtx;             /* NCI service handle */
typedef struct NCIStmt          NCIStmt;             /* NCI statement handle */
typedef struct NCIBind          NCIBind;                  /* NCI bind handle */
typedef struct NCIDefine        NCIDefine;              /* NCI Define handle */
typedef struct NCIDescribe      NCIDescribe;          /* NCI Describe handle */
typedef struct NCIServer        NCIServer;              /* NCI Server handle */
typedef struct NCISession       NCISession;     /* NCI Authentication handle */
typedef struct NCIComplexObject NCIComplexObject;          /* NCI COR handle */
typedef struct NCITrans         NCITrans;          /* NCI Transaction handle */
typedef struct NCISecurity      NCISecurity;          /* NCI Security handle */
typedef struct NCISubscription  NCISubscription;      /* subscription handle */

typedef struct NCICPool         NCICPool;          /* connection pool handle */
typedef struct NCISPool         NCISPool;             /* session pool handle */
typedef struct NCIAuthInfo      NCIAuthInfo;                  /* auth handle */
typedef struct NCIThreadMutex   NCIThreadMutex;
typedef struct NCIAdmin         NCIAdmin;

/* NCIThread Key for Thread-Specific Data */
typedef struct NCIThreadKey     NCIThreadKey;
typedef struct NCIThreadHandle  NCIThreadHandle;

/* NCIThread Thread ID */
typedef struct NCIThreadId      NCIThreadId;

typedef void (*NCIThreadKeyDestFunc)(void*);

/*-----------------------Descriptor Definitions------------------------------*/
typedef struct NCISnapshot          NCISnapshot;            /* NCI snapshot descriptor */
typedef struct NCIResult            NCIResult;              /* NCI Result Set Descriptor */
typedef struct NCILobLocator        NCILobLocator;          /* NCI Lob Locator descriptor */
typedef struct NCIParam             NCIParam;               /* NCI PARameter descriptor */

/* NCI COR descriptor */
typedef struct NCIComplexObjectComp NCIComplexObjectComp;   /* NCI COR descriptor */

typedef struct NCIRowid             NCIRowid;               /* NCI ROWID descriptor */

typedef struct NCIDateTime          NCIDateTime;            /* NCI DateTime descriptor */
typedef struct NCIInterval          NCIInterval;            /* NCI Interval descriptor */

typedef struct NCIUcb               NCIUcb;                 /* NCI User Callback descriptor */
typedef struct NCIServerDNs         NCIServerDNs;           /* NCI server DN descriptor */

typedef struct NCIRaw               NCIRaw;
typedef struct NCIString            NCIString; 

/*
 * NCIType - NCI Type Description Object 
 *
 * The contents of an 'NCIType' is private/opaque to clients.  Clients just 
 * need to declare and pass 'NCIType' pointers in to the type manage
 * functions.
 * The pointer points to the type in the object cache.  Thus, clients don't
 * need to allocate space for this type and must NEVER free the pointer to the
 * 'NCIType'.
 */

typedef struct NCIType              NCIType;

/* NCIColl - generic collection type */
typedef struct NCIColl              NCIColl;
typedef NCIColl                     NCITable;

/* NCIIter - collection iterator */
typedef struct NCIIter              NCIIter;

struct NCIIOV
{
    void     *bfp;                            /* The Pointer to the data buffer */
    ub4       bfl;                                 /* Length of the Data Buffer */
};
typedef struct NCIIOV NCIIOV;

enum NCIObjectLifetime
{
    /* 0 = uninitialized */
    NCI_OBJECT_PERSISTENT = 1,                          /* persistent object */
    NCI_OBJECT_TRANSIENT,                               /* transient object */
    NCI_OBJECT_VALUE                                    /* value object */
};
typedef enum NCIObjectLifetime NCIObjectLifetime;

enum NCIPinOpt
{
    /* 0 = uninitialized */
    NCI_PIN_DEFAULT = 1,                    /* default pin option */
    NCI_PIN_ANY     = 3,                    /* pin any copy of the object */
    NCI_PIN_RECENT  = 4,                    /* pin recent copy of the object */
    NCI_PIN_LATEST  = 5                     /* pin latest copy of the object */
};
typedef enum NCIPinOpt  NCIPinOpt;

/* The NCITypeCode type is interchangeable with the existing SQLT type
   which is a ub2 */
typedef ub2            NCITypeCode;

/*----------------------- GET OPTIONS FOR TDO  ------------------------------*/
enum NCITypeGetOpt
{
    NCI_TYPEGET_HEADER,
    /* load only the header portion of the TDO when getting type */
    NCI_TYPEGET_ALL       /* load all attribute and method descriptors as well */
};
typedef enum NCITypeGetOpt  NCITypeGetOpt;

typedef ub1                NCIObjectPropId;
#define NCI_OBJECTPROP_LIFETIME 1       /* persistent or transient or value */
#define NCI_OBJECTPROP_SCHEMA 2         /* schema name of table containing object */
#define NCI_OBJECTPROP_TABLE 3          /* table name of table containing object */
#define NCI_OBJECTPROP_PIN_DURATION 4   /* pin duartion of object */
#define NCI_OBJECTPROP_ALLOC_DURATION 5 /* alloc duartion of object */
#define NCI_OBJECTPROP_LOCK 6           /* lock status of object */
#define NCI_OBJECTPROP_MARKSTATUS 7     /* mark status of object */
#define NCI_OBJECTPROP_VIEW 8           /* is object a view object or not? */

/*------------------------- OBJECT REFERENCE (REF) --------------------------*/
typedef struct NCIRef       NCIRef;

/*-------------------------- AQ Descriptors ---------------------------------*/
typedef struct NCIAQEnqOptions      NCIAQEnqOptions; /* AQ Enqueue Options hdl */
typedef struct NCIAQDeqOptions      NCIAQDeqOptions; /* AQ Dequeue Options hdl */
typedef struct NCIAQMsgProperties   NCIAQMsgProperties;  /* AQ Mesg Properties */
typedef struct NCIAQAgent           NCIAQAgent;         /* AQ Agent descriptor */
typedef struct NCIAQNfyDescriptor   NCIAQNfyDescriptor;   /* AQ Nfy descriptor */
typedef struct NCIAQSignature       NCIAQSignature;            /* AQ Siganture */
/*---------------------------------------------------------------------------*/

/* Lob typedefs for Pro*C */
typedef struct NCILobLocator        NCIClobLocator;    /* NCI Character LOB Locator */
typedef struct NCILobLocator        NCIBlobLocator;       /* NCI Binary LOB Locator */
typedef struct NCILobLocator        NCIBFileLocator; /* NCI Binary LOB File Locator */
/*---------------------------------------------------------------------------*/

/* Undefined value for tz in interval types*/
#define NCI_INTHR_UNK               24

/* These defined adjustment values */
#define NCI_ADJUST_UNK              10
#define NCI_ORACLE_DATE             0
#define NCI_ANSI_DATE               1

/*------------------------ Lob-specific Definitions -------------------------*/

/*
 * nciloff - NCI Lob OFFset
 *
 * The offset in the lob data.  The offset is specified in terms of bytes for
 * BLOBs and BFILes.  Character offsets are used for CLOBs, NCLOBs.
 * The maximum size of internal lob data is 4 gigabytes.  FILE LOB 
 * size is limited by the operating system.
 */
typedef ub4                        NCILobOffset;

/*
 * ncillen - NCI Lob LENgth (of lob data)
 *
 * Specifies the length of lob data in bytes for BLOBs and BFILes and in 
 * characters for CLOBs, NCLOBs.  The maximum length of internal lob
 * data is 4 gigabytes.  The length of FILE LOBs is limited only by the
 * operating system.
 */
typedef ub4                        NCILobLength;

/*
 * ncilmo - NCI Lob open MOdes
 *
 * The mode specifies the planned operations that will be performed on the
 * FILE lob data.  The FILE lob can be opened in read-only mode only.
 * 
 * In the future, we may include read/write, append and truncate modes.  Append
 * is equivalent to read/write mode except that the FILE is positioned for
 * writing to the end.  Truncate is equivalent to read/write mode except that
 * the FILE LOB data is first truncated to a length of 0 before use.
 */
enum NCILobMode
{
    NCI_LOBMODE_READONLY = 1,           /* read-only */
    NCI_LOBMODE_READWRITE = 2           /* read_write for internal lobs only */
};
typedef enum NCILobMode NCILobMode;

/*--------------------------- OBJECT LOCK OPTION ----------------------------*/
enum NCILockOpt
{
    /* 0 = uninitialized */
    NCI_LOCK_NONE       = 1,        /* null (same as no lock) */
    NCI_LOCK_X          = 2,        /* exclusive lock */
    NCI_LOCK_X_NOWAIT   = 3         /* exclusive lock, do not wait  */
};
typedef enum NCILockOpt NCILockOpt;

/*------------------------ TYPE ENCAPSULTATION LEVEL ------------------------*/
enum NCITypeEncap
{
    /* 0 = uninitialized */
    NCI_TYPEENCAP_PRIVATE,          /* private: only internally visible */
    NCI_TYPEENCAP_PUBLIC            /* public: visible to both internally and externally */
};
typedef enum NCITypeEncap NCITypeEncap;

/*--------------------------- TYPE PARAMETER MODE ---------------------------*/
enum NCITypeParamMode
{
    /* PL/SQL starts this from 0 */
    NCI_TYPEPARAM_IN = 0,                                                /* in */
    NCI_TYPEPARAM_OUT,                                                  /* out */
    NCI_TYPEPARAM_INOUT,                                             /* in-out */
    NCI_TYPEPARAM_BYREF,              /* call by reference (implicitly in-out) */
    NCI_TYPEPARAM_OUTNCPY,                         /* OUT with NOCOPY modifier */
    NCI_TYPEPARAM_INOUTNCPY                     /* IN OUT with NOCOPY modifier */
};
typedef enum NCITypeParamMode NCITypeParamMode;

#define NCI_ATTR_PURITY_DEFAULT         0x00
#define NCI_ATTR_PURITY_NEW             0x01
#define NCI_ATTR_PURITY_SELF            0x02
/*-------------------------- OBJECT Duration --------------------------------*/

typedef ub2                            NCIDuration;

#define NCI_DURATION_INVALID            0xFFFF                                  /* Invalid duration */
#define NCI_DURATION_BEGIN              (NCIDuration)10
/* beginning sequence of duration */
#define NCI_DURATION_NULL               (NCIDuration)(NCI_DURATION_BEGIN-1)
/* null duration */
#define NCI_DURATION_DEFAULT            (NCIDuration)(NCI_DURATION_BEGIN-2)     /* default */
#define NCI_DURATION_USER_CALLBACK      (NCIDuration)(NCI_DURATION_BEGIN-3)
#define NCI_DURATION_NEXT               (NCIDuration)(NCI_DURATION_BEGIN-4)
/* next special duration */
#define NCI_DURATION_SESSION            (NCIDuration)(NCI_DURATION_BEGIN)
/* the end of user session */
#define NCI_DURATION_TRANS              (NCIDuration)(NCI_DURATION_BEGIN+1)
/* the end of user transaction */
/*---------------------------------------------------------------------------*/
enum NCIRefreshOpt
{
    /* 0 = uninitialized */
    NCI_REFRESH_LOADED = 1        /* refresh objects loaded in the transaction */
};
typedef enum NCIRefreshOpt          NCIRefreshOpt; 

/* NCI representation of XMLType */
typedef struct NCIXMLType           NCIXMLType;

/* NCI representation of NCIDomDocument */
typedef struct NCIDOMDocument       NCIDOMDocument;

/* NCI representation of NCIExtProcContext */
typedef struct NCIExtProcContext    NCIExtProcContext;
/*----------------------------Piece Definitions------------------------------*/

#ifndef NCI_FLAGS
#define NCI_FLAGS
#define NCI_ONE_PIECE                   0                   /* one piece */
#define NCI_FIRST_PIECE                 1                   /* the first piece */
#define NCI_NEXT_PIECE                  2                   /* the next of many pieces */
#define NCI_LAST_PIECE                  3                   /* the last piece */
#endif

/*---------------------------------------------------------------------------*/

/*--------------------------- OBJECT INDICATOR ------------------------------*/

typedef sb2        NCIInd;
/*
 * NCIInd -- a variable of this type contains (null) indicator information
 */

#define NCI_IND_NOTNULL                 (NCIInd)0                       /* not NULL */
#define NCI_IND_NULL                    (NCIInd)(-1)                    /* NULL */
#define NCI_IND_BADNULL                 (NCIInd)(-2)                    /* BAD NULL */
#define NCI_IND_NOTNULLABLE             (NCIInd)(-3)                    /* not NULLable */

/*--------------------------- FILE open modes -------------------------------*/
#define NCI_FILE_READONLY               1                               /* readonly mode open for FILE types */
/*---------------------------------------------------------------------------*/
/*--------------------------- LOB open modes --------------------------------*/
#define NCI_LOB_READONLY                1                               /* readonly mode open for ILOB types */
#define NCI_LOB_READWRITE               2                               /* read write mode open for ILOBs */
#define NCI_LOB_WRITEONLY               3                               /* Writeonly mode open for ILOB types*/
#define NCI_LOB_APPENDONLY              4                               /* Appendonly mode open for ILOB types */
#define NCI_LOB_FULLOVERWRITE           5                               /* Completely overwrite ILOB */
#define NCI_LOB_FULLREAD                6                               /* Doing a Full Read of ILOB */

/*----------------------- LOB Buffering Flush Flags -------------------------*/
#define NCI_LOB_BUFFER_FREE             1
#define NCI_LOB_BUFFER_NOFREE           2
/*---------------------------------------------------------------------------*/

/*---------------------------LOB Option Types -------------------------------*/
#define NCI_LOB_OPT_COMPRESS            1                               /* SECUREFILE Compress */
#define NCI_LOB_OPT_ENCRYPT             2                               /* SECUREFILE Encrypt */
#define NCI_LOB_OPT_DEDUPLICATE         4                               /* SECUREFILE Deduplicate */
#define NCI_LOB_OPT_ALLOCSIZE           8                               /* SECUREFILE Allocation Size */
#define NCI_LOB_OPT_CONTENTTYPE         16                              /* SECUREFILE Content Type */
#define NCI_LOB_OPT_MODTIME             32                              /* SECUREFILE Modification Time */

/*------------------------   LOB Option Values ------------------------------*/
/* Compression */
#define NCI_LOB_COMPRESS_OFF            0                               /* Compression off */
#define NCI_LOB_COMPRESS_ON             1                               /* Compression on */

/* Encryption */
#define NCI_LOB_ENCRYPT_OFF             0                               /* Encryption Off */
#define NCI_LOB_ENCRYPT_ON              2                               /* Encryption On */

/* Deduplciate */
#define NCI_LOB_DEDUPLICATE_OFF         0                               /* Deduplicate Off */
#define NCI_LOB_DEDUPLICATE_ON          4                               /* Deduplicate Lobs */

/*--------------------------- NCI Statement Types ---------------------------*/
#define NCI_STMT_UNKNOWN                0                               /* Unknown statement */
#define NCI_STMT_SELECT                 1                               /* select statement */
#define NCI_STMT_UPDATE                 2                               /* update statement */
#define NCI_STMT_DELETE                 3                               /* delete statement */
#define NCI_STMT_INSERT                 4                               /* Insert Statement */
#define NCI_STMT_CREATE                 5                               /* create statement */
#define NCI_STMT_DROP                   6                               /* drop statement */
#define NCI_STMT_ALTER                  7                               /* alter statement */
#define NCI_STMT_BEGIN                  8                               /* begin ... (pl/sql statement)*/
#define NCI_STMT_DECLARE                9                               /* declare .. (pl/sql statement ) */
#define NCI_STMT_CALL                   10                              /* corresponds to kpu call */
#define NCI_STMT_MERGE                  16                              /* merge statement */
/*---------------------------------------------------------------------------*/

/*--------------------------- NCI Parameter Types ---------------------------*/
#define NCI_PTYPE_UNK                   0                               /* unknown   */
#define NCI_PTYPE_TABLE                 1                               /* table     */
#define NCI_PTYPE_VIEW                  2                               /* view      */
#define NCI_PTYPE_PROC                  3                               /* procedure */
#define NCI_PTYPE_FUNC                  4                               /* function  */
#define NCI_PTYPE_PKG                   5                               /* package   */
#define NCI_PTYPE_TYPE                  6                               /* user-defined type */
#define NCI_PTYPE_SYN                   7                               /* synonym   */
#define NCI_PTYPE_SEQ                   8                               /* sequence  */
#define NCI_PTYPE_COL                   9                               /* column    */
#define NCI_PTYPE_ARG                   10                              /* argument  */
#define NCI_PTYPE_LIST                  11                              /* list      */
#define NCI_PTYPE_TYPE_ATTR             12                              /* user-defined type's attribute */
#define NCI_PTYPE_TYPE_COLL             13                              /* collection type's element */
#define NCI_PTYPE_TYPE_METHOD           14                              /* user-defined type's method */
#define NCI_PTYPE_TYPE_ARG              15                              /* user-defined type method's arg */
#define NCI_PTYPE_TYPE_RESULT           16                              /* user-defined type method's result */
#define NCI_PTYPE_SCHEMA                17                              /* schema */
#define NCI_PTYPE_DATABASE              18                              /* database */
#define NCI_PTYPE_RULE                  19                              /* rule */
#define NCI_PTYPE_RULE_SET              20                              /* rule set */
#define NCI_PTYPE_EVALUATION_CONTEXT    21                              /* evaluation context */
#define NCI_PTYPE_TABLE_ALIAS           22                              /* table alias */
#define NCI_PTYPE_VARIABLE_TYPE         23                              /* variable type */
#define NCI_PTYPE_NAME_VALUE            24                              /* name value pair */

/*---------------------------------------------------------------------------*/

/*----------------------------- NCI List Types ------------------------------*/
#define NCI_LTYPE_UNK                   0                               /* unknown   */
#define NCI_LTYPE_COLUMN                1                               /* column list */
#define NCI_LTYPE_ARG_PROC              2                               /* procedure argument list */
#define NCI_LTYPE_ARG_FUNC              3                               /* function argument list */
#define NCI_LTYPE_SUBPRG                4                               /* subprogram list */
#define NCI_LTYPE_TYPE_ATTR             5                               /* type attribute */
#define NCI_LTYPE_TYPE_METHOD           6                               /* type method */
#define NCI_LTYPE_TYPE_ARG_PROC         7                               /* type method w/o result argument list */
#define NCI_LTYPE_TYPE_ARG_FUNC         8                               /* type method w/result argument list */
#define NCI_LTYPE_SCH_OBJ               9                               /* schema object list */
#define NCI_LTYPE_DB_SCH                10                              /* database schema list */
#define NCI_LTYPE_TYPE_SUBTYPE          11                              /* subtype list */
#define NCI_LTYPE_TABLE_ALIAS           12                              /* table alias list */
#define NCI_LTYPE_VARIABLE_TYPE         13                              /* variable type list */
#define NCI_LTYPE_NAME_VALUE            14                              /* name value list */

/*---------------------------------------------------------------------------*/

/*-------------------------- Memory Cartridge Services ---------------------*/
#define NCI_MEMORY_CLEARED              1
/*-------------------------- Pickler Cartridge Services ---------------------*/
typedef struct NCIPicklerTdsCtx         NCIPicklerTdsCtx;
typedef struct NCIPicklerTds            NCIPicklerTds;
typedef struct NCIPicklerImage          NCIPicklerImage;
typedef struct NCIPicklerFdo            NCIPicklerFdo;
typedef ub4                            NCIPicklerTdsElement;

typedef struct NCIAnyData               NCIAnyData;
typedef struct NCIAnyDataSet            NCIAnyDataSet;
typedef struct NCIAnyDataCtx            NCIAnyDataCtx;

/*---------------------------------------------------------------------------*/

/*--------------------------- User Callback Constants -----------------------*/
#define NCI_UCBTYPE_ENTRY               1                          /* entry callback */
#define NCI_UCBTYPE_EXIT                2                           /* exit callback */
#define NCI_UCBTYPE_REPLACE             3                    /* replacement callback */
/*---------------------------------------------------------------------------*/

/*--------------------- NLS service type and constance ----------------------*/
#define NCI_NLS_DAYNAME1                1                       /* Native name for Monday */
#define NCI_NLS_DAYNAME2                2                       /* Native name for Tuesday */
#define NCI_NLS_DAYNAME3                3                       /* Native name for Wednesday */
#define NCI_NLS_DAYNAME4                4                       /* Native name for Thursday */
#define NCI_NLS_DAYNAME5                5                       /* Native name for Friday */
#define NCI_NLS_DAYNAME6                6                       /* Native name for for Saturday */
#define NCI_NLS_DAYNAME7                7                       /* Native name for for Sunday */
#define NCI_NLS_ABDAYNAME1              8                       /* Native abbreviated name for Monday */
#define NCI_NLS_ABDAYNAME2              9                       /* Native abbreviated name for Tuesday */
#define NCI_NLS_ABDAYNAME3              10                      /* Native abbreviated name for Wednesday */
#define NCI_NLS_ABDAYNAME4              11                      /* Native abbreviated name for Thursday */
#define NCI_NLS_ABDAYNAME5              12                      /* Native abbreviated name for Friday */
#define NCI_NLS_ABDAYNAME6              13                      /* Native abbreviated name for for Saturday */
#define NCI_NLS_ABDAYNAME7              14                      /* Native abbreviated name for for Sunday */
#define NCI_NLS_MONTHNAME1              15                      /* Native name for January */
#define NCI_NLS_MONTHNAME2              16                      /* Native name for February */
#define NCI_NLS_MONTHNAME3              17                      /* Native name for March */
#define NCI_NLS_MONTHNAME4              18                      /* Native name for April */
#define NCI_NLS_MONTHNAME5              19                      /* Native name for May */
#define NCI_NLS_MONTHNAME6              20                      /* Native name for June */
#define NCI_NLS_MONTHNAME7              21                      /* Native name for July */
#define NCI_NLS_MONTHNAME8              22                      /* Native name for August */
#define NCI_NLS_MONTHNAME9              23                      /* Native name for September */
#define NCI_NLS_MONTHNAME10             24                      /* Native name for October */
#define NCI_NLS_MONTHNAME11             25                      /* Native name for November */
#define NCI_NLS_MONTHNAME12             26                      /* Native name for December */
#define NCI_NLS_ABMONTHNAME1            27                      /* Native abbreviated name for January */
#define NCI_NLS_ABMONTHNAME2            28                      /* Native abbreviated name for February */
#define NCI_NLS_ABMONTHNAME3            29                      /* Native abbreviated name for March */
#define NCI_NLS_ABMONTHNAME4            30                      /* Native abbreviated name for April */
#define NCI_NLS_ABMONTHNAME5            31                      /* Native abbreviated name for May */
#define NCI_NLS_ABMONTHNAME6            32                      /* Native abbreviated name for June */
#define NCI_NLS_ABMONTHNAME7            33                      /* Native abbreviated name for July */
#define NCI_NLS_ABMONTHNAME8            34                      /* Native abbreviated name for August */
#define NCI_NLS_ABMONTHNAME9            35                      /* Native abbreviated name for September */
#define NCI_NLS_ABMONTHNAME10           36                      /* Native abbreviated name for October */
#define NCI_NLS_ABMONTHNAME11           37                      /* Native abbreviated name for November */
#define NCI_NLS_ABMONTHNAME12           38                      /* Native abbreviated name for December */
#define NCI_NLS_YES                     39                      /* Native string for affirmative response */
#define NCI_NLS_NO                      40                      /* Native negative response */
#define NCI_NLS_AM                      41                      /* Native equivalent string of AM */
#define NCI_NLS_PM                      42                      /* Native equivalent string of PM */
#define NCI_NLS_AD                      43                      /* Native equivalent string of AD */
#define NCI_NLS_BC                      44                      /* Native equivalent string of BC */
#define NCI_NLS_DECIMAL                 45                      /* decimal character */
#define NCI_NLS_GROUP                   46                      /* group separator */
#define NCI_NLS_DEBIT                   47                      /* Native symbol of debit */
#define NCI_NLS_CREDIT                  48                      /* Native sumbol of credit */
#define NCI_NLS_DATEFORMAT              49                      /* date format */
#define NCI_NLS_INT_CURRENCY            50                      /* International currency symbol */
#define NCI_NLS_LOC_CURRENCY            51                      /* Locale currency symbol */
#define NCI_NLS_LANGUAGE                52                      /* Language name */
#define NCI_NLS_ABLANGUAGE              53                      /* Abbreviation for language name */
#define NCI_NLS_TERRITORY               54                      /* Territory name */
#define NCI_NLS_CHARACTER_SET           55                      /* Character set name */
#define NCI_NLS_LINGUISTIC_NAME         56                      /* Linguistic name */
#define NCI_NLS_CALENDAR                57                      /* Calendar name */
#define NCI_NLS_DUAL_CURRENCY           78                      /* Dual currency symbol */
#define NCI_NLS_WRITINGDIR              79                      /* Language writing direction */
#define NCI_NLS_ABTERRITORY             80                      /* Territory Abbreviation */
#define NCI_NLS_DDATEFORMAT             81                      /* default date format */
#define NCI_NLS_DTIMEFORMAT             82                      /* default time format */
#define NCI_NLS_SFDATEFORMAT            83                      /* Local string formatted date format */
#define NCI_NLS_SFTIMEFORMAT            84                      /* Local string formatted time format */
#define NCI_NLS_NUMGROUPING             85                      /* Number grouping fields */
#define NCI_NLS_LISTSEP                 86                      /* List separator */
#define NCI_NLS_MONDECIMAL              87                      /* Monetary decimal character */
#define NCI_NLS_MONGROUP                88                      /* Monetary group separator */
#define NCI_NLS_MONGROUPING             89                      /* Monetary grouping fields */
#define NCI_NLS_INT_CURRENCYSEP         90                      /* International currency separator */
#define NCI_NLS_CHARSET_MAXBYTESZ       91                      /* Maximum character byte size      */
#define NCI_NLS_CHARSET_FIXEDWIDTH      92                      /* Fixed-width charset byte size    */
#define NCI_NLS_CHARSET_ID              93                      /* Character set id */
#define NCI_NLS_NCHARSET_ID             94                      /* NCharacter set id */
#define NCI_NLS_MAXBUFSZ                100                     /* Max buffer size may need for NCINlsGetInfo */

#define NCI_NLS_BINARY                  0x1             /* for the binary comparison */
#define NCI_NLS_LINGUISTIC              0x2             /* for linguistic comparison */
#define NCI_NLS_CASE_INSENSITIVE        0x10            /* for case-insensitive comparison */

#define NCI_NLS_UPPERCASE               0x20               /* convert to uppercase */
#define NCI_NLS_LOWERCASE               0x40               /* convert to lowercase */

#define NCI_NLS_CS_IANA_TO_ORA          0   /* Map charset name from IANA to Oracle */
#define NCI_NLS_CS_ORA_TO_IANA          1   /* Map charset name from Oracle to IANA */
#define NCI_NLS_LANG_ISO_TO_ORA         2   /* Map language name from ISO to Oracle */
#define NCI_NLS_LANG_ORA_TO_ISO         3   /* Map language name from Oracle to ISO */
#define NCI_NLS_TERR_ISO_TO_ORA         4   /* Map territory name from ISO to Oracle*/
#define NCI_NLS_TERR_ORA_TO_ISO         5   /* Map territory name from Oracle to ISO*/
#define NCI_NLS_TERR_ISO3_TO_ORA        6   /* Map territory name from 3-letter ISO */
/* abbreviation to Oracle               */
#define NCI_NLS_TERR_ORA_TO_ISO3        7   /* Map territory name from Oracle to    */
/* 3-letter ISO abbreviation            */

typedef struct NCIMsg                   NCIMsg;
typedef ub4                             NCIWchar;

#define NCI_XMLTYPE_CREATE_OCISTRING    1
#define NCI_XMLTYPE_CREATE_CLOB         2
#define NCI_XMLTYPE_CREATE_BLOB         3

/*------------------------- Kerber Authentication Modes ---------------------*/
#define NCI_KERBCRED_PROXY              1       /* Apply Kerberos Creds for Proxy */
#define NCI_KERBCRED_CLIENT_IDENTIFIER  2       /*Apply Creds for Secure Client ID */
/*--------------------------------------------------------------------------- 
                     PRIVATE TYPES AND CONSTANTS 
  ---------------------------------------------------------------------------*/
struct NCITime
{
    ub1 NCITimeHH;              /* hours; range is 0 <= hours <=23 */
    ub1 NCITimeMI;              /* minutes; range is 0 <= minutes <= 59 */
    ub1 NCITimeSS;              /* seconds; range is 0 <= seconds <= 59 */
};
typedef struct NCITime  NCITime;

struct NCIDate
{
    sb2       NCIDateYYYY;         /* gregorian year; range is -4712 <= year <= 9999 */
    ub1       NCIDateMM;           /* month; range is 1 <= month < 12 */
    ub1       NCIDateDD;           /* day; range is 1 <= day <= 31 */
    NCITime   NCIDateTime;          /* time */
};
typedef struct NCIDate  NCIDate;

/*----- values for NCI_ATTR_DIRPATH_SKIPINDEX_METHOD attribute -----*/
#define NCI_DIRPATH_INDEX_MAINT_SKIP_UNUSABLE           2
#define NCI_DIRPATH_INDEX_MAINT_DONT_SKIP_UNUSABLE      3
#define NCI_DIRPATH_INDEX_MAINT_SKIP_ALL                4

/* values for NCI_ATTR_STATE attribute of NCIDirPathCtx */
#define NCI_DIRPATH_NORMAL                              1               /* can accept rows, last row complete */
#define NCI_DIRPATH_PARTIAL                             2               /* last row was partial */
#define NCI_DIRPATH_NOT_PREPARED                        3               /* direct path context is not prepared */

/*----- values for cflg argument to NCIDirpathColArrayEntrySet -----*/
#define NCI_DIRPATH_COL_COMPLETE                        0               /* column data is complete */
#define NCI_DIRPATH_COL_NULL                            1               /* column is null */
#define NCI_DIRPATH_COL_PARTIAL                         2               /* column data is partial */
#define NCI_DIRPATH_COL_ERROR                           3               /* column error, ignore row */

/*----- values for action parameter to NCIDirPathDataSave -----*/
#define NCI_DIRPATH_DATASAVE_SAVEONLY                   0               /* data save point only */
#define NCI_DIRPATH_DATASAVE_FINISH                     1               /* execute finishing logic */
/* save portion of input data (before space error occurred) and finish */
#define NCI_DIRPATH_DATASAVE_PARTIAL                    2

/*- NCI_ATTR_DIRPATH_EXPR_TYPE values (describes NCI_ATTR_NAME expr type) -*/
#define NCI_DIRPATH_EXPR_OBJ_CONSTR                     1               /* NAME is an object constructor */
#define NCI_DIRPATH_EXPR_SQL                            2               /* NAME is an opaque or sql function */
#define NCI_DIRPATH_EXPR_REF_TBLNAME                    3               /* NAME is table name if ref is scoped*/

/* Listing of error bits used by NCIDateCheck() */
#define NCI_DATE_INVALID_DAY                            0x1             /* Bad DAy */
#define NCI_DATE_DAY_BELOW_VALID                        0x2             /* Bad DAy Low/high bit (1=low)*/
#define NCI_DATE_INVALID_MONTH                          0x4             /* Bad MOnth */
#define NCI_DATE_MONTH_BELOW_VALID                      0x8             /* Bad MOnth Low/high bit (1=low)*/
#define NCI_DATE_INVALID_YEAR                           0x10            /* Bad YeaR */
#define NCI_DATE_YEAR_BELOW_VALID                       0x20            /* Bad YeaR Low/high bit (1=low)*/
#define NCI_DATE_INVALID_HOUR                           0x40            /* Bad HouR */
#define NCI_DATE_HOUR_BELOW_VALID                       0x80            /* Bad HouR Low/high bit (1=low)*/
#define NCI_DATE_INVALID_MINUTE                         0x100           /* Bad MiNute */
#define NCI_DATE_MINUTE_BELOW_VALID                     0x200           /* Bad MiNute Low/high bit (1=low)*/
#define NCI_DATE_INVALID_SECOND                         0x400           /* Bad SeCond */
#define NCI_DATE_SECOND_BELOW_VALID                     0x800           /* bad second Low/high bit (1=low)*/
#define NCI_DATE_DAY_MISSING_FROM_1582                  0x1000          /* Day is one of those "missing" from 1582 */
#define NCI_DATE_YEAR_ZERO                              0x2000          /* Year may not equal zero */
#define NCI_DATE_INVALID_FORMAT                         0x8000          /* Bad date format input */

typedef struct NCIDirPathCtx                NCIDirPathCtx;                  /* context */
typedef struct NCIDirPathFuncCtx            NCIDirPathFuncCtx;     /* function context */
typedef struct NCIDirPathColArray           NCIDirPathColArray;        /* column array */
typedef struct NCIDirPathStream             NCIDirPathStream;                /* stream */
typedef struct NCIDirPathDesc               NCIDirPathDesc;  /* direct path descriptor */

typedef sb4 (*NCICallbackInBind)(dvoid *ictxp, NCIBind *bindp, ub4 iter,
                                ub4 index, dvoid **bufpp, ub4 *alenp,
                                ub1 *piecep, dvoid **indp);

typedef sb4 (*NCICallbackOutBind)(dvoid *octxp, NCIBind *bindp, ub4 iter,
                                ub4 index, dvoid **bufpp, ub4 **alenp,
                                ub1 *piecep, dvoid **indp,
                                ub2 **rcodep);

typedef sb4 (*NCICallbackDefine)(dvoid *octxp, NCIDefine *defnp, ub4 iter,
                                dvoid **bufpp, ub4 **alenp, ub1 *piecep,
                                dvoid **indp, ub2 **rcodep);


/*number*/
#define NCI_NUMBER_SIZE     22
struct NCINumber
{
    ub1 NCINumberPart[NCI_NUMBER_SIZE];
};
typedef struct NCINumber    NCINumber;

#define NCIDateGetDate(date, year, month, day) \
{ \
    *year = (date)->NCIDateYYYY; \
    *month = (date)->NCIDateMM; \
    *day = (date)->NCIDateDD; \
}
#define NCIDateSetTime(date, hour, min, sec) \
{ \
    (date)->NCIDateTime.NCITimeHH = hour; \
    (date)->NCIDateTime.NCITimeMI = min; \
    (date)->NCIDateTime.NCITimeSS = sec; \
}
#define NCIDateSetDate(date, year, month, day) \
{ \
    (date)->NCIDateYYYY = year; \
    (date)->NCIDateMM = month; \
    (date)->NCIDateDD = day; \
}
#define NCIDateGetTime(date, hour, min, sec) \
{ \
    *hour = (date)->NCIDateTime.NCITimeHH; \
    *min = (date)->NCIDateTime.NCITimeMI; \
    *sec = (date)->NCIDateTime.NCITimeSS; \
}

NCI_API
sword
NCIInitialize(
    ub4                     mode,
    dvoid*                  ctxp,
    dvoid*                  (*malocfp)(dvoid *ctxp, size_t size),
    dvoid*                  (*ralocfp)(dvoid *ctxp, dvoid *memptr, size_t newsize),
    void                    (*mfreefp)(dvoid *ctxp, dvoid *memptr)
);

NCI_API
sword
NCIEnvInit(
    NCIEnv**                envp,
    ub4                     mode,
    size_t                  xtramem_sz,
    dvoid**                 usrmempp
);

NCI_API
sword
NCIEnvCreate(
    NCIEnv**                envhpp,
    ub4                     mode,
    const void*             ctxp,
    const void*             (*malocfp) (dvoid *ctxp, size_t size),
    const void*             (*ralocfp) (dvoid *ctxp, dvoid *memptr, size_t newsize),
    const void              (*mfreefp) (dvoid *ctxp, dvoid *memptr),
    size_t                  xtramemsz,
    dvoid**                 usrmempp
);

NCI_API
sword
NCIEnvNlsCreate(
    NCIEnv**                envhpp,
    ub4                     mode,
    void*                   ctxp,
    void*                   (*malocfp)(void  *ctxp, size_t size),
    void*                   (*ralocfp)(void  *ctxp, void  *memptr, size_t newsize),
    void                    (*mfreefp)(void  *ctxp, void  *memptr),
    size_t                  xtramemsz,
    void**                  usrmempp,
    ub2                     charset,
    ub2                     ncharset
);

NCI_API
sword
NCIHandleAlloc(
    dvoid*                  parenth,
    dvoid**                 hndlpp,
    CONST ub4               type, 
    CONST size_t            xtramem_sz,
    dvoid**                 usrmempp
);

NCI_API
sword
NCIHandleFree(
    dvoid*                  hndlp,
    ub4                     type
);

NCI_API
sword
NCISessionBegin(
    NCISvcCtx*              svchp,
    NCIError*               errhp,
    NCISession*             usrhp,
    ub4                     credt,
    ub4                     mode
);

NCI_API
sword
NCIServerAttach(
    NCIServer*              srvhp,
    NCIError*               errhp,
    CONST NCIText*          dblink,
    sb4                     dblink_len,
    ub4                     mode
);

NCI_API
sword
NCIStmtPrepare(
    NCIStmt*                stmtp,
    NCIError*               errhp,
    NCIText*                stmt,
    ub4                     stmt_len,
    ub4                     language,
    ub4                     mode
);

NCI_API
sword
NCIStmtGetPieceInfo(
    CONST NCIStmt*          stmtp,
    NCIError*               errhp,
    dvoid**                 hndlpp,
    ub4*                    typep,
    ub1*                    in_outp,
    ub4*                    iterp,
    ub4*                    idxp,
    ub1*                    piecep
);

NCI_API
sword
NCIStmtSetPieceInfo(
    dvoid*                  hndlp,
    ub4                     type,
    NCIError*               errhp,
    CONST dvoid*            bufp,
    ub4*                    alenp,
    ub1                     piece,
    CONST dvoid*            indp,
    ub2*                    rcodep
);

NCI_API
sword
NCIStmtExecute(
    NCISvcCtx*              svchp,
    NCIStmt*                stmtp,
    NCIError*               errhp,
    ub4                     iters,
    ub4                     rowoff,
    CONST NCISnapshot*      snap_in,
    NCISnapshot*            snap_out,
    ub4                     mode
);

NCI_API
sword
NCIStmtFetch(
    NCIStmt*                stmtp,
    NCIError*               errhp,
    ub4                     nrows,
    ub2                     orientation,
    ub4                     mode
);

NCI_API
sword
NCIDefineByPos(
    NCIStmt*                stmtp,
    NCIDefine**             defnp,
    NCIError*               errhp,
    ub4                     position,
    dvoid*                  valuep,
    sb4                     value_sz,
    ub2                     dty,
    dvoid*                  indp,
    ub2*                    rlenp,
    ub2*                    rcodep,
    ub4                     mode
);

NCI_API
sword
NCIErrorGet(
    dvoid*                  hndlp,
    ub4                     recordno,
    NCIText*                sqlstate,
    sb4*                    errcodep,
    NCIText*                bufp,
    ub4                     bufsiz,
    ub4                     type
);

NCI_API
sword
NCIBindByPos(
    NCIStmt*                stmtp,
    NCIBind**               bindp,
    NCIError*               errhp,
    ub4                     position,
    dvoid*                  valuep,
    sb4                     value_sz,
    ub2                     dty,
    dvoid*                  indp,
    ub2*                    alenp,
    ub2*                    rcodep,
    ub4                     maxarr_len,
    ub4*                    curelep,
    ub4                     mode
);

NCI_API
sword
NCIBindByName(
    NCIStmt*                stmtp,
    NCIBind**               bindp,
    NCIError*               errhp,
    CONST NCIText*          placeholder,
    sb4                     placeh_len,
    dvoid*                  valuep,
    sb4                     value_sz,
    ub2                     dty,
    dvoid*                  indp,
    ub2*                    alenp,
    ub2*                    rcodep,
    ub4                     maxarr_len,
    ub4*                    curelep,
    ub4                     mode
);

NCI_API
sword
NCIBindDynamic(
    NCIBind*                bindp,
    NCIError*               errhp,
    void*                   ictxp,
    NCICallbackInBind       icbfp,
    dvoid*                  octxp,
    NCICallbackOutBind      ocbfp
);

NCI_API
sword
NCILogon(
    NCIEnv*                 envhp,
    NCIError*               errhp,
    NCISvcCtx**             svchp,
    CONST NCIText*          username,
    ub4                     uname_len,
    CONST NCIText*          password,
    ub4                     passwd_len,
    CONST NCIText*          dbname,
    ub4                     dbname_len
);

NCI_API
sword
NCILogoff(
    NCISvcCtx*              svchp,
    NCIError*               errhp
);

NCI_API
sword
NCIPasswordChange(
    NCISvcCtx*              svchp,
    NCIError*               errhp,
    CONST NCIText*          user_name,
    ub4                     usernm_len,
    CONST NCIText*          opasswd,
    ub4                     opasswd_len,
    CONST NCIText*          npasswd,
    ub4                     npasswd_len,
    ub4                     mode
);

NCI_API
sword
NCITransStart(
    NCISvcCtx*              svchp,
    NCIError*               errhp,
    uword                   timeout,
    ub4                     flags
);

NCI_API
sword
NCITransCommit(
    NCISvcCtx*              svchp,
    NCIError*               errhp,
    ub4                     flags
);

NCI_API
sword
NCITransRollback(
    NCISvcCtx*              svchp,
    NCIError*               errhp,
    ub4                     flags
);

NCI_API
sword
NCIServerDetach(
    NCIServer*              srvhp,
    NCIError*               errhp,
    ub4                     mode
);

NCI_API
sword
NCISessionEnd(
    NCISvcCtx*              svchp,
    NCIError*               errhp,
    NCISession*             usrhp,
    ub4                     mode
);

NCI_API
sword
NCIAttrGet(
    CONST dvoid*            trgthndlp,
    ub4                     trghndltyp,
    dvoid*                  attributep,
    ub4*                    sizep,
    ub4                     attrtype,
    NCIError*               errhp
);

NCI_API
sword
NCIAttrSet(
    dvoid*                  trgthndlp,
    ub4                     trghndltyp,
    dvoid*                  attributep,
    ub4                     size,
    ub4                     attrtype,
    NCIError*               errhp
);

NCI_API
sword
NCIParamGet(
    CONST dvoid*            hndlp,
    ub4                     htype,
    NCIError*               errhp, 
    dvoid**                 parmdpp,
    ub4                     pos
);

NCI_API
sword
NCIParamSet(
    dvoid*                  hdlp,
    ub4                     htyp,
    NCIError*               errhp,
    CONST dvoid*            dscp,
    ub4                     dtyp,
    ub4                     pos
);

NCI_API
sword
NCIDescribeAny(
    NCISvcCtx*              svchp,
    NCIError*               errhp,
    dvoid*                  objptr,
    ub4                     objnm_len,
    ub1                     objptr_typ,
    ub1                     info_level,
    ub1                     objtyp,
    NCIDescribe*            dschp
);

NCI_API
sword
NCIBindArrayOfStruct(
    NCIBind*                bindp,
    NCIError*               errhp,
    ub4                     pvskip,
    ub4                     indskip,
    ub4                     alskip,
    ub4                     rcskip
);

NCI_API
sword
NCIDefineArrayOfStruct(
    NCIDefine*              defnp,
    NCIError*               errhp,
    ub4                     pvskip,
    ub4                     indskip,
    ub4                     rlskip,
    ub4                     rcskip
);

NCI_API
sword
NCIDescriptorAlloc(
    CONST dvoid*            parenth,
    dvoid**                 descpp,
    CONST ub4               type,
    CONST size_t            xtramem_sz,
    dvoid**                 usrmempp
);

NCI_API
sword
NCIDescriptorFree(
    dvoid*                  descp,
    CONST ub4               type
);

NCI_API
sword
NCILobWrite(
    NCISvcCtx*              svchp,
    NCIError*               errhp,
    NCILobLocator*          locp,
    ub4*                    amtp,
    ub4                     offset,
    dvoid*                  bufp,
    ub4                     buflen, 
    ub1                     piece,
    dvoid*                  ctxp, 
    sb4                     (*cbfp)(dvoid *ctxp, dvoid* bufp, ub4* len, ub1* piece),
    ub2                     csid,
    ub1                     csfrm
);

NCI_API
sword
NCIBreak(
    dvoid*                  hndlp,
    NCIError*               errhp
);

NCI_API
sword
NCILobGetLength(
    NCISvcCtx*              svchp,
    NCIError*               errhp,
    NCILobLocator*          locp,
    ub4*                    lenp
);

NCI_API
sword
NCILobRead(
    NCISvcCtx*              svchp,
    NCIError*               errhp,
    NCILobLocator*          locp,
    ub4*                    amtp,
    ub4                     offset,
    dvoid*                  bufp,
    ub4                     bufl, 
    dvoid*                  ctxp,
    sb4                     (*cbfp)(dvoid* ctxp, CONST dvoid* bufp, ub4 len, ub1 piece),
    ub2                     csid,
    ub1                     csfrm
);

NCI_API
sword
NCILobRead2(
    NCISvcCtx*              svchp,
    NCIError*               errhp,
    NCILobLocator*          locp,
    ub8*                    byte_amtp,
    ub8*                    char_amtp,
    ub8                     offset,
    void*                   bufp,
    ub8                     bufl,
    ub1                     piece,
    void*                   ctxp, 
    sb4                     (*cbfp)(void* ctxp, const void* bufp, ub8 lenp, ub1 piecep, void** changed_bufpp, ub8* changed_lenp),
    ub2                     csid,
    ub1                     csfrm
);

NCI_API
sword  
NCIStmtFetchRow(
    NCIStmt*                stmthp,
    NCIError*               errhp, 
    ub4                     nrows,
    ub2                     orientation,
    sb4                     fetchOffset,
    ub4                     mode 
);

NCI_API
sword
NCIDirPathPrepare(
    NCIDirPathCtx*          dpctx,
    NCISvcCtx*              svchp,
    NCIError*               errhp
);

NCI_API
sword
NCIDirPathColArrayReset(
    NCIDirPathColArray*     dpca,
    NCIError*               errhp
);

NCI_API
sword
NCIDirPathStreamReset(
    NCIDirPathStream*       dpstr,
    NCIError*               errhp
);

NCI_API
sword
NCIDirPathColArrayEntrySet(
    NCIDirPathColArray*     dpca,
    NCIError*               errhp,
    ub4                     rownum,
    ub2                     colIdx,
    ub1*                    cvalp,
    ub4                     clen,
    ub1                     cflg
);

NCI_API
sword
NCIDirPathColArrayEntryGet(
    NCIDirPathColArray*     dpca,
    NCIError*               errhp,
    ub4                     rownum,
    ub2                     colIdx,
    ub1**                   cvalpp,
    ub4*                    clenp,
    ub1*                    cflgp
);

NCI_API
sword
NCIDirPathDataSave(
    NCIDirPathCtx*          dpctx,
    NCIError*               errhp,
    ub4                     action
);

NCI_API
sword
NCIDirPathColArrayToStream(
    NCIDirPathColArray*     dpca,
    NCIDirPathCtx*          dpctx,
    NCIDirPathStream*       dpstr,
    NCIError*               errhp,
    ub4                     rowcnt,
    ub4                     rowoff
);

NCI_API
sword
NCIDirPathFinish(
    NCIDirPathCtx*          dpctx,
    NCIError*               errhp
);

NCI_API
sword
NCIDirPathLoadStream(
    NCIDirPathCtx*          dpctx,
    NCIDirPathStream*       dpstr,
    NCIError*               errhp
);

NCI_API
sword
NCIDirPathFlushRow(
    NCIDirPathCtx*          dpctx,
    NCIError*               errhp
);

NCI_API
sword
NCIDirPathAbort(
    NCIDirPathCtx*          dpctx,
    NCIError*               errhp 
);

NCI_API
sword 
NCIIntervalAdd(
    dvoid*                  hndl,
    NCIError*               err,
    NCIInterval*            addend1,
    NCIInterval*            addend2,
    NCIInterval*            result
);

NCI_API
sword
NCIIntervalAssign(
    dvoid*                  hndl,
    NCIError*               err,
    CONST NCIInterval*      ininter,
    NCIInterval*            outinter
);

NCI_API
sword 
NCIIntervalCheck(
    dvoid*                  hndl,
    NCIError*               err,
    CONST NCIInterval*      interval,
    ub4*                    valid
);

NCI_API
sword 
NCIIntervalCompare(
    dvoid*                  hndl,
    NCIError*               err,
    NCIInterval*            inter1,
    NCIInterval*            inter2,
    sword*                  result
);

NCI_API
sword 
NCIIntervalDivide(
    dvoid*                  hndl,
    NCIError*               err,
    NCIInterval*            dividend, 
    NCINumber*              divisor,
    NCIInterval*            result
);

NCI_API
sword 
NCIIntervalFromNumber(
    dvoid*                  hndl,
    NCIError*               err,
    NCIInterval*            inter,
    NCINumber*              number
);

NCI_API
sword 
NCIIntervalFromText(
    dvoid*                  hndl,
    NCIError*               err,
    CONST NCIText*          inpstr,
    size_t                  str_len,
    NCIInterval*            result
);

NCI_API
sword
NCIIntervalFromTZ(
    dvoid*                  hndl,
    NCIError*               err,
    CONST NCIText*          inpstring,
    size_t                  str_len,
    NCIInterval*            result
);

NCI_API
sword
NCIIntervalGetDaySecond(
    dvoid*                  hndl,
    NCIError*               err,
    sb4*                    dy,
    sb4*                    hr,
    sb4*                    mm,
    sb4*                    ss,
    sb4*                    fsec,
    CONST NCIInterval*      interval
);

NCI_API
sword
NCIIntervalGetYearMonth(
    dvoid*                  hndl,
    NCIError*               err,
    sb4*                    yr,
    sb4*                    mnth,
    CONST NCIInterval*      interval
);

NCI_API
sword 
NCIIntervalMultiply(
    dvoid*                  hndl,
    NCIError*               err,
    CONST NCIInterval*      inter,
    NCINumber*              nfactor,
    NCIInterval*            result
);

NCI_API
sword 
NCIIntervalSetDaySecond(
    dvoid*                  hndl,
    NCIError*               err,
    sb4                     dy,
    sb4                     hr,
    sb4                     mm,
    sb4                     ss,
    sb4                     fsec,
    NCIInterval*            result
);

NCI_API
sword 
NCIIntervalSetYearMonth(
    dvoid*                  hndl,
    NCIError*               err,
    sb4                     yr,
    sb4                     mnth,
    NCIInterval*            result
);

NCI_API
sword 
NCIIntervalSubtract(
    dvoid*                  hndl,
    NCIError*               err,
    NCIInterval*            minuend, 
    NCIInterval*            subtrahend,
    NCIInterval*            result
);

NCI_API
sword 
NCIIntervalToNumber(
    dvoid*                  hndl,
    NCIError*               err,
    CONST NCIInterval*      interval,
    NCINumber*              number
);

NCI_API
sword 
NCIIntervalToText(
    dvoid*                  hndl,
    NCIError*               err,
    CONST NCIInterval*      interval,
    ub1                     lfprec,
    ub1                     fsprec,
    NCIText*                buffer,
    size_t                  buflen,
    size_t*                 resultlen
);

NCI_API
sword
NCILobFileCloseAll(
    NCISvcCtx*              svchp,
    NCIError*               errhp
);

NCI_API
sword 
NCIServerVersion(
    dvoid*                  hndlp,
    NCIError*               errhp,
    NCIText*                bufp,
    ub4                     bufsz,
    ub1                     hndltype
);

NCI_API
sword 
NCILobLocatorIsInit(
    NCIEnv*                 envhp,
    NCIError*               errhp,
    CONST NCILobLocator*    locp,
    boolean*                is_initialized
);

NCI_API
sword
NCILobTrim(
    NCISvcCtx*              svchp,
    NCIError*               errhp,
    NCILobLocator*          locp,
    ub4                     newlen
);

NCI_API
sword
NCILobAssign(
    NCIEnv*                 envhp,
    NCIError*               errhp,
    CONST NCILobLocator*    src_locp,
    NCILobLocator**         dst_locpp
);

NCI_API 
sword
NCILobCharSetForm(
    NCIEnv*                 envhp,
    NCIError*               errhp,
    const NCILobLocator*    locp,
    ub1*                    csfrm
);

NCI_API
sword 
NCILobIsEqual(
    NCIEnv*                 envhp,
    const NCILobLocator*    x,
    const NCILobLocator*    y,
    boolean*                is_equal
);

NCI_API
sword
NCILobFileGetName(
    NCIEnv*                 envhp,
    NCIError*               errhp,
    CONST NCILobLocator*    filep,
    NCIText*                dir_alias,
    ub2*                    d_length,
    NCIText*                filename,
    ub2*                    f_length
);

NCI_API
sword
NCILobFileSetName(
    NCIEnv*                 envhp,
    NCIError*               errhp,
    NCILobLocator**         filepp,
    CONST NCIText*          dir_alias,
    ub2                     d_length,
    CONST NCIText*          filename,
    ub2                     f_length
);

NCI_API
sword
NCILobFileExists(
    NCISvcCtx*              svchp,
    NCIError*               errhp,
    NCILobLocator*          filep,
    boolean*                flag
);

NCI_API 
sword
NCILobFileOpen( 
    NCISvcCtx*              svchp,
    NCIError*               errhp,
    NCILobLocator*          filep,
    ub1                     mode
);

NCI_API 
sword 
NCILobFileClose(
    NCISvcCtx*              svchp,
    NCIError*               errhp,
    NCILobLocator*          filep
);

NCI_API
sword 
NCILobFileIsOpen(
    NCISvcCtx*              svchp,
    NCIError*               errhp,
    NCILobLocator*          filep,
    boolean*                flag
);

NCI_API
sword 
NCILobLoadFromFile(
    NCISvcCtx*              svchp,
    NCIError*               errhp,
    NCILobLocator*          dst_locp,
    NCILobLocator*          src_locp,
    ub4                     amount,
    ub4                     dst_offset,
    ub4                     src_offset
);

NCI_API 
sword 
NCILobCreateTemporary(
    NCISvcCtx*              svchp,
    NCIError*               errhp,
    NCILobLocator*          locp,
    ub2                     csid,
    ub1                     csfrm,
    ub1                     lobtype,
    boolean                 cache,
    NCIDuration             duration
);

NCI_API
sword 
NCILobFlushBuffer(
    NCISvcCtx*              svchp,
    NCIError*               errhp,
    NCILobLocator*          locp,
    ub4                     flag
);

NCI_API
sword 
NCILobFreeTemporary(
    NCISvcCtx*              svchp,
    NCIError*               errhp,
    NCILobLocator*          locp
);

NCI_API 
sword
NCILobLocatorAssign(
    NCISvcCtx*              svchp,
    NCIError*               errhp,
    CONST NCILobLocator*    src_locp,
    NCILobLocator**         dst_locpp
);

NCI_API 
sword 
NCILobIsOpen(
    NCISvcCtx*              svchp,
    NCIError*               errhp,
    NCILobLocator*          locp,
    boolean*                flag
);

NCI_API
sword
NCINumberAssign(
    NCIError*               err,
    CONST NCINumber*        from,
    NCINumber*              to
);

NCI_API
sword
NCINumberFromReal(
    NCIError*               err,
    CONST dvoid*            rnum,
    uword                   rnum_length,
    NCINumber*              number
);

NCI_API
sword
NCINumberFromInt(
    NCIError*               err,
    CONST dvoid*            inum,
    uword                   inum_length,
    uword                   inum_s_flag,
    NCINumber*              number
);

NCI_API
sword
NCINumberFromText(
    NCIError*               err,
    CONST NCIText*          str,
    ub4                     str_length,
    CONST NCIText*          fmt,
    ub4                     fmt_length,
    CONST NCIText*          nls_params,
    ub4                     nls_p_length,
    NCINumber*              number
);

NCI_API
sword
NCINumberToInt(
    NCIError*               err,
    CONST NCINumber*        number,
    uword                   rsl_length,
    uword                   rsl_flag,
    dvoid*                  rsl
);

NCI_API
sword
NCINumberToReal(
    NCIError*               err,
    CONST NCINumber*        number,
    uword                   rsl_length,
    dvoid*                  rsl
);

NCI_API
sword
NCINumberToText(
    NCIError*               err,
    const NCINumber*        number,
    const NCIText*          fmt,
    ub4                     fmt_length,
    const NCIText*          nls_params,
    ub4                     nls_p_length,
    ub4*                    buf_size,
    NCIText*                buf 
);

NCI_API
sword
NCINumberMod(
    NCIError*               err,
    const NCINumber*        number1,
    const NCINumber*        number2,
    NCINumber*              result
);

NCI_API
sword
NCINumberDiv(
    NCIError*               err,
    const NCINumber*        number1,
    const NCINumber*        number2,
    NCINumber*              result
);

NCI_API
sword
NCINumberMul(
    NCIError*               err,
    const NCINumber*        number1,
    const NCINumber*        number2,
    NCINumber*              result
);

NCI_API
sword
NCINumberSub(
    NCIError*               err,
    const NCINumber*        number1,
    const NCINumber*        number2,
    NCINumber*              result
);

NCI_API
sword
NCINumberAdd(
    NCIError*               err,
    const NCINumber*        number1,
    const NCINumber*        number2,
    NCINumber*              result
);

NCI_API
sword
NCINumberDec(
    NCIError*               err,
    NCINumber*              number
);

NCI_API
sword
NCINumberInc(
    NCIError*               err,
    NCINumber*              number
);

NCI_API
sword
NCINumberNeg(
    NCIError*               err,
    const NCINumber*        number,
    NCINumber*              result
);

NCI_API
sword
NCINumberAbs(
    NCIError*               err,
    const NCINumber*        number,
    NCINumber*              result
);

NCI_API
ub1*
NCIRawPtr(
    NCIEnv*                 envhp,
    const NCIRaw*           raw
);

NCI_API
ub4
NCIRawSize(
    NCIEnv*                 envhp,
    const NCIRaw*           raw
);

NCI_API
sword
NCIRawAllocSize(
    NCIEnv*                 envhp,
    NCIError*               errhp,
    const NCIRaw*           raw,
    ub4*                    allocsize
);

NCI_API 
sword 
NCIRawAssignBytes(
    NCIEnv*                 envhp,
    NCIError*               errhp,
    const ub1*              source,
    ub4                     source_len,
    NCIRaw**                target
);

NCI_API
sword
NCIRawResize(
    NCIEnv*                 envhp,
    NCIError*               errhp,
    ub2                     new_size,
    NCIRaw**                raw
);

NCI_API
sword
NCIRawAssignRaw(
    NCIEnv*                 envhp,
    NCIError*               errhp,
    const NCIRaw*           rhs,
    NCIRaw**                lhs
);

NCI_API 
text*
NCIStringPtr(
    NCIEnv*                 env,
    const NCIString*        vs
);

NCI_API
sword 
NCIDateTimeToText(
    void*                   hndl,
    NCIError*               err,
    const NCIDateTime*      date,
    const NCIText*          fmt,
    ub1                     fmt_length,
    ub1                     fsprec,
    const NCIText*          lang_name,
    size_t                  lang_length,
    ub4*                    buf_size,
    NCIText*                buf
);

NCI_API
sword 
NCIDateTimeFromText(
    void*                   hndl,
    NCIError*               err,
    const NCIText*          date_str,
    size_t                  dstr_length,
    const NCIText*          fmt,
    ub1                     fmt_length,
    const NCIText*          lang_name,
    size_t                  lang_length,
    NCIDateTime*            datetime
);

NCI_API
sword 
NCIDateAddMonths(
    NCIError*               err,
    const NCIDate*          date,
    sb4                     num_months,
    NCIDate*                result 
);

NCI_API
sword 
NCIDateAddDays(
    NCIError*               err,
    const NCIDate*          date,
    sb4                     num_days,
    NCIDate*                result
);

NCI_API
sword 
NCIDateNextDay(
    NCIError*               err,
    const NCIDate*          date,
    const NCIText*          day,
    ub4                     day_length,
    NCIDate*                next_day
);

NCI_API
sword 
NCIDateFromText(
    NCIError*               err,
    const NCIText*          date_str,
    ub4                     d_str_length,
    const NCIText*          fmt,
    ub1                     fmt_length,
    const NCIText*          lang_name,
    ub4                     lang_length,
    NCIDate*                date 
);

NCI_API
sword 
NCIDateToText(
    NCIError*               err,
    const NCIDate*          date,
    const NCIText*          fmt,
    ub1                     fmt_length,
    const NCIText*          lang_name,
    ub4                     lang_length,
    ub4*                    buf_size,
    NCIText*                buf
);

NCI_API
sword
NCIDateCompare(
    NCIError*               err,
    const NCIDate*          date1,
    const NCIDate*          date2,
    sword*                  result
);

NCI_API
sword 
NCIDateCheck(
    NCIError*               err,
    const NCIDate*          date,
    uword*                  valid
);

NCI_API
sword 
NCIDateDaysBetween(
    NCIError*               err,
    const NCIDate*          date1,
    const NCIDate*          date2,
    sb4*                    num_days
);

NCI_API
sword 
NCIDateLastDay(
    NCIError*               err,
    const NCIDate*          date,
    NCIDate*                last_day
);

NCI_API
sword 
NCIDateSysDate(
    NCIError*               err,
    NCIDate*                sys_date
);

NCI_API
sword
NCINlsNumericInfoGet(
    void*                   hndl,
    NCIError*               errhp,
    sb4*                    val,
    ub2                     item
);

NCI_API
sword
NCIDateTimeGetDate(
    dvoid*                  hndl,
    NCIError*               err,
    CONST NCIDateTime*      datetime,
    sb2*                    year,
    ub1*                    month,
    ub1*                    day
);

NCI_API
sword
NCIDateTimeGetTime(
    dvoid*                  hndl,
    NCIError*               err,
    NCIDateTime*            datetime,
    ub1*                    hour,
    ub1*                    min,
    ub1*                    sec,
    ub4*                    fsec
);

NCI_API
sword 
NCIDateTimeAssign(
    void*                   hndl,
    NCIError*               err,
    const NCIDateTime*      from,
    NCIDateTime*            to
);

NCI_API
sword
NCIDateTimeGetTimeZoneOffset(
    void*                   hndl,
    NCIError*               err,
    const NCIDateTime*      datetime,
    sb1*                    hour,
    sb1*                    min
);

NCI_API
sword
NCIDateTimeGetTimeZoneName(
    dvoid*                  hndl,
    NCIError*               err,
    CONST NCIDateTime*      datetime,
    ub1*                    buf,
    ub4*                    buflen
);

NCI_API
sword 
NCIDateTimeConstruct(
    dvoid*                  hndl,
    NCIError*               err,
    NCIDateTime*            datetime,
    sb2                     year,
    ub1                     month,
    ub1                     day,
    ub1                     hour,
    ub1                     min,
    ub1                     sec,
    ub4                     fsec,
    NCIText*                timezone,
    size_t                  timezone_length
);

NCI_API
sword
NCIThreadMutexInit(
    void*                   hndl,
    NCIError*               err,
    NCIThreadMutex**        mutex
);

NCI_API
sword
NCIThreadMutexAcquire(
    void*                   hndl,
    NCIError*               err,
    NCIThreadMutex*         mutex
);

NCI_API
sword
NCIThreadMutexRelease(
    void*                   hndl,
    NCIError*               err,
    NCIThreadMutex*         mutex
);

NCI_API
sword
NCIThreadMutexDestroy(
    void*                   hndl,
    NCIError*               err,
    NCIThreadMutex**        mutex
);

NCI_API
sword 
NCIConnectionPoolCreate(
    NCIEnv*                 envhp,
    NCIError*               errhp,
    NCICPool*               poolhp,
    NCIText**               poolName,
    sb4*                    poolNameLen,
    const NCIText*          dblink,
    sb4                     dblinkLen,
    ub4                     connMin,
    ub4                     connMax,
    ub4                     connIncr,
    const NCIText*          poolUsername,
    sb4                     poolUserLen,
    const NCIText*          poolPassword,
    sb4                     poolPassLen,
    ub4                     mode
);

NCI_API
sword
NCIConnectionPoolDestroy(
    NCICPool*               poolhp,
    NCIError*               errhp,
    ub4                     mode
);

NCI_API
sword 
NCISessionGet(
    NCIEnv*                 envhp,
    NCIError*               errhp,
    NCISvcCtx**             svchp,
    NCIAuthInfo*            authInfop,
    NCIText*                dbName,
    ub4                     dbName_len,
    const NCIText*          tagInfo,
    ub4                     tagInfo_len,
    NCIText**               retTagInfo,
    ub4*                    retTagInfo_len,
    boolean*                found,
    ub4                     mode
);

NCI_API
sword 
NCISessionRelease(
    NCISvcCtx*              svchp,
    NCIError*               errhp,
    NCIText*                tag,
    ub4                     tag_len,
    ub4                     mode
);

NCI_API
sword 
NCIPing(
    NCISvcCtx*              svchp,
    NCIError*               errhp,
    ub4                     mode
);

NCI_API
sword 
NCIDateZoneToZone(
    NCIError*               err,
    const NCIDate*          date1,
    const NCIText*          zon1,
    ub4                     zon1_length,
    const NCIText*          zon2,
    ub4                     zon2_length,
    NCIDate*                date2 
);

NCI_API 
sword 
NCILobGetLength2(
    NCISvcCtx*              svchp,
    NCIError*               errhp,
    NCILobLocator*          locp,
    ub8*                    lenp 
);

NCI_API
sword
NCIThreadInit(
    void*                   hndl,
    NCIError*               err
);

NCI_API
void
NCIThreadProcessInit();

NCI_API
sword
NCIThreadTerm(
    void*                   hndl,
    NCIError*               err
);

NCI_API
sword
NCILobTrim2(
    NCISvcCtx*              svchp,
    NCIError*               errhp,
    NCILobLocator*          locp,
    ub8                     newlen
);

NCI_API
sword
NCILobWrite2(
    NCISvcCtx*              svchp,
    NCIError*               errhp,
    NCILobLocator*          locp,
    ub8*                    byte_amtp,
    ub8*                    char_amtp,
    ub8                     offset,
    void*                   bufp,
    ub8                     buflen,
    ub1                     piece,
    void*                   ctxp,
    sb4                     (*cbfp)(void* ctxp, void* bufp, ub8* lenp, ub1* piecep, void** changed_bufpp, ub8* changed_lenp),
    ub2                     csid,
    ub1                     csfrm
);

NCI_API
sword
NCILobErase(
    NCISvcCtx*              svchp,
    NCIError*               errhp,
    NCILobLocator*          locp,
    ub4*                    amount,
    ub4                     offset
);

NCI_API
sword
NCILobErase2(
    NCISvcCtx*              svchp,
    NCIError*               errhp,
    NCILobLocator*          locp,
    ub8*                    amount,
    ub8                     offset
);

NCI_API
sword
NCILobGetChunkSize(
    NCISvcCtx*              svchp,
    NCIError*               errhp,
    NCILobLocator*          locp,
    ub4*                    chunk_size
);

NCI_API
sword
NCILobCopy(
    NCISvcCtx*              svchp,
    NCIError*               errhp,
    NCILobLocator*          dst_locp,
    NCILobLocator*          src_locp,
    ub4                     amount,
    ub4                     dst_offset,
    ub4                     src_offset
);

NCI_API
sword
NCILobCopy2(
    NCISvcCtx*              svchp,
    NCIError*               errhp,
    NCILobLocator*          dst_locp,
    NCILobLocator*          src_locp,
    ub8                     amount,
    ub8                     dst_offset,
    ub8                     src_offset
);

NCI_API
sword
NCILobLoadFromFile2(
    NCISvcCtx*              svchp,
    NCIError*               errhp,
    NCILobLocator*          dst_locp,
    NCILobLocator*          src_locp,
    ub8                     amount,
    ub8                     dst_offset,
    ub8                     src_offset
); 

NCI_API
sword
NCILobWriteAppend(
    NCISvcCtx*              svchp,
    NCIError*               errhp,
    NCILobLocator*          locp,
    ub4*                    amtp,
    void*                   bufp,
    ub4                     buflen,
    ub1                     piece,
    void*                   ctxp,
    sb4                     (*cbfp)(void* ctxp, void* bufp, ub4* lenp, ub1* piecep),
    ub2                     csid,
    ub1                     csfrm 
);

NCI_API
sword
NCILobIsTemporary(
    NCIEnv*                 envhp,
    NCIError*               errhp,
    NCILobLocator*          locp,
    boolean*                is_temporary
);

NCI_API
sword
NCILobOpen(
    NCISvcCtx*              svchp,
    NCIError*               errhp,
    NCILobLocator*          locp,
    ub1                     mode
);

NCI_API
sword
NCILobClose(
    NCISvcCtx*              svchp,
    NCIError*               errhp,
    NCILobLocator*          locp
);

NCI_API
sword 
NCIDateTimeIntervalAdd(
    dvoid*                  hndl,
    NCIError*               err,
    NCIDateTime*            datetime,
    NCIInterval*            inter,
    NCIDateTime*            outdatetime
);

NCI_API
sword 
NCIDateTimeIntervalSub(
    dvoid*                  hndl,
    NCIError*               err,
    NCIDateTime*            datetime,
    NCIInterval*            inter,
    NCIDateTime*            outdatetime
);

NCI_API
sword
NCIDateTimeSubtract(
    void*                   hndl,
    NCIError*               err,
    NCIDateTime*            indate1,
    NCIDateTime*            indate2,
    NCIInterval*            inter
);

NCI_API
sword
NCIDateTimeSysTimeStamp(
    void*                   hndl,
    NCIError*               err,
    NCIDateTime*            sys_date
);

NCI_API
sword
NCIDateTimeConvert(
    void*                   hndl,
    NCIError*               err,
    NCIDateTime*            indate,
    NCIDateTime*            outdate
);

NCI_API
sword
NCIDateTimeCheck(
    void*                   hndl,
    NCIError*               err,
    const NCIDateTime*      date,
    ub4*                    valid
);

NCI_API
sword
NCIDateTimeCompare(
    void*                   hndl,
    NCIError*               err,
    const NCIDateTime*      date1,
    const NCIDateTime*      date2,
    sword*                  result
);

NCI_API
sword
NCIThreadIdInit(
    void*                   hndl,
    NCIError*               err,
    NCIThreadId**           tid
);

NCI_API
sword
NCIThreadHndInit(
    void*                   hndl,
    NCIError*               err,
    NCIThreadHandle**       thnd
);

NCI_API
sword
NCIThreadIdDestroy(
    void*                   hndl,
    NCIError*               err,
    NCIThreadId**           tid
);

NCI_API
sword
NCIThreadHndDestroy(
    void*                   hndl,
    NCIError*               err,
    NCIThreadHandle**       thnd
);

NCI_API
sword
NCIThreadClose(
    void*                   hndl,
    NCIError*               err,
    NCIThreadHandle*        tHnd
);

NCI_API
sword
NCIThreadCreate(
    void*                   hndl,
    NCIError*               err,
    void                    (*start)(void*),
    void*                   arg,
    NCIThreadId*            tid,
    NCIThreadHandle*        tHnd
);

NCI_API
sword
NCIThreadJoin(
    void*                   hndl,
    NCIError*               err,
    NCIThreadHandle*        tHnd
);

NCI_API
sword 
NCIStmtRelease(
    NCIStmt*                stmthp,
    NCIError*               errhp,
    const NCIText*          key,
    ub4                     keylen,
    ub4                     mode
);

NCI_API
sword 
NCIStmtPrepareWithCache(
    NCISvcCtx*              svchp,
    NCIStmt**               stmthp,
    NCIError*               errhp,
    const NCIText*          stmttext,
    ub4                     stmt_len,
    const NCIText*          key,
    ub4                     keylen,
    ub4                     language,
    ub4                     mode
);

NCI_API
sword 
NCILobAppend(
    NCISvcCtx*              svchp,
    NCIError*               errhp,
    NCILobLocator*          dst_locp,
    NCILobLocator*          src_locp 
);

NCI_API
sword
NCINumberCmp(
    NCIError*               err,
    const NCINumber*        number1,
    const NCINumber*        number2,
    sword*                  result
);

NCI_API
sword
NCINumberIsInt(
    NCIError*               err,
    const NCINumber*        number,
    boolean*                result
);

NCI_API
sword
NCILogon2(
    NCIEnv*                 envhp,
    NCIError*               errhp,
    NCISvcCtx**             svchp,
    CONST NCIText*          username,
    ub4                     uname_len,
    CONST NCIText*          password,
    ub4                     passwd_len,
    CONST NCIText*          dbname,
    ub4                     dbname_len,
    ub4                     mode
);

NCI_API 
sword
NCILobCharSetId(
    NCIEnv*                 envhp,
    NCIError*               errhp,
    const NCILobLocator*    locp,
    ub2*                    csid
);

NCI_API 
sword
NCIDirPathColArrayRowGet(
    NCIDirPathColArray*     dpca,
    NCIError*               errhp,
    ub4                     rownum,
    ub1***                  cvalppp,
    ub4**                   clenpp,
    ub1**                   cflgpp
);

NCI_API
ub4
NCIStringSize(
    NCIEnv*                 env,
    const NCIString*        vs
);

NCI_API 
sword 
NCIStringAssignText(
    NCIEnv*                 env,
    NCIError*               err,
    const NCIText*          rhs,
    ub2                     rhs_len,
    NCIString**             lhs
);

NCI_API
sword
NCIRowidToChar(
    NCIRowid*               rowidDesc,
    NCIText*                outbfp,
    ub2*                    outbflp,
    NCIError*               errhp
);

NCI_API
sword
NCINlsEnvironmentVariableGet(
    void*                   val,
    size_t                  size,
    ub2                     item,
    ub2                     charset,
    size_t*                 rsize
);

NCI_API 
sword 
NCIStringAllocSize(
    NCIEnv*                 env,
    NCIError*               err,
    const NCIString*        vs,
    ub4*                    allocsize
);

NCI_API 
sword 
NCIStringAssign(
    NCIEnv*                 env,
    NCIError*               err,
    const NCIString*        rhs,
    NCIString**             lhs
);

NCI_API 
sword 
NCIStringResize(
    NCIEnv*                 env,
    NCIError*               err,
    ub4                     new_size,
    NCIString**             str
);

NCI_API
sword 
NCIDateAssign(
    NCIError*               err,
    const NCIDate*          from,
    NCIDate*                to 
);

NCI_API 
sword
NCIDefineDynamic(
    NCIDefine*              defnp,
    NCIError*               errhp,
    void*                   octxp,
    NCICallbackDefine       ocbfp 
);

NCI_API
sword
NCIStmtGetBindInfo(
    NCIStmt*                stmtp,
    NCIError*               errhp,
    ub4                     size,
    ub4                     startloc,
    sb4*                    found,
    NCIText*                bvnp[],
    ub1                     bvnl[],
    NCIText*                invp[],
    ub1                     inpl[],
    ub1                     dupl[],
    NCIBind*                hndl[]
);

NCI_API
sword
NCIDateTimeToArray(
    void*                   hndl,
    NCIError*               err,
    const NCIDateTime*      datetime,
    const NCIInterval*      reftz,
    ub1*                    outarray,
    ub4*                    len,
    ub1                     fsprec
);

NCI_API
sword
NCIDateTimeFromArray(
    void*                   hndl,
    NCIError*               err,
    const ub1*              inarray,
    ub4*                    len,
    ub1                     type,
    NCIDateTime*            datetime,
    const NCIInterval*      reftz,
    ub1                     fsprec 
);

NCI_API
sword
NCITerminate(
    ub4                     mode
);

NCI_API
size_t
NCIMultiByteStrCaseConversion(
    void*                   hndl,
    NCIText*                dststr,
    const NCIText*          srcstr,
    ub4                     flag
);

NCI_API 
sword
NCIClientVersion(
    sword*                  major_version,
    sword*                  minor_version,
    sword*                  update_num,
    sword*                  patch_num,
    sword*                  port_update_num
);

NCI_API
ub2
NCINlsCharSetNameToId(
    void*                   hndl,
    const NCIText*          name
);

NCI_API
sword
NCINlsCharSetIdToName(
    void*                   hndl,
    NCIText*                buf,
    size_t                  buflen,
    ub2                     id
);

NCI_API
sword
NCILobEnableBuffering(
    NCISvcCtx*              svchp,
    NCIError*               errhp,
    NCILobLocator*          locp
);

NCI_API
sword
NCILobDisableBuffering(
    NCISvcCtx*              svchp,
    NCIError*               errhp,
    NCILobLocator*          locp
);

NCI_API
sword
NCILobDurationBegin(
    NCIEnv*                 env,
    NCIError*               err,
    CONST NCISvcCtx*        svc,
    NCIDuration             parent,
    NCIDuration*            duration
);

NCI_API
sword
NCILobDurationEnd(
    NCIEnv*                 env,
    NCIError*               err,
    CONST NCISvcCtx*        svc,
    NCIDuration             duration
);

NCI_API
sword
NCITypeArrayByName(
    NCIEnv*                 envhp,
    NCIError*               errhp,
    const NCISvcCtx*        svc,
    ub4                     array_len,
    const NCIText*          schema_name[],
    ub4                     s_length[],
    const NCIText*          type_name[],
    ub4                     t_length[],
    const NCIText*          version_name[],
    ub4                     v_length[],
    NCIDuration             pin_duration,
    NCITypeGetOpt           get_option,
    NCIType*                tdo[]
);

NCI_API
sword
NCITypeArrayByRef(
    NCIEnv*                 envhp,
    NCIError*               errhp,
    ub4                     array_len,
    const NCIRef*           type_ref[],
    NCIDuration             pin_duration,
    NCITypeGetOpt           get_option,
    NCIType*                tdo[]
);

NCI_API
sword
NCITypeByName(
    NCIEnv*                 env,
    NCIError*               err, 
    const NCISvcCtx*        svc, 
    const NCIText*          schema_name,
    ub4                     s_length, 
    const NCIText*          type_name, 
    ub4                     t_length, 
    const NCIText*          version_name,
    ub4                     v_length,
    NCIDuration             pin_duration,
    NCITypeGetOpt           get_option,
    NCIType**               tdo 
);

NCI_API
sword
NCITypeByRef(
    NCIEnv*                 env,
    NCIError*               err,
    const NCIRef*           type_ref,
    NCIDuration             pin_duration,
    NCITypeGetOpt           get_option,
    NCIType**               tdo 
);

NCI_API
cbool
CryptoInit(
    void**                  crypto_para
); 

NCI_API
void
CryptoDestroy(
    void*                   crypto_para
); 

NCI_API
cbool
CryptoCipherEncryptInit(
    ub2                     inner_id,
    void*                   crypto_para,
    ub1*                    key,
    ub2                     key_size,
    void**                  encrypt_para
);

NCI_API
sb4
CryptoCipherGetCipherextSize(
    ub2                     inner_id,
    void*                   crypto_para,
    void*                   encrypt_para,
    sb4                     plain_text_size
); 

NCI_API
sb4
CryptoCipherEncrypt(
    ub2                     inner_id,
    void*                   crypto_para,
    void*                   encrypt_para,
    ub1*                    plain_text,
    ub2                     plain_text_size,
    ub1*                    cipher_text,
    ub2                     cipher_text_buf_size
); 

NCI_API
void 
CryptoCipherCleanup(
    ub2                     inner_id,
    void*                   crypto_para,
    void*                   cipher_para
); 

NCI_API
cbool 
CryptoCipherDecryptInit(
    ub2                     inner_id,
    void*                   crypto_para,
    ub1*                    key,
    ub2                     key_size,
    void**                  decrypt_para
);

NCI_API
sb4
CryptoCipherGetPlainTextSize(
    ub2                     inner_id,
    void*                   crypto_para,
    void*                   decrypt_para,
    sb4                     cipher_text_size
);

NCI_API
sb4
CryptoCipherDecrypt(
    ub2                     inner_id,
    void*                   crypto_para,
    void*                   decrypt_para,
    ub1*                    cipher_text,
    ub2                     cipher_text_size,
    ub1*                    plain_text,
    ub2                     plain_text_buf_size
);

NCI_API
cbool
CryptoCipherHashInit(
    ub2                     inner_id,
    void*                   crypto_para,
    void**                  hash_para
);

NCI_API
void
CryptoCipherHashUpdate(
    ub2                     inner_id,
    void*                   crypto_para,
    void*                   hash_para,
    ub1*                    msg,
    ub2                     msg_size
);

NCI_API
sb4
CryptoCipherHashFinal(
    ub2                     inner_id,
    void*                   crypto_para,
    void*                   hash_para,
    ub1*                    digest,
    ub2                     digest_buf_size
);

#ifdef __cplusplus
}
#endif      //__cplusplus

#endif      //_NCI_H
