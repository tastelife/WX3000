USE [wx]
GO
/****** Object:  Table [dbo].[userGroup]    Script Date: 04/19/2011 17:25:05 ******/
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
INSERT [dbo].[userGroup] ([col_userGroup_id], [col_group_id], [col_user_id], [col_userGroup_recordState], [col_userGroup_operator], [col_userGroup_opertor], [col_userGroup_copyFromID]) VALUES (1, 1, 1, 1, 0, CAST(0x00009ECA011EC257 AS DateTime), 0)
INSERT [dbo].[userGroup] ([col_userGroup_id], [col_group_id], [col_user_id], [col_userGroup_recordState], [col_userGroup_operator], [col_userGroup_opertor], [col_userGroup_copyFromID]) VALUES (2, 1, 20, 1, 0, CAST(0x00009ECA010B6865 AS DateTime), 0)
INSERT [dbo].[userGroup] ([col_userGroup_id], [col_group_id], [col_user_id], [col_userGroup_recordState], [col_userGroup_operator], [col_userGroup_opertor], [col_userGroup_copyFromID]) VALUES (3, 31, 32, 1, 34, CAST(0x00009ECA010C1C32 AS DateTime), -1)
INSERT [dbo].[userGroup] ([col_userGroup_id], [col_group_id], [col_user_id], [col_userGroup_recordState], [col_userGroup_operator], [col_userGroup_opertor], [col_userGroup_copyFromID]) VALUES (11, 41, 11, 11, 44, CAST(0x00009ECA01110520 AS DateTime), 11)
INSERT [dbo].[userGroup] ([col_userGroup_id], [col_group_id], [col_user_id], [col_userGroup_recordState], [col_userGroup_operator], [col_userGroup_opertor], [col_userGroup_copyFromID]) VALUES (18, 41, 42, 1, 44, CAST(0x00009ECA011115C7 AS DateTime), -1)
INSERT [dbo].[userGroup] ([col_userGroup_id], [col_group_id], [col_user_id], [col_userGroup_recordState], [col_userGroup_operator], [col_userGroup_opertor], [col_userGroup_copyFromID]) VALUES (17, 21, 522, 0, 53, CAST(0x00009ECA0112887E AS DateTime), 0)
INSERT [dbo].[userGroup] ([col_userGroup_id], [col_group_id], [col_user_id], [col_userGroup_recordState], [col_userGroup_operator], [col_userGroup_opertor], [col_userGroup_copyFromID]) VALUES (21, 21, 5, 1, 53, CAST(0x00009ECA0112BBDE AS DateTime), -1)
INSERT [dbo].[userGroup] ([col_userGroup_id], [col_group_id], [col_user_id], [col_userGroup_recordState], [col_userGroup_operator], [col_userGroup_opertor], [col_userGroup_copyFromID]) VALUES (22, 21, 2, 1, 0, CAST(0x00009ECA011DD0CA AS DateTime), -1)
INSERT [dbo].[userGroup] ([col_userGroup_id], [col_group_id], [col_user_id], [col_userGroup_recordState], [col_userGroup_operator], [col_userGroup_opertor], [col_userGroup_copyFromID]) VALUES (23, 1, 3, 1, 0, CAST(0x00009ECA011DF2C1 AS DateTime), -1)
INSERT [dbo].[userGroup] ([col_userGroup_id], [col_group_id], [col_user_id], [col_userGroup_recordState], [col_userGroup_operator], [col_userGroup_opertor], [col_userGroup_copyFromID]) VALUES (24, 2, 21, 1, 0, CAST(0x00009ECA011EB367 AS DateTime), -1)
INSERT [dbo].[userGroup] ([col_userGroup_id], [col_group_id], [col_user_id], [col_userGroup_recordState], [col_userGroup_operator], [col_userGroup_opertor], [col_userGroup_copyFromID]) VALUES (25, 1, 27, 1, 0, CAST(0x00009ECA011EBCC1 AS DateTime), -1)
/****** Object:  Table [dbo].[user1]    Script Date: 04/19/2011 17:25:05 ******/
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
INSERT [dbo].[user1] ([col_user_id], [col_user_loginName], [col_user_empId], [col_user_passwd], [col_user_recordState], [col_user_operator], [col_user_operatorTime], [col_user_copyFromID]) VALUES (1, N'1                   ', 11, N'1                                                                                                                                                                                                                                                               ', 1, 23, CAST(0x00009EC200BDB205 AS DateTime), 1)
INSERT [dbo].[user1] ([col_user_id], [col_user_loginName], [col_user_empId], [col_user_passwd], [col_user_recordState], [col_user_operator], [col_user_operatorTime], [col_user_copyFromID]) VALUES (9, N'qw                  ', -1, N'qw                                                                                                                                                                                                                                                              ', 2, 23, CAST(0x00009EC200BDC4D8 AS DateTime), 0)
INSERT [dbo].[user1] ([col_user_id], [col_user_loginName], [col_user_empId], [col_user_passwd], [col_user_recordState], [col_user_operator], [col_user_operatorTime], [col_user_copyFromID]) VALUES (3, N'sss4                ', 5, N'6                                                                                                                                                                                                                                                               ', 2, 0, CAST(0x00009EC400B75510 AS DateTime), 9)
INSERT [dbo].[user1] ([col_user_id], [col_user_loginName], [col_user_empId], [col_user_passwd], [col_user_recordState], [col_user_operator], [col_user_operatorTime], [col_user_copyFromID]) VALUES (10, N'qw1                 ', -1, N'qw                                                                                                                                                                                                                                                              ', 2, 0, CAST(0x00009EC400B7581A AS DateTime), 0)
INSERT [dbo].[user1] ([col_user_id], [col_user_loginName], [col_user_empId], [col_user_passwd], [col_user_recordState], [col_user_operator], [col_user_operatorTime], [col_user_copyFromID]) VALUES (12, N'qw5                 ', -1, N'qw                                                                                                                                                                                                                                                              ', 2, 0, CAST(0x00009EC40108A90D AS DateTime), 0)
INSERT [dbo].[user1] ([col_user_id], [col_user_loginName], [col_user_empId], [col_user_passwd], [col_user_recordState], [col_user_operator], [col_user_operatorTime], [col_user_copyFromID]) VALUES (14, N'qw6                 ', -1, N'qw                                                                                                                                                                                                                                                              ', 2, 0, CAST(0x00009EC40108A676 AS DateTime), 0)
INSERT [dbo].[user1] ([col_user_id], [col_user_loginName], [col_user_empId], [col_user_passwd], [col_user_recordState], [col_user_operator], [col_user_operatorTime], [col_user_copyFromID]) VALUES (15, N'qw12                ', -1, N'12                                                                                                                                                                                                                                                              ', 2, 0, CAST(0x00009EC600ED9D0F AS DateTime), 0)
INSERT [dbo].[user1] ([col_user_id], [col_user_loginName], [col_user_empId], [col_user_passwd], [col_user_recordState], [col_user_operator], [col_user_operatorTime], [col_user_copyFromID]) VALUES (16, N'qw13                ', -1, N'                                                                                                                                                                                                                                                                ', 2, 0, CAST(0x00009EC900ABAB6D AS DateTime), -1)
INSERT [dbo].[user1] ([col_user_id], [col_user_loginName], [col_user_empId], [col_user_passwd], [col_user_recordState], [col_user_operator], [col_user_operatorTime], [col_user_copyFromID]) VALUES (21, N'a1                  ', -1, N'                                                                                                                                                                                                                                                                ', 3, 0, CAST(0x00009EC900ABA44E AS DateTime), -1)
INSERT [dbo].[user1] ([col_user_id], [col_user_loginName], [col_user_empId], [col_user_passwd], [col_user_recordState], [col_user_operator], [col_user_operatorTime], [col_user_copyFromID]) VALUES (22, N'23                  ', -1, N'                                                                                                                                                                                                                                                                ', 2, 0, CAST(0x00009EC400F7B363 AS DateTime), -1)
INSERT [dbo].[user1] ([col_user_id], [col_user_loginName], [col_user_empId], [col_user_passwd], [col_user_recordState], [col_user_operator], [col_user_operatorTime], [col_user_copyFromID]) VALUES (23, N'zz                  ', -1, N'                                                                                                                                                                                                                                                                ', 2, 0, CAST(0x00009EC40108A429 AS DateTime), -1)
INSERT [dbo].[user1] ([col_user_id], [col_user_loginName], [col_user_empId], [col_user_passwd], [col_user_recordState], [col_user_operator], [col_user_operatorTime], [col_user_copyFromID]) VALUES (24, N'wwwwww              ', -1, N'                                                                                                                                                                                                                                                                ', 2, 0, CAST(0x00009EC600ED9F37 AS DateTime), -1)
INSERT [dbo].[user1] ([col_user_id], [col_user_loginName], [col_user_empId], [col_user_passwd], [col_user_recordState], [col_user_operator], [col_user_operatorTime], [col_user_copyFromID]) VALUES (25, N'qwerqw              ', -1, N'                                                                                                                                                                                                                                                                ', 2, 0, CAST(0x00009EC600A324BF AS DateTime), -1)
INSERT [dbo].[user1] ([col_user_id], [col_user_loginName], [col_user_empId], [col_user_passwd], [col_user_recordState], [col_user_operator], [col_user_operatorTime], [col_user_copyFromID]) VALUES (26, N'qwqwq               ', -1, N'                                                                                                                                                                                                                                                                ', 2, 0, CAST(0x00009EC600ECF316 AS DateTime), -1)
INSERT [dbo].[user1] ([col_user_id], [col_user_loginName], [col_user_empId], [col_user_passwd], [col_user_recordState], [col_user_operator], [col_user_operatorTime], [col_user_copyFromID]) VALUES (27, N'Q                   ', -1, N'                                                                                                                                                                                                                                                                ', 3, 0, CAST(0x00009EC900ABA88C AS DateTime), -1)
INSERT [dbo].[user1] ([col_user_id], [col_user_loginName], [col_user_empId], [col_user_passwd], [col_user_recordState], [col_user_operator], [col_user_operatorTime], [col_user_copyFromID]) VALUES (11, N'2                   ', -1, N'                                                                                                                                                                                                                                                                ', 2, 0, CAST(0x00009EC600EDA174 AS DateTime), 0)
INSERT [dbo].[user1] ([col_user_id], [col_user_loginName], [col_user_empId], [col_user_passwd], [col_user_recordState], [col_user_operator], [col_user_operatorTime], [col_user_copyFromID]) VALUES (17, N'12                  ', -1, N'                                                                                                                                                                                                                                                                ', 2, 0, CAST(0x00009EC500B42B4A AS DateTime), -1)
INSERT [dbo].[user1] ([col_user_id], [col_user_loginName], [col_user_empId], [col_user_passwd], [col_user_recordState], [col_user_operator], [col_user_operatorTime], [col_user_copyFromID]) VALUES (18, N'123                 ', -1, N'                                                                                                                                                                                                                                                                ', 2, 0, CAST(0x00009EC401165B97 AS DateTime), -1)
INSERT [dbo].[user1] ([col_user_id], [col_user_loginName], [col_user_empId], [col_user_passwd], [col_user_recordState], [col_user_operator], [col_user_operatorTime], [col_user_copyFromID]) VALUES (19, N'1234                ', -1, N'                                                                                                                                                                                                                                                                ', 2, 0, CAST(0x00009EC500B4F1F5 AS DateTime), -1)
INSERT [dbo].[user1] ([col_user_id], [col_user_loginName], [col_user_empId], [col_user_passwd], [col_user_recordState], [col_user_operator], [col_user_operatorTime], [col_user_copyFromID]) VALUES (20, N'12345               ', -1, N'                                                                                                                                                                                                                                                                ', 2, 0, CAST(0x00009EC600ED9A0D AS DateTime), -1)
/****** Object:  Table [dbo].[login]    Script Date: 04/19/2011 17:25:05 ******/
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
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (70, 1, CAST(0x00009EC600AA460F AS DateTime), 3, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78  192.168.56.1    ', 2, 0, CAST(0x00009EC600ECDAC7 AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (71, 1, CAST(0x00009EC600ECDAC9 AS DateTime), 3, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78  192.168.56.1    ', 2, 0, CAST(0x00009EC600ED94A7 AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (72, 1, CAST(0x00009EC600ED94A9 AS DateTime), 3, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78  192.168.56.1    ', 2, 0, CAST(0x00009EC600F24649 AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (73, 1, CAST(0x00009EC600F2464B AS DateTime), 3, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78  192.168.56.1    ', 2, 0, CAST(0x00009EC600FD5DCC AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (61, 1, CAST(0x00009EC500F540E8 AS DateTime), 3, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78  192.168.56.1    ', 2, 0, CAST(0x00009EC5010EEB30 AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (62, 1, CAST(0x00009EC5010E3044 AS DateTime), 3, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78  192.168.56.1    ', 2, 0, CAST(0x00009EC5010EEB30 AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (66, 1, CAST(0x00009EC501132897 AS DateTime), 3, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78  192.168.56.1    ', 2, 0, CAST(0x00009EC600A20C9C AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (68, 1, CAST(0x00009EC600A20CA5 AS DateTime), 2, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78  192.168.56.1    ', 1, 0, CAST(0x00009EC600A20CA5 AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (69, 1, CAST(0x00009EC600A31A5A AS DateTime), 3, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78  192.168.56.1    ', 2, 0, CAST(0x00009EC600AA460C AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (74, 1, CAST(0x00009EC600FD5DD0 AS DateTime), 3, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78  192.168.56.1    ', 2, 0, CAST(0x00009EC600FD93B1 AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (75, 1, CAST(0x00009EC600FD93B3 AS DateTime), 3, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78  192.168.56.1    ', 2, 0, CAST(0x00009EC600FE44FB AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (76, 1, CAST(0x00009EC600FE44FD AS DateTime), 3, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78  192.168.56.1    ', 2, 0, CAST(0x00009EC600FF0C24 AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (77, 1, CAST(0x00009EC600FF0C27 AS DateTime), 3, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78  192.168.56.1    ', 2, 0, CAST(0x00009EC600FFE8CB AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (78, 1, CAST(0x00009EC600FFE8CD AS DateTime), 3, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78  192.168.56.1    ', 2, 0, CAST(0x00009EC601015D2F AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (79, 1, CAST(0x00009EC601015D32 AS DateTime), 3, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78  192.168.56.1    ', 2, 0, CAST(0x00009EC60102CD06 AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (80, 1, CAST(0x00009EC60102CD08 AS DateTime), 3, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78  192.168.56.1    ', 2, 0, CAST(0x00009EC900AB9B8B AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (81, 1, CAST(0x00009EC900AB9B8E AS DateTime), 3, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78  192.168.56.1    ', 2, 0, CAST(0x00009EC900EE3969 AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (82, 1, CAST(0x00009EC900EE396C AS DateTime), 3, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78  192.168.56.1    ', 2, 0, CAST(0x00009EC900EE843E AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (83, 1, CAST(0x00009EC900EE8440 AS DateTime), 3, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78  192.168.56.1    ', 2, 0, CAST(0x00009EC900EEEEA7 AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (84, 1, CAST(0x00009EC900EEEEA9 AS DateTime), 0, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78  192.168.56.1    ', 2, 0, CAST(0x00009EC900EF33CD AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (85, 1, CAST(0x00009EC900EF53F1 AS DateTime), 0, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78  192.168.56.1    ', 2, 0, CAST(0x00009EC900EF5E7A AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (86, 1, CAST(0x00009EC900F41447 AS DateTime), 0, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78  192.168.56.1    ', 2, 0, CAST(0x00009EC900F42008 AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (87, 1, CAST(0x00009EC900F653CB AS DateTime), 0, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78  192.168.56.1    ', 2, 0, CAST(0x00009EC900F66670 AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (63, 1, CAST(0x00009EC5010EA434 AS DateTime), 3, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78  192.168.56.1    ', 2, 0, CAST(0x00009EC5010EEB30 AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (64, 1, CAST(0x00009EC5010EEB32 AS DateTime), 3, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78  192.168.56.1    ', 2, 0, CAST(0x00009EC501132895 AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (88, 1, CAST(0x00009EC900F69CE7 AS DateTime), 0, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78  192.168.56.1    ', 2, 0, CAST(0x00009EC900F6D563 AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (89, 1, CAST(0x00009EC900FFC79B AS DateTime), 0, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78  192.168.56.1    ', 2, 0, CAST(0x00009EC900FFE63D AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (90, 1, CAST(0x00009EC9010059D7 AS DateTime), 0, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78  192.168.56.1    ', 2, 0, CAST(0x00009EC901006C88 AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (93, 1, CAST(0x00009EC9011945A2 AS DateTime), 0, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78  192.168.56.1    ', 2, 0, CAST(0x00009EC901195404 AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (94, 1, CAST(0x00009EC901198F0E AS DateTime), 0, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78  192.168.56.1    ', 2, 0, CAST(0x00009EC90119A458 AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (95, 1, CAST(0x00009EC90119D817 AS DateTime), 0, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78  192.168.56.1    ', 2, 0, CAST(0x00009EC90119EEAC AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (96, 1, CAST(0x00009EC9011B6909 AS DateTime), 0, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78  192.168.56.1    ', 2, 0, CAST(0x00009EC9011B79A3 AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (97, 1, CAST(0x00009EC9011D8073 AS DateTime), 0, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78  192.168.56.1    ', 2, 0, CAST(0x00009EC9011D8894 AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (98, 1, CAST(0x00009EC9011DA49F AS DateTime), 0, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78  192.168.56.1    ', 2, 0, CAST(0x00009EC9011E00F4 AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (99, 1, CAST(0x00009EC9011E329B AS DateTime), 0, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78  192.168.56.1    ', 2, 0, CAST(0x00009EC9011EAE2B AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (101, 1, CAST(0x00009ECA011C359D AS DateTime), 0, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78  192.168.56.1    ', 2, 0, CAST(0x00009ECA011C4C75 AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (102, 1, CAST(0x00009ECA011D14C1 AS DateTime), 3, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78  192.168.56.1    ', 2, 0, CAST(0x00009ECA011DB806 AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (91, 1, CAST(0x00009EC901106C7F AS DateTime), 0, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78  192.168.56.1    ', 2, 0, CAST(0x00009EC90110787E AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (92, 1, CAST(0x00009EC90110C661 AS DateTime), 0, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78  192.168.56.1    ', 2, 0, CAST(0x00009EC90110D3C4 AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (100, 1, CAST(0x00009EC9011ED1CF AS DateTime), 0, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78  192.168.56.1    ', 2, 0, CAST(0x00009EC9011EE47B AS DateTime), -1)
INSERT [dbo].[login] ([col_login_id], [col_user_id], [col_login_loginTime], [col_login_state], [col_login_computerName], [col_login_mac], [col_login_ip], [col_login_recordState], [col_login_operatorUserID], [col_login_operatoTime], [col_login_copyFromID]) VALUES (103, 1, CAST(0x00009ECA011DB808 AS DateTime), 1, N'7bwz82x_win7pro                                                                                                                 ', N'                                                                                                                                ', N'192.168.120.78  192.168.56.1    ', 1, 0, CAST(0x00009ECA011DB808 AS DateTime), -1)
/****** Object:  Table [dbo].[hintuser]    Script Date: 04/19/2011 17:25:05 ******/
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
/****** Object:  Table [dbo].[hint]    Script Date: 04/19/2011 17:25:05 ******/
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
/****** Object:  Table [dbo].[groupFunctionPointPower]    Script Date: 04/19/2011 17:25:05 ******/
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
/****** Object:  Table [dbo].[group]    Script Date: 04/19/2011 17:25:05 ******/
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
INSERT [dbo].[group] ([col_group_id], [col_group_name], [col_group_recordState], [col_group_opertor], [col_group_opertoTime], [col_group_copyFromID]) VALUES (3, N'试用组                                                                                                                          ', 1, 0, CAST(0x00009F9800000000 AS DateTime), 0)
INSERT [dbo].[group] ([col_group_id], [col_group_name], [col_group_recordState], [col_group_opertor], [col_group_opertoTime], [col_group_copyFromID]) VALUES (4, N'禁用组                                                                                                                          ', 1, 0, CAST(0x00009F9800000000 AS DateTime), 0)
/****** Object:  Table [dbo].[functinPoint]    Script Date: 04/19/2011 17:25:05 ******/
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
/****** Object:  Table [dbo].[publicinFormation]    Script Date: 04/19/2011 17:25:05 ******/
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
/****** Object:  Table [dbo].[powerEnum]    Script Date: 04/19/2011 17:25:05 ******/
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
INSERT [dbo].[powerEnum] ([col_powerEnum_id], [col_powerEnum_type], [col_powerEnum_enum], [col_powerEnum_name], [col_powerEnum_manual], [col_powerEnum_recordState], [col_powerEnum_operator], [col_powerEnum_operatoTime], [col_powerEnum_recordCopyFrom]) VALUES (100001, N'login.state', 1, N'登录', NULL, 1, 0, CAST(0x00009F9800000000 AS DateTime), 0)
INSERT [dbo].[powerEnum] ([col_powerEnum_id], [col_powerEnum_type], [col_powerEnum_enum], [col_powerEnum_name], [col_powerEnum_manual], [col_powerEnum_recordState], [col_powerEnum_operator], [col_powerEnum_operatoTime], [col_powerEnum_recordCopyFrom]) VALUES (100002, N'login.state', 2, N'退出', NULL, 1, 0, CAST(0x00009F9800000000 AS DateTime), 0)
INSERT [dbo].[powerEnum] ([col_powerEnum_id], [col_powerEnum_type], [col_powerEnum_enum], [col_powerEnum_name], [col_powerEnum_manual], [col_powerEnum_recordState], [col_powerEnum_operator], [col_powerEnum_operatoTime], [col_powerEnum_recordCopyFrom]) VALUES (100003, N'login.state', 3, N'异常退出', NULL, 1, 0, CAST(0x00009F9800000000 AS DateTime), 0)
INSERT [dbo].[powerEnum] ([col_powerEnum_id], [col_powerEnum_type], [col_powerEnum_enum], [col_powerEnum_name], [col_powerEnum_manual], [col_powerEnum_recordState], [col_powerEnum_operator], [col_powerEnum_operatoTime], [col_powerEnum_recordCopyFrom]) VALUES (100004, N'login.state', 4, N'强制退出', NULL, 1, 0, CAST(0x00009F9800000000 AS DateTime), 0)
INSERT [dbo].[powerEnum] ([col_powerEnum_id], [col_powerEnum_type], [col_powerEnum_enum], [col_powerEnum_name], [col_powerEnum_manual], [col_powerEnum_recordState], [col_powerEnum_operator], [col_powerEnum_operatoTime], [col_powerEnum_recordCopyFrom]) VALUES (200001, N'functionPointPower', 1, N'新建', NULL, 1, 0, CAST(0x00009F9800000000 AS DateTime), 0)
INSERT [dbo].[powerEnum] ([col_powerEnum_id], [col_powerEnum_type], [col_powerEnum_enum], [col_powerEnum_name], [col_powerEnum_manual], [col_powerEnum_recordState], [col_powerEnum_operator], [col_powerEnum_operatoTime], [col_powerEnum_recordCopyFrom]) VALUES (200002, N'functionPointPower', 2, N'删除', NULL, 1, 0, CAST(0x00009F9800000000 AS DateTime), 0)
INSERT [dbo].[powerEnum] ([col_powerEnum_id], [col_powerEnum_type], [col_powerEnum_enum], [col_powerEnum_name], [col_powerEnum_manual], [col_powerEnum_recordState], [col_powerEnum_operator], [col_powerEnum_operatoTime], [col_powerEnum_recordCopyFrom]) VALUES (200003, N'functionPointPower', 4, N'修改', NULL, 1, 0, CAST(0x00009F9800000000 AS DateTime), 0)
INSERT [dbo].[powerEnum] ([col_powerEnum_id], [col_powerEnum_type], [col_powerEnum_enum], [col_powerEnum_name], [col_powerEnum_manual], [col_powerEnum_recordState], [col_powerEnum_operator], [col_powerEnum_operatoTime], [col_powerEnum_recordCopyFrom]) VALUES (200004, N'functionPointPower', 8, N'查看', NULL, 1, 0, CAST(0x00009F9800000000 AS DateTime), 0)
/****** Object:  Table [dbo].[newID]    Script Date: 04/19/2011 17:25:05 ******/
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
INSERT [dbo].[newID] ([col_newID_ID], [col_newID_lastID], [col_newID_tableName]) VALUES (0, 27, N'user1                           ')
INSERT [dbo].[newID] ([col_newID_ID], [col_newID_lastID], [col_newID_tableName]) VALUES (1, 103, N'login                           ')
INSERT [dbo].[newID] ([col_newID_ID], [col_newID_lastID], [col_newID_tableName]) VALUES (2, 25, N'userGroup                       ')
/****** Object:  Table [dbo].[messageBoard]    Script Date: 04/19/2011 17:25:05 ******/
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
/****** Object:  StoredProcedure [dbo].[userGroup_add]    Script Date: 04/19/2011 17:25:04 ******/
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
           ,@col_userGroup_opertor datetime
           ,@col_userGroup_copyFromID int)

AS
BEGIN

INSERT INTO [wx].[dbo].[userGroup]
           (col_userGroup_id
           ,col_group_id
           ,col_user_id
           ,col_userGroup_recordState
           ,col_userGroup_operator
           ,col_userGroup_opertor
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
/****** Object:  StoredProcedure [dbo].[user_add]    Script Date: 04/19/2011 17:25:04 ******/
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
/****** Object:  View [dbo].[View_Power]    Script Date: 04/19/2011 17:25:05 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE VIEW [dbo].[View_Power]
AS
SELECT     dbo.userGroup.col_userGroup_id, dbo.user1.col_user_id, dbo.[group].col_group_id, dbo.user1.col_user_loginName, dbo.[group].col_group_name
FROM         dbo.user1 LEFT OUTER JOIN
                      dbo.userGroup ON dbo.user1.col_user_id = dbo.userGroup.col_user_id LEFT OUTER JOIN
                      dbo.[group] ON dbo.userGroup.col_group_id = dbo.[group].col_group_id
WHERE     (dbo.user1.col_user_recordState <> 2)
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
         Begin Table = "user1"
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
' , @level0type=N'SCHEMA',@level0name=N'dbo', @level1type=N'VIEW',@level1name=N'View_Power'
GO
EXEC sys.sp_addextendedproperty @name=N'MS_DiagramPaneCount', @value=1 , @level0type=N'SCHEMA',@level0name=N'dbo', @level1type=N'VIEW',@level1name=N'View_Power'
GO
/****** Object:  StoredProcedure [dbo].[userGroup_edit]    Script Date: 04/19/2011 17:25:04 ******/
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
      ,[col_userGroup_opertor] = getdate()
 WHERE [col_userGroup_id] = @col_userGroup_id
 
END
GO
/****** Object:  StoredProcedure [dbo].[userGroup_delete]    Script Date: 04/19/2011 17:25:04 ******/
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
/****** Object:  StoredProcedure [dbo].[login_logoutExceptionAll]    Script Date: 04/19/2011 17:25:04 ******/
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
/****** Object:  StoredProcedure [dbo].[login_logoutException]    Script Date: 04/19/2011 17:25:04 ******/
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
/****** Object:  StoredProcedure [dbo].[login_logout]    Script Date: 04/19/2011 17:25:04 ******/
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
/****** Object:  StoredProcedure [dbo].[login_login]    Script Date: 04/19/2011 17:25:04 ******/
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
/****** Object:  StoredProcedure [dbo].[login_IsLogining]    Script Date: 04/19/2011 17:25:04 ******/
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
/****** Object:  StoredProcedure [dbo].[comm_CreateNewID]    Script Date: 04/19/2011 17:25:04 ******/
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
/****** Object:  StoredProcedure [dbo].[user_IsBeing]    Script Date: 04/19/2011 17:25:04 ******/
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
/****** Object:  StoredProcedure [dbo].[user_edit]    Script Date: 04/19/2011 17:25:04 ******/
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
/****** Object:  StoredProcedure [dbo].[user_delete]    Script Date: 04/19/2011 17:25:04 ******/
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
/****** Object:  StoredProcedure [dbo].[user_CreateNewID]    Script Date: 04/19/2011 17:25:04 ******/
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
/****** Object:  StoredProcedure [dbo].[login_CreateNewID]    Script Date: 04/19/2011 17:25:04 ******/
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
/****** Object:  StoredProcedure [dbo].[userGroup_CreateNewID]    Script Date: 04/19/2011 17:25:04 ******/
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
/****** Object:  StoredProcedure [dbo].[userGroup_setByUserID]    Script Date: 04/19/2011 17:25:04 ******/
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
			   ,[col_userGroup_opertor]
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
			  ,[col_userGroup_opertor] = getdate()
			WHERE [col_user_id] = @col_user_id
			
	end
      
END
GO
