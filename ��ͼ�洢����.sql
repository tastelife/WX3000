USE [wx]
GO
/*==============================================================*/
/* DBMS name:      Microsoft SQL Server 2008                    */
/* Created on:     2011-5-18 20:11:27                           */
/*==============================================================*/


if exists (select 1
          from sysobjects
          where  id = object_id('dbo.login_CreateNewID')
          and type in ('P','PC'))
   drop procedure dbo.login_CreateNewID
go

if exists (select 1
          from sysobjects
          where  id = object_id('dbo.user_CreateNewID')
          and type in ('P','PC'))
   drop procedure dbo.user_CreateNewID
go

if exists (select 1
          from sysobjects
          where  id = object_id('dbo.userGroup_setByUserID')
          and type in ('P','PC'))
   drop procedure dbo.userGroup_setByUserID
go

if exists (select 1
          from sysobjects
          where  id = object_id('dbo.userGroup_CreateNewID')
          and type in ('P','PC'))
   drop procedure dbo.userGroup_CreateNewID
go

if exists (select 1
          from sysobjects
          where  id = object_id('dbo.comm_CreateNewID')
          and type in ('P','PC'))
   drop procedure dbo.comm_CreateNewID
go

if exists (select 1
          from sysobjects
          where  id = object_id('dbo.login_IsLogining')
          and type in ('P','PC'))
   drop procedure dbo.login_IsLogining
go

if exists (select 1
          from sysobjects
          where  id = object_id('dbo.login_login')
          and type in ('P','PC'))
   drop procedure dbo.login_login
go

if exists (select 1
          from sysobjects
          where  id = object_id('dbo.login_logout')
          and type in ('P','PC'))
   drop procedure dbo.login_logout
go

if exists (select 1
          from sysobjects
          where  id = object_id('dbo.login_logoutException')
          and type in ('P','PC'))
   drop procedure dbo.login_logoutException
go

if exists (select 1
          from sysobjects
          where  id = object_id('dbo.login_logoutExceptionAll')
          and type in ('P','PC'))
   drop procedure dbo.login_logoutExceptionAll
go

if exists (select 1
          from sysobjects
          where  id = object_id('dbo.userGroup_add')
          and type in ('P','PC'))
   drop procedure dbo.userGroup_add
go

if exists (select 1
          from sysobjects
          where  id = object_id('dbo.userGroup_delete')
          and type in ('P','PC'))
   drop procedure dbo.userGroup_delete
go

if exists (select 1
          from sysobjects
          where  id = object_id('dbo.userGroup_edit')
          and type in ('P','PC'))
   drop procedure dbo.userGroup_edit
go

if exists (select 1
          from sysobjects
          where  id = object_id('dbo.user_IsBeing')
          and type in ('P','PC'))
   drop procedure dbo.user_IsBeing
go

if exists (select 1
          from sysobjects
          where  id = object_id('dbo.user_add')
          and type in ('P','PC'))
   drop procedure dbo.user_add
go

if exists (select 1
          from sysobjects
          where  id = object_id('dbo.user_delete')
          and type in ('P','PC'))
   drop procedure dbo.user_delete
go

if exists (select 1
          from sysobjects
          where  id = object_id('dbo.user_edit')
          and type in ('P','PC'))
   drop procedure dbo.user_edit
go

if exists (select 1
            from  sysobjects
           where  id = object_id('dbo.View_GroupFunPointPower')
            and   type = 'V')
   drop view dbo.View_GroupFunPointPower
go

if exists (select 1
            from  sysobjects
           where  id = object_id('dbo.View_UserGroup')
            and   type = 'V')
   drop view dbo.View_UserGroup
go

execute sp_revokedbaccess dbo
go

/*==============================================================*/
/* User: dbo                                                    */
/*==============================================================*/
execute sp_grantdbaccess dbo
go

