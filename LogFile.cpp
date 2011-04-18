/** 
 *  文件: 	CLogFile.cpp
 *	功能:
 * 		日志文件控制类
 *  版本号： 0.0.1
 *  创建人: 王宝明
 *  时间: 2007-02-01
 */
 
 
#include "StdAfx.h"

 

#include "LogFile.h"
#include <iostream> 
#include <fstream> 
using namespace std;


CLogFile::CLogFile()
{
	m_hFile			= NULL;
}

CLogFile::~CLogFile()
{
	this->CloseFile();
}




/** 
*  功能:
*  	打开文件
*  函数名:
*  	long OpenFile( char *pszFileName )
*  参数:
*  	pszFileName----文件名
*  返回:
*  	0---成功
*  	-1----已经打开一个文件
*  	-2----文件打开失败
*  全局变量:
*  	m_hFile----赋值
*  
*  创建人: 王宝明
*  版本号： 0.0.1
*  时间: 2007-01-31 
*/
long CLogFile::OpenFile(char *pszFileName)
{
	long				nRtn = -1;
	fstream				*myfile; 
	
	if ( NULL == m_hFile )
	{
		//new myfile 变量
		myfile = new fstream; 	
		//打开文件 
		myfile->open( pszFileName, ios::out|ios::app|ios::ate ); 
		if ( myfile->is_open() )
		{
			//打开文件 成功处理
			nRtn = 0;
			m_hFile = (void *)myfile;
		} 
		else
		{
			//打开文件 失败处理
			nRtn = -2;
			delete myfile;
		}
	}
	
	return nRtn;
}




/** 
*  功能:
*  	关闭文件
*  函数名:
*  	long CloseFile( )
*  返回:
*  	0---成功
*  	-1----失败
*  全局变量:
*  	m_hFile----赋值
*  
*  创建人: 王宝明
*  版本号： 0.0.1
*  时间: 2007-01-31 
*/
long CLogFile::CloseFile()
{
	long				nRtn = 0;
	fstream				*myfile; 

	//关闭文件
	if ( NULL != m_hFile )
	{
		//文件已打开时的处理
		myfile = (fstream *)m_hFile; 	
		//关闭文件
		myfile->close();
		//释放空间
		delete myfile;
		m_hFile = NULL;
	}

	return nRtn;
}




/** 
*  功能:
*  	是否打开文件
*  函数名:
*  	bool IsOpen( void)
*  返回:
*  	true---已打开文件
*  	false----未打开文件
*  全局变量:
*  	m_hFile----使用
*  
*  创建人: 王宝明
*  版本号： 0.0.1
*  时间: 2007-01-31 
*/
bool CLogFile::IsOpen()
{
	bool				bRtn = false;

	if ( NULL != m_hFile )
	{
		bRtn = true;
	}

	return bRtn;
}




/** 
*  功能:
*  	向文件写数据
*  函数名:
*  	long WriteFile( char *pcData, long nLen )
*  参数:
*  	pcData----数据
*  	nLen----数据的长度
*  返回:
*  	>=0---实际写入的数据
*  	-1----文件未打开
*  	-2----文件写失败
*  全局变量:
*  	m_hFile----使用
*  
*  创建人: 王宝明
*  版本号： 0.0.1
*  时间: 2007-01-31 
*/
long CLogFile::WriteFile(char *pcData, long nLen)
{
	long				nRtn = -1;
	fstream				*myfile; 

	if ( NULL != m_hFile )
	{
		//文件已打开时的处理
		nRtn = -2;
		myfile = (fstream *)m_hFile; 	
		myfile->seekp( 0, ios::end );
		myfile->write( pcData, nLen )  ;
		if ( !myfile->bad() )
		{
			//写成功
			nRtn = nLen ;
		}
	}

	return nRtn;
}





/** 
*  功能:
*  	得到文件长度
*  函数名:
*  	long GetFileLength()
*  返回:
*  	>= 0----文件长度
*  	< 0----文件未打开
*  全局变量:
*  	m_hFile----使用
*  
*  创建人: 王宝明
*  版本号： 0.0.2
*  时间: 2011-04-08
*/
long CLogFile::GetFileLength()
{
	long				nRtn = -1;
	fstream				*myfile; 

	if ( NULL != m_hFile )
	{
		//文件打开时的返回长度
		myfile = (fstream *)m_hFile;
		myfile->seekp( 0, ios::end );
		nRtn = (long)myfile->tellp() ;
	}

	return nRtn;
}























