USE [wx]
GO
/*==============================================================*/
/* DBMS name:      Microsoft SQL Server 2005                    */
/* Created on:     2011-5-21 17:48:52                           */
/*==============================================================*/


if exists (select 1
            from  sysobjects
           where  id = object_id('companyBase')
            and   type = 'U')
   drop table companyBase
go

if exists (select 1
            from  sysobjects
           where  id = object_id('dictionary')
            and   type = 'U')
   drop table dictionary
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('employee')
            and   name  = 'Relationship_8_FK'
            and   indid > 0
            and   indid < 255)
   drop index employee.Relationship_8_FK
go

if exists (select 1
            from  sysobjects
           where  id = object_id('employee')
            and   type = 'U')
   drop table employee
go

if exists (select 1
            from  sysobjects
           where  id = object_id('functinPoint')
            and   type = 'U')
   drop table functinPoint
go

if exists (select 1
            from  sysobjects
           where  id = object_id('"group"')
            and   type = 'U')
   drop table "group"
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('groupFunctionPointPower')
            and   name  = 'Relationship_4_FK'
            and   indid > 0
            and   indid < 255)
   drop index groupFunctionPointPower.Relationship_4_FK
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('groupFunctionPointPower')
            and   name  = 'Relationship_3_FK'
            and   indid > 0
            and   indid < 255)
   drop index groupFunctionPointPower.Relationship_3_FK
go

if exists (select 1
            from  sysobjects
           where  id = object_id('groupFunctionPointPower')
            and   type = 'U')
   drop table groupFunctionPointPower
go

if exists (select 1
            from  sysobjects
           where  id = object_id('hint')
            and   type = 'U')
   drop table hint
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('hintuser')
            and   name  = 'Relationship_7_FK'
            and   indid > 0
            and   indid < 255)
   drop index hintuser.Relationship_7_FK
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('hintuser')
            and   name  = 'Relationship_6_FK'
            and   indid > 0
            and   indid < 255)
   drop index hintuser.Relationship_6_FK
go

if exists (select 1
            from  sysobjects
           where  id = object_id('hintuser')
            and   type = 'U')
   drop table hintuser
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('login')
            and   name  = 'Relationship_5_FK'
            and   indid > 0
            and   indid < 255)
   drop index login.Relationship_5_FK
go

if exists (select 1
            from  sysobjects
           where  id = object_id('login')
            and   type = 'U')
   drop table login
go

if exists (select 1
            from  sysobjects
           where  id = object_id('messageBoard')
            and   type = 'U')
   drop table messageBoard
go

if exists (select 1
            from  sysobjects
           where  id = object_id('newID')
            and   type = 'U')
   drop table newID
go

if exists (select 1
            from  sysobjects
           where  id = object_id('publicinFormation')
            and   type = 'U')
   drop table publicinFormation
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('userGroup')
            and   name  = 'Relationship_2_FK'
            and   indid > 0
            and   indid < 255)
   drop index userGroup.Relationship_2_FK
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('userGroup')
            and   name  = 'Relationship_1_FK'
            and   indid > 0
            and   indid < 255)
   drop index userGroup.Relationship_1_FK
go

if exists (select 1
            from  sysobjects
           where  id = object_id('userGroup')
            and   type = 'U')
   drop table userGroup
go

if exists (select 1
            from  sysobjects
           where  id = object_id('userTBL')
            and   type = 'U')
   drop table userTBL
go

/*==============================================================*/
/* Table: companyBase                                           */
/*==============================================================*/
create table companyBase (
   col_companyBase_id   int                  not null,
   col_companyBase_companyName nvarchar(128)        not null,
   col_companyBase_higherAuthoritiesID int                  not null,
   col_companyBase_phone nvarchar(20)         null,
   col_companyBase_header int                  null,
   col_companyBase_cretateTime datetime             null,
   col_companyBase_memo text                 null,
   col_companyBase_recordState tinyint              not null,
   col_companyBase_operator int                  not null,
   col_companyBase_operatoTime datetime             not null,
   col_companyBase_recordCopyFrom int                  not null,
   constraint PK_COMPANYBASE primary key nonclustered (col_companyBase_id)
)
go