/*==============================================================*/
/* View: View_GroupFunPointPower                                */
/*==============================================================*/
create view dbo.View_GroupFunPointPower as
SELECT     dbo.[group].col_group_id, dbo.functinPoint.col_functinPoint_name, dbo.functinPoint.col_functinPoint_displayName, 
                      dbo.groupFunctionPointPower.col_groupFuncitonPointPower
FROM         dbo.[group] INNER JOIN
                      dbo.groupFunctionPointPower ON dbo.[group].col_group_id = dbo.groupFunctionPointPower.col_group_id INNER JOIN
                      dbo.functinPoint ON dbo.groupFunctionPointPower.col_functinPoint_id = dbo.functinPoint.col_functinPoint_id
go

/*==============================================================*/
/* View: View_UserGroup                                         */
/*==============================================================*/
create view dbo.View_UserGroup as
SELECT     dbo.userGroup.col_userGroup_id, dbo.userTBL.col_user_id, dbo.[group].col_group_id, dbo.userTBL.col_user_loginName, dbo.[group].col_group_name
FROM         dbo.userTBL LEFT OUTER JOIN
                      dbo.userGroup ON dbo.userTBL.col_user_id = dbo.userGroup.col_user_id LEFT OUTER JOIN
                      dbo.[group] ON dbo.userGroup.col_group_id = dbo.[group].col_group_id
WHERE     (dbo.userTBL.col_user_recordState = 1) OR
                      (dbo.userTBL.col_user_recordState = 3)
go


create procedure dbo.comm_CreateNewID (
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
go


create procedure dbo.login_CreateNewID as
BEGIN

	SET NOCOUNT ON;
	
	DECLARE	@return_value int

	EXEC	@return_value = [dbo].[comm_CreateNewID]
			@tableName = N'login'
		
	return @return_value

END
go


create procedure dbo.login_IsLogining (
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
go


create procedure dbo.login_login (@col_login_id int 
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
go


create procedure dbo.login_logout (@col_login_id int 
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
go


create procedure dbo.login_logoutException (@col_user_id int 
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
go


create procedure dbo.login_logoutExceptionAll (@col_login_operatorUserID int) as
BEGIN

	SET NOCOUNT ON;
	
UPDATE [wx].[dbo].login
      set [col_login_state] = 3
      ,[col_login_recordState] = 2
      ,[col_login_operatorUserID] = @col_login_operatorUserID
      ,[col_login_operatoTime] = GETDATE()
 WHERE [col_login_state] = 1
 
END
go


create procedure dbo.userGroup_CreateNewID as
BEGIN

	SET NOCOUNT ON;
	
	DECLARE	@return_value int

	EXEC	@return_value = [dbo].[comm_CreateNewID]
			@tableName = N'userGroup'
		
	return @return_value

END
go


create procedure dbo.userGroup_add (@col_userGroup_id int
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
go


create procedure dbo.userGroup_delete (@col_userGroup_id int
            ,@col_userGroup_operator int) as
BEGIN

delete [wx].[dbo].[userGroup]
 WHERE [col_userGroup_id] = @col_userGroup_id
 
END
go


create procedure dbo.userGroup_edit (@col_userGroup_id int
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
go


create procedure dbo.userGroup_setByUserID (
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
go


create procedure dbo.user_CreateNewID as
BEGIN

	SET NOCOUNT ON;
	
	DECLARE	@return_value int

	EXEC	@return_value = [dbo].[comm_CreateNewID]
			@tableName = N'userTBL'
		
	return @return_value

END
go


create procedure dbo.user_IsBeing (
            @col_user_loginName char(20)) as
BEGIN

	SET NOCOUNT ON;
	
	declare @count int
	set @count=0
	
	select @count =COUNT(*) from dbo.userTBL where col_user_loginName=@col_user_loginName

	return @count
END
go


create procedure dbo.user_add (
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
go


create procedure dbo.user_delete (
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
go


create procedure dbo.user_edit (
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
go

