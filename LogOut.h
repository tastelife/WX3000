/** 
*  文件: 	CLogOut.h
*	功能:
* 		日志输出类
*  版本号： 0.0.1
*  创建人: 王宝明
*  时间: 2007-02-01
*/

#ifndef CLOGOUT_H_
#define CLOGOUT_H_

#include "LogFile.h"
#include <iostream>
#include <fstream> 
#include <sstream>
using namespace std;


#define CLOGOUT_FILE_LEN				1024
#define CLOGOUT_BUF_LEN					1024




class CLogOut
{
public:
	CLogOut();
	virtual ~CLogOut();

	/** 
	*  功能:
	*  	设置输出模式
	*  函数名:
	*  	char SetOutputMod( char cMode )
	*  参数:
	*  	cMode----输出模式
	*  返回:
	*  	被设置的输出模式
	*  全局变量:
	*  	m_cOutputMode ---- 修改
	*  创建人: 王宝明
	*  版本号： 0.0.1
	*  时间: 2007-01-30
	*/
	char SetOutputMod(char cMode);


	/** 
	*  功能:
	*  	设置输出的级别
	*  函数名:
	*  	char SetOutputLevel( char cLevel )
	*  参数:
	*  	cLevel----输出级别
	*  返回:
	*  	被设置的输出模式
	*  全局变量:
	*  	m_cOutputLevel ---- 修改
	*  创建人: 王宝明
	*  版本号： 0.0.1
	*  时间: 2007-01-30
	*/
	char SetOutputLevel(char cLevel);


	/** 
	*  功能:
	*  	设置输出的级别
	*  函数名:
	*  	char SetOutputLevelDesi( char cLevel )
	*  参数:
	*  	cLevel----输出级别
	*  返回:
	*  	被设置的输出模式
	*  全局变量:
	*  	m_cOutputLevelDesi ---- 修改
	*  创建人: 王宝明
	*  版本号： 0.0.1
	*  时间: 2007-01-30
	*/
	char SetOutputLevelDesi(char cLevel);


	/** 
	*  功能:
	*  	输出日志
	*  函数名:
	*  	long OutputLog( char *pcInfo, char *pcData, long nDataLen, char cLevel )
	*  参数:
	*  	pcInfo----直接输出的实际字符串以"\0"结束
	*  	pcData----转成十六进制输出
	*  	cLevel----输出级别
	*  返回:
	*  	>0----成功
	*   ==0----不属于输出级别
	*  	<0----失败
	*  全局变量:
	*  	m_CLogFile----使用
	*  创建人: 王宝明
	*  版本号： 0.0.1
	*  时间: 2007-01-30
	*/
	long OutputLog(const char *pcInfo, const char *pcData, long nDataLen, char cLeve);


	/** 
	*  功能:
	*  	设置日志输出的文件名
	*  函数名:
	*  	void SetFileName( char *pszFileName )
	*  参数:
	*  	pszFileName----文件名
	*  全局变量:
	*  	m_szFileName---修改
	*  
	*  创建人: 王宝明
	*  版本号： 0.0.1
	*  时间: 2007-01-30
	*/
	void SetFileName(char *pszFileName);


	/** 
	*  功能:
	*  	设置日志输出的文件长度
	*  函数名:
	*  	long SetFileLen( long nFileLen )
	*  参数:
	*  	nFileLen----文件长度
	*  返回:
	*  	被设置的文件长度
	*  全局变量:
	*  	m_nFileLen ---- 修改
	*  创建人: 王宝明
	*  版本号： 0.0.1
	*  时间: 2007-01-30
	*/
	long SetFileLen(long nFileLen);


	/** 
	*  功能:
	*  	设置是否输出扩展数据
	*  函数名:
	*  	bool SetOutDump( bool IsOut )
	*  参数:
	*  	IsOut----是否输出
	*  返回:
	*  	是否输出
	*  全局变量:
	*  	m_IsOutDump ---- 修改
	*  创建人: 王宝明
	*  版本号： 0.0.1
	*  时间: 2007-01-30
	*/
	bool SetOutDump( bool IsOut );



	/** 
	*  功能:
	*  	启动 打开文件
	*  函数名:
	*  	long Init( long nDataLen )
	*  参数:
	*  	nDataLen----所需文件空闲空间
	*  返回:
	*  	0---成功
	*  	-1----已经打开一个文件
	*  	-2----文件打开失败
	*  全局变量:
	*  	m_cOutputMode----使用
	*  	m_cOutputLevel----使用
	*  	m_szFileName----修改
	*  	m_nFileLen----使用
	*  	m_CLogFile----使用
	*  
	*  
	*  创建人: 王宝明
	*  版本号： 0.0.1
	*  时间: 2007-01-31
	*/
	long Init( long nDataLen );


	/** 
	*  功能:
	*  	停止 关闭文件
	*  函数名:
	*  	long UnInit( void )
	*  返回:
	*  	0---成功
	*  	-1----失败
	*  全局变量:
	*  	m_CLogFile----使用
	*  创建人: 王宝明
	*  版本号： 0.0.1
	*  时间: 2007-01-30
	*/
	long UnInit();


protected:

