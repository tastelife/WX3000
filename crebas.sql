USE [wx]
GO
/****** Object:  Table [dbo].[userGroup]    Script Date: 04/14/2011 16:45:46 ******/
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
	[col_userGroup_opertor] [datetime] NOT NULL,
	[col_userGroup_copyFromID] [int] NOT NULL,
 CONSTRAINT [PK_USERGROUP] PRIMARY KEY NONCLUSTERED 
(
	[col_userGroup_id] ASC
)WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[user1]    Script Date: 04/14/2011 16:45:46 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[user1](
	[col_user_id] [int] NOT NULL,
	[col_user_loginName] [char](20) NOT NULL,
	[col_user_empId] [int] NULL,
	[col_user_passwd] [char](256) NOT NULL,
	[col_user_recordState] [tinyint] NOT NULL,
	[col_user_operator] [int] NOT NULL,
	[col_user_operatorTime] [datetime] NOT NULL,
	[col_user_copyFromID] [int] NOT NULL,
 CONSTRAINT [PK_USER] PRIMARY KEY NONCLUSTERED 
(
	[col_user_id] ASC
)WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
SET ANSI_PADDING OFF
GO
INSERT [dbo].[user1] ([col_user_id], [col_user_loginName], [col_user_empId], [col_user_passwd], [col_user_recordState], [col_user_operator], [col_user_operatorTime], [col_user_copyFromID]) VALUES (1, N'1                   ', 11, N'11                                                                                                                                                                                                                                                              ', 2, 23, CAST(0x00009EC200BDB205 AS DateTime), 1)
INSERT [dbo].[user1] ([col_user_id], [col_user_loginName], [col_user_empId], [col_user_passwd], [col_user_recordState], [col_user_operator], [col_user_operatorTime], [col_user_copyFromID]) VALUES (9, N'qw                  ', -1, N'qw                                                                                                                                                                                                                                                              ', 2, 23, CAST(0x00009EC200BDC4D8 AS DateTime), 0)
INSERT [dbo].[user1] ([col_user_id], [col_user_loginName], [col_user_empId], [col_user_passwd], [col_user_recordState], [col_user_operator], [col_user_operatorTime], [col_user_copyFromID]) VALUES (3, N'sss4                ', 5, N'6                                                                                                                                                                                                                                                               ', 2, 0, CAST(0x00009EC400B75510 AS DateTime), 9)
INSERT [dbo].[user1] ([col_user_id], [col_user_loginName], [col_user_empId], [col_user_passwd], [col_user_recordState], [col_user_operator], [col_user_operatorTime], [col_user_copyFromID]) VALUES (10, N'qw1                 ', -1, N'qw                                                                                                                                                                                                                                                              ', 2, 0, CAST(0x00009EC400B7581A AS DateTime), 0)
INSERT [dbo].[user1] ([col_user_id], [col_user_loginName], [col_user_empId], [col_user_passwd], [col_user_recordState], [col_user_operator], [col_user_operatorTime], [col_user_copyFromID]) VALUES (12, N'qw5                 ', -1, N'qw                                                                                                                                                                                                                                                              ', 2, 0, CAST(0x00009EC40108A90D AS DateTime), 0)
INSERT [dbo].[user1] ([col_user_id], [col_user_loginName], [col_user_empId], [col_user_passwd], [col_user_recordState], [col_user_operator], [col_user_operatorTime], [col_user_copyFromID]) VALUES (14, N'qw6                 ', -1, N'qw                                                                                                                                                                                                                                                              ', 2, 0, CAST(0x00009EC40108A676 AS DateTime), 0)
INSERT [dbo].[user1] ([col_user_id], [col_user_loginName], [col_user_empId], [col_user_passwd], [col_user_recordState], [col_user_operator], [col_user_operatorTime], [col_user_copyFromID]) VALUES (15, N'qw12                ', -1, N'12                                                                                                                                                                                                                                                              ', 1, 0, CAST(0x00009EC200AE2A72 AS DateTime), 0)
INSERT [dbo].[user1] ([col_user_id], [col_user_loginName], [col_user_empId], [col_user_passwd], [col_user_recordState], [col_user_operator], [col_user_operatorTime], [col_user_copyFromID]) VALUES (16, N'qw13                ', -1, N'1                                                                                                                                                                                                                                                               ', 1, 0, CAST(0x00009EC200B2F684 AS DateTime), -1)
INSERT [dbo].[user1] ([col_user_id], [col_user_loginName], [col_user_empId], [col_user_passwd], [col_user_recordState], [col_user_operator], [col_user_operatorTime], [col_user_copyFromID]) VALUES (21, N'a1                  ', -1, N'1                                                                                                                                                                                                                                                               ', 1, 0, CAST(0x00009EC400C1E8D6 AS DateTime), -1)
INSERT [dbo].[user1] ([col_user_id], [col_user_loginName], [col_user_empId], [col_user_passwd], [col_user_recordState], [col_user_operator], [col_user_operatorTime], [col_user_copyFromID]) VALUES (22, N'23                  ', -1, N'                                                                                                                                                                                                                                                                ', 2, 0, CAST(0x00009EC400F7B363 AS DateTime), -1)
INSERT [dbo].[user1] ([col_user_id], [col_user_loginName], [col_user_empId], [col_user_passwd], [col_user_recordState], [col_user_operator], [col_user_operatorTime], [col_user_copyFromID]) VALUES (23, N'zz                  ', -1, N'                                                                                                                                                                                                                                                                ', 2, 0, CAST(0x00009EC40108A429 AS DateTime), -1)
INSERT [dbo].[user1] ([col_user_id], [col_user_loginName], [col_user_empId], [col_user_passwd], [col_user_recordState], [col_user_operator], [col_user_operatorTime], [col_user_copyFromID]) VALUES (24, N'wwwwww              ', -1, N'                                                                                                                                                                                                                                                                ', 2, 0, CAST(0x00009EC400F7CCDF AS DateTime), -1)
INSERT [dbo].[user1] ([col_user_id], [col_user_loginName], [col_user_empId], [col_user_passwd], [col_user_recordState], [col_user_operator], [col_user_operatorTime], [col_user_copyFromID]) VALUES (25, N'qwerqw              ', -1, N'                                                                                                                                                                                                                                                                ', 3, 0, CAST(0x00009EC500B50023 AS DateTime), -1)
INSERT [dbo].[user1] ([col_user_id], [col_user_loginName], [col_user_empId], [col_user_passwd], [col_user_recordState], [col_user_operator], [col_user_operatorTime], [col_user_copyFromID]) VALUES (11, N'2                   ', -1, N'qw                                                                                                                                                                                                                                                              ', 2, 0, CAST(0x00009EC400BF576B AS DateTime), 0)
INSERT [dbo].[user1] ([col_user_id], [col_user_loginName], [col_user_empId], [col_user_passwd], [col_user_recordState], [col_user_operator], [col_user_operatorTime], [col_user_copyFromID]) VALUES (17, N'12                  ', -1, N'                                                                                                                                                                                                                                                                ', 2, 0, CAST(0x00009EC500B42B4A AS DateTime), -1)
INSERT [dbo].[user1] ([col_user_id], [col_user_loginName], [col_user_empId], [col_user_passwd], [col_user_recordState], [col_user_operator], [col_user_operatorTime], [col_user_copyFromID]) VALUES (18, N'123                 ', -1, N'                                                                                                                                                                                                                                                                ', 2, 0, CAST(0x00009EC401165B97 AS DateTime), -1)
INSERT [dbo].[user1] ([col_user_id], [col_user_loginName], [col_user_empId], [col_user_passwd], [col_user_recordState], [col_user_operator], [col_user_operatorTime], [col_user_copyFromID]) VALUES (19, N'1234                ', -1, N'                                                                                                                                                                                                                                                                ', 2, 0, CAST(0x00009EC500B4F1F5 AS DateTime), -1)
INSERT [dbo].[user1] ([col_user_id], [col_user_loginName], [col_user_empId], [col_user_passwd], [col_user_recordState], [col_user_operator], [col_user_operatorTime], [col_user_copyFromID]) VALUES (20, N'12345               ', -1, N'                                                                                                                                                                                                                                                                ', 3, 0, CAST(0x00009EC401165F0B AS DateTime), -1)
/****** Object:  Table [dbo].[publicinFormation]    Script Date: 04/14/2011 16:45:46 ******/
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
/****** Object:  Table [dbo].[powerEnum]    Script Date: 04/14/2011 16:45:46 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[powerEnum](
	[col_powerEnum_id] [int] NOT NULL,
	[col_powerEnum_type] [text] NOT NULL,
	[col_powerEnum_enum] [int] NOT NULL,
	[col_powerEnum_name] [text] NOT NULL,
	[col_powerEnum_manual] [text] NULL,
	[col_powerEnum_recordState] [tinyint] NOT NULL,
	[col_powerEnum_operator] [int] NOT NULL,
	[col_powerEnum_operatoTime] [datetime] NOT NULL,
	[col_powerEnum_recordCopyFrom] [int] NOT NULL,
 CONSTRAINT [PK_POWERENUM] PRIMARY KEY NONCLUSTERED 
(
	[col_powerEnum_id] ASC
)WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY]
) ON [PRIMARY] TEXTIMAGE_ON [PRIMARY]
GO
INSERT [dbo].[powerEnum] ([col_powerEnum_id], [col_powerEnum_type], [col_powerEnum_enum], [col_powerEnum_name], [col_powerEnum_manual], [col_powerEnum_recordState], [col_powerEnum_operator], [col_powerEnum_operatoTime], [col_powerEnum_recordCopyFrom]) VALUES (101, N'recordState', 1, N'新建', NULL, 1, 0, CAST(0x00009F9800000000 AS DateTime), 0)
INSERT [dbo].[powerEnum] ([col_powerEnum_id], [col_powerEnum_type], [col_powerEnum_enum], [col_powerEnum_name], [col_powerEnum_manual], [col_powerEnum_recordState], [col_powerEnum_operator], [col_powerEnum_operatoTime], [col_powerEnum_recordCopyFrom]) VALUES (102, N'recordState', 2, N'删除', NULL, 1, 0, CAST(0x00009F9800000000 AS DateTime), 0)
INSERT [dbo].[powerEnum] ([col_powerEnum_id], [col_powerEnum_type], [col_powerEnum_enum], [col_powerEnum_name], [col_powerEnum_manual], [col_powerEnum_recordState], [col_powerEnum_operator], [col_powerEnum_operatoTime], [col_powerEnum_recordCopyFrom]) VALUES (103, N'recordState', 3, N'修改', NULL, 1, 0, CAST(0x00009F9800000000 AS DateTime), 0)
INSERT [dbo].[powerEnum] ([col_powerEnum_id], [col_powerEnum_type], [col_powerEnum_enum], [col_powerEnum_name], [col_powerEnum_manual], [col_powerEnum_recordState], [col_powerEnum_operator], [col_powerEnum_operatoTime], [col_powerEnum_recordCopyFrom]) VALUES (104, N'recordState', 4, N'记录新建', NULL, 1, 0, CAST(0x00009F9800000000 AS DateTime), 0)
INSERT [dbo].[powerEnum] ([col_powerEnum_id], [col_powerEnum_type], [col_powerEnum_enum], [col_powerEnum_name], [col_powerEnum_manual], [col_powerEnum_recordState], [col_powerEnum_operator], [col_powerEnum_operatoTime], [col_powerEnum_recordCopyFrom]) VALUES (105, N'recordState', 5, N'记录删除', NULL, 1, 0, CAST(0x00009F9800000000 AS DateTime), 0)
INSERT [dbo].[powerEnum] ([col_powerEnum_id], [col_powerEnum_type], [col_powerEnum_enum], [col_powerEnum_name], [col_powerEnum_manual], [col_powerEnum_recordState], [col_powerEnum_operator], [col_powerEnum_operatoTime], [col_powerEnum_recordCopyFrom]) VALUES (106, N'recordState', 6, N'记录修改', NULL, 1, 0, CAST(0x00009F9800000000 AS DateTime), 0)
INSERT [dbo].[powerEnum] ([col_powerEnum_id], [col_powerEnum_type], [col_powerEnum_enum], [col_powerEnum_name], [col_powerEnum_manual], [col_powerEnum_recordState], [col_powerEnum_operator], [col_powerEnum_operatoTime], [col_powerEnum_recordCopyFrom]) VALUES (100101, N'login_state', 1, N'登录', NULL, 1, 0, CAST(0x00009F9800000000 AS DateTime), 0)
INSERT [dbo].[powerEnum] ([col_powerEnum_id], [col_powerEnum_type], [col_powerEnum_enum], [col_powerEnum_name], [col_powerEnum_manual], [col_powerEnum_recordState], [col_powerEnum_operator], [col_powerEnum_operatoTime], [col_powerEnum_recordCopyFrom]) VALUES (100102, N'login_state', 2, N'退出', NULL, 1, 0, CAST(0x00009F9800000000 AS DateTime), 0)
INSERT [dbo].[powerEnum] ([col_powerEnum_id], [col_powerEnum_type], [col_powerEnum_enum], [col_powerEnum_name], [col_powerEnum_manual], [col_powerEnum_recordState], [col_powerEnum_operator], [col_powerEnum_operatoTime], [col_powerEnum_recordCopyFrom]) VALUES (100103, N'login_state', 3, N'异常退出', NULL, 1, 0, CAST(0x00009F9800000000 AS DateTime), 0)
INSERT [dbo].[powerEnum] ([col_powerEnum_id], [col_powerEnum_type], [col_powerEnum_enum], [col_powerEnum_name], [col_powerEnum_manual], [col_powerEnum_recordState], [col_powerEnum_operator], [col_powerEnum_operatoTime], [col_powerEnum_recordCopyFrom]) VALUES (100104, N'login_state', 4, N'强制退出', NULL, 1, 0, CAST(0x00009F9800000000 AS DateTime), 0)
/****** Object:  Table [dbo].[newID]    Script Date: 04/14/2011 16:45:46 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[newID](
	[col_newID_ID] [int] NOT NULL,
	[col_newID_lastID] [int] NOT NULL,
	[col_newID_tableName] [char](32) NOT NULL,
 CONSTRAINT [PK_NEWID] PRIMARY KEY NONCLUSTERED 
(
	[col_newID_ID] ASC
)WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
SET ANSI_PADDING OFF
GO
INSERT [dbo].[newID] ([col_newID_ID], [col_newID_lastID], [col_newID_tableName]) VALUES (0, 25, N'user1                           ')
INSERT [dbo].[newID] ([col_newID_ID], [col_newID_lastID], [col_newID_tableName]) VALUES (1, 67, N'login                           ')
/****** Object:  Table [dbo].[messageBoard]    Script Date: 04/14/2011 16:45:46 ******/
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
/****** Object:  Table [dbo].[login]    Script Date: 04/14/2011 16:45:46 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[login](
	[col_login_id] [int] NOT NULL,
	[col_user_id] [int] NOT NULL,
	[col_login_loginTime] [datetime] NOT NULL,
	[col_login_state] [int] NOT NULL,
	[col_login_computerName] [char](128) NULL,
	[col_login_mac] [char](128) NULL,
	[col_login_ip] [char](32) NULL,
	[col_login_recordState] [tinyint] NOT NULL,
	[col_login_operatorUserID] [int] NOT NULL,
	[col_login_operatoTime] [datetime] NOT NULL,
	[col_login_copyFromID] [int] NOT NULL,
 CONSTRAINT [PK_LOGIN] PRIMARY KEY NONCLUSTERED 
(
	[col_login_id] ASC
)WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
SET ANSI_PADDING OFF
GO
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (1, 0, CAST(0x00009E5E00000000 AS DateTime), 3, N'0                                                                                                                               ', N'0                                                                                                                               ', N'0                               ', 2, 5, CAST(0x00009EC500E594EE AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (11, 2, CAST(0x00009E5E00000000 AS DateTime), 3, N'1                                                                                                                               ', N'4                                                                                                                               ', N'5                               ', 2, 5, CAST(0x00009EC500E594EE AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (2, 2, CAST(0x00009EC500DC137F AS DateTime), 4, N'33                                                                                                                              ', N'33                                                                                                                              ', N'33                              ', 2, 12121, CAST(0x00009EC500DE7C71 AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (7, 1, CAST(0x00009EC500F45556 AS DateTime), 3, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78  192.168.56.1    ', 2, 0, CAST(0x00009EC5010EEB30 AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (61, 1, CAST(0x00009EC500F540E8 AS DateTime), 3, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78  192.168.56.1    ', 2, 0, CAST(0x00009EC5010EEB30 AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (62, 1, CAST(0x00009EC5010E3044 AS DateTime), 3, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78  192.168.56.1    ', 2, 0, CAST(0x00009EC5010EEB30 AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (66, 1, CAST(0x00009EC501132897 AS DateTime), 1, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78  192.168.56.1    ', 1, 0, CAST(0x00009EC501132897 AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (63, 1, CAST(0x00009EC5010EA434 AS DateTime), 3, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78  192.168.56.1    ', 2, 0, CAST(0x00009EC5010EEB30 AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (64, 1, CAST(0x00009EC5010EEB32 AS DateTime), 3, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78  192.168.56.1    ', 2, 0, CAST(0x00009EC501132895 AS DateTime), -1)
/****** Object:  Table [dbo].[hintuser]    Script Date: 04/14/2011 16:45:46 ******/
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
/****** Object:  Table [dbo].[hint]    Script Date: 04/14/2011 16:45:46 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
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
	[col_HINT_title] [char](128) NOT NULL,
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
SET ANSI_PADDING OFF
GO
/****** Object:  Table [dbo].[groupFunctionPointPower]    Script Date: 04/14/2011 16:45:46 ******/
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
/****** Object:  Table [dbo].[group]    Script Date: 04/14/2011 16:45:46 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[group](
	[col_group_id] [int] NOT NULL,
	[col_group_name] [char](128) NOT NULL,
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
SET ANSI_PADDING OFF
GO
/****** Object:  Table [dbo].[functinPoint]    Script Date: 04/14/2011 16:45:46 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[functinPoint](
	[col_functinPoint_id] [int] NOT NULL,
	[col_functinPoint_name] [text] NOT NULL,
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
/****** Object:  StoredProcedure [dbo].[comm_CreateNewID]    Script Date: 04/14/2011 16:45:44 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
create PROCEDURE [dbo].[comm_CreateNewID]
(
@tableName char(32)
)

AS
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
/****** Object:  StoredProcedure [dbo].[login_logoutExceptionAll]    Script Date: 04/14/2011 16:45:44 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
create PROCEDURE [dbo].[login_logoutExceptionAll]
           (@col_login_operatorUserID int)
AS
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
/****** Object:  StoredProcedure [dbo].[login_logoutException]    Script Date: 04/14/2011 16:45:44 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE PROCEDURE [dbo].[login_logoutException]
           (@col_user_id int 
           ,@col_login_operatorUserID int)
AS
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
/****** Object:  StoredProcedure [dbo].[login_logout]    Script Date: 04/14/2011 16:45:44 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE PROCEDURE [dbo].[login_logout]
           (@col_login_id int 
           ,@col_login_state int 
           ,@col_login_operatorUserID int)
AS
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
/****** Object:  StoredProcedure [dbo].[login_login]    Script Date: 04/14/2011 16:45:44 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE PROCEDURE [dbo].[login_login]
           (@col_login_id int 
           ,@col_user_id int 
           ,@col_login_loginTime datetime 
           ,@col_login_state int 
           ,@col_login_computerName char(128) 
           ,@col_login_mac char(128) 
           ,@col_login_ip char(32) 
           ,@col_login_recordState tinyint 
           ,@col_login_operatorUserID int 
           ,@col_login_operatoTime datetime 
           ,@col_login_copyFromID int )
AS
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
/****** Object:  StoredProcedure [dbo].[login_IsLogining]    Script Date: 04/14/2011 16:45:44 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
create PROCEDURE [dbo].[login_IsLogining](
           @col_user_id int )
AS
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
/****** Object:  StoredProcedure [dbo].[user_add]    Script Date: 04/14/2011 16:45:44 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE PROCEDURE [dbo].[user_add](
           @col_user_id int,
           @col_user_loginName char(20),
           @col_user_empId int,
           @col_user_passwd char(256),
           @col_user_recordStat tinyint,
           @col_user_operator int,
           @col_user_operatorTime datetime,
           @col_user_copyFromID int)
AS
BEGIN

	SET NOCOUNT ON;
	
INSERT INTO [wx].dbo.user1
           (col_user_id
           ,col_user_loginName
           ,col_user_empId
           ,col_user_passwd
           ,col_user_recordState
           ,col_user_operator
           ,col_user_operatorTime
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
/****** Object:  StoredProcedure [dbo].[user_IsBeing]    Script Date: 04/14/2011 16:45:44 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE PROCEDURE [dbo].[user_IsBeing](
           @col_user_loginName char(20))
AS
BEGIN

	SET NOCOUNT ON;
	
	declare @count int
	set @count=0
	
	select @count =COUNT(*) from dbo.user1 where col_user_loginName=@col_user_loginName

	return @count
END
GO
/****** Object:  StoredProcedure [dbo].[user_edit]    Script Date: 04/14/2011 16:45:44 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE PROCEDURE [dbo].[user_edit](
           @col_user_id int,
           @col_user_loginName char(20),
           @col_user_empId int,
           @col_user_passwd char(256),
           @col_user_recordStat tinyint,
           @col_user_operator int,
           @col_user_operatorTime datetime,
           @col_user_copyFromID int)
AS
BEGIN

	SET NOCOUNT ON;
	
UPDATE [wx].[dbo].[user1]
   SET [col_user_empId] = @col_user_empId
      ,[col_user_passwd] = @col_user_passwd
      ,[col_user_recordState] = 3
      ,[col_user_operator] = @col_user_operator
      ,[col_user_operatorTime] = GETDATE()
 WHERE col_user_id = @col_user_id
END
GO
/****** Object:  StoredProcedure [dbo].[user_delete]    Script Date: 04/14/2011 16:45:44 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
create PROCEDURE [dbo].[user_delete](
           @col_user_id int,
           @col_user_operator int)
AS
BEGIN

	SET NOCOUNT ON;
	
UPDATE [wx].[dbo].[user1]
   SET [col_user_recordState] = 2
      ,[col_user_operator] = @col_user_operator
      ,[col_user_operatorTime] = GETDATE()
 WHERE col_user_id = @col_user_id
END
GO
/****** Object:  StoredProcedure [dbo].[user_CreateNewID]    Script Date: 04/14/2011 16:45:44 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE PROCEDURE [dbo].[user_CreateNewID]

AS
BEGIN

	SET NOCOUNT ON;
	
	DECLARE	@return_value int

	EXEC	@return_value = [dbo].[comm_CreateNewID]
			@tableName = N'user1'
		
	return @return_value

END
GO
/****** Object:  StoredProcedure [dbo].[login_CreateNewID]    Script Date: 04/14/2011 16:45:44 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
create PROCEDURE [dbo].[login_CreateNewID]

AS
BEGIN

	SET NOCOUNT ON;
	
	DECLARE	@return_value int

	EXEC	@return_value = [dbo].[comm_CreateNewID]
			@tableName = N'login'
		
	return @return_value

END
GO
