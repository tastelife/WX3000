/** 
*  文件: 	CLogFile.h
*	功能:
* 		日志文件控制类
*  版本号： 0.0.1
*  创建人: 王宝明
*  时间: 2007-02-01
*/




#ifndef CLOGFILE_H_
#define CLOGFILE_H_

class CLogFile
{
public:
	CLogFile();
	virtual ~CLogFile();

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
	long OpenFile(char *pszFileName);


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
	long CloseFile();


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
	bool IsOpen();


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
	long WriteFile(char *pcData, long nLen);


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
	*  版本号： 0.0.1
	*  时间: 2007-01-31 
	*/
	long GetFileLength(); 



private: 
	/** 
	*  打开文件句柄
	*  
	*  创建人: 王宝明
	*  版本号： 0.0.1
	*  时间: 2007-01-31 
	*/
	void *m_hFile;

};

#endif /*CLOGFILE_H_*/
