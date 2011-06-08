USE [wx]
GO
/****** Object:  Table [dbo].[functinPoint]    Script Date: 06/08/2011 16:09:32 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[functinPoint](
	[col_functinPoint_id] [int] NOT NULL,
	[col_functinPoint_name] [text] NOT NULL,
	[col_functinPoint_displayName] [text] NULL,
	[col_functinPoint_recordState] [tinyint] NOT NULL,
	[col_functinPoint_operator] [int] NOT NULL,
	[col_functinPoint_opertoTime] [datetime] NOT NULL,
	[col_functinPoint_copyFromID] [int] NOT NULL,
 CONSTRAINT [PK_FUNCTINPOINT] PRIMARY KEY NONCLUSTERED 
(
	[col_functinPoint_id] ASC
)WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY]
) ON [PRIMARY] TEXTIMAGE_ON [PRIMARY]
GO
/****** Object:  Table [dbo].[group]    Script Date: 06/08/2011 16:09:32 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[group](
	[col_group_id] [int] NOT NULL,
	[col_group_name] [nvarchar](128) NOT NULL,
	[col_group_recordState] [tinyint] NOT NULL,
	[col_group_opertor] [int] NOT NULL,
	[col_group_opertoTime] [datetime] NOT NULL,
	[col_group_copyFromID] [int] NOT NULL,
 CONSTRAINT [PK_GROUP] PRIMARY KEY NONCLUSTERED 
(
	[col_group_id] ASC
)WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[groupFunctionPointPower]    Script Date: 06/08/2011 16:09:32 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[groupFunctionPointPower](
	[col_group_id] [int] NOT NULL,
	[col_functinPoint_id] [int] NOT NULL,
	[col_groupFuncitonPointPower] [int] NOT NULL,
	[col_groupFunctionPointPower_recordState] [tinyint] NOT NULL,
	[col_groupFunctionPointPower_operator] [int] NOT NULL,
	[col_groupFunctionPointPower_operatoTime] [datetime] NOT NULL,
	[col_groupFunctionPointPower_copyFrom] [int] NOT NULL
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[hint]    Script Date: 06/08/2011 16:09:32 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[hint](
	[col_HINT_NO] [int] NOT NULL,
	[col_HINT_sender] [text] NULL,
	[col_HINT_type] [int] NOT NULL,
	[col_HINT_whileHint] [int] NULL,
	[col_HINT_while] [int] NOT NULL,
	[col_HINT_hintTime] [datetime] NOT NULL,
	[col_HINT_lastTime] [datetime] NULL,
	[col_HINT_AutoRun] [tinyint] NOT NULL,
	[col_HINT_runText] [text] NULL,
	[col_HINT_isHint] [tinyint] NOT NULL,
	[col_HINT_title] [nvarchar](128) NOT NULL,
	[col_HINT_text] [text] NOT NULL,
	[col_HINT_recordState] [tinyint] NOT NULL,
	[col_HINT_operator] [int] NOT NULL,
	[col_HINT_operatoTime] [datetime] NOT NULL,
	[col_HINT_copyFromID] [int] NOT NULL,
 CONSTRAINT [PK_HINT] PRIMARY KEY NONCLUSTERED 
(
	[col_HINT_NO] ASC
)WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY]
) ON [PRIMARY] TEXTIMAGE_ON [PRIMARY]
GO
/****** Object:  Table [dbo].[hintuser]    Script Date: 06/08/2011 16:09:32 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[hintuser](
	[hintuser_id] [int] NOT NULL,
	[col_HINT_NO] [int] NOT NULL,
	[col_user_id] [int] NOT NULL,
	[hintuser_recordState] [tinyint] NOT NULL,
	[hintuser_operator] [int] NOT NULL,
	[hintuser_operatoTime] [datetime] NOT NULL,
	[hintuser_copyFromID] [int] NOT NULL,
 CONSTRAINT [PK_HINTUSER] PRIMARY KEY NONCLUSTERED 
(
	[hintuser_id] ASC
)WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[login]    Script Date: 06/08/2011 16:09:32 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[login](
	[col_login_id] [int] NOT NULL,
	[col_user_id] [int] NOT NULL,
	[col_login_loginTime] [datetime] NOT NULL,
	[col_login_state] [int] NOT NULL,
	[col_login_computerName] [nvarchar](128) NULL,
	[col_login_mac] [text] NULL,
	[col_login_ip] [text] NULL,
	[col_login_recordState] [tinyint] NOT NULL,
	[col_login_operatorUserID] [int] NOT NULL,
	[col_login_operatoTime] [datetime] NOT NULL,
	[col_login_copyFromID] [int] NOT NULL,
 CONSTRAINT [PK_LOGIN] PRIMARY KEY NONCLUSTERED 
(
	[col_login_id] ASC
)WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY]
) ON [PRIMARY] TEXTIMAGE_ON [PRIMARY]
GO
/****** Object:  Table [dbo].[messageBoard]    Script Date: 06/08/2011 16:09:32 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[messageBoard](
	[col_MSGBOARD_NO] [int] NOT NULL,
 CONSTRAINT [PK_MESSAGEBOARD] PRIMARY KEY NONCLUSTERED 
(
	[col_MSGBOARD_NO] ASC
)WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[newID]    Script Date: 06/08/2011 16:09:32 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[newID](
	[col_newID_ID] [int] NOT NULL,
	[col_newID_lastID] [int] NOT NULL,
	[col_newID_tableName] [nvarchar](32) NOT NULL,
 CONSTRAINT [PK_NEWID] PRIMARY KEY NONCLUSTERED 
(
	[col_newID_ID] ASC
)WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[publicinFormation]    Script Date: 06/08/2011 16:09:32 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[publicinFormation](
	[col_PUBFORM_NO] [int] NOT NULL,
 CONSTRAINT [PK_PUBLICINFORMATION] PRIMARY KEY NONCLUSTERED 
(
	[col_PUBFORM_NO] ASC
)WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[userGroup]    Script Date: 06/08/2011 16:09:32 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[userGroup](
	[col_userGroup_id] [int] NOT NULL,
	[col_group_id] [int] NOT NULL,
	[col_user_id] [int] NOT NULL,
	[col_userGroup_recordState] [tinyint] NOT NULL,
	[col_userGroup_operator] [int] NOT NULL,
	[col_userGroup_operatoTime] [datetime] NOT NULL,
	[col_userGroup_copyFromID] [int] NOT NULL,
 CONSTRAINT [PK_USERGROUP] PRIMARY KEY NONCLUSTERED 
(
	[col_userGroup_id] ASC
)WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[userTBL]    Script Date: 06/08/2011 16:09:32 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[userTBL](
	[col_user_id] [int] NOT NULL,
	[col_user_loginName] [nvarchar](20) NOT NULL,
	[col_user_empId] [int] NULL,
	[col_user_passwd] [nvarchar](256) NOT NULL,
	[col_user_recordState] [tinyint] NOT NULL,
	[col_user_operator] [int] NOT NULL,
	[col_user_operatoTime] [datetime] NOT NULL,
	[col_user_copyFromID] [int] NOT NULL,
 CONSTRAINT [PK_USERTBL] PRIMARY KEY NONCLUSTERED 
(
	[col_user_id] ASC
)WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[companyBase]    Script Date: 06/08/2011 16:09:32 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[companyBase](
	[col_companyBase_id] [int] NOT NULL,
	[col_companyBase_companyName] [nvarchar](128) NOT NULL,
	[col_companyBase_higherAuthoritiesID] [int] NOT NULL,
	[col_companyBase_phone] [nvarchar](20) NULL,
	[col_companyBase_header] [int] NULL,
	[col_companyBase_cretateTime] [datetime] NULL,
	[col_companyBase_memo] [text] NULL,
	[col_companyBase_recordState] [tinyint] NOT NULL,
	[col_companyBase_operator] [int] NOT NULL,
	[col_companyBase_operatoTime] [datetime] NOT NULL,
	[col_companyBase_recordCopyFrom] [int] NOT NULL,
 CONSTRAINT [PK_COMPANYBASE] PRIMARY KEY NONCLUSTERED 
(
	[col_companyBase_id] ASC
)WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY]
) ON [PRIMARY] TEXTIMAGE_ON [PRIMARY]
GO
/****** Object:  Table [dbo].[dictionary]    Script Date: 06/08/2011 16:09:32 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[dictionary](
	[col_dictionary_id] [int] NOT NULL,
	[col_dictionary_type] [text] NOT NULL,
	[col_dictionary_enum] [int] NOT NULL,
	[col_dictionary_name] [text] NOT NULL,
	[col_dictionary_manual] [text] NULL,
	[col_dictionary_recordState] [tinyint] NOT NULL,
	[col_dictionary_operator] [int] NOT NULL,
	[col_dictionary_operatoTime] [datetime] NOT NULL,
	[col_dictionary_recordCopyFrom] [int] NOT NULL,
 CONSTRAINT [PK_DICTIONARY] PRIMARY KEY NONCLUSTERED 
(
	[col_dictionary_id] ASC
)WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY]
) ON [PRIMARY] TEXTIMAGE_ON [PRIMARY]
GO
/****** Object:  Table [dbo].[employee]    Script Date: 06/08/2011 16:09:32 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[employee](
	[col_employee_id] [int] NOT NULL,
	[col_companyBase_id] [int] NULL,
	[col_employee_name] [nvarchar](20) NOT NULL,
	[col_employee_sex] [int] NOT NULL,
	[col_employee_birthday] [datetime] NOT NULL,
	[col_employee_mobile] [nvarchar](20) NULL,
	[col_employee_phone] [nvarchar](20) NULL,
	[col_employee_position] [int] NOT NULL,
	[col_employee_positionState] [int] NOT NULL,
	[col_employee_recordState] [tinyint] NOT NULL,
	[col_employee_operator] [int] NOT NULL,
	[col_employee_operatoTime] [datetime] NOT NULL,
	[col_employee_recordCopyFrom] [int] NOT NULL,
 CONSTRAINT [PK_EMPLOYEE] PRIMARY KEY NONCLUSTERED 
(
	[col_employee_id] ASC
)WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  View [dbo].[View_GroupFunPointPower]    Script Date: 06/08/2011 16:09:33 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
/*==============================================================*/
/* View: View_GroupFunPointPower                                */
/*==============================================================*/
create view [dbo].[View_GroupFunPointPower] as
SELECT     dbo.[group].col_group_id, dbo.functinPoint.col_functinPoint_name, dbo.functinPoint.col_functinPoint_displayName, 
                      dbo.groupFunctionPointPower.col_groupFuncitonPointPower
