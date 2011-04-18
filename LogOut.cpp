/** 
 *  �ļ�: 	CLogOut.cpp
 *	����:
 * 		��־�����
 *  �汾�ţ� 0.0.1
 *  ������: ������
 *  ʱ��: 2007-02-01
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
*  ����:
*  	�������ģʽ
*  ������:
*  	char SetOutputMod( char cMode )
*  ����:
*  	cMode----���ģʽ
*  ����:
*  	�����õ����ģʽ
*  ȫ�ֱ���:
*  	m_cOutputMode ---- �޸�
*  ������: ������
*  �汾�ţ� 0.0.1
*  ʱ��: 2007-01-30
*/
char CLogOut::SetOutputMod(char cMode)
{
	m_cOutputMode = cMode;

	return  m_cOutputMode;
}




/** 
*  ����:
*  	��������ļ���
*  ������:
*  	char SetOutputLevel( char cLevel )
*  ����:
*  	cLevel----�������
*  ����:
*  	�����õ����ģʽ
*  ȫ�ֱ���:
*  	m_cOutputLevel ---- �޸�
*  ������: ������
*  �汾�ţ� 0.0.1
*  ʱ��: 2007-01-30
*/
char CLogOut::SetOutputLevel(char cLevel)
{
	m_cOutputLevel = cLevel;

	return m_cOutputLevel;
}





/** 
*  ����:
*  	��������ļ���
*  ������:
*  	char SetOutputLevelDesi( char cLevel )
*  ����:
*  	cLevel----�������
*  ����:
*  	�����õ����ģʽ
*  ȫ�ֱ���:
*  	m_cOutputLevelDesi ---- �޸�
*  ������: ������
*  �汾�ţ� 0.0.1
*  ʱ��: 2007-01-30
*/
char CLogOut::SetOutputLevelDesi(char cLevel)
{
	m_cOutputLevelDesi = cLevel;

	return m_cOutputLevelDesi;
}




/** 
*  ����:
*  	�����־
*  ������:
*  	long OutputLog( char *pcInfo, char *pcData, long nDataLen, char cLevel )
*  ����:
*  	pcInfo----ֱ�������ʵ���ַ�����"\0"����
*  	pcData----ת��ʮ���������
*  	cLevel----�������
*  ����:
*  	>0----�ɹ�
*   ==0----�������������
*  	<0----ʧ��
*  ȫ�ֱ���:
*  	m_CLogFile----ʹ��
*  ������: ������
*  �汾�ţ� 0.0.1
*  ʱ��: 2007-01-30
*/
long CLogOut::OutputLog(const char *pcInfo, const char *pcData, long nDataLen, char cLeve)
{
	long				nRtn = 1;
	long				nLen = 0;
	//ת������ʹ����new�������ռ�
	char				*pcPisData = NULL;

	//�������
	if ( ((cLeve < this->m_cOutputLevel)&&(this->m_cOutputLevel<=60)) || 
		(cLeve == this->m_cOutputLevel) || (cLeve == this->m_cOutputLevelDesi) )
	{	
		//�������չ����
		if ( !m_IsOutDump )
		{
			nDataLen = 0;
		}
		
		//ת����Ҫ��ʾ������
		if ( 0 < (nLen = this->ConverData( pcInfo, pcData, nDataLen, &pcPisData )) )
		{
			//������ļ�
			if ( 0x02&m_cOutputMode )
			{
				//�ж��ļ��Ƿ�д�� 
				while ( IsFull( nLen ) )
				{
					//���´��ļ�
					this->UnInit();
					this->Init( nLen );
				}
				//д����
				if ( NULL != pcPisData )
				{
					if ( (nLen = m_CLogFile.WriteFile( pcPisData, nLen )) >= 0 )
					{
						nRtn = nLen;
					}
				}
			}
			
			//��׼���
			if ( (0x01&m_cOutputMode)&&(NULL != pcPisData) )
			{
				cout << pcPisData;
			}
		}

		//�ͷſռ�
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
*  ����:
*  	������־������ļ���
*  ������:
*  	void SetFileName( char *pszFileName )
*  ����:
*  	pszFileName----�ļ���
*  ȫ�ֱ���:
*  	m_szFileName---�޸�
*  
*  ������: ������
*  �汾�ţ� 0.0.1
*  ʱ��: 2007-01-30
*/
void CLogOut::SetFileName(char *pszFileName)
{
	stringstream sstr;
	sstr << pszFileName;
	sstr >> m_szFileName;
}




/** 
*  ����:
*  	������־������ļ�����
*  ������:
*  	long SetFileLen( long nFileLen )
*  ����:
*  	nFileLen----�ļ�����
*  ����:
*  	�����õ��ļ�����
*  ȫ�ֱ���:
*  	m_nFileLen ---- �޸�
*  ������: ������
*  �汾�ţ� 0.0.1
*  ʱ��: 2007-01-30
*/
long CLogOut::SetFileLen(long nFileLen)
{
	return (m_nFileLen = nFileLen);
}




/** 
*  ����:
*  	�����Ƿ������չ����
*  ������:
*  	bool SetOutDump( bool IsOut )
*  ����:
*  	IsOut----�Ƿ����
*  ����:
*  	�Ƿ����
*  ȫ�ֱ���:
*  	m_IsOutDump ---- �޸�
*  ������: ������
*  �汾�ţ� 0.0.1
*  ʱ��: 2007-01-30
*/
bool CLogOut::SetOutDump( bool IsOut )
{
	return (m_IsOutDump = IsOut);
}




/** 
*  ����:
*  	���� ���ļ�
*  ������:
*  	long Init( void )
*  ����:
*  	nDataLen----�����ļ����пռ�
*  ����:
*  	0---�ɹ�
*  	-1----�Ѿ���һ���ļ�
*  	-2----�ļ���ʧ��
*  ȫ�ֱ���:
*  	m_cOutputMode----ʹ��
*  	m_cOutputLevel----ʹ��
*  	m_szFileName----�޸�
*  	m_nFileLen----ʹ��
*  	m_CLogFile----ʹ��
*  
*  
*  ������: ������
*  �汾�ţ� 0.0.1
*  ʱ��: 2007-01-31
*/
long CLogOut::Init( long nDataLen )
{
	long				nRtn = -2;

	//����ļ��� 
	if ( 0 < this->GetFileName( m_szFileName, nDataLen, m_szFileName ))
	{
		//���ļ�
		nRtn = m_CLogFile.OpenFile( m_szFileName );
	}


	return nRtn;
}




/** 
*  ����:
*  	ֹͣ �ر��ļ�
*  ������:
*  	long UnInit( void )
*  ����:
*  	0---�ɹ�
*  	-1----ʧ��
*  ȫ�ֱ���:
*  	m_CLogFile----ʹ��
*  ������: ������
*  �汾�ţ� 0.0.1
*  ʱ��: 2007-01-30
*/
long CLogOut::UnInit()
{
	return m_CLogFile.CloseFile();
}




/** 
*  ����:
*  	�����־
*  ������:
*  	bool IsFull( long nDataLen )
*  ����:
*  	nDataLen----�ļ�ʣ��ռ���Сֵ ����
*  ����:
*  	false----�ռ䲻��
*  	true----�ռ��㹻
*  ������: ������
*  �汾�ţ� 0.0.1
*  ʱ��: 2007-02-01
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