/*==============================================================*/
/* Table: dictionary                                            */
/*==============================================================*/
create table dictionary (
   col_dictionary_id    int                  not null,
   col_dictionary_type  text                 not null,
   col_dictionary_enum  int                  not null,
   col_dictionary_name  text                 not null,
   col_dictionary_manual text                 null,
   col_dictionary_recordState tinyint              not null,
   col_dictionary_operator int                  not null,
   col_dictionary_operatoTime datetime             not null,
   col_dictionary_recordCopyFrom int                  not null,
   constraint PK_DICTIONARY primary key nonclustered (col_dictionary_id)
)
go

/*==============================================================*/
/* Table: employee                                              */
/*==============================================================*/
create table employee (
   col_employee_id      int                  not null,
   col_companyBase_id   int                  null,
   col_employee_name    nvarchar(20)         not null,
   col_employee_sex     int                  not null,
   col_employee_birthday datetime             not null,
   col_employee_mobile  nvarchar(20)         null,
   col_employee_phone   nvarchar(20)         null,
   col_employee_position int                  not null,
   col_employee_recordState tinyint              not null,
   col_employee_operator int                  not null,
   col_employee_operatoTime datetime             not null,
   col_employee_recordCopyFrom int                  not null,
   constraint PK_EMPLOYEE primary key nonclustered (col_employee_id)
)
go

/*==============================================================*/
/* Index: Relationship_8_FK                                     */
/*==============================================================*/
create index Relationship_8_FK on employee (
col_companyBase_id ASC
)
go

/*==============================================================*/
/* Table: functinPoint                                          */
/*==============================================================*/
create table functinPoint (
   col_functinPoint_id  int                  not null,
   col_functinPoint_name text                 not null,
   col_functinPoint_displayName text                 null,
   col_functinPoint_recordState tinyint              not null,
   col_functinPoint_operator int                  not null,
   col_functinPoint_opertoTime datetime             not null,
   col_functinPoint_copyFromID int                  not null,
   constraint PK_FUNCTINPOINT primary key nonclustered (col_functinPoint_id)
)
go

/*==============================================================*/
/* Table: "group"                                               */
/*==============================================================*/
create table "group" (
   col_group_id         int                  not null,
   col_group_name       nvarchar(128)        not null,
   col_group_recordState tinyint              not null,
   col_group_opertor    int                  not null,
   col_group_opertoTime datetime             not null,
   col_group_copyFromID int                  not null,
   constraint PK_GROUP primary key nonclustered (col_group_id)
)
go

/*==============================================================*/
/* Table: groupFunctionPointPower                               */
/*==============================================================*/
create table groupFunctionPointPower (
   col_group_id         int                  not null,
   col_functinPoint_id  int                  not null,
   col_groupFuncitonPointPower int                  not null,
   col_groupFunctionPointPower_recordState tinyint              not null,
   col_groupFunctionPointPower_operator int                  not null,
   col_groupFunctionPointPower_operatoTime datetime             not null,
   col_groupFunctionPointPower_copyFrom int                  not null
)
go

/*==============================================================*/
/* Index: Relationship_3_FK                                     */
/*==============================================================*/
create index Relationship_3_FK on groupFunctionPointPower (
col_functinPoint_id ASC
)
go

/*==============================================================*/
/* Index: Relationship_4_FK                                     */
/*==============================================================*/
create index Relationship_4_FK on groupFunctionPointPower (
col_group_id ASC
)
go

/*==============================================================*/
/* Table: hint                                                  */
/*==============================================================*/
create table hint (
   col_HINT_NO          int                  not null,
   col_HINT_sender      text                 null,
   col_HINT_type        int                  not null,
   col_HINT_whileHint   int                  null,
   col_HINT_while       int                  not null,
   col_HINT_hintTime    datetime             not null,
   col_HINT_lastTime    datetime             null,
   col_HINT_AutoRun     tinyint              not null,
   col_HINT_runText     text                 null,
   col_HINT_isHint      tinyint              not null,
   col_HINT_title       nvarchar(128)        not null,
   col_HINT_text        text                 not null,
   col_HINT_recordState tinyint              not null,
   col_HINT_operator    int                  not null,
   col_HINT_operatoTime datetime             not null,
   col_HINT_copyFromID  int                  not null,
   constraint PK_HINT primary key nonclustered (col_HINT_NO)
)
go

