USE [wx]
GO
/****** Object:  Table [dbo].[functinPoint]    Script Date: 06/08/2011 11:07:08 ******/
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
INSERT [dbo].[functinPoint] ([col_functinPoint_id], [col_functinPoint_name], [col_functinPoint_displayName], [col_functinPoint_recordState], [col_functinPoint_operator], [col_functinPoint_opertoTime], [col_functinPoint_copyFromID]) VALUES (101, N'user', N'用户管理', 1, -1, CAST(0x000007D900000000 AS DateTime), -1)
INSERT [dbo].[functinPoint] ([col_functinPoint_id], [col_functinPoint_name], [col_functinPoint_displayName], [col_functinPoint_recordState], [col_functinPoint_operator], [col_functinPoint_opertoTime], [col_functinPoint_copyFromID]) VALUES (201, N'power', N'权限管理', 1, -1, CAST(0x000007D900000000 AS DateTime), -1)
INSERT [dbo].[functinPoint] ([col_functinPoint_id], [col_functinPoint_name], [col_functinPoint_displayName], [col_functinPoint_recordState], [col_functinPoint_operator], [col_functinPoint_opertoTime], [col_functinPoint_copyFromID]) VALUES (301, N'companyBase', N'部门', 1, -1, CAST(0x000007D900000000 AS DateTime), -1)
INSERT [dbo].[functinPoint] ([col_functinPoint_id], [col_functinPoint_name], [col_functinPoint_displayName], [col_functinPoint_recordState], [col_functinPoint_operator], [col_functinPoint_opertoTime], [col_functinPoint_copyFromID]) VALUES (401, N'employee', N'员工', 1, -1, CAST(0x000007D900000000 AS DateTime), -1)
INSERT [dbo].[functinPoint] ([col_functinPoint_id], [col_functinPoint_name], [col_functinPoint_displayName], [col_functinPoint_recordState], [col_functinPoint_operator], [col_functinPoint_opertoTime], [col_functinPoint_copyFromID]) VALUES (501, N'customer', N'客户', 1, -1, CAST(0x000007D900000000 AS DateTime), -1)
INSERT [dbo].[functinPoint] ([col_functinPoint_id], [col_functinPoint_name], [col_functinPoint_displayName], [col_functinPoint_recordState], [col_functinPoint_operator], [col_functinPoint_opertoTime], [col_functinPoint_copyFromID]) VALUES (601, N'supplier', N'供应商', 1, -1, CAST(0x000007D900000000 AS DateTime), -1)
/****** Object:  Table [dbo].[group]    Script Date: 06/08/2011 11:07:08 ******/
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
INSERT [dbo].[group] ([col_group_id], [col_group_name], [col_group_recordState], [col_group_opertor], [col_group_opertoTime], [col_group_copyFromID]) VALUES (1, N'管理组', 1, -1, CAST(0x00009F9800000000 AS DateTime), -1)
INSERT [dbo].[group] ([col_group_id], [col_group_name], [col_group_recordState], [col_group_opertor], [col_group_opertoTime], [col_group_copyFromID]) VALUES (2, N'常规组', 1, -1, CAST(0x00009F9800000000 AS DateTime), -1)
INSERT [dbo].[group] ([col_group_id], [col_group_name], [col_group_recordState], [col_group_opertor], [col_group_opertoTime], [col_group_copyFromID]) VALUES (3, N'受限组', 1, -1, CAST(0x00009F9800000000 AS DateTime), -1)
INSERT [dbo].[group] ([col_group_id], [col_group_name], [col_group_recordState], [col_group_opertor], [col_group_opertoTime], [col_group_copyFromID]) VALUES (4, N'禁用组', 1, -1, CAST(0x00009F9800000000 AS DateTime), -1)
/****** Object:  Table [dbo].[groupFunctionPointPower]    Script Date: 06/08/2011 11:07:08 ******/
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
INSERT [dbo].[groupFunctionPointPower] ([col_group_id], [col_functinPoint_id], [col_groupFuncitonPointPower], [col_groupFunctionPointPower_recordState], [col_groupFunctionPointPower_operator], [col_groupFunctionPointPower_operatoTime], [col_groupFunctionPointPower_copyFrom]) VALUES (1, 101, 15, 1, -1, CAST(0x00009F9800000000 AS DateTime), -1)
INSERT [dbo].[groupFunctionPointPower] ([col_group_id], [col_functinPoint_id], [col_groupFuncitonPointPower], [col_groupFunctionPointPower_recordState], [col_groupFunctionPointPower_operator], [col_groupFunctionPointPower_operatoTime], [col_groupFunctionPointPower_copyFrom]) VALUES (2, 101, 8, 1, -1, CAST(0x00009F9800000000 AS DateTime), -1)
INSERT [dbo].[groupFunctionPointPower] ([col_group_id], [col_functinPoint_id], [col_groupFuncitonPointPower], [col_groupFunctionPointPower_recordState], [col_groupFunctionPointPower_operator], [col_groupFunctionPointPower_operatoTime], [col_groupFunctionPointPower_copyFrom]) VALUES (3, 101, 8, 1, -1, CAST(0x00009F9800000000 AS DateTime), -1)
INSERT [dbo].[groupFunctionPointPower] ([col_group_id], [col_functinPoint_id], [col_groupFuncitonPointPower], [col_groupFunctionPointPower_recordState], [col_groupFunctionPointPower_operator], [col_groupFunctionPointPower_operatoTime], [col_groupFunctionPointPower_copyFrom]) VALUES (4, 101, 0, 1, -1, CAST(0x00009F9800000000 AS DateTime), -1)
INSERT [dbo].[groupFunctionPointPower] ([col_group_id], [col_functinPoint_id], [col_groupFuncitonPointPower], [col_groupFunctionPointPower_recordState], [col_groupFunctionPointPower_operator], [col_groupFunctionPointPower_operatoTime], [col_groupFunctionPointPower_copyFrom]) VALUES (1, 201, 15, 1, -1, CAST(0x00009F9800000000 AS DateTime), -1)
INSERT [dbo].[groupFunctionPointPower] ([col_group_id], [col_functinPoint_id], [col_groupFuncitonPointPower], [col_groupFunctionPointPower_recordState], [col_groupFunctionPointPower_operator], [col_groupFunctionPointPower_operatoTime], [col_groupFunctionPointPower_copyFrom]) VALUES (2, 201, 0, 1, -1, CAST(0x00009F9800000000 AS DateTime), -1)
INSERT [dbo].[groupFunctionPointPower] ([col_group_id], [col_functinPoint_id], [col_groupFuncitonPointPower], [col_groupFunctionPointPower_recordState], [col_groupFunctionPointPower_operator], [col_groupFunctionPointPower_operatoTime], [col_groupFunctionPointPower_copyFrom]) VALUES (3, 201, 0, 1, -1, CAST(0x00009F9800000000 AS DateTime), -1)
INSERT [dbo].[groupFunctionPointPower] ([col_group_id], [col_functinPoint_id], [col_groupFuncitonPointPower], [col_groupFunctionPointPower_recordState], [col_groupFunctionPointPower_operator], [col_groupFunctionPointPower_operatoTime], [col_groupFunctionPointPower_copyFrom]) VALUES (4, 201, 0, 1, -1, CAST(0x00009F9800000000 AS DateTime), -1)
INSERT [dbo].[groupFunctionPointPower] ([col_group_id], [col_functinPoint_id], [col_groupFuncitonPointPower], [col_groupFunctionPointPower_recordState], [col_groupFunctionPointPower_operator], [col_groupFunctionPointPower_operatoTime], [col_groupFunctionPointPower_copyFrom]) VALUES (1, 301, 15, 1, -1, CAST(0x00009F9800000000 AS DateTime), -1)
INSERT [dbo].[groupFunctionPointPower] ([col_group_id], [col_functinPoint_id], [col_groupFuncitonPointPower], [col_groupFunctionPointPower_recordState], [col_groupFunctionPointPower_operator], [col_groupFunctionPointPower_operatoTime], [col_groupFunctionPointPower_copyFrom]) VALUES (2, 301, 15, 1, -1, CAST(0x00009F9800000000 AS DateTime), -1)
INSERT [dbo].[groupFunctionPointPower] ([col_group_id], [col_functinPoint_id], [col_groupFuncitonPointPower], [col_groupFunctionPointPower_recordState], [col_groupFunctionPointPower_operator], [col_groupFunctionPointPower_operatoTime], [col_groupFunctionPointPower_copyFrom]) VALUES (3, 301, 8, 1, -1, CAST(0x00009F9800000000 AS DateTime), -1)
INSERT [dbo].[groupFunctionPointPower] ([col_group_id], [col_functinPoint_id], [col_groupFuncitonPointPower], [col_groupFunctionPointPower_recordState], [col_groupFunctionPointPower_operator], [col_groupFunctionPointPower_operatoTime], [col_groupFunctionPointPower_copyFrom]) VALUES (4, 301, 0, 1, -1, CAST(0x00009F9800000000 AS DateTime), -1)
INSERT [dbo].[groupFunctionPointPower] ([col_group_id], [col_functinPoint_id], [col_groupFuncitonPointPower], [col_groupFunctionPointPower_recordState], [col_groupFunctionPointPower_operator], [col_groupFunctionPointPower_operatoTime], [col_groupFunctionPointPower_copyFrom]) VALUES (1, 401, 15, 1, -1, CAST(0x00009F9800000000 AS DateTime), -1)
INSERT [dbo].[groupFunctionPointPower] ([col_group_id], [col_functinPoint_id], [col_groupFuncitonPointPower], [col_groupFunctionPointPower_recordState], [col_groupFunctionPointPower_operator], [col_groupFunctionPointPower_operatoTime], [col_groupFunctionPointPower_copyFrom]) VALUES (2, 401, 15, 1, -1, CAST(0x00009F9800000000 AS DateTime), -1)
INSERT [dbo].[groupFunctionPointPower] ([col_group_id], [col_functinPoint_id], [col_groupFuncitonPointPower], [col_groupFunctionPointPower_recordState], [col_groupFunctionPointPower_operator], [col_groupFunctionPointPower_operatoTime], [col_groupFunctionPointPower_copyFrom]) VALUES (3, 401, 8, 1, -1, CAST(0x00009F9800000000 AS DateTime), -1)
INSERT [dbo].[groupFunctionPointPower] ([col_group_id], [col_functinPoint_id], [col_groupFuncitonPointPower], [col_groupFunctionPointPower_recordState], [col_groupFunctionPointPower_operator], [col_groupFunctionPointPower_operatoTime], [col_groupFunctionPointPower_copyFrom]) VALUES (4, 401, 0, 1, -1, CAST(0x00009F9800000000 AS DateTime), -1)
INSERT [dbo].[groupFunctionPointPower] ([col_group_id], [col_functinPoint_id], [col_groupFuncitonPointPower], [col_groupFunctionPointPower_recordState], [col_groupFunctionPointPower_operator], [col_groupFunctionPointPower_operatoTime], [col_groupFunctionPointPower_copyFrom]) VALUES (1, 501, 15, 1, -1, CAST(0x00009F9800000000 AS DateTime), -1)
INSERT [dbo].[groupFunctionPointPower] ([col_group_id], [col_functinPoint_id], [col_groupFuncitonPointPower], [col_groupFunctionPointPower_recordState], [col_groupFunctionPointPower_operator], [col_groupFunctionPointPower_operatoTime], [col_groupFunctionPointPower_copyFrom]) VALUES (2, 501, 15, 1, -1, CAST(0x00009F9800000000 AS DateTime), -1)
INSERT [dbo].[groupFunctionPointPower] ([col_group_id], [col_functinPoint_id], [col_groupFuncitonPointPower], [col_groupFunctionPointPower_recordState], [col_groupFunctionPointPower_operator], [col_groupFunctionPointPower_operatoTime], [col_groupFunctionPointPower_copyFrom]) VALUES (3, 501, 8, 1, -1, CAST(0x00009F9800000000 AS DateTime), -1)
INSERT [dbo].[groupFunctionPointPower] ([col_group_id], [col_functinPoint_id], [col_groupFuncitonPointPower], [col_groupFunctionPointPower_recordState], [col_groupFunctionPointPower_operator], [col_groupFunctionPointPower_operatoTime], [col_groupFunctionPointPower_copyFrom]) VALUES (4, 501, 0, 1, -1, CAST(0x00009F9800000000 AS DateTime), -1)
INSERT [dbo].[groupFunctionPointPower] ([col_group_id], [col_functinPoint_id], [col_groupFuncitonPointPower], [col_groupFunctionPointPower_recordState], [col_groupFunctionPointPower_operator], [col_groupFunctionPointPower_operatoTime], [col_groupFunctionPointPower_copyFrom]) VALUES (1, 601, 15, 1, -1, CAST(0x00009F9800000000 AS DateTime), -1)
INSERT [dbo].[groupFunctionPointPower] ([col_group_id], [col_functinPoint_id], [col_groupFuncitonPointPower], [col_groupFunctionPointPower_recordState], [col_groupFunctionPointPower_operator], [col_groupFunctionPointPower_operatoTime], [col_groupFunctionPointPower_copyFrom]) VALUES (2, 601, 15, 1, -1, CAST(0x00009F9800000000 AS DateTime), -1)
INSERT [dbo].[groupFunctionPointPower] ([col_group_id], [col_functinPoint_id], [col_groupFuncitonPointPower], [col_groupFunctionPointPower_recordState], [col_groupFunctionPointPower_operator], [col_groupFunctionPointPower_operatoTime], [col_groupFunctionPointPower_copyFrom]) VALUES (3, 601, 8, 1, -1, CAST(0x00009F9800000000 AS DateTime), -1)
INSERT [dbo].[groupFunctionPointPower] ([col_group_id], [col_functinPoint_id], [col_groupFuncitonPointPower], [col_groupFunctionPointPower_recordState], [col_groupFunctionPointPower_operator], [col_groupFunctionPointPower_operatoTime], [col_groupFunctionPointPower_copyFrom]) VALUES (4, 601, 0, 1, -1, CAST(0x00009F9800000000 AS DateTime), -1)
/****** Object:  Table [dbo].[hint]    Script Date: 06/08/2011 11:07:08 ******/
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
/****** Object:  Table [dbo].[hintuser]    Script Date: 06/08/2011 11:07:08 ******/
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
/****** Object:  Table [dbo].[login]    Script Date: 06/08/2011 11:07:08 ******/
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
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (237, 1, CAST(0x00009EED01589537 AS DateTime), 0, N'wx-a6268ebe86cc                                                                                                                 ', N'00241DDF0178                                                                                                                  ', N'192.168.1.102  ', 2, 0, CAST(0x00009EED01589C8B AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (236, 1, CAST(0x00009EED0154C42D AS DateTime), 0, N'wx-a6268ebe86cc                                                                                                                 ', N'00241DDF0178                                                                                                                  ', N'192.168.1.102  ', 2, 0, CAST(0x00009EED01551033 AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (238, 1, CAST(0x00009EFC00AB19EF AS DateTime), 0, N'7bwz82x_win7pro                                                                                                                 ', N' . . . . . . . . . . . : 7bwz82x_win7pro                                                                                       ', N'192.168.120.78  192.168.56.1  ', 2, 1, CAST(0x00009EFC00AB86FC AS DateTime), -1)
/****** Object:  Table [dbo].[messageBoard]    Script Date: 06/08/2011 11:07:08 ******/
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
/****** Object:  Table [dbo].[newID]    Script Date: 06/08/2011 11:07:08 ******/
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
INSERT [dbo].[newID] ([col_newID_ID], [col_newID_lastID], [col_newID_tableName]) VALUES (0, 34, N'userTBL')
INSERT [dbo].[newID] ([col_newID_ID], [col_newID_lastID], [col_newID_tableName]) VALUES (1, 238, N'login')
INSERT [dbo].[newID] ([col_newID_ID], [col_newID_lastID], [col_newID_tableName]) VALUES (2, 31, N'userGroup')
/****** Object:  Table [dbo].[publicinFormation]    Script Date: 06/08/2011 11:07:08 ******/
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
/****** Object:  Table [dbo].[userGroup]    Script Date: 06/08/2011 11:07:08 ******/
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
INSERT [dbo].[userGroup] ([col_userGroup_id], [col_group_id], [col_user_id], [col_userGroup_recordState], [col_userGroup_operator], [col_userGroup_operatoTime], [col_userGroup_copyFromID]) VALUES (1, 1, 1, 1, -1, CAST(0x00009EED00A827F6 AS DateTime), -1)
INSERT [dbo].[userGroup] ([col_userGroup_id], [col_group_id], [col_user_id], [col_userGroup_recordState], [col_userGroup_operator], [col_userGroup_operatoTime], [col_userGroup_copyFromID]) VALUES (2, 1, 20, 1, -1, CAST(0x00009ECA010B6865 AS DateTime), -1)
INSERT [dbo].[userGroup] ([col_userGroup_id], [col_group_id], [col_user_id], [col_userGroup_recordState], [col_userGroup_operator], [col_userGroup_operatoTime], [col_userGroup_copyFromID]) VALUES (3, 31, 32, 1, -1, CAST(0x00009ECA010C1C32 AS DateTime), -1)
INSERT [dbo].[userGroup] ([col_userGroup_id], [col_group_id], [col_user_id], [col_userGroup_recordState], [col_userGroup_operator], [col_userGroup_operatoTime], [col_userGroup_copyFromID]) VALUES (11, 2, 11, 11, -1, CAST(0x00009EED00B644EE AS DateTime), -1)
INSERT [dbo].[userGroup] ([col_userGroup_id], [col_group_id], [col_user_id], [col_userGroup_recordState], [col_userGroup_operator], [col_userGroup_operatoTime], [col_userGroup_copyFromID]) VALUES (18, 41, 42, 1, -1, CAST(0x00009ECA011115C7 AS DateTime), -1)
INSERT [dbo].[userGroup] ([col_userGroup_id], [col_group_id], [col_user_id], [col_userGroup_recordState], [col_userGroup_operator], [col_userGroup_operatoTime], [col_userGroup_copyFromID]) VALUES (17, 21, 522, 0, -1, CAST(0x00009ECA0112887E AS DateTime), -1)
INSERT [dbo].[userGroup] ([col_userGroup_id], [col_group_id], [col_user_id], [col_userGroup_recordState], [col_userGroup_operator], [col_userGroup_operatoTime], [col_userGroup_copyFromID]) VALUES (21, 21, 5, 1, -1, CAST(0x00009ECA0112BBDE AS DateTime), -1)
INSERT [dbo].[userGroup] ([col_userGroup_id], [col_group_id], [col_user_id], [col_userGroup_recordState], [col_userGroup_operator], [col_userGroup_operatoTime], [col_userGroup_copyFromID]) VALUES (22, 21, 2, 1, -1, CAST(0x00009ECA011DD0CA AS DateTime), -1)
INSERT [dbo].[userGroup] ([col_userGroup_id], [col_group_id], [col_user_id], [col_userGroup_recordState], [col_userGroup_operator], [col_userGroup_operatoTime], [col_userGroup_copyFromID]) VALUES (23, 1, 3, 1, -1, CAST(0x00009ECA011DF2C1 AS DateTime), -1)
INSERT [dbo].[userGroup] ([col_userGroup_id], [col_group_id], [col_user_id], [col_userGroup_recordState], [col_userGroup_operator], [col_userGroup_operatoTime], [col_userGroup_copyFromID]) VALUES (24, 4, 21, 1, -1, CAST(0x00009EED01049F69 AS DateTime), -1)
INSERT [dbo].[userGroup] ([col_userGroup_id], [col_group_id], [col_user_id], [col_userGroup_recordState], [col_userGroup_operator], [col_userGroup_operatoTime], [col_userGroup_copyFromID]) VALUES (25, 2, 27, 1, -1, CAST(0x00009ED300C1724F AS DateTime), -1)
INSERT [dbo].[userGroup] ([col_userGroup_id], [col_group_id], [col_user_id], [col_userGroup_recordState], [col_userGroup_operator], [col_userGroup_operatoTime], [col_userGroup_copyFromID]) VALUES (26, 3, 17, 1, -1, CAST(0x00009ED400EA62B8 AS DateTime), -1)
INSERT [dbo].[userGroup] ([col_userGroup_id], [col_group_id], [col_user_id], [col_userGroup_recordState], [col_userGroup_operator], [col_userGroup_operatoTime], [col_userGroup_copyFromID]) VALUES (27, 4, 19, 1, -1, CAST(0x00009ED400EA6797 AS DateTime), -1)
INSERT [dbo].[userGroup] ([col_userGroup_id], [col_group_id], [col_user_id], [col_userGroup_recordState], [col_userGroup_operator], [col_userGroup_operatoTime], [col_userGroup_copyFromID]) VALUES (28, 3, 28, 1, -1, CAST(0x00009EDA01066935 AS DateTime), -1)
INSERT [dbo].[userGroup] ([col_userGroup_id], [col_group_id], [col_user_id], [col_userGroup_recordState], [col_userGroup_operator], [col_userGroup_operatoTime], [col_userGroup_copyFromID]) VALUES (29, 4, 29, 1, -1, CAST(0x00009EED00A54681 AS DateTime), -1)
INSERT [dbo].[userGroup] ([col_userGroup_id], [col_group_id], [col_user_id], [col_userGroup_recordState], [col_userGroup_operator], [col_userGroup_operatoTime], [col_userGroup_copyFromID]) VALUES (30, 2, 31, 1, -1, CAST(0x00009EED00A537A1 AS DateTime), -1)
INSERT [dbo].[userGroup] ([col_userGroup_id], [col_group_id], [col_user_id], [col_userGroup_recordState], [col_userGroup_operator], [col_userGroup_operatoTime], [col_userGroup_copyFromID]) VALUES (31, 2, 30, 1, 1, CAST(0x00009EFC00AB521C AS DateTime), -1)
/****** Object:  Table [dbo].[userTBL]    Script Date: 06/08/2011 11:07:08 ******/
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
INSERT [dbo].[userTBL] ([col_user_id], [col_user_loginName], [col_user_empId], [col_user_passwd], [col_user_recordState], [col_user_operator], [col_user_operatoTime], [col_user_copyFromID]) VALUES (1, N'1', 1, N'1', 3, -1, CAST(0x00009EDB01128150 AS DateTime), -1)
INSERT [dbo].[userTBL] ([col_user_id], [col_user_loginName], [col_user_empId], [col_user_passwd], [col_user_recordState], [col_user_operator], [col_user_operatoTime], [col_user_copyFromID]) VALUES (9, N'qw', -1, N'qw', 2, -1, CAST(0x00009EC200BDC4D8 AS DateTime), -1)
INSERT [dbo].[userTBL] ([col_user_id], [col_user_loginName], [col_user_empId], [col_user_passwd], [col_user_recordState], [col_user_operator], [col_user_operatoTime], [col_user_copyFromID]) VALUES (3, N'sss4', 5, N'3', 1, -1, CAST(0x00009EC400B75510 AS DateTime), -1)
INSERT [dbo].[userTBL] ([col_user_id], [col_user_loginName], [col_user_empId], [col_user_passwd], [col_user_recordState], [col_user_operator], [col_user_operatoTime], [col_user_copyFromID]) VALUES (10, N'qw1', -1, N'qw', 2, -1, CAST(0x00009EC400B7581A AS DateTime), -1)
INSERT [dbo].[userTBL] ([col_user_id], [col_user_loginName], [col_user_empId], [col_user_passwd], [col_user_recordState], [col_user_operator], [col_user_operatoTime], [col_user_copyFromID]) VALUES (12, N'qw5', -1, N'qw', 2, -1, CAST(0x00009EC40108A90D AS DateTime), -1)
INSERT [dbo].[userTBL] ([col_user_id], [col_user_loginName], [col_user_empId], [col_user_passwd], [col_user_recordState], [col_user_operator], [col_user_operatoTime], [col_user_copyFromID]) VALUES (14, N'qw6', -1, N'qw', 2, -1, CAST(0x00009EC40108A676 AS DateTime), -1)
INSERT [dbo].[userTBL] ([col_user_id], [col_user_loginName], [col_user_empId], [col_user_passwd], [col_user_recordState], [col_user_operator], [col_user_operatoTime], [col_user_copyFromID]) VALUES (15, N'qw12', -1, N'12', 2, -1, CAST(0x00009EC600ED9D0F AS DateTime), -1)
INSERT [dbo].[userTBL] ([col_user_id], [col_user_loginName], [col_user_empId], [col_user_passwd], [col_user_recordState], [col_user_operator], [col_user_operatoTime], [col_user_copyFromID]) VALUES (16, N'qw13', -1, N'', 2, -1, CAST(0x00009EC900ABAB6D AS DateTime), -1)
INSERT [dbo].[userTBL] ([col_user_id], [col_user_loginName], [col_user_empId], [col_user_passwd], [col_user_recordState], [col_user_operator], [col_user_operatoTime], [col_user_copyFromID]) VALUES (21, N'a1', 1, N'                                                                                                                                                                                                                                                                ', 3, -1, CAST(0x00009EED01039872 AS DateTime), -1)
INSERT [dbo].[userTBL] ([col_user_id], [col_user_loginName], [col_user_empId], [col_user_passwd], [col_user_recordState], [col_user_operator], [col_user_operatoTime], [col_user_copyFromID]) VALUES (22, N'23', -1, N'', 2, -1, CAST(0x00009EC400F7B363 AS DateTime), -1)
INSERT [dbo].[userTBL] ([col_user_id], [col_user_loginName], [col_user_empId], [col_user_passwd], [col_user_recordState], [col_user_operator], [col_user_operatoTime], [col_user_copyFromID]) VALUES (23, N'zz', -1, N'', 2, -1, CAST(0x00009EC40108A429 AS DateTime), -1)
INSERT [dbo].[userTBL] ([col_user_id], [col_user_loginName], [col_user_empId], [col_user_passwd], [col_user_recordState], [col_user_operator], [col_user_operatoTime], [col_user_copyFromID]) VALUES (24, N'wwwwww', -1, N'', 2, -1, CAST(0x00009EC600ED9F37 AS DateTime), -1)
INSERT [dbo].[userTBL] ([col_user_id], [col_user_loginName], [col_user_empId], [col_user_passwd], [col_user_recordState], [col_user_operator], [col_user_operatoTime], [col_user_copyFromID]) VALUES (25, N'qwerqw', -1, N'', 2, -1, CAST(0x00009EC600A324BF AS DateTime), -1)
INSERT [dbo].[userTBL] ([col_user_id], [col_user_loginName], [col_user_empId], [col_user_passwd], [col_user_recordState], [col_user_operator], [col_user_operatoTime], [col_user_copyFromID]) VALUES (26, N'qwqwq', -1, N'', 2, -1, CAST(0x00009EC600ECF316 AS DateTime), -1)
INSERT [dbo].[userTBL] ([col_user_id], [col_user_loginName], [col_user_empId], [col_user_passwd], [col_user_recordState], [col_user_operator], [col_user_operatoTime], [col_user_copyFromID]) VALUES (27, N'Q', -1, N'', 3, -1, CAST(0x00009EC900ABA88C AS DateTime), -1)
INSERT [dbo].[userTBL] ([col_user_id], [col_user_loginName], [col_user_empId], [col_user_passwd], [col_user_recordState], [col_user_operator], [col_user_operatoTime], [col_user_copyFromID]) VALUES (11, N'2', -1, N'2', 3, -1, CAST(0x00009EDA010644DA AS DateTime), -1)
INSERT [dbo].[userTBL] ([col_user_id], [col_user_loginName], [col_user_empId], [col_user_passwd], [col_user_recordState], [col_user_operator], [col_user_operatoTime], [col_user_copyFromID]) VALUES (17, N'12', -1, N'', 3, -1, CAST(0x00009ED300C16124 AS DateTime), -1)
INSERT [dbo].[userTBL] ([col_user_id], [col_user_loginName], [col_user_empId], [col_user_passwd], [col_user_recordState], [col_user_operator], [col_user_operatoTime], [col_user_copyFromID]) VALUES (18, N'123', -1, N'', 2, -1, CAST(0x00009ED300C153F5 AS DateTime), -1)
INSERT [dbo].[userTBL] ([col_user_id], [col_user_loginName], [col_user_empId], [col_user_passwd], [col_user_recordState], [col_user_operator], [col_user_operatoTime], [col_user_copyFromID]) VALUES (19, N'1234', -1, N'', 2, -1, CAST(0x00009EED00A51E8B AS DateTime), -1)
INSERT [dbo].[userTBL] ([col_user_id], [col_user_loginName], [col_user_empId], [col_user_passwd], [col_user_recordState], [col_user_operator], [col_user_operatoTime], [col_user_copyFromID]) VALUES (20, N'12345', -1, N'', 2, -1, CAST(0x00009EC600ED9A0D AS DateTime), -1)
INSERT [dbo].[userTBL] ([col_user_id], [col_user_loginName], [col_user_empId], [col_user_passwd], [col_user_recordState], [col_user_operator], [col_user_operatoTime], [col_user_copyFromID]) VALUES (28, N'3', -1, N'3                                                                                                                                                                                                                                                               ', 3, -1, CAST(0x00009EED0112F887 AS DateTime), -1)
INSERT [dbo].[userTBL] ([col_user_id], [col_user_loginName], [col_user_empId], [col_user_passwd], [col_user_recordState], [col_user_operator], [col_user_operatoTime], [col_user_copyFromID]) VALUES (29, N'4', -1, N'4', 3, -1, CAST(0x00009EDA010654B1 AS DateTime), -1)
INSERT [dbo].[userTBL] ([col_user_id], [col_user_loginName], [col_user_empId], [col_user_passwd], [col_user_recordState], [col_user_operator], [col_user_operatoTime], [col_user_copyFromID]) VALUES (31, N'www', -1, N'w', 1, -1, CAST(0x00009EDB0111B36D AS DateTime), -1)
INSERT [dbo].[userTBL] ([col_user_id], [col_user_loginName], [col_user_empId], [col_user_passwd], [col_user_recordState], [col_user_operator], [col_user_operatoTime], [col_user_copyFromID]) VALUES (30, N'5', -1, N'5', 3, -1, CAST(0x00009EDB00FAB0A8 AS DateTime), -1)
INSERT [dbo].[userTBL] ([col_user_id], [col_user_loginName], [col_user_empId], [col_user_passwd], [col_user_recordState], [col_user_operator], [col_user_operatoTime], [col_user_copyFromID]) VALUES (32, N'www1                ', 1, N'                                                                                                                                                                                                                                                                ', 1, -1, CAST(0x00009EED010389C8 AS DateTime), -1)
INSERT [dbo].[userTBL] ([col_user_id], [col_user_loginName], [col_user_empId], [col_user_passwd], [col_user_recordState], [col_user_operator], [col_user_operatoTime], [col_user_copyFromID]) VALUES (33, N'w1                  ', -1, N'33                                                                                                                                                                                                                                                              ', 2, -1, CAST(0x00009EED01057113 AS DateTime), -1)
INSERT [dbo].[userTBL] ([col_user_id], [col_user_loginName], [col_user_empId], [col_user_passwd], [col_user_recordState], [col_user_operator], [col_user_operatoTime], [col_user_copyFromID]) VALUES (34, N'w2                  ', -1, N'2                                                                                                                                                                                                                                                               ', 2, 1, CAST(0x00009EFC00AB39E4 AS DateTime), -1)
/****** Object:  Table [dbo].[companyBase]    Script Date: 06/08/2011 11:07:08 ******/
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
INSERT [dbo].[companyBase] ([col_companyBase_id], [col_companyBase_companyName], [col_companyBase_higherAuthoritiesID], [col_companyBase_phone], [col_companyBase_header], [col_companyBase_cretateTime], [col_companyBase_memo], [col_companyBase_recordState], [col_companyBase_operator], [col_companyBase_operatoTime], [col_companyBase_recordCopyFrom]) VALUES (1, N'companyBase1', 0, N'123456', 1, CAST(0x00009DEC00000000 AS DateTime), NULL, 1, -1, CAST(0x00009E5E00000000 AS DateTime), -1)
/****** Object:  Table [dbo].[dictionary]    Script Date: 06/08/2011 11:07:08 ******/
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
INSERT [dbo].[dictionary] ([col_dictionary_id], [col_dictionary_type], [col_dictionary_enum], [col_dictionary_name], [col_dictionary_manual], [col_dictionary_recordState], [col_dictionary_operator], [col_dictionary_operatoTime], [col_dictionary_recordCopyFrom]) VALUES (101, N'recordState', 1, N'新建', NULL, 1, -1, CAST(0x00009F9800000000 AS DateTime), -1)
INSERT [dbo].[dictionary] ([col_dictionary_id], [col_dictionary_type], [col_dictionary_enum], [col_dictionary_name], [col_dictionary_manual], [col_dictionary_recordState], [col_dictionary_operator], [col_dictionary_operatoTime], [col_dictionary_recordCopyFrom]) VALUES (102, N'recordState', 2, N'删除', NULL, 1, -1, CAST(0x00009F9800000000 AS DateTime), -1)
INSERT [dbo].[dictionary] ([col_dictionary_id], [col_dictionary_type], [col_dictionary_enum], [col_dictionary_name], [col_dictionary_manual], [col_dictionary_recordState], [col_dictionary_operator], [col_dictionary_operatoTime], [col_dictionary_recordCopyFrom]) VALUES (103, N'recordState', 3, N'修改', NULL, 1, -1, CAST(0x00009F9800000000 AS DateTime), -1)
INSERT [dbo].[dictionary] ([col_dictionary_id], [col_dictionary_type], [col_dictionary_enum], [col_dictionary_name], [col_dictionary_manual], [col_dictionary_recordState], [col_dictionary_operator], [col_dictionary_operatoTime], [col_dictionary_recordCopyFrom]) VALUES (104, N'recordState', 4, N'痕迹新建', N'不是当前数据', 1, -1, CAST(0x00009F9800000000 AS DateTime), -1)
INSERT [dbo].[dictionary] ([col_dictionary_id], [col_dictionary_type], [col_dictionary_enum], [col_dictionary_name], [col_dictionary_manual], [col_dictionary_recordState], [col_dictionary_operator], [col_dictionary_operatoTime], [col_dictionary_recordCopyFrom]) VALUES (105, N'recordState', 5, N'痕迹删除', NULL, 1, -1, CAST(0x00009F9800000000 AS DateTime), -1)
INSERT [dbo].[dictionary] ([col_dictionary_id], [col_dictionary_type], [col_dictionary_enum], [col_dictionary_name], [col_dictionary_manual], [col_dictionary_recordState], [col_dictionary_operator], [col_dictionary_operatoTime], [col_dictionary_recordCopyFrom]) VALUES (106, N'recordState', 6, N'痕迹修改', NULL, 1, -1, CAST(0x00009F9800000000 AS DateTime), -1)
INSERT [dbo].[dictionary] ([col_dictionary_id], [col_dictionary_type], [col_dictionary_enum], [col_dictionary_name], [col_dictionary_manual], [col_dictionary_recordState], [col_dictionary_operator], [col_dictionary_operatoTime], [col_dictionary_recordCopyFrom]) VALUES (100001, N'login.state', 1, N'登录', NULL, 1, -1, CAST(0x00009F9800000000 AS DateTime), -1)
INSERT [dbo].[dictionary] ([col_dictionary_id], [col_dictionary_type], [col_dictionary_enum], [col_dictionary_name], [col_dictionary_manual], [col_dictionary_recordState], [col_dictionary_operator], [col_dictionary_operatoTime], [col_dictionary_recordCopyFrom]) VALUES (100002, N'login.state', 2, N'退出', NULL, 1, -1, CAST(0x00009F9800000000 AS DateTime), -1)
INSERT [dbo].[dictionary] ([col_dictionary_id], [col_dictionary_type], [col_dictionary_enum], [col_dictionary_name], [col_dictionary_manual], [col_dictionary_recordState], [col_dictionary_operator], [col_dictionary_operatoTime], [col_dictionary_recordCopyFrom]) VALUES (100003, N'login.state', 3, N'异常退出', NULL, 1, -1, CAST(0x00009F9800000000 AS DateTime), -1)
INSERT [dbo].[dictionary] ([col_dictionary_id], [col_dictionary_type], [col_dictionary_enum], [col_dictionary_name], [col_dictionary_manual], [col_dictionary_recordState], [col_dictionary_operator], [col_dictionary_operatoTime], [col_dictionary_recordCopyFrom]) VALUES (100004, N'login.state', 4, N'强制退出', NULL, 1, -1, CAST(0x00009F9800000000 AS DateTime), -1)
INSERT [dbo].[dictionary] ([col_dictionary_id], [col_dictionary_type], [col_dictionary_enum], [col_dictionary_name], [col_dictionary_manual], [col_dictionary_recordState], [col_dictionary_operator], [col_dictionary_operatoTime], [col_dictionary_recordCopyFrom]) VALUES (200001, N'functionPointPower', 1, N'新建', NULL, 1, -1, CAST(0x00009F9800000000 AS DateTime), -1)
INSERT [dbo].[dictionary] ([col_dictionary_id], [col_dictionary_type], [col_dictionary_enum], [col_dictionary_name], [col_dictionary_manual], [col_dictionary_recordState], [col_dictionary_operator], [col_dictionary_operatoTime], [col_dictionary_recordCopyFrom]) VALUES (200002, N'functionPointPower', 2, N'删除', NULL, 1, -1, CAST(0x00009F9800000000 AS DateTime), -1)
INSERT [dbo].[dictionary] ([col_dictionary_id], [col_dictionary_type], [col_dictionary_enum], [col_dictionary_name], [col_dictionary_manual], [col_dictionary_recordState], [col_dictionary_operator], [col_dictionary_operatoTime], [col_dictionary_recordCopyFrom]) VALUES (200003, N'functionPointPower', 4, N'修改', NULL, 1, -1, CAST(0x00009F9800000000 AS DateTime), -1)
INSERT [dbo].[dictionary] ([col_dictionary_id], [col_dictionary_type], [col_dictionary_enum], [col_dictionary_name], [col_dictionary_manual], [col_dictionary_recordState], [col_dictionary_operator], [col_dictionary_operatoTime], [col_dictionary_recordCopyFrom]) VALUES (200004, N'functionPointPower', 8, N'查看', NULL, 1, -1, CAST(0x00009F9800000000 AS DateTime), -1)
INSERT [dbo].[dictionary] ([col_dictionary_id], [col_dictionary_type], [col_dictionary_enum], [col_dictionary_name], [col_dictionary_manual], [col_dictionary_recordState], [col_dictionary_operator], [col_dictionary_operatoTime], [col_dictionary_recordCopyFrom]) VALUES (300001, N'employee.state', 1, N'在职', NULL, 1, -1, CAST(0x00009F9800000000 AS DateTime), -1)
INSERT [dbo].[dictionary] ([col_dictionary_id], [col_dictionary_type], [col_dictionary_enum], [col_dictionary_name], [col_dictionary_manual], [col_dictionary_recordState], [col_dictionary_operator], [col_dictionary_operatoTime], [col_dictionary_recordCopyFrom]) VALUES (300002, N'employee.state', 2, N'离职', NULL, 1, -1, CAST(0x00009F9800000000 AS DateTime), -1)
INSERT [dbo].[dictionary] ([col_dictionary_id], [col_dictionary_type], [col_dictionary_enum], [col_dictionary_name], [col_dictionary_manual], [col_dictionary_recordState], [col_dictionary_operator], [col_dictionary_operatoTime], [col_dictionary_recordCopyFrom]) VALUES (300003, N'employee.state', 3, N'休假', NULL, 1, -1, CAST(0x00009F9800000000 AS DateTime), -1)
INSERT [dbo].[dictionary] ([col_dictionary_id], [col_dictionary_type], [col_dictionary_enum], [col_dictionary_name], [col_dictionary_manual], [col_dictionary_recordState], [col_dictionary_operator], [col_dictionary_operatoTime], [col_dictionary_recordCopyFrom]) VALUES (201, N'sex', 1, N'男', NULL, 1, -1, CAST(0x00009F9800000000 AS DateTime), -1)
INSERT [dbo].[dictionary] ([col_dictionary_id], [col_dictionary_type], [col_dictionary_enum], [col_dictionary_name], [col_dictionary_manual], [col_dictionary_recordState], [col_dictionary_operator], [col_dictionary_operatoTime], [col_dictionary_recordCopyFrom]) VALUES (202, N'sex', 2, N'女', NULL, 1, -1, CAST(0x00009F9800000000 AS DateTime), -1)
INSERT [dbo].[dictionary] ([col_dictionary_id], [col_dictionary_type], [col_dictionary_enum], [col_dictionary_name], [col_dictionary_manual], [col_dictionary_recordState], [col_dictionary_operator], [col_dictionary_operatoTime], [col_dictionary_recordCopyFrom]) VALUES (203, N'sex', 3, N'其它', NULL, 1, -1, CAST(0x00009F9800000000 AS DateTime), -1)
INSERT [dbo].[dictionary] ([col_dictionary_id], [col_dictionary_type], [col_dictionary_enum], [col_dictionary_name], [col_dictionary_manual], [col_dictionary_recordState], [col_dictionary_operator], [col_dictionary_operatoTime], [col_dictionary_recordCopyFrom]) VALUES (204, N'sex', 4, N'未知', NULL, 1, -1, CAST(0x00009F9800000000 AS DateTime), -1)
/****** Object:  Table [dbo].[employee]    Script Date: 06/08/2011 11:07:08 ******/
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
INSERT [dbo].[employee] ([col_employee_id], [col_companyBase_id], [col_employee_name], [col_employee_sex], [col_employee_birthday], [col_employee_mobile], [col_employee_phone], [col_employee_position], [col_employee_positionState], [col_employee_recordState], [col_employee_operator], [col_employee_operatoTime], [col_employee_recordCopyFrom]) VALUES (1, 1, N'name1', 1, CAST(0x00009B8500CE4384 AS DateTime), N'123456', N'123456789', 1, 1, 1, -1, CAST(0x00009E5E00C5C100 AS DateTime), -1)
/****** Object:  View [dbo].[View_GroupFunPointPower]    Script Date: 06/08/2011 11:07:09 ******/
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
/****** Object:  View [dbo].[View_UserGroup]    Script Date: 06/08/2011 11:07:09 ******/
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
/****** Object:  StoredProcedure [dbo].[login_IsLogining]    Script Date: 06/08/2011 11:07:07 ******/
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
/****** Object:  StoredProcedure [dbo].[login_login]    Script Date: 06/08/2011 11:07:07 ******/
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
/****** Object:  StoredProcedure [dbo].[login_logout]    Script Date: 06/08/2011 11:07:07 ******/
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
/****** Object:  StoredProcedure [dbo].[login_logoutException]    Script Date: 06/08/2011 11:07:07 ******/
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
/****** Object:  StoredProcedure [dbo].[login_logoutExceptionAll]    Script Date: 06/08/2011 11:07:07 ******/
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
/****** Object:  StoredProcedure [dbo].[comm_CreateNewID]    Script Date: 06/08/2011 11:07:07 ******/
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
/****** Object:  StoredProcedure [dbo].[userGroup_add]    Script Date: 06/08/2011 11:07:07 ******/
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
/****** Object:  StoredProcedure [dbo].[userGroup_delete]    Script Date: 06/08/2011 11:07:07 ******/
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
/****** Object:  StoredProcedure [dbo].[userGroup_edit]    Script Date: 06/08/2011 11:07:07 ******/
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
/****** Object:  StoredProcedure [dbo].[user_IsBeing]    Script Date: 06/08/2011 11:07:07 ******/
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
/****** Object:  StoredProcedure [dbo].[user_add]    Script Date: 06/08/2011 11:07:07 ******/
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
/****** Object:  StoredProcedure [dbo].[user_delete]    Script Date: 06/08/2011 11:07:07 ******/
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
/****** Object:  StoredProcedure [dbo].[user_edit]    Script Date: 06/08/2011 11:07:07 ******/
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
/****** Object:  StoredProcedure [dbo].[dictionary_edit]    Script Date: 06/08/2011 11:07:07 ******/
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
/****** Object:  StoredProcedure [dbo].[employee_add]    Script Date: 06/08/2011 11:07:07 ******/
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
/****** Object:  StoredProcedure [dbo].[employee_edit]    Script Date: 06/08/2011 11:07:07 ******/
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
/****** Object:  StoredProcedure [dbo].[employee_delete]    Script Date: 06/08/2011 11:07:07 ******/
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
/****** Object:  StoredProcedure [dbo].[user_CreateNewID]    Script Date: 06/08/2011 11:07:07 ******/
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
/****** Object:  StoredProcedure [dbo].[login_CreateNewID]    Script Date: 06/08/2011 11:07:07 ******/
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
/****** Object:  StoredProcedure [dbo].[userGroup_CreateNewID]    Script Date: 06/08/2011 11:07:07 ******/
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
/****** Object:  StoredProcedure [dbo].[userGroup_setByUserID]    Script Date: 06/08/2011 11:07:07 ******/
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