	/** 
	*  功能:
	*  	输出日志
	*  函数名:
	*  	virtual long ConverData( char *pcInfo, char *pcData, long nDataLen, char *pcOut )
	*  参数:
	*  	pcInfo----直接输出的实际字符串以"\0"结束
	*  	pcData----转成十六进制输出
	*  	pcOut----存放数据
	*  返回:
	*  	>0----成功
	*  	<=0----失败
	*  创建人: 王宝明
	*  版本号： 0.0.1
	*  时间: 2007-02-01
	*/
	virtual long ConverData(const char *pcInfo, const char *pcData, long nDataLen, char **pcOut)
	{
		int				long i = 0;
		stringstream	sstr;
		string			strBuf;
		string			strRtn;

		if ( NULL != pcInfo )
		{
			strRtn = pcInfo;
		}
		//输出扩展
		if ( m_IsOutDump )
		{
			//数据位置
			strRtn += "\n        00 01 02 03 04 05 06 07 08 09 0A 0B 0C 0D 0E 0F";
			strRtn += "\n        *************************************************";

			//pcData以十六进制输出
			for ( i=0; (NULL!=pcData) && i<nDataLen; i++ )
			{
				if ( i%16 == 0 )
				{
					strRtn += "\n        ";
				}
				sstr.clear();
				strBuf = "";
				//以两位显示不足前加0
				sstr.width( 2 );
				sstr.fill( '0' );
				//以十六进制显示
				sstr << hex << (unsigned int)(unsigned char)pcData[i];
				sstr >> strBuf;
				strRtn += strBuf;
				strRtn += " ";

			}

			strRtn += "\n        *************************************************";
		}

		strRtn += "\n";

		*pcOut = new char[strRtn.size()+1];
		memcpy( *pcOut, strRtn.c_str(), strRtn.size() );
		(*pcOut)[strRtn.size()] = 0;
		
		return (long)strRtn.size();
	}


	/** 
	*  功能:
	*  	输出日志
	*  函数名:
	*  	virtual long GetFileName(char *fileName, long nDataLen, char *pcOut)
	*  参数:
	*  	fileName----输入文件名
	*  	nDataLen----所需文件空闲空间
	*  	pcOut----输出文件名
	*  返回:
	*  	>=0----成功
	*  	<0----失败
	*  创建人: 王宝明
	*  版本号： 0.0.1
	*  时间: 2007-02-02
	*/
	virtual long GetFileName(char *fileName, long nDataLen, char *pcOut)
	{
		long				nRtn = -1;
		string				strFileName;
		stringstream		sstr;
		CLogFile logfile;

		//得到文件名
		strFileName = fileName;
		strFileName += "00.log" ;
		sstr << strFileName ;
		sstr >> pcOut;

		//是否需要清空文件
		if ( 0 == logfile.OpenFile( pcOut ) )
		{
			if ( (m_nFileLen - logfile.GetFileLength()) > nDataLen )
			{
				nRtn = m_nFileLen - logfile.GetFileLength();
			} 
			logfile.CloseFile();

			//清空文件
			if ( -1 == nRtn )
			{
				fstream myfile; 
				myfile.open( fileName,ios::trunc );
				if(!myfile.fail()) 
				{
					nRtn = 0;
				}
				myfile.close();
			}
		}
		

		return nRtn;
	}


	/** 
	*  功能:
	*  	输出日志
	*  函数名:
	*  	bool IsFull( long nDataLen )
	*  参数:
	*  	nDataLen----文件剩余空间最小值 返回
	*  返回:
	*  	false----空间不足
	*  	true----空间足够
	*  创建人: 王宝明
	*  版本号： 0.0.1
	*  时间: 2007-02-01
	*/
	bool IsFull( long nDataLen );


protected:

	/** 
	*  日志输出文件大小
	*  创建人: 王宝明
	*  版本号： 0.0.1
	*/
	long m_nFileLen;


private:

	/** 
	*  输出模式:
	*  	0x01 标准输出
	*  	0x02 输出到文件
	*  	可同时存在 相与 如0x03
	*  创建人: 王宝明
	*  版本号： 0.0.1
	*  时间: 2007-01-30 
	*/
	char m_cOutputMode;


	/** 
	*  输出级别限制
	*  	m_cOutputLeve <= 60 :
	*  	1--10 严重错误
	*  	11--20 普通错误
	*  	21--30 重要输出
	*  	31--40 普通输出
	* 	41--51 测试输出
	*  	OutputLog() 函数的cLevel参数不大于m_cOutputLevel时输出
	*  	m_cOutputLeve > 60:
	*  	OutputLog() 函数的cLevel参数等于m_cOutputLevel时输出
	*   
	*  
	*  创建人: 王宝明
	*  版本号： 0.0.1
	*  时间: 2007-01-30
	*/
	char m_cOutputLevel;


	/** 
	*  输出的特定级别
	*   
	*  
	*  创建人: 王宝明
	*  版本号： 0.0.1
	*  时间: 2007-01-30
	*/
	char m_cOutputLevelDesi;


	/** 
	*  是否输出扩展数据 既
	*  	long OutputLog(char *pcInfo, char *pcData, long nDataLen, char cLeve)
	*  	第二个参数
	*  	true 发送
	*  	false 不发送
	* 	
	*   
	*  
	*  创建人: 王宝明
	*  版本号： 0.0.1
	*  时间: 2007-02-10
	*/
	bool m_IsOutDump;


	/** 
	*  日志输出的文件名,
	*  	扩展名为".log"自动添加
	*  	生成文件时在"."前自动添数字
	*  创建人: 王宝明
	*  版本号： 0.0.1
	*  时间: 2007-01-31
	*/
	char m_szFileName[CLOGOUT_FILE_LEN];


	/** 
	*  文件操作类对像
	*  创建人: 王宝明
	*  版本号： 0.0.1
	*  时间: 2007-02-01
	*/
	CLogFile m_CLogFile;

};

#endif /*CLOGOUT_H_*/
