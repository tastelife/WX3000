/** 
 *  �ļ�: 	CLogFile.cpp
 *	����:
 * 		��־�ļ�������
 *  �汾�ţ� 0.0.1
 *  ������: ������
 *  ʱ��: 2007-02-01
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
*  ����:
*  	���ļ�
*  ������:
*  	long OpenFile( char *pszFileName )
*  ����:
*  	pszFileName----�ļ���
*  ����:
*  	0---�ɹ�
*  	-1----�Ѿ���һ���ļ�
*  	-2----�ļ���ʧ��
*  ȫ�ֱ���:
*  	m_hFile----��ֵ
*  
*  ������: ������
*  �汾�ţ� 0.0.1
*  ʱ��: 2007-01-31 
*/
long CLogFile::OpenFile(char *pszFileName)
{
	long				nRtn = -1;
	fstream				*myfile; 
	
	if ( NULL == m_hFile )
	{
		//new myfile ����
		myfile = new fstream; 	
		//���ļ� 
		myfile->open( pszFileName, ios::out|ios::app|ios::ate ); 
		if ( myfile->is_open() )
		{
			//���ļ� �ɹ�����
			nRtn = 0;
			m_hFile = (void *)myfile;
		} 
		else
		{
			//���ļ� ʧ�ܴ���
			nRtn = -2;
			delete myfile;
		}
	}
	
	return nRtn;
}




/** 
*  ����:
*  	�ر��ļ�
*  ������:
*  	long CloseFile( )
*  ����:
*  	0---�ɹ�
*  	-1----ʧ��
*  ȫ�ֱ���:
*  	m_hFile----��ֵ
*  
*  ������: ������
*  �汾�ţ� 0.0.1
*  ʱ��: 2007-01-31 
*/
long CLogFile::CloseFile()
{
	long				nRtn = 0;
	fstream				*myfile; 

	//�ر��ļ�
	if ( NULL != m_hFile )
	{
		//�ļ��Ѵ�ʱ�Ĵ���
		myfile = (fstream *)m_hFile; 	
		//�ر��ļ�
		myfile->close();
		//�ͷſռ�
		delete myfile;
		m_hFile = NULL;
	}

	return nRtn;
}




/** 
*  ����:
*  	�Ƿ���ļ�
*  ������:
*  	bool IsOpen( void)
*  ����:
*  	true---�Ѵ��ļ�
*  	false----δ���ļ�
*  ȫ�ֱ���:
*  	m_hFile----ʹ��
*  
*  ������: ������
*  �汾�ţ� 0.0.1
*  ʱ��: 2007-01-31 
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
*  ����:
*  	���ļ�д����
*  ������:
*  	long WriteFile( char *pcData, long nLen )
*  ����:
*  	pcData----����
*  	nLen----���ݵĳ���
*  ����:
*  	>=0---ʵ��д�������
*  	-1----�ļ�δ��
*  	-2----�ļ�дʧ��
*  ȫ�ֱ���:
*  	m_hFile----ʹ��
*  
*  ������: ������
*  �汾�ţ� 0.0.1
*  ʱ��: 2007-01-31 
*/
long CLogFile::WriteFile(char *pcData, long nLen)
{
	long				nRtn = -1;
	fstream				*myfile; 

	if ( NULL != m_hFile )
	{
		//�ļ��Ѵ�ʱ�Ĵ���
		nRtn = -2;
		myfile = (fstream *)m_hFile; 	
		myfile->seekp( 0, ios::end );
		myfile->write( pcData, nLen )  ;
		if ( !myfile->bad() )
		{
			//д�ɹ�
			nRtn = nLen ;
		}
	}

	return nRtn;
}





/** 
*  ����:
*  	�õ��ļ�����
*  ������:
*  	long GetFileLength()
*  ����:
*  	>= 0----�ļ�����
*  	< 0----�ļ�δ��
*  ȫ�ֱ���:
*  	m_hFile----ʹ��
*  
*  ������: ������
*  �汾�ţ� 0.0.2
*  ʱ��: 2011-04-08
*/
long CLogFile::GetFileLength()
{
	long				nRtn = -1;
	fstream				*myfile; 

	if ( NULL != m_hFile )
	{
		//�ļ���ʱ�ķ��س���
		myfile = (fstream *)m_hFile;
		myfile->seekp( 0, ios::end );
		nRtn = (long)myfile->tellp() ;
	}

	return nRtn;
}























