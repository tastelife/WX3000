/** 
 *  文件: 	CLogOut.cpp
 *	功能:
 * 		日志输出类
 *  版本号： 0.0.1
 *  创建人: 王宝明
 *  时间: 2007-02-01
 */
 
 
#include "StdAfx.h"

 
#include "LogFile.h"
#include "LogOut.h"
#include <iostream>
#include <sstream>
using namespace std;




CLogOut::CLogOut()
{
	m_nFileLen			= 0x4FFFFFFF,
	m_cOutputLevel		= (60),
	m_cOutputMode		= (3);
	m_IsOutDump			= true;
	m_cOutputLevelDesi	= 0;
}




CLogOut::~CLogOut()
{
	this->UnInit();
}




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
char CLogOut::SetOutputMod(char cMode)
{
	m_cOutputMode = cMode;

	return  m_cOutputMode;
}




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
char CLogOut::SetOutputLevel(char cLevel)
{
	m_cOutputLevel = cLevel;

	return m_cOutputLevel;
}





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
char CLogOut::SetOutputLevelDesi(char cLevel)
{
	m_cOutputLevelDesi = cLevel;

	return m_cOutputLevelDesi;
}




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
long CLogOut::OutputLog(const char *pcInfo, const char *pcData, long nDataLen, char cLeve)
{
	long				nRtn = 1;
	long				nLen = 0;
	//转换函数使用用new给其分配空间
	char				*pcPisData = NULL;

	//输出级别
	if ( ((cLeve < this->m_cOutputLevel)&&(this->m_cOutputLevel<=60)) || 
		(cLeve == this->m_cOutputLevel) || (cLeve == this->m_cOutputLevelDesi) )
	{	
		//不输出扩展数据
		if ( !m_IsOutDump )
		{
			nDataLen = 0;
		}
		
		//转换成要显示的数据
		if ( 0 < (nLen = this->ConverData( pcInfo, pcData, nDataLen, &pcPisData )) )
		{
			//输出到文件
			if ( 0x02&m_cOutputMode )
			{
				//判断文件是否写满 
				while ( IsFull( nLen ) )
				{
					//重新打开文件
					this->UnInit();
					this->Init( nLen );
				}
				//写数据
				if ( NULL != pcPisData )
				{
					if ( (nLen = m_CLogFile.WriteFile( pcPisData, nLen )) >= 0 )
					{
						nRtn = nLen;
					}
				}
			}
			
			//标准输出
			if ( (0x01&m_cOutputMode)&&(NULL != pcPisData) )
			{
				cout << pcPisData;
			}
		}

		//释放空间
		if ( NULL != pcPisData )
		{
			delete pcPisData;
		}
	} 
	else
	{
		nRtn = 0;
	}

	return nRtn;
}




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
void CLogOut::SetFileName(char *pszFileName)
{
	stringstream sstr;
	sstr << pszFileName;
	sstr >> m_szFileName;
}




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
long CLogOut::SetFileLen(long nFileLen)
{
	return (m_nFileLen = nFileLen);
}




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
bool CLogOut::SetOutDump( bool IsOut )
{
	return (m_IsOutDump = IsOut);
}




/** 
*  功能:
*  	启动 打开文件
*  函数名:
*  	long Init( void )
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
long CLogOut::Init( long nDataLen )
{
	long				nRtn = -2;

	//获得文件名 
	if ( 0 < this->GetFileName( m_szFileName, nDataLen, m_szFileName ))
	{
		//打开文件
		nRtn = m_CLogFile.OpenFile( m_szFileName );
	}


	return nRtn;
}




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
long CLogOut::UnInit()
{
	return m_CLogFile.CloseFile();
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
bool CLogOut::IsFull( long nDataLen )
{
	bool				bRtn = false;

	if ( (nDataLen+m_CLogFile.GetFileLength()) > m_nFileLen )
	{
		bRtn = true;
	}

	return bRtn;
}