FROM         dbo.[group] INNER JOIN
                      dbo.groupFunctionPointPower ON dbo.[group].col_group_id = dbo.groupFunctionPointPower.col_group_id INNER JOIN
                      dbo.functinPoint ON dbo.groupFunctionPointPower.col_functinPoint_id = dbo.functinPoint.col_functinPoint_id
GO
/****** Object:  View [dbo].[View_UserGroup]    Script Date: 06/08/2011 16:09:33 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
/*==============================================================*/
/* View: View_UserGroup                                         */
/*==============================================================*/
create view [dbo].[View_UserGroup] as
SELECT     dbo.userGroup.col_userGroup_id, dbo.userTBL.col_user_id, dbo.[group].col_group_id, dbo.userTBL.col_user_loginName, dbo.[group].col_group_name
FROM         dbo.userTBL LEFT OUTER JOIN
                      dbo.userGroup ON dbo.userTBL.col_user_id = dbo.userGroup.col_user_id LEFT OUTER JOIN
                      dbo.[group] ON dbo.userGroup.col_group_id = dbo.[group].col_group_id
WHERE     (dbo.userTBL.col_user_recordState = 1) OR
                      (dbo.userTBL.col_user_recordState = 3)
GO
/****** Object:  StoredProcedure [dbo].[login_IsLogining]    Script Date: 06/08/2011 16:09:30 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
create procedure [dbo].[login_IsLogining] (
            @col_user_id int ) as
BEGIN

	SET NOCOUNT ON;
	
	declare @count int
	set @count=0
	
	select @count =COUNT(*) from [wx].dbo.login 
		where col_user_id=@col_user_id
			and [col_login_state]=1

	return @count
END
GO
/****** Object:  StoredProcedure [dbo].[login_login]    Script Date: 06/08/2011 16:09:30 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
create procedure [dbo].[login_login] (@col_login_id int 
            ,@col_user_id int 
            ,@col_login_loginTime datetime 
            ,@col_login_state int 
            ,@col_login_computerName char(128) 
            ,@col_login_mac char(128) 
            ,@col_login_ip text 
            ,@col_login_recordState tinyint 
            ,@col_login_operatorUserID int 
            ,@col_login_operatoTime datetime 
            ,@col_login_copyFromID int ) as
BEGIN

	SET NOCOUNT ON;
	
INSERT INTO [wx].dbo.login
           ([col_login_id]
           ,[col_user_id]
           ,[col_login_loginTime]
           ,[col_login_state]
           ,[col_login_computerName]
           ,[col_login_mac]
           ,[col_login_ip]
           ,[col_login_recordState]
           ,[col_login_operatorUserID]
           ,[col_login_operatoTime]
           ,[col_login_copyFromID])
     VALUES
           (@col_login_id
           ,@col_user_id
           ,getdate()
           ,1
           ,@col_login_computerName
           ,@col_login_mac
           ,@col_login_ip
           ,1
           ,@col_login_operatorUserID
           ,getdate()
           ,-1)

END
GO
/****** Object:  StoredProcedure [dbo].[login_logout]    Script Date: 06/08/2011 16:09:30 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
create procedure [dbo].[login_logout] (@col_login_id int 
            ,@col_login_state int 
            ,@col_login_operatorUserID int) as
BEGIN

	SET NOCOUNT ON;
	
UPDATE [wx].[dbo].login
      set [col_login_state] = @col_login_state 
      ,[col_login_recordState] = 2
      ,[col_login_operatorUserID] = @col_login_operatorUserID
      ,[col_login_operatoTime] = GETDATE()
 WHERE [col_login_id] = @col_login_id
 
END
GO
/****** Object:  StoredProcedure [dbo].[login_logoutException]    Script Date: 06/08/2011 16:09:30 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
create procedure [dbo].[login_logoutException] (@col_user_id int 
            ,@col_login_operatorUserID int) as
BEGIN

	SET NOCOUNT ON;
	
UPDATE [wx].[dbo].login
      set [col_login_state] = 3
      ,[col_login_recordState] = 2
      ,[col_login_operatorUserID] = @col_login_operatorUserID
      ,[col_login_operatoTime] = GETDATE()
 WHERE [col_user_id] = @col_user_id
	and [col_login_state] = 1
 
END
GO
/****** Object:  StoredProcedure [dbo].[login_logoutExceptionAll]    Script Date: 06/08/2011 16:09:30 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
create procedure [dbo].[login_logoutExceptionAll] (@col_login_operatorUserID int) as
BEGIN

	SET NOCOUNT ON;
	
UPDATE [wx].[dbo].login
      set [col_login_state] = 3
      ,[col_login_recordState] = 2
      ,[col_login_operatorUserID] = @col_login_operatorUserID
      ,[col_login_operatoTime] = GETDATE()
 WHERE [col_login_state] = 1
 
END
GO
/****** Object:  StoredProcedure [dbo].[comm_CreateNewID]    Script Date: 06/08/2011 16:09:30 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
create procedure [dbo].[comm_CreateNewID] (
 @tableName char(32)
 ) as
BEGIN

	SET NOCOUNT ON;

 UPDATE [wx].[dbo].[newID]  SET [col_newID_lastID] = [col_newID_lastID]+1 
	WHERE [col_newID_tableName] = @tableName
 
 declare @value int 
 set @value = -1
 
 select @value = [col_newID_lastID] 
	from [wx].[dbo].[newID] 
	WHERE [col_newID_tableName] = @tableName
 
 return @value

END
GO
/****** Object:  StoredProcedure [dbo].[userGroup_add]    Script Date: 06/08/2011 16:09:30 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
create procedure [dbo].[userGroup_add] (@col_userGroup_id int
            ,@col_group_id int
            ,@col_user_id int
            ,@col_userGroup_recordState tinyint
            ,@col_userGroup_operator int
            ,@col_userGroup_operatoTime datetime
            ,@col_userGroup_copyFromID int) as
BEGIN

INSERT INTO [wx].[dbo].[userGroup]
           (col_userGroup_id
           ,col_group_id
           ,col_user_id
           ,col_userGroup_recordState
           ,col_userGroup_operator
           ,col_userGroup_operatoTime
           ,col_userGroup_copyFromID)
     VALUES
           (@col_userGroup_id
           ,@col_group_id
           ,@col_user_id
           ,1
           ,@col_userGroup_operator
           ,getdate()
           ,-1)

END
GO
/****** Object:  StoredProcedure [dbo].[userGroup_delete]    Script Date: 06/08/2011 16:09:30 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
create procedure [dbo].[userGroup_delete] (@col_userGroup_id int
            ,@col_userGroup_operator int) as
BEGIN

delete [wx].[dbo].[userGroup]
 WHERE [col_userGroup_id] = @col_userGroup_id
 
END
GO
/****** Object:  StoredProcedure [dbo].[userGroup_edit]    Script Date: 06/08/2011 16:09:30 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
create procedure [dbo].[userGroup_edit] (@col_userGroup_id int
            ,@col_group_id int
            ,@col_userGroup_operator int) as
BEGIN

UPDATE [wx].[dbo].[userGroup]
   SET [col_group_id] = @col_group_id
      ,[col_userGroup_recordState] = 3
      ,[col_userGroup_operator] = @col_userGroup_operator
      ,[col_userGroup_operatoTime] = getdate()
 WHERE [col_userGroup_id] = @col_userGroup_id
 
END
GO
/****** Object:  StoredProcedure [dbo].[user_IsBeing]    Script Date: 06/08/2011 16:09:30 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
create procedure [dbo].[user_IsBeing] (
            @col_user_loginName char(20)) as
BEGIN

	SET NOCOUNT ON;
	
	declare @count int
	set @count=0
	
	select @count =COUNT(*) from dbo.userTBL where col_user_loginName=@col_user_loginName

	return @count
END
GO
/****** Object:  StoredProcedure [dbo].[user_add]    Script Date: 06/08/2011 16:09:30 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
create procedure [dbo].[user_add] (
            @col_user_id int,
            @col_user_loginName char(20),
            @col_user_empId int,
            @col_user_passwd char(256),
            @col_user_recordStat tinyint,
            @col_user_operator int,
            @col_user_operatoTime datetime,
            @col_user_copyFromID int) as
BEGIN

	SET NOCOUNT ON;
	
INSERT INTO [wx].dbo.userTBL
           (col_user_id
           ,col_user_loginName
           ,col_user_empId
           ,col_user_passwd
           ,col_user_recordState
           ,col_user_operator
           ,col_user_operatoTime
           ,col_user_copyFromID)
     VALUES
           (@col_user_id
           ,@col_user_loginName
           ,@col_user_empId
           ,@col_user_passwd
           ,1
           ,@col_user_operator
           ,getdate()
           ,-1)

END
GO
/****** Object:  StoredProcedure [dbo].[user_delete]    Script Date: 06/08/2011 16:09:30 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
create procedure [dbo].[user_delete] (
            @col_user_id int,
            @col_user_operator int) as
BEGIN

	SET NOCOUNT ON;
	
UPDATE [wx].[dbo].[userTBL]
   SET [col_user_recordState] = 2
      ,[col_user_operator] = @col_user_operator
      ,[col_user_operatoTime] = GETDATE()
 WHERE col_user_id = @col_user_id
END
GO
/****** Object:  StoredProcedure [dbo].[user_edit]    Script Date: 06/08/2011 16:09:30 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
create procedure [dbo].[user_edit] (
            @col_user_id int,
            @col_user_loginName char(20),
            @col_user_empId int,
            @col_user_passwd char(256),
            @col_user_recordStat tinyint,
            @col_user_operator int,
            @col_user_operatoTime datetime,
            @col_user_copyFromID int) as
BEGIN

	SET NOCOUNT ON;
	
UPDATE [wx].[dbo].[userTBL]
   SET [col_user_empId] = @col_user_empId
      ,[col_user_passwd] = @col_user_passwd
      ,[col_user_recordState] = 3
      ,[col_user_operator] = @col_user_operator
      ,[col_user_operatoTime] = GETDATE()
 WHERE col_user_id = @col_user_id
END
GO
/****** Object:  StoredProcedure [dbo].[dictionary_edit]    Script Date: 06/08/2011 16:09:30 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE procedure [dbo].[dictionary_edit] (
            @col_dictionary_id int,
            @col_dictionary_type text,
            @col_dictionary_enum int,
            @col_dictionary_name text,
            @col_dictionary_manual text,
            @col_user_recordStat tinyint,
            @col_user_operator int,
            @col_user_operatoTime datetime,
            @col_user_copyFromID int) as
BEGIN

	SET NOCOUNT ON;

 
 UPDATE [wx].[dbo].[dictionary]
   SET [col_dictionary_name] = @col_dictionary_name
      ,[col_dictionary_manual] = @col_dictionary_manual
      ,[col_dictionary_recordState] = 3
      ,[col_dictionary_operator] = @col_user_operator
      ,[col_dictionary_operatoTime] = GETDATE()
 WHERE convert(nvarchar,[col_dictionary_type])=convert(nvarchar,@col_dictionary_type) and 
		[col_dictionary_enum]=@col_dictionary_enum
END
GO
/****** Object:  StoredProcedure [dbo].[employee_add]    Script Date: 06/08/2011 16:09:30 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE procedure [dbo].[employee_add] (
			@col_employee_id int,
			@col_companyBase_id int,
			@col_employee_name nvarchar,
			@col_employee_sex int,
			@col_employee_birthday datetime,
			@col_employee_mobile nvarchar,
			@col_employee_phone nvarchar,
			@col_employee_position int,
			@col_employee_positionState int,
			@col_employee_recordState tinyint,
			@col_employee_operator int,
			@col_employee_operatoTime datetime,
			@col_employee_recordCopyFrom int	
            ) as
BEGIN

	SET NOCOUNT ON;
	
	INSERT INTO [wx].[dbo].[employee]
           ([col_employee_id]
           ,[col_companyBase_id]
           ,[col_employee_name]
           ,[col_employee_sex]
           ,[col_employee_birthday]
           ,[col_employee_mobile]
           ,[col_employee_phone]
           ,[col_employee_position]
           ,[col_employee_positionState]
           ,[col_employee_recordState]
           ,[col_employee_operator]
           ,[col_employee_operatoTime]
           ,[col_employee_recordCopyFrom])
     VALUES
           (@col_employee_id
           ,@col_companyBase_id
           ,@col_employee_name
           ,@col_employee_sex
           ,@col_employee_birthday
           ,@col_employee_mobile
           ,@col_employee_phone
           ,@col_employee_position
           ,@col_employee_positionState
           ,1
           ,@col_employee_operator
           ,getdate()
           ,-1)
END
GO
/****** Object:  StoredProcedure [dbo].[employee_edit]    Script Date: 06/08/2011 16:09:30 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE procedure [dbo].[employee_edit] (
			@col_employee_id int,
			@col_companyBase_id int,
			@col_employee_name nvarchar,
			@col_employee_sex int,
			@col_employee_birthday datetime,
			@col_employee_mobile nvarchar,
			@col_employee_phone nvarchar,
			@col_employee_position int,
			@col_employee_positionState int,
			@col_employee_recordState tinyint,
			@col_employee_operator int,
			@col_employee_operatoTime datetime,
			@col_employee_recordCopyFrom int	
            ) as
BEGIN

	SET NOCOUNT ON;
	 
 UPDATE [wx].[dbo].[employee]
   SET [col_companyBase_id] = @col_companyBase_id
      ,[col_employee_name] = @col_employee_name
      ,[col_employee_sex] = @col_employee_sex
      ,[col_employee_birthday] = @col_employee_birthday
      ,[col_employee_mobile] = @col_employee_mobile
      ,[col_employee_phone] = @col_employee_phone
      ,[col_employee_position] = @col_employee_position
      ,[col_employee_positionState] = @col_employee_positionState
      ,[col_employee_recordState] = 3
      ,[col_employee_operator] = @col_employee_operator
      ,[col_employee_operatoTime] = GETDATE()
 WHERE [col_employee_id] = @col_employee_id
 
END
GO
/****** Object:  StoredProcedure [dbo].[employee_delete]    Script Date: 06/08/2011 16:09:30 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE procedure [dbo].[employee_delete] (
            @col_employee_id int,
            @col_employee_operator int) as
BEGIN

	SET NOCOUNT ON;
	
UPDATE [wx].[dbo].[employee]
   SET [col_employee_recordState] = 2
      ,[col_employee_operator] = @col_employee_operator
      ,[col_employee_operatoTime] = GETDATE()
 WHERE [col_employee_id] = @col_employee_id
END
GO
/****** Object:  StoredProcedure [dbo].[user_CreateNewID]    Script Date: 06/08/2011 16:09:30 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
create procedure [dbo].[user_CreateNewID] as
BEGIN

	SET NOCOUNT ON;
	
	DECLARE	@return_value int

	EXEC	@return_value = [dbo].[comm_CreateNewID]
			@tableName = N'userTBL'
		
	return @return_value

END
GO
/****** Object:  StoredProcedure [dbo].[login_CreateNewID]    Script Date: 06/08/2011 16:09:30 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
create procedure [dbo].[login_CreateNewID] as
BEGIN

	SET NOCOUNT ON;
	
	DECLARE	@return_value int

	EXEC	@return_value = [dbo].[comm_CreateNewID]
			@tableName = N'login'
		
	return @return_value

END
GO
/****** Object:  StoredProcedure [dbo].[userGroup_CreateNewID]    Script Date: 06/08/2011 16:09:30 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
create procedure [dbo].[userGroup_CreateNewID] as
BEGIN

	SET NOCOUNT ON;
	
	DECLARE	@return_value int

	EXEC	@return_value = [dbo].[comm_CreateNewID]
			@tableName = N'userGroup'
		
	return @return_value

END
GO
/****** Object:  StoredProcedure [dbo].[userGroup_setByUserID]    Script Date: 06/08/2011 16:09:30 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
create procedure [dbo].[userGroup_setByUserID] (
             @col_user_id int
 		   ,@col_group_id int
            ,@col_userGroup_operator int) as
BEGIN

	SET NOCOUNT ON;
	
	declare @count int
	set @count = 0
	select @count = COUNT(*) 
		from [wx].[dbo].[userGroup] 
		WHERE [col_user_id] = @col_user_id
				
	if (@count=0)
	begin 		
		declare @userGroup_id int
			
		EXEC	@userGroup_id = [dbo].[userGroup_CreateNewID]
				
		INSERT INTO [wx].[dbo].[userGroup]
			   ([col_userGroup_id]
			   ,[col_group_id]
			   ,[col_user_id]
			   ,[col_userGroup_recordState]
			   ,[col_userGroup_operator]
			   ,[col_userGroup_operatoTime]
			   ,[col_userGroup_copyFromID])
		 VALUES
			   (@userGroup_id
			   ,@col_group_id
			   ,@col_user_id
			   ,1
			   ,@col_userGroup_operator
			   ,getdate()
			   ,-1)
	end
	else
	begin
			           
		UPDATE [wx].[dbo].[userGroup]
			SET [col_group_id] = @col_group_id
			  ,[col_userGroup_operator] = @col_userGroup_operator
			  ,[col_userGroup_operatoTime] = getdate()
			WHERE [col_user_id] = @col_user_id
			
	end
      
END
GO
