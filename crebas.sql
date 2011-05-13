USE [wx]
GO
/****** Object:  Table [dbo].[userGroup]    Script Date: 05/13/2011 16:55:09 ******/
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
INSERT [dbo].[userGroup] ([col_userGroup_id], [col_group_id], [col_user_id], [col_userGroup_recordState], [col_userGroup_operator], [col_userGroup_operatoTime], [col_userGroup_copyFromID]) VALUES (1, 1, 1, 1, 0, CAST(0x00009ECA011EC257 AS DateTime), 0)
INSERT [dbo].[userGroup] ([col_userGroup_id], [col_group_id], [col_user_id], [col_userGroup_recordState], [col_userGroup_operator], [col_userGroup_operatoTime], [col_userGroup_copyFromID]) VALUES (2, 1, 20, 1, 0, CAST(0x00009ECA010B6865 AS DateTime), 0)
INSERT [dbo].[userGroup] ([col_userGroup_id], [col_group_id], [col_user_id], [col_userGroup_recordState], [col_userGroup_operator], [col_userGroup_operatoTime], [col_userGroup_copyFromID]) VALUES (3, 31, 32, 1, 34, CAST(0x00009ECA010C1C32 AS DateTime), -1)
INSERT [dbo].[userGroup] ([col_userGroup_id], [col_group_id], [col_user_id], [col_userGroup_recordState], [col_userGroup_operator], [col_userGroup_operatoTime], [col_userGroup_copyFromID]) VALUES (11, 2, 11, 11, 0, CAST(0x00009EDA010662EB AS DateTime), 11)
INSERT [dbo].[userGroup] ([col_userGroup_id], [col_group_id], [col_user_id], [col_userGroup_recordState], [col_userGroup_operator], [col_userGroup_operatoTime], [col_userGroup_copyFromID]) VALUES (18, 41, 42, 1, 44, CAST(0x00009ECA011115C7 AS DateTime), -1)
INSERT [dbo].[userGroup] ([col_userGroup_id], [col_group_id], [col_user_id], [col_userGroup_recordState], [col_userGroup_operator], [col_userGroup_operatoTime], [col_userGroup_copyFromID]) VALUES (17, 21, 522, 0, 53, CAST(0x00009ECA0112887E AS DateTime), 0)
INSERT [dbo].[userGroup] ([col_userGroup_id], [col_group_id], [col_user_id], [col_userGroup_recordState], [col_userGroup_operator], [col_userGroup_operatoTime], [col_userGroup_copyFromID]) VALUES (21, 21, 5, 1, 53, CAST(0x00009ECA0112BBDE AS DateTime), -1)
INSERT [dbo].[userGroup] ([col_userGroup_id], [col_group_id], [col_user_id], [col_userGroup_recordState], [col_userGroup_operator], [col_userGroup_operatoTime], [col_userGroup_copyFromID]) VALUES (22, 21, 2, 1, 0, CAST(0x00009ECA011DD0CA AS DateTime), -1)
INSERT [dbo].[userGroup] ([col_userGroup_id], [col_group_id], [col_user_id], [col_userGroup_recordState], [col_userGroup_operator], [col_userGroup_operatoTime], [col_userGroup_copyFromID]) VALUES (23, 1, 3, 1, 0, CAST(0x00009ECA011DF2C1 AS DateTime), -1)
INSERT [dbo].[userGroup] ([col_userGroup_id], [col_group_id], [col_user_id], [col_userGroup_recordState], [col_userGroup_operator], [col_userGroup_operatoTime], [col_userGroup_copyFromID]) VALUES (24, 2, 21, 1, 0, CAST(0x00009ECA011EB367 AS DateTime), -1)
INSERT [dbo].[userGroup] ([col_userGroup_id], [col_group_id], [col_user_id], [col_userGroup_recordState], [col_userGroup_operator], [col_userGroup_operatoTime], [col_userGroup_copyFromID]) VALUES (25, 2, 27, 1, 0, CAST(0x00009ED300C1724F AS DateTime), -1)
INSERT [dbo].[userGroup] ([col_userGroup_id], [col_group_id], [col_user_id], [col_userGroup_recordState], [col_userGroup_operator], [col_userGroup_operatoTime], [col_userGroup_copyFromID]) VALUES (26, 3, 17, 1, 0, CAST(0x00009ED400EA62B8 AS DateTime), -1)
INSERT [dbo].[userGroup] ([col_userGroup_id], [col_group_id], [col_user_id], [col_userGroup_recordState], [col_userGroup_operator], [col_userGroup_operatoTime], [col_userGroup_copyFromID]) VALUES (27, 4, 19, 1, 0, CAST(0x00009ED400EA6797 AS DateTime), -1)
INSERT [dbo].[userGroup] ([col_userGroup_id], [col_group_id], [col_user_id], [col_userGroup_recordState], [col_userGroup_operator], [col_userGroup_operatoTime], [col_userGroup_copyFromID]) VALUES (28, 3, 28, 1, 0, CAST(0x00009EDA01066935 AS DateTime), -1)
INSERT [dbo].[userGroup] ([col_userGroup_id], [col_group_id], [col_user_id], [col_userGroup_recordState], [col_userGroup_operator], [col_userGroup_operatoTime], [col_userGroup_copyFromID]) VALUES (29, 4, 29, 1, 0, CAST(0x00009EDA01066E9D AS DateTime), -1)
/****** Object:  Table [dbo].[publicinFormation]    Script Date: 05/13/2011 16:55:09 ******/
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
/****** Object:  Table [dbo].[newID]    Script Date: 05/13/2011 16:55:09 ******/
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
INSERT [dbo].[newID] ([col_newID_ID], [col_newID_lastID], [col_newID_tableName]) VALUES (0, 31, N'userTBL                         ')
INSERT [dbo].[newID] ([col_newID_ID], [col_newID_lastID], [col_newID_tableName]) VALUES (1, 176, N'login                           ')
INSERT [dbo].[newID] ([col_newID_ID], [col_newID_lastID], [col_newID_tableName]) VALUES (2, 29, N'userGroup                       ')
/****** Object:  Table [dbo].[messageBoard]    Script Date: 05/13/2011 16:55:09 ******/
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
/****** Object:  Table [dbo].[login]    Script Date: 05/13/2011 16:55:09 ******/
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
SET ANSI_PADDING OFF
GO
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (114, 1, CAST(0x00009ED400FBF3C1 AS DateTime), 0, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78 192.168.56.1', 2, 0, CAST(0x00009ED400FC0207 AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (116, 1, CAST(0x00009EDA00EAD4F6 AS DateTime), 0, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78 192.168.56.1', 2, 0, CAST(0x00009EDA00EAF5BB AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (117, 1, CAST(0x00009EDA0103B943 AS DateTime), 3, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78 192.168.56.1', 2, 0, CAST(0x00009EDA01041113 AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (118, 1, CAST(0x00009EDA01041118 AS DateTime), 0, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78 192.168.56.1', 2, 0, CAST(0x00009EDA01045C00 AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (119, 1, CAST(0x00009EDA0104AF66 AS DateTime), 0, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78 192.168.56.1', 2, 0, CAST(0x00009EDA0104E1EF AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (120, 1, CAST(0x00009EDA01062A85 AS DateTime), 0, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78 192.168.56.1', 2, 0, CAST(0x00009EDA010684C7 AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (121, 11, CAST(0x00009EDA010762D3 AS DateTime), 0, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78 192.168.56.1', 2, 0, CAST(0x00009EDA0107662E AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (122, 29, CAST(0x00009EDA01076BED AS DateTime), 0, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78 192.168.56.1', 2, 0, CAST(0x00009EDA0107B869 AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (123, 1, CAST(0x00009EDA010AE8AB AS DateTime), 0, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78 192.168.56.1', 2, 0, CAST(0x00009EDA010AF7FC AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (124, 11, CAST(0x00009EDA010AFD05 AS DateTime), 0, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78 192.168.56.1', 2, 0, CAST(0x00009EDA010B437C AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (125, 28, CAST(0x00009EDA010B4A84 AS DateTime), 0, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78 192.168.56.1', 2, 0, CAST(0x00009EDA010B61DC AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (126, 29, CAST(0x00009EDA010B669B AS DateTime), 0, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78 192.168.56.1', 2, 0, CAST(0x00009EDA010B747B AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (127, 1, CAST(0x00009EDA010C8843 AS DateTime), 0, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78 192.168.56.1', 2, 0, CAST(0x00009EDA010C895D AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (128, 29, CAST(0x00009EDA010C8CBA AS DateTime), 0, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78 192.168.56.1', 2, 0, CAST(0x00009EDA010C91E5 AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (129, 1, CAST(0x00009EDA010E393C AS DateTime), 0, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78 192.168.56.1', 2, 0, CAST(0x00009EDA010E4022 AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (130, 11, CAST(0x00009EDA010E4413 AS DateTime), 0, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78 192.168.56.1', 2, 0, CAST(0x00009EDA010E51F2 AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (131, 29, CAST(0x00009EDA010E55A7 AS DateTime), 0, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78 192.168.56.1', 2, 0, CAST(0x00009EDA010E5799 AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (132, 28, CAST(0x00009EDA010E5AE8 AS DateTime), 0, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78 192.168.56.1', 2, 0, CAST(0x00009EDA010E5F53 AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (133, 11, CAST(0x00009EDA010F2260 AS DateTime), 0, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78 192.168.56.1', 2, 0, CAST(0x00009EDA010F2F16 AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (134, 11, CAST(0x00009EDA010F75D2 AS DateTime), 0, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78 192.168.56.1', 2, 0, CAST(0x00009EDA010F8348 AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (135, 1, CAST(0x00009EDA010F86E8 AS DateTime), 0, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78 192.168.56.1', 2, 0, CAST(0x00009EDA010F8ADF AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (136, 1, CAST(0x00009EDB00BE6914 AS DateTime), 0, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78 192.168.56.1', 2, 0, CAST(0x00009EDB00BE6B69 AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (137, 11, CAST(0x00009EDB00BE6EC0 AS DateTime), 0, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78 192.168.56.1', 2, 0, CAST(0x00009EDB00BE7668 AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (138, 28, CAST(0x00009EDB00BE7CC9 AS DateTime), 0, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78 192.168.56.1', 2, 0, CAST(0x00009EDB00BE87FC AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (139, 29, CAST(0x00009EDB00BE8BAE AS DateTime), 0, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78 192.168.56.1', 2, 0, CAST(0x00009EDB00BE8D4F AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (140, 1, CAST(0x00009EDB00BE904A AS DateTime), 0, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78 192.168.56.1', 2, 0, CAST(0x00009EDB00BE9136 AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (141, 1, CAST(0x00009EDB00BE94B9 AS DateTime), 0, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78 192.168.56.1', 2, 0, CAST(0x00009EDB00BEBE09 AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (142, 1, CAST(0x00009EDB00DCACE8 AS DateTime), 0, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78 192.168.56.1', 2, 0, CAST(0x00009EDB00DCCAB0 AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (143, 1, CAST(0x00009EDB00DD5D19 AS DateTime), 0, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78 192.168.56.1', 2, 0, CAST(0x00009EDB00DD79D5 AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (144, 1, CAST(0x00009EDB00E66F89 AS DateTime), 0, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78  192.168.56.1  ', 2, 0, CAST(0x00009EDB00E6817C AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (145, 1, CAST(0x00009EDB00E6E3E3 AS DateTime), 0, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78  192.168.56.1  ', 2, 0, CAST(0x00009EDB00E74736 AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (146, 11, CAST(0x00009EDB00E74C2C AS DateTime), 0, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78  192.168.56.1  ', 2, 0, CAST(0x00009EDB00E76C13 AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (147, 28, CAST(0x00009EDB00E7703F AS DateTime), 0, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78  192.168.56.1  ', 2, 0, CAST(0x00009EDB00E77745 AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (148, 29, CAST(0x00009EDB00E781F9 AS DateTime), 0, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78  192.168.56.1  ', 2, 0, CAST(0x00009EDB00E78987 AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (149, 29, CAST(0x00009EDB00E78E99 AS DateTime), 0, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78  192.168.56.1  ', 2, 0, CAST(0x00009EDB00E7946E AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (150, 28, CAST(0x00009EDB00E79867 AS DateTime), 0, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78  192.168.56.1  ', 2, 0, CAST(0x00009EDB00E79F03 AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (151, 11, CAST(0x00009EDB00E7A2C6 AS DateTime), 0, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78  192.168.56.1  ', 2, 0, CAST(0x00009EDB00E7ABEE AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (152, 1, CAST(0x00009EDB00E7B150 AS DateTime), 0, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78  192.168.56.1  ', 2, 0, CAST(0x00009EDB00E7D390 AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (164, 1, CAST(0x00009EDB010F482B AS DateTime), 0, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78  192.168.56.1  ', 2, 0, CAST(0x00009EDB010FBF9D AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (165, 1, CAST(0x00009EDB011020E2 AS DateTime), 0, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78  192.168.56.1  ', 2, 0, CAST(0x00009EDB01103B20 AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (166, 1, CAST(0x00009EDB01107F4A AS DateTime), 0, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78  192.168.56.1  ', 2, 0, CAST(0x00009EDB011093A1 AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (167, 1, CAST(0x00009EDB0110B41F AS DateTime), 0, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78  192.168.56.1  ', 2, 0, CAST(0x00009EDB0110C90A AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (168, 1, CAST(0x00009EDB011158EF AS DateTime), 0, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78  192.168.56.1  ', 2, 0, CAST(0x00009EDB01117D60 AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (169, 1, CAST(0x00009EDB0111A6E8 AS DateTime), 3, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78  192.168.56.1  ', 2, 0, CAST(0x00009EDB011260F9 AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (170, 1, CAST(0x00009EDB011260FB AS DateTime), 0, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78  192.168.56.1  ', 2, 0, CAST(0x00009EDB011287B9 AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (171, 1, CAST(0x00009EE001030C25 AS DateTime), 0, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78  192.168.56.1  ', 2, 0, CAST(0x00009EE001032D28 AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (172, 11, CAST(0x00009EE00103307D AS DateTime), 0, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78  192.168.56.1  ', 2, 0, CAST(0x00009EE001033368 AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (173, 28, CAST(0x00009EE0010338E9 AS DateTime), 0, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78  192.168.56.1  ', 2, 0, CAST(0x00009EE001033ADE AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (93, 1, CAST(0x00009EC9011945A2 AS DateTime), 0, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78 192.168.56.1', 2, 0, CAST(0x00009EC901195404 AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (94, 1, CAST(0x00009EC901198F0E AS DateTime), 0, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78 192.168.56.1', 2, 0, CAST(0x00009EC90119A458 AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (95, 1, CAST(0x00009EC90119D817 AS DateTime), 0, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78 192.168.56.1', 2, 0, CAST(0x00009EC90119EEAC AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (96, 1, CAST(0x00009EC9011B6909 AS DateTime), 0, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78 192.168.56.1', 2, 0, CAST(0x00009EC9011B79A3 AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (97, 1, CAST(0x00009EC9011D8073 AS DateTime), 0, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78 192.168.56.1', 2, 0, CAST(0x00009EC9011D8894 AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (98, 1, CAST(0x00009EC9011DA49F AS DateTime), 0, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78 192.168.56.1', 2, 0, CAST(0x00009EC9011E00F4 AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (99, 1, CAST(0x00009EC9011E329B AS DateTime), 0, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78 192.168.56.1', 2, 0, CAST(0x00009EC9011EAE2B AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (101, 1, CAST(0x00009ECA011C359D AS DateTime), 0, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78 192.168.56.1', 2, 0, CAST(0x00009ECA011C4C75 AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (102, 1, CAST(0x00009ECA011D14C1 AS DateTime), 3, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78 192.168.56.1', 2, 0, CAST(0x00009ECA011DB806 AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (91, 1, CAST(0x00009EC901106C7F AS DateTime), 0, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78 192.168.56.1', 2, 0, CAST(0x00009EC90110787E AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (92, 1, CAST(0x00009EC90110C661 AS DateTime), 0, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78 192.168.56.1', 2, 0, CAST(0x00009EC90110D3C4 AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (100, 1, CAST(0x00009EC9011ED1CF AS DateTime), 0, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78 192.168.56.1', 2, 0, CAST(0x00009EC9011EE47B AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (103, 1, CAST(0x00009ECA011DB808 AS DateTime), 3, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78 192.168.56.1', 2, 0, CAST(0x00009ED300BCA994 AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (104, 1, CAST(0x00009ED300BCAB5C AS DateTime), 3, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78 192.168.56.1', 2, 0, CAST(0x00009ED300BCB50C AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (105, 1, CAST(0x00009ED300BCB50F AS DateTime), 0, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78 192.168.56.1', 2, 0, CAST(0x00009ED300BCCC6B AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (106, 1, CAST(0x00009ED300BEF093 AS DateTime), 0, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78 192.168.56.1', 2, 0, CAST(0x00009ED300BEF387 AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (107, 1, CAST(0x00009ED300BF36B0 AS DateTime), 0, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78 192.168.56.1', 2, 0, CAST(0x00009ED300BF3EAA AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (108, 1, CAST(0x00009ED300BF8C72 AS DateTime), 0, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78 192.168.56.1', 2, 0, CAST(0x00009ED300BFB201 AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (109, 1, CAST(0x00009ED300C12098 AS DateTime), 0, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78 192.168.56.1', 2, 0, CAST(0x00009ED300C17A63 AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (110, 1, CAST(0x00009ED400E8D065 AS DateTime), 0, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78 192.168.56.1', 2, 0, CAST(0x00009ED400E8ECD2 AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (111, 1, CAST(0x00009ED400EA4AA1 AS DateTime), 0, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78 192.168.56.1', 2, 0, CAST(0x00009ED400EAE5E9 AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (112, 1, CAST(0x00009ED400F153B0 AS DateTime), 0, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78 192.168.56.1', 2, 0, CAST(0x00009ED400F1A844 AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (113, 1, CAST(0x00009ED400F78AD5 AS DateTime), 3, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78 192.168.56.1', 2, 0, CAST(0x00009ED400FBF3BD AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (115, 1, CAST(0x00009ED4010854B1 AS DateTime), 0, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78 192.168.56.1', 2, 0, CAST(0x00009ED40108615D AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (153, 1, CAST(0x00009EDB00E88E2B AS DateTime), 0, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78  192.168.56.1  ', 2, 0, CAST(0x00009EDB00E9FF69 AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (154, 1, CAST(0x00009EDB00EA02E3 AS DateTime), 0, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78  192.168.56.1  ', 2, 0, CAST(0x00009EDB00EA0CC0 AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (155, 1, CAST(0x00009EDB00EE410F AS DateTime), 0, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78  192.168.56.1  ', 2, 0, CAST(0x00009EDB00EE436B AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (156, 11, CAST(0x00009EDB00EE465B AS DateTime), 0, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78  192.168.56.1  ', 2, 0, CAST(0x00009EDB00EE4879 AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (157, 28, CAST(0x00009EDB00EE506D AS DateTime), 0, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78  192.168.56.1  ', 2, 0, CAST(0x00009EDB00EE521A AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (158, 29, CAST(0x00009EDB00EE5565 AS DateTime), 0, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78  192.168.56.1  ', 2, 0, CAST(0x00009EDB00EE57D2 AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (159, 1, CAST(0x00009EDB00EECBA6 AS DateTime), 0, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78  192.168.56.1  ', 2, 0, CAST(0x00009EDB00EEEA3D AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (160, 1, CAST(0x00009EDB00FA75BD AS DateTime), 0, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78  192.168.56.1  ', 2, 0, CAST(0x00009EDB00FAC579 AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (161, 1, CAST(0x00009EDB00FBFE28 AS DateTime), 0, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78  192.168.56.1  ', 2, 0, CAST(0x00009EDB00FC0D68 AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (162, 1, CAST(0x00009EDB00FC3132 AS DateTime), 0, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78  192.168.56.1  ', 2, 0, CAST(0x00009EDB00FC4A25 AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (163, 1, CAST(0x00009EDB010D4FBF AS DateTime), 3, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78  192.168.56.1  ', 2, 0, CAST(0x00009EDB010F4829 AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (174, 29, CAST(0x00009EE001033EA1 AS DateTime), 0, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78  192.168.56.1  ', 2, 0, CAST(0x00009EE00103461B AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (175, 1, CAST(0x00009EE100F1CBC6 AS DateTime), 0, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78  192.168.56.1  ', 2, 0, CAST(0x00009EE100F1D75E AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (176, 1, CAST(0x00009EE1010A89FC AS DateTime), 0, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78  192.168.56.1  ', 2, 0, CAST(0x00009EE1010B0803 AS DateTime), -1)
/****** Object:  Table [dbo].[hintuser]    Script Date: 05/13/2011 16:55:09 ******/
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
/****** Object:  Table [dbo].[hint]    Script Date: 05/13/2011 16:55:09 ******/
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
/****** Object:  Table [dbo].[groupFunctionPointPower]    Script Date: 05/13/2011 16:55:09 ******/
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
INSERT [dbo].[groupFunctionPointPower] ([col_group_id], [col_functinPoint_id], [col_groupFuncitonPointPower], [col_groupFunctionPointPower_recordState], [col_groupFunctionPointPower_operator], [col_groupFunctionPointPower_operatoTime], [col_groupFunctionPointPower_copyFrom]) VALUES (1, 101, 15, 1, 0, CAST(0x00009F9800000000 AS DateTime), 0)
INSERT [dbo].[groupFunctionPointPower] ([col_group_id], [col_functinPoint_id], [col_groupFuncitonPointPower], [col_groupFunctionPointPower_recordState], [col_groupFunctionPointPower_operator], [col_groupFunctionPointPower_operatoTime], [col_groupFunctionPointPower_copyFrom]) VALUES (2, 101, 8, 1, 0, CAST(0x00009F9800000000 AS DateTime), 0)
INSERT [dbo].[groupFunctionPointPower] ([col_group_id], [col_functinPoint_id], [col_groupFuncitonPointPower], [col_groupFunctionPointPower_recordState], [col_groupFunctionPointPower_operator], [col_groupFunctionPointPower_operatoTime], [col_groupFunctionPointPower_copyFrom]) VALUES (3, 101, 8, 1, 0, CAST(0x00009F9800000000 AS DateTime), 0)
INSERT [dbo].[groupFunctionPointPower] ([col_group_id], [col_functinPoint_id], [col_groupFuncitonPointPower], [col_groupFunctionPointPower_recordState], [col_groupFunctionPointPower_operator], [col_groupFunctionPointPower_operatoTime], [col_groupFunctionPointPower_copyFrom]) VALUES (4, 101, 0, 1, 0, CAST(0x00009F9800000000 AS DateTime), 0)
INSERT [dbo].[groupFunctionPointPower] ([col_group_id], [col_functinPoint_id], [col_groupFuncitonPointPower], [col_groupFunctionPointPower_recordState], [col_groupFunctionPointPower_operator], [col_groupFunctionPointPower_operatoTime], [col_groupFunctionPointPower_copyFrom]) VALUES (1, 201, 15, 1, 0, CAST(0x00009F9800000000 AS DateTime), 0)
INSERT [dbo].[groupFunctionPointPower] ([col_group_id], [col_functinPoint_id], [col_groupFuncitonPointPower], [col_groupFunctionPointPower_recordState], [col_groupFunctionPointPower_operator], [col_groupFunctionPointPower_operatoTime], [col_groupFunctionPointPower_copyFrom]) VALUES (2, 201, 0, 1, 0, CAST(0x00009F9800000000 AS DateTime), 0)
INSERT [dbo].[groupFunctionPointPower] ([col_group_id], [col_functinPoint_id], [col_groupFuncitonPointPower], [col_groupFunctionPointPower_recordState], [col_groupFunctionPointPower_operator], [col_groupFunctionPointPower_operatoTime], [col_groupFunctionPointPower_copyFrom]) VALUES (3, 201, 0, 1, 0, CAST(0x00009F9800000000 AS DateTime), 0)
INSERT [dbo].[groupFunctionPointPower] ([col_group_id], [col_functinPoint_id], [col_groupFuncitonPointPower], [col_groupFunctionPointPower_recordState], [col_groupFunctionPointPower_operator], [col_groupFunctionPointPower_operatoTime], [col_groupFunctionPointPower_copyFrom]) VALUES (4, 201, 0, 1, 0, CAST(0x00009F9800000000 AS DateTime), 0)
/****** Object:  Table [dbo].[group]    Script Date: 05/13/2011 16:55:09 ******/
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
INSERT [dbo].[group] ([col_group_id], [col_group_name], [col_group_recordState], [col_group_opertor], [col_group_opertoTime], [col_group_copyFromID]) VALUES (1, N'管理组                                                                                                                          ', 1, 0, CAST(0x00009F9800000000 AS DateTime), 0)
INSERT [dbo].[group] ([col_group_id], [col_group_name], [col_group_recordState], [col_group_opertor], [col_group_opertoTime], [col_group_copyFromID]) VALUES (2, N'常规组                                                                                                                          ', 1, 0, CAST(0x00009F9800000000 AS DateTime), 0)
INSERT [dbo].[group] ([col_group_id], [col_group_name], [col_group_recordState], [col_group_opertor], [col_group_opertoTime], [col_group_copyFromID]) VALUES (3, N'受限组                                                                                                                          ', 1, 0, CAST(0x00009F9800000000 AS DateTime), 0)
INSERT [dbo].[group] ([col_group_id], [col_group_name], [col_group_recordState], [col_group_opertor], [col_group_opertoTime], [col_group_copyFromID]) VALUES (4, N'禁用组                                                                                                                          ', 1, 0, CAST(0x00009F9800000000 AS DateTime), 0)
/****** Object:  Table [dbo].[functinPoint]    Script Date: 05/13/2011 16:55:09 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[functinPoint](
	[col_functinPoint_id] [int] NOT NULL,
	[col_functinPoint_name] [text] NOT NULL,
	[col_functinPoint_displayName] [text] NOT NULL,
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
INSERT [dbo].[functinPoint] ([col_functinPoint_id], [col_functinPoint_name], [col_functinPoint_displayName], [col_functinPoint_recordState], [col_functinPoint_operator], [col_functinPoint_opertoTime], [col_functinPoint_copyFromID]) VALUES (101, N'user', N'用户管理', 1, 0, CAST(0x000007D900000000 AS DateTime), 0)
INSERT [dbo].[functinPoint] ([col_functinPoint_id], [col_functinPoint_name], [col_functinPoint_displayName], [col_functinPoint_recordState], [col_functinPoint_operator], [col_functinPoint_opertoTime], [col_functinPoint_copyFromID]) VALUES (201, N'power', N'权限管理', 1, 0, CAST(0x000007D900000000 AS DateTime), 0)
/****** Object:  Table [dbo].[employee ]    Script Date: 05/13/2011 16:55:09 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[employee ](
	[col_employee_id] [int] NOT NULL,
	[col_employee_name] [char](20) NOT NULL,
	[col_companyBase_id] [int] NOT NULL,
	[col_employee_sex] [int] NOT NULL,
	[col_employee_birthday] [datetime] NOT NULL,
	[col_employee_mobile] [char](20) NULL,
	[col_employee_phone] [char](20) NULL,
	[col_employee_position] [int] NOT NULL,
	[col_employee_recordState] [tinyint] NOT NULL,
	[col_employee_operator] [int] NOT NULL,
	[col_employee_operatoTime] [datetime] NOT NULL,
	[col_employee_recordCopyFrom] [int] NOT NULL,
 CONSTRAINT [PK_employee ] PRIMARY KEY CLUSTERED 
(
	[col_employee_id] ASC
)WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
SET ANSI_PADDING OFF
GO
/****** Object:  Table [dbo].[dictionary ]    Script Date: 05/13/2011 16:55:09 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[dictionary ](
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
INSERT [dbo].[dictionary ] ([col_dictionary_id], [col_dictionary_type], [col_dictionary_enum], [col_dictionary_name], [col_dictionary_manual], [col_dictionary_recordState], [col_dictionary_operator], [col_dictionary_operatoTime], [col_dictionary_recordCopyFrom]) VALUES (101, N'recordState', 1, N'新建', NULL, 1, 0, CAST(0x00009F9800000000 AS DateTime), 0)
INSERT [dbo].[dictionary ] ([col_dictionary_id], [col_dictionary_type], [col_dictionary_enum], [col_dictionary_name], [col_dictionary_manual], [col_dictionary_recordState], [col_dictionary_operator], [col_dictionary_operatoTime], [col_dictionary_recordCopyFrom]) VALUES (102, N'recordState', 2, N'删除', NULL, 1, 0, CAST(0x00009F9800000000 AS DateTime), 0)
INSERT [dbo].[dictionary ] ([col_dictionary_id], [col_dictionary_type], [col_dictionary_enum], [col_dictionary_name], [col_dictionary_manual], [col_dictionary_recordState], [col_dictionary_operator], [col_dictionary_operatoTime], [col_dictionary_recordCopyFrom]) VALUES (103, N'recordState', 3, N'修改', NULL, 1, 0, CAST(0x00009F9800000000 AS DateTime), 0)
INSERT [dbo].[dictionary ] ([col_dictionary_id], [col_dictionary_type], [col_dictionary_enum], [col_dictionary_name], [col_dictionary_manual], [col_dictionary_recordState], [col_dictionary_operator], [col_dictionary_operatoTime], [col_dictionary_recordCopyFrom]) VALUES (104, N'recordState', 4, N'痕迹新建', N'不是当前数据', 1, 0, CAST(0x00009F9800000000 AS DateTime), 0)
INSERT [dbo].[dictionary ] ([col_dictionary_id], [col_dictionary_type], [col_dictionary_enum], [col_dictionary_name], [col_dictionary_manual], [col_dictionary_recordState], [col_dictionary_operator], [col_dictionary_operatoTime], [col_dictionary_recordCopyFrom]) VALUES (105, N'recordState', 5, N'痕迹删除', NULL, 1, 0, CAST(0x00009F9800000000 AS DateTime), 0)
INSERT [dbo].[dictionary ] ([col_dictionary_id], [col_dictionary_type], [col_dictionary_enum], [col_dictionary_name], [col_dictionary_manual], [col_dictionary_recordState], [col_dictionary_operator], [col_dictionary_operatoTime], [col_dictionary_recordCopyFrom]) VALUES (106, N'recordState', 6, N'痕迹修改', NULL, 1, 0, CAST(0x00009F9800000000 AS DateTime), 0)
INSERT [dbo].[dictionary ] ([col_dictionary_id], [col_dictionary_type], [col_dictionary_enum], [col_dictionary_name], [col_dictionary_manual], [col_dictionary_recordState], [col_dictionary_operator], [col_dictionary_operatoTime], [col_dictionary_recordCopyFrom]) VALUES (100001, N'login.state', 1, N'登录', NULL, 1, 0, CAST(0x00009F9800000000 AS DateTime), 0)
INSERT [dbo].[dictionary ] ([col_dictionary_id], [col_dictionary_type], [col_dictionary_enum], [col_dictionary_name], [col_dictionary_manual], [col_dictionary_recordState], [col_dictionary_operator], [col_dictionary_operatoTime], [col_dictionary_recordCopyFrom]) VALUES (100002, N'login.state', 2, N'退出', NULL, 1, 0, CAST(0x00009F9800000000 AS DateTime), 0)
INSERT [dbo].[dictionary ] ([col_dictionary_id], [col_dictionary_type], [col_dictionary_enum], [col_dictionary_name], [col_dictionary_manual], [col_dictionary_recordState], [col_dictionary_operator], [col_dictionary_operatoTime], [col_dictionary_recordCopyFrom]) VALUES (100003, N'login.state', 3, N'异常退出', NULL, 1, 0, CAST(0x00009F9800000000 AS DateTime), 0)
INSERT [dbo].[dictionary ] ([col_dictionary_id], [col_dictionary_type], [col_dictionary_enum], [col_dictionary_name], [col_dictionary_manual], [col_dictionary_recordState], [col_dictionary_operator], [col_dictionary_operatoTime], [col_dictionary_recordCopyFrom]) VALUES (100004, N'login.state', 4, N'强制退出', NULL, 1, 0, CAST(0x00009F9800000000 AS DateTime), 0)
INSERT [dbo].[dictionary ] ([col_dictionary_id], [col_dictionary_type], [col_dictionary_enum], [col_dictionary_name], [col_dictionary_manual], [col_dictionary_recordState], [col_dictionary_operator], [col_dictionary_operatoTime], [col_dictionary_recordCopyFrom]) VALUES (200001, N'functionPointPower', 1, N'新建', NULL, 1, 0, CAST(0x00009F9800000000 AS DateTime), 0)
INSERT [dbo].[dictionary ] ([col_dictionary_id], [col_dictionary_type], [col_dictionary_enum], [col_dictionary_name], [col_dictionary_manual], [col_dictionary_recordState], [col_dictionary_operator], [col_dictionary_operatoTime], [col_dictionary_recordCopyFrom]) VALUES (200002, N'functionPointPower', 2, N'删除', NULL, 1, 0, CAST(0x00009F9800000000 AS DateTime), 0)
INSERT [dbo].[dictionary ] ([col_dictionary_id], [col_dictionary_type], [col_dictionary_enum], [col_dictionary_name], [col_dictionary_manual], [col_dictionary_recordState], [col_dictionary_operator], [col_dictionary_operatoTime], [col_dictionary_recordCopyFrom]) VALUES (200003, N'functionPointPower', 4, N'修改', NULL, 1, 0, CAST(0x00009F9800000000 AS DateTime), 0)
INSERT [dbo].[dictionary ] ([col_dictionary_id], [col_dictionary_type], [col_dictionary_enum], [col_dictionary_name], [col_dictionary_manual], [col_dictionary_recordState], [col_dictionary_operator], [col_dictionary_operatoTime], [col_dictionary_recordCopyFrom]) VALUES (200004, N'functionPointPower', 8, N'查看', NULL, 1, 0, CAST(0x00009F9800000000 AS DateTime), 0)
/****** Object:  Table [dbo].[companyBase ]    Script Date: 05/13/2011 16:55:09 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[companyBase ](
	[col_companyBase_id] [int] NOT NULL,
	[col_companyBase_companyName] [char](20) NOT NULL,
	[col_companyBase_higherAuthoritiesID] [int] NOT NULL,
	[col_companyBase_phone] [char](20) NULL,
	[col_companyBase_header] [int] NULL,
	[col_companyBase_cretateTime] [datetime] NOT NULL,
	[col_companyBase_memo] [text] NULL,
	[col_companyBase_recordState] [tinyint] NOT NULL,
	[col_companyBase_operator] [int] NOT NULL,
	[col_companyBase_operatoTime] [datetime] NOT NULL,
	[col_companyBase_recordCopyFrom] [int] NOT NULL,
 CONSTRAINT [PK_companyBase ] PRIMARY KEY CLUSTERED 
(
	[col_companyBase_id] ASC
)WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY]
) ON [PRIMARY] TEXTIMAGE_ON [PRIMARY]
GO
SET ANSI_PADDING OFF
GO
/****** Object:  Table [dbo].[userTBL]    Script Date: 05/13/2011 16:55:09 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[userTBL](
	[col_user_id] [int] NOT NULL,
	[col_user_loginName] [char](20) NOT NULL,
	[col_user_empId] [int] NULL,
	[col_user_passwd] [char](256) NOT NULL,
	[col_user_recordState] [tinyint] NOT NULL,
	[col_user_operator] [int] NOT NULL,
	[col_user_operatoTime] [datetime] NOT NULL,
	[col_user_copyFromID] [int] NOT NULL,
 CONSTRAINT [PK_USER] PRIMARY KEY NONCLUSTERED 
(
	[col_user_id] ASC
)WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
SET ANSI_PADDING OFF
GO
INSERT [dbo].[userTBL] ([col_user_id], [col_user_loginName], [col_user_empId], [col_user_passwd], [col_user_recordState], [col_user_operator], [col_user_operatoTime], [col_user_copyFromID]) VALUES (1, N'1                   ', -1, N'1                                                                                                                                                                                                                                                               ', 3, 0, CAST(0x00009EDB01128150 AS DateTime), 1)
INSERT [dbo].[userTBL] ([col_user_id], [col_user_loginName], [col_user_empId], [col_user_passwd], [col_user_recordState], [col_user_operator], [col_user_operatoTime], [col_user_copyFromID]) VALUES (9, N'qw                  ', -1, N'qw                                                                                                                                                                                                                                                              ', 2, 23, CAST(0x00009EC200BDC4D8 AS DateTime), 0)
INSERT [dbo].[userTBL] ([col_user_id], [col_user_loginName], [col_user_empId], [col_user_passwd], [col_user_recordState], [col_user_operator], [col_user_operatoTime], [col_user_copyFromID]) VALUES (3, N'sss4                ', 5, N'6                                                                                                                                                                                                                                                               ', 2, 0, CAST(0x00009EC400B75510 AS DateTime), 9)
INSERT [dbo].[userTBL] ([col_user_id], [col_user_loginName], [col_user_empId], [col_user_passwd], [col_user_recordState], [col_user_operator], [col_user_operatoTime], [col_user_copyFromID]) VALUES (10, N'qw1                 ', -1, N'qw                                                                                                                                                                                                                                                              ', 2, 0, CAST(0x00009EC400B7581A AS DateTime), 0)
INSERT [dbo].[userTBL] ([col_user_id], [col_user_loginName], [col_user_empId], [col_user_passwd], [col_user_recordState], [col_user_operator], [col_user_operatoTime], [col_user_copyFromID]) VALUES (12, N'qw5                 ', -1, N'qw                                                                                                                                                                                                                                                              ', 2, 0, CAST(0x00009EC40108A90D AS DateTime), 0)
INSERT [dbo].[userTBL] ([col_user_id], [col_user_loginName], [col_user_empId], [col_user_passwd], [col_user_recordState], [col_user_operator], [col_user_operatoTime], [col_user_copyFromID]) VALUES (14, N'qw6                 ', -1, N'qw                                                                                                                                                                                                                                                              ', 2, 0, CAST(0x00009EC40108A676 AS DateTime), 0)
INSERT [dbo].[userTBL] ([col_user_id], [col_user_loginName], [col_user_empId], [col_user_passwd], [col_user_recordState], [col_user_operator], [col_user_operatoTime], [col_user_copyFromID]) VALUES (15, N'qw12                ', -1, N'12                                                                                                                                                                                                                                                              ', 2, 0, CAST(0x00009EC600ED9D0F AS DateTime), 0)
INSERT [dbo].[userTBL] ([col_user_id], [col_user_loginName], [col_user_empId], [col_user_passwd], [col_user_recordState], [col_user_operator], [col_user_operatoTime], [col_user_copyFromID]) VALUES (16, N'qw13                ', -1, N'                                                                                                                                                                                                                                                                ', 2, 0, CAST(0x00009EC900ABAB6D AS DateTime), -1)
INSERT [dbo].[userTBL] ([col_user_id], [col_user_loginName], [col_user_empId], [col_user_passwd], [col_user_recordState], [col_user_operator], [col_user_operatoTime], [col_user_copyFromID]) VALUES (21, N'a1                  ', -1, N'                                                                                                                                                                                                                                                                ', 3, 0, CAST(0x00009EC900ABA44E AS DateTime), -1)
INSERT [dbo].[userTBL] ([col_user_id], [col_user_loginName], [col_user_empId], [col_user_passwd], [col_user_recordState], [col_user_operator], [col_user_operatoTime], [col_user_copyFromID]) VALUES (22, N'23                  ', -1, N'                                                                                                                                                                                                                                                                ', 2, 0, CAST(0x00009EC400F7B363 AS DateTime), -1)
INSERT [dbo].[userTBL] ([col_user_id], [col_user_loginName], [col_user_empId], [col_user_passwd], [col_user_recordState], [col_user_operator], [col_user_operatoTime], [col_user_copyFromID]) VALUES (23, N'zz                  ', -1, N'                                                                                                                                                                                                                                                                ', 2, 0, CAST(0x00009EC40108A429 AS DateTime), -1)
INSERT [dbo].[userTBL] ([col_user_id], [col_user_loginName], [col_user_empId], [col_user_passwd], [col_user_recordState], [col_user_operator], [col_user_operatoTime], [col_user_copyFromID]) VALUES (24, N'wwwwww              ', -1, N'                                                                                                                                                                                                                                                                ', 2, 0, CAST(0x00009EC600ED9F37 AS DateTime), -1)
INSERT [dbo].[userTBL] ([col_user_id], [col_user_loginName], [col_user_empId], [col_user_passwd], [col_user_recordState], [col_user_operator], [col_user_operatoTime], [col_user_copyFromID]) VALUES (25, N'qwerqw              ', -1, N'                                                                                                                                                                                                                                                                ', 2, 0, CAST(0x00009EC600A324BF AS DateTime), -1)
INSERT [dbo].[userTBL] ([col_user_id], [col_user_loginName], [col_user_empId], [col_user_passwd], [col_user_recordState], [col_user_operator], [col_user_operatoTime], [col_user_copyFromID]) VALUES (26, N'qwqwq               ', -1, N'                                                                                                                                                                                                                                                                ', 2, 0, CAST(0x00009EC600ECF316 AS DateTime), -1)
INSERT [dbo].[userTBL] ([col_user_id], [col_user_loginName], [col_user_empId], [col_user_passwd], [col_user_recordState], [col_user_operator], [col_user_operatoTime], [col_user_copyFromID]) VALUES (27, N'Q                   ', -1, N'                                                                                                                                                                                                                                                                ', 3, 0, CAST(0x00009EC900ABA88C AS DateTime), -1)
INSERT [dbo].[userTBL] ([col_user_id], [col_user_loginName], [col_user_empId], [col_user_passwd], [col_user_recordState], [col_user_operator], [col_user_operatoTime], [col_user_copyFromID]) VALUES (11, N'2                   ', -1, N'2                                                                                                                                                                                                                                                               ', 3, 0, CAST(0x00009EDA010644DA AS DateTime), 0)
INSERT [dbo].[userTBL] ([col_user_id], [col_user_loginName], [col_user_empId], [col_user_passwd], [col_user_recordState], [col_user_operator], [col_user_operatoTime], [col_user_copyFromID]) VALUES (17, N'12                  ', -1, N'                                                                                                                                                                                                                                                                ', 3, 0, CAST(0x00009ED300C16124 AS DateTime), -1)
INSERT [dbo].[userTBL] ([col_user_id], [col_user_loginName], [col_user_empId], [col_user_passwd], [col_user_recordState], [col_user_operator], [col_user_operatoTime], [col_user_copyFromID]) VALUES (18, N'123                 ', -1, N'                                                                                                                                                                                                                                                                ', 2, 0, CAST(0x00009ED300C153F5 AS DateTime), -1)
INSERT [dbo].[userTBL] ([col_user_id], [col_user_loginName], [col_user_empId], [col_user_passwd], [col_user_recordState], [col_user_operator], [col_user_operatoTime], [col_user_copyFromID]) VALUES (19, N'1234                ', -1, N'                                                                                                                                                                                                                                                                ', 3, 0, CAST(0x00009EDB010F730C AS DateTime), -1)
INSERT [dbo].[userTBL] ([col_user_id], [col_user_loginName], [col_user_empId], [col_user_passwd], [col_user_recordState], [col_user_operator], [col_user_operatoTime], [col_user_copyFromID]) VALUES (20, N'12345               ', -1, N'                                                                                                                                                                                                                                                                ', 2, 0, CAST(0x00009EC600ED9A0D AS DateTime), -1)
INSERT [dbo].[userTBL] ([col_user_id], [col_user_loginName], [col_user_empId], [col_user_passwd], [col_user_recordState], [col_user_operator], [col_user_operatoTime], [col_user_copyFromID]) VALUES (28, N'3                   ', -1, N'3                                                                                                                                                                                                                                                               ', 3, 0, CAST(0x00009EDA01064DEB AS DateTime), -1)
INSERT [dbo].[userTBL] ([col_user_id], [col_user_loginName], [col_user_empId], [col_user_passwd], [col_user_recordState], [col_user_operator], [col_user_operatoTime], [col_user_copyFromID]) VALUES (29, N'4                   ', -1, N'4                                                                                                                                                                                                                                                               ', 3, 0, CAST(0x00009EDA010654B1 AS DateTime), -1)
INSERT [dbo].[userTBL] ([col_user_id], [col_user_loginName], [col_user_empId], [col_user_passwd], [col_user_recordState], [col_user_operator], [col_user_operatoTime], [col_user_copyFromID]) VALUES (31, N'www                 ', -1, N'w                                                                                                                                                                                                                                                               ', 1, 0, CAST(0x00009EDB0111B36D AS DateTime), -1)
INSERT [dbo].[userTBL] ([col_user_id], [col_user_loginName], [col_user_empId], [col_user_passwd], [col_user_recordState], [col_user_operator], [col_user_operatoTime], [col_user_copyFromID]) VALUES (30, N'5                   ', -1, N'5                                                                                                                                                                                                                                                               ', 3, 0, CAST(0x00009EDB00FAB0A8 AS DateTime), -1)
/****** Object:  View [dbo].[View_UserGroup]    Script Date: 05/13/2011 16:55:10 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE VIEW [dbo].[View_UserGroup]
AS
SELECT     dbo.userGroup.col_userGroup_id, dbo.userTBL.col_user_id, dbo.[group].col_group_id, dbo.userTBL.col_user_loginName, dbo.[group].col_group_name
FROM         dbo.userTBL LEFT OUTER JOIN
                      dbo.userGroup ON dbo.userTBL.col_user_id = dbo.userGroup.col_user_id LEFT OUTER JOIN
                      dbo.[group] ON dbo.userGroup.col_group_id = dbo.[group].col_group_id
WHERE     (dbo.userTBL.col_user_recordState = 1) OR
                      (dbo.userTBL.col_user_recordState = 3)
GO
EXEC sys.sp_addextendedproperty @name=N'MS_DiagramPane1', @value=N'[0E232FF0-B466-11cf-A24F-00AA00A3EFFF, 1.00]
Begin DesignProperties = 
   Begin PaneConfigurations = 
      Begin PaneConfiguration = 0
         NumPanes = 4
         Configuration = "(H (1[41] 4[25] 2[12] 3) )"
      End
      Begin PaneConfiguration = 1
         NumPanes = 3
         Configuration = "(H (1 [50] 4 [25] 3))"
      End
      Begin PaneConfiguration = 2
         NumPanes = 3
         Configuration = "(H (1 [50] 2 [25] 3))"
      End
      Begin PaneConfiguration = 3
         NumPanes = 3
         Configuration = "(H (4 [30] 2 [40] 3))"
      End
      Begin PaneConfiguration = 4
         NumPanes = 2
         Configuration = "(H (1 [56] 3))"
      End
      Begin PaneConfiguration = 5
         NumPanes = 2
         Configuration = "(H (2 [66] 3))"
      End
      Begin PaneConfiguration = 6
         NumPanes = 2
         Configuration = "(H (4 [50] 3))"
      End
      Begin PaneConfiguration = 7
         NumPanes = 1
         Configuration = "(V (3))"
      End
      Begin PaneConfiguration = 8
         NumPanes = 3
         Configuration = "(H (1[56] 4[18] 2) )"
      End
      Begin PaneConfiguration = 9
         NumPanes = 2
         Configuration = "(H (1 [75] 4))"
      End
      Begin PaneConfiguration = 10
         NumPanes = 2
         Configuration = "(H (1[66] 2) )"
      End
      Begin PaneConfiguration = 11
         NumPanes = 2
         Configuration = "(H (4 [60] 2))"
      End
      Begin PaneConfiguration = 12
         NumPanes = 1
         Configuration = "(H (1) )"
      End
      Begin PaneConfiguration = 13
         NumPanes = 1
         Configuration = "(V (4))"
      End
      Begin PaneConfiguration = 14
         NumPanes = 1
         Configuration = "(V (2))"
      End
      ActivePaneConfig = 0
   End
   Begin DiagramPane = 
      Begin Origin = 
         Top = 0
         Left = 0
      End
      Begin Tables = 
         Begin Table = "userTBL"
            Begin Extent = 
               Top = 6
               Left = 38
               Bottom = 125
               Right = 237
            End
            DisplayFlags = 280
            TopColumn = 0
         End
         Begin Table = "userGroup"
            Begin Extent = 
               Top = 6
               Left = 275
               Bottom = 125
               Right = 497
            End
            DisplayFlags = 280
            TopColumn = 0
         End
         Begin Table = "group"
            Begin Extent = 
               Top = 126
               Left = 38
               Bottom = 245
               Right = 238
            End
            DisplayFlags = 280
            TopColumn = 0
         End
      End
   End
   Begin SQLPane = 
   End
   Begin DataPane = 
      Begin ParameterDefaults = ""
      End
      Begin ColumnWidths = 9
         Width = 284
         Width = 1500
         Width = 1500
         Width = 1980
         Width = 1500
         Width = 1875
         Width = 1500
         Width = 1500
         Width = 1500
      End
   End
   Begin CriteriaPane = 
      Begin ColumnWidths = 11
         Column = 2100
         Alias = 900
         Table = 1170
         Output = 720
         Append = 1400
         NewValue = 1170
         SortType = 1350
         SortOrder = 1410
         GroupBy = 1350
         Filter = 1350
         Or = 1350
         Or = 1350
         Or = 1350
      End
   End
End
' , @level0type=N'SCHEMA',@level0name=N'dbo', @level1type=N'VIEW',@level1name=N'View_UserGroup'
GO
EXEC sys.sp_addextendedproperty @name=N'MS_DiagramPaneCount', @value=1 , @level0type=N'SCHEMA',@level0name=N'dbo', @level1type=N'VIEW',@level1name=N'View_UserGroup'
GO
/****** Object:  View [dbo].[View_GroupFunPointPower]    Script Date: 05/13/2011 16:55:10 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE VIEW [dbo].[View_GroupFunPointPower]
AS
SELECT     dbo.[group].col_group_id, dbo.functinPoint.col_functinPoint_name, dbo.functinPoint.col_functinPoint_displayName, 
                      dbo.groupFunctionPointPower.col_groupFuncitonPointPower
FROM         dbo.[group] INNER JOIN
                      dbo.groupFunctionPointPower ON dbo.[group].col_group_id = dbo.groupFunctionPointPower.col_group_id INNER JOIN
                      dbo.functinPoint ON dbo.groupFunctionPointPower.col_functinPoint_id = dbo.functinPoint.col_functinPoint_id
GO
EXEC sys.sp_addextendedproperty @name=N'MS_DiagramPane1', @value=N'[0E232FF0-B466-11cf-A24F-00AA00A3EFFF, 1.00]
Begin DesignProperties = 
   Begin PaneConfigurations = 
      Begin PaneConfiguration = 0
         NumPanes = 4
         Configuration = "(H (1[41] 4[20] 2[15] 3) )"
      End
      Begin PaneConfiguration = 1
         NumPanes = 3
         Configuration = "(H (1 [50] 4 [25] 3))"
      End
      Begin PaneConfiguration = 2
         NumPanes = 3
         Configuration = "(H (1 [50] 2 [25] 3))"
      End
      Begin PaneConfiguration = 3
         NumPanes = 3
         Configuration = "(H (4 [30] 2 [40] 3))"
      End
      Begin PaneConfiguration = 4
         NumPanes = 2
         Configuration = "(H (1 [56] 3))"
      End
      Begin PaneConfiguration = 5
         NumPanes = 2
         Configuration = "(H (2 [66] 3))"
      End
      Begin PaneConfiguration = 6
         NumPanes = 2
         Configuration = "(H (4 [50] 3))"
      End
      Begin PaneConfiguration = 7
         NumPanes = 1
         Configuration = "(V (3))"
      End
      Begin PaneConfiguration = 8
         NumPanes = 3
         Configuration = "(H (1[56] 4[18] 2) )"
      End
      Begin PaneConfiguration = 9
         NumPanes = 2
         Configuration = "(H (1 [75] 4))"
      End
      Begin PaneConfiguration = 10
         NumPanes = 2
         Configuration = "(H (1[66] 2) )"
      End
      Begin PaneConfiguration = 11
         NumPanes = 2
         Configuration = "(H (4 [60] 2))"
      End
      Begin PaneConfiguration = 12
         NumPanes = 1
         Configuration = "(H (1) )"
      End
      Begin PaneConfiguration = 13
         NumPanes = 1
         Configuration = "(V (4))"
      End
      Begin PaneConfiguration = 14
         NumPanes = 1
         Configuration = "(V (2))"
      End
      ActivePaneConfig = 0
   End
   Begin DiagramPane = 
      Begin Origin = 
         Top = 0
         Left = 0
      End
      Begin Tables = 
         Begin Table = "group"
            Begin Extent = 
               Top = 6
               Left = 38
               Bottom = 125
               Right = 238
            End
            DisplayFlags = 280
            TopColumn = 0
         End
         Begin Table = "groupFunctionPointPower"
            Begin Extent = 
               Top = 6
               Left = 276
               Bottom = 125
               Right = 573
            End
            DisplayFlags = 280
            TopColumn = 1
         End
         Begin Table = "functinPoint"
            Begin Extent = 
               Top = 6
               Left = 611
               Bottom = 125
               Right = 842
            End
            DisplayFlags = 280
            TopColumn = 0
         End
      End
   End
   Begin SQLPane = 
   End
   Begin DataPane = 
      Begin ParameterDefaults = ""
      End
      Begin ColumnWidths = 9
         Width = 284
         Width = 1500
         Width = 2160
         Width = 2325
         Width = 1500
         Width = 1500
         Width = 1500
         Width = 1500
         Width = 1500
      End
   End
   Begin CriteriaPane = 
      Begin ColumnWidths = 11
         Column = 1440
         Alias = 900
         Table = 1170
         Output = 720
         Append = 1400
         NewValue = 1170
         SortType = 1350
         SortOrder = 1410
         GroupBy = 1350
         Filter = 1350
         Or = 1350
         Or = 1350
         Or = 1350
      End
   End
End
' , @level0type=N'SCHEMA',@level0name=N'dbo', @level1type=N'VIEW',@level1name=N'View_GroupFunPointPower'
GO
EXEC sys.sp_addextendedproperty @name=N'MS_DiagramPaneCount', @value=1 , @level0type=N'SCHEMA',@level0name=N'dbo', @level1type=N'VIEW',@level1name=N'View_GroupFunPointPower'
GO
/****** Object:  StoredProcedure [dbo].[userGroup_add]    Script Date: 05/13/2011 16:55:07 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
create PROCEDURE [dbo].[userGroup_add]
           (@col_userGroup_id int
           ,@col_group_id int
           ,@col_user_id int
           ,@col_userGroup_recordState tinyint
           ,@col_userGroup_operator int
           ,@col_userGroup_operatoTime datetime
           ,@col_userGroup_copyFromID int)

AS
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
/****** Object:  StoredProcedure [dbo].[user_add]    Script Date: 05/13/2011 16:55:07 ******/
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
           @col_user_operatoTime datetime,
           @col_user_copyFromID int)
AS
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
/****** Object:  StoredProcedure [dbo].[userGroup_edit]    Script Date: 05/13/2011 16:55:07 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE PROCEDURE [dbo].[userGroup_edit]
           (@col_userGroup_id int
           ,@col_group_id int
           ,@col_userGroup_operator int)

AS
BEGIN

UPDATE [wx].[dbo].[userGroup]
   SET [col_group_id] = @col_group_id
      ,[col_userGroup_recordState] = 3
      ,[col_userGroup_operator] = @col_userGroup_operator
      ,[col_userGroup_operatoTime] = getdate()
 WHERE [col_userGroup_id] = @col_userGroup_id
 
END
GO
/****** Object:  StoredProcedure [dbo].[userGroup_delete]    Script Date: 05/13/2011 16:55:07 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
create PROCEDURE [dbo].[userGroup_delete]
           (@col_userGroup_id int
           ,@col_userGroup_operator int)

AS
BEGIN

delete [wx].[dbo].[userGroup]
 WHERE [col_userGroup_id] = @col_userGroup_id
 
END
GO
/****** Object:  StoredProcedure [dbo].[comm_CreateNewID]    Script Date: 05/13/2011 16:55:07 ******/
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
/****** Object:  StoredProcedure [dbo].[login_logoutExceptionAll]    Script Date: 05/13/2011 16:55:07 ******/
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
/****** Object:  StoredProcedure [dbo].[login_logoutException]    Script Date: 05/13/2011 16:55:07 ******/
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
/****** Object:  StoredProcedure [dbo].[login_logout]    Script Date: 05/13/2011 16:55:07 ******/
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
/****** Object:  StoredProcedure [dbo].[login_login]    Script Date: 05/13/2011 16:55:07 ******/
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
           ,@col_login_ip text 
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
/****** Object:  StoredProcedure [dbo].[login_IsLogining]    Script Date: 05/13/2011 16:55:07 ******/
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
/****** Object:  StoredProcedure [dbo].[user_IsBeing]    Script Date: 05/13/2011 16:55:07 ******/
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
	
	select @count =COUNT(*) from dbo.userTBL where col_user_loginName=@col_user_loginName

	return @count
END
GO
/****** Object:  StoredProcedure [dbo].[user_edit]    Script Date: 05/13/2011 16:55:07 ******/
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
           @col_user_operatoTime datetime,
           @col_user_copyFromID int)
AS
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
/****** Object:  StoredProcedure [dbo].[user_delete]    Script Date: 05/13/2011 16:55:07 ******/
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
	
UPDATE [wx].[dbo].[userTBL]
   SET [col_user_recordState] = 2
      ,[col_user_operator] = @col_user_operator
      ,[col_user_operatoTime] = GETDATE()
 WHERE col_user_id = @col_user_id
END
GO
/****** Object:  StoredProcedure [dbo].[user_CreateNewID]    Script Date: 05/13/2011 16:55:07 ******/
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
			@tableName = N'userTBL'
		
	return @return_value

END
GO
/****** Object:  StoredProcedure [dbo].[login_CreateNewID]    Script Date: 05/13/2011 16:55:07 ******/
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
/****** Object:  StoredProcedure [dbo].[userGroup_CreateNewID]    Script Date: 05/13/2011 16:55:07 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
create PROCEDURE [dbo].[userGroup_CreateNewID]

AS
BEGIN

	SET NOCOUNT ON;
	
	DECLARE	@return_value int

	EXEC	@return_value = [dbo].[comm_CreateNewID]
			@tableName = N'userGroup'
		
	return @return_value

END
GO
/****** Object:  StoredProcedure [dbo].[userGroup_setByUserID]    Script Date: 05/13/2011 16:55:07 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE PROCEDURE [dbo].[userGroup_setByUserID](
            @col_user_id int
		   ,@col_group_id int
           ,@col_userGroup_operator int)
AS
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