/*==============================================================*/
/* Table: hintuser                                              */
/*==============================================================*/
create table hintuser (
   hintuser_id          int                  not null,
   col_HINT_NO          int                  not null,
   col_user_id          int                  not null,
   hintuser_recordState tinyint              not null,
   hintuser_operator    int                  not null,
   hintuser_operatoTime datetime             not null,
   hintuser_copyFromID  int                  not null,
   constraint PK_HINTUSER primary key nonclustered (hintuser_id)
)
go

/*==============================================================*/
/* Index: Relationship_6_FK                                     */
/*==============================================================*/
create index Relationship_6_FK on hintuser (
col_user_id ASC
)
go

/*==============================================================*/
/* Index: Relationship_7_FK                                     */
/*==============================================================*/
create index Relationship_7_FK on hintuser (
col_HINT_NO ASC
)
go

/*==============================================================*/
/* Table: login                                                 */
/*==============================================================*/
create table login (
   col_login_id         int                  not null,
   col_user_id          int                  not null,
   col_login_loginTime  datetime             not null,
   col_login_state      int                  not null,
   col_login_computerName nvarchar(128)        null,
   col_login_mac        text                 null,
   col_login_ip         text                 null,
   col_login_recordState tinyint              not null,
   col_login_operatorUserID int                  not null,
   col_login_operatoTime datetime             not null,
   col_login_copyFromID int                  not null,
   constraint PK_LOGIN primary key nonclustered (col_login_id)
)
go

/*==============================================================*/
/* Index: Relationship_5_FK                                     */
/*==============================================================*/
create index Relationship_5_FK on login (
col_user_id ASC
)
go

/*==============================================================*/
/* Table: messageBoard                                          */
/*==============================================================*/
create table messageBoard (
   col_MSGBOARD_NO      int                  not null,
   constraint PK_MESSAGEBOARD primary key nonclustered (col_MSGBOARD_NO)
)
go

/*==============================================================*/
/* Table: newID                                                 */
/*==============================================================*/
create table newID (
   col_newID_ID         int                  not null,
   col_newID_lastID     int                  not null,
   col_newID_tableName  nvarchar(32)         not null,
   constraint PK_NEWID primary key nonclustered (col_newID_ID)
)
go

/*==============================================================*/
/* Table: publicinFormation                                     */
/*==============================================================*/
create table publicinFormation (
   col_PUBFORM_NO       int                  not null,
   constraint PK_PUBLICINFORMATION primary key nonclustered (col_PUBFORM_NO)
)
go

/*==============================================================*/
/* Table: userGroup                                             */
/*==============================================================*/
create table userGroup (
   col_userGroup_id     int                  not null,
   col_group_id         int                  not null,
   col_user_id          int                  not null,
   col_userGroup_recordState tinyint              not null,
   col_userGroup_operator int                  not null,
   col_userGroup_operatoTime datetime             not null,
   col_userGroup_copyFromID int                  not null,
   constraint PK_USERGROUP primary key nonclustered (col_userGroup_id)
)
go

/*==============================================================*/
/* Index: Relationship_1_FK                                     */
/*==============================================================*/
create index Relationship_1_FK on userGroup (
col_user_id ASC
)
go

/*==============================================================*/
/* Index: Relationship_2_FK                                     */
/*==============================================================*/
create index Relationship_2_FK on userGroup (
col_group_id ASC
)
go

/*==============================================================*/
/* Table: userTBL                                               */
/*==============================================================*/
create table userTBL (
   col_user_id          int                  not null,
   col_user_loginName   nvarchar(20)         not null,
   col_user_empId       int                  null,
   col_user_passwd      nvarchar(256)        not null,
   col_user_recordState tinyint              not null,
   col_user_operator    int                  not null,
   col_user_operatoTime datetime             not null,
   col_user_copyFromID  int                  not null,
   constraint PK_USERTBL primary key nonclustered (col_user_id)
)
go

