/** 
*  �ļ�: 	CLogOut.h
*	����:
* 		��־�����
*  �汾�ţ� 0.0.1
*  ������: ������
*  ʱ��: 2007-02-01
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
	char SetOutputMod(char cMode);


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
	char SetOutputLevel(char cLevel);


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
	char SetOutputLevelDesi(char cLevel);


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
	long OutputLog(const char *pcInfo, const char *pcData, long nDataLen, char cLeve);


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
	void SetFileName(char *pszFileName);


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
	long SetFileLen(long nFileLen);


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
	bool SetOutDump( bool IsOut );



	/** 
	*  ����:
	*  	���� ���ļ�
	*  ������:
	*  	long Init( long nDataLen )
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
	long Init( long nDataLen );


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
	long UnInit();


protected:

	/** 
	*  ����:
	*  	�����־
	*  ������:
	*  	virtual long ConverData( char *pcInfo, char *pcData, long nDataLen, char *pcOut )
	*  ����:
	*  	pcInfo----ֱ�������ʵ���ַ�����"\0"����
	*  	pcData----ת��ʮ���������
	*  	pcOut----�������
	*  ����:
	*  	>0----�ɹ�
	*  	<=0----ʧ��
	*  ������: ������
	*  �汾�ţ� 0.0.1
	*  ʱ��: 2007-02-01
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
		//�����չ
		if ( m_IsOutDump )
		{
			//����λ��
			strRtn += "\n        00 01 02 03 04 05 06 07 08 09 0A 0B 0C 0D 0E 0F";
			strRtn += "\n        *************************************************";

			//pcData��ʮ���������
			for ( i=0; (NULL!=pcData) && i<nDataLen; i++ )
			{
				if ( i%16 == 0 )
				{
					strRtn += "\n        ";
				}
				sstr.clear();
				strBuf = "";
				//����λ��ʾ����ǰ��0
				sstr.width( 2 );
				sstr.fill( '0' );
				//��ʮ��������ʾ
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
	*  ����:
	*  	�����־
	*  ������:
	*  	virtual long GetFileName(char *fileName, long nDataLen, char *pcOut)
	*  ����:
	*  	fileName----�����ļ���
	*  	nDataLen----�����ļ����пռ�
	*  	pcOut----����ļ���
	*  ����:
	*  	>=0----�ɹ�
	*  	<0----ʧ��
	*  ������: ������
	*  �汾�ţ� 0.0.1
	*  ʱ��: 2007-02-02
	*/
	virtual long GetFileName(char *fileName, long nDataLen, char *pcOut)
	{
		long				nRtn = -1;
		string				strFileName;
		stringstream		sstr;
		CLogFile logfile;

		//�õ��ļ���
		strFileName = fileName;
		strFileName += "00.log" ;
		sstr << strFileName ;
		sstr >> pcOut;

		//�Ƿ���Ҫ����ļ�
		if ( 0 == logfile.OpenFile( pcOut ) )
		{
			if ( (m_nFileLen - logfile.GetFileLength()) > nDataLen )
			{
				nRtn = m_nFileLen - logfile.GetFileLength();
			} 
			logfile.CloseFile();

			//����ļ�
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
	bool IsFull( long nDataLen );


protected:

	/** 
	*  ��־����ļ���С
	*  ������: ������
	*  �汾�ţ� 0.0.1
	*/
	long m_nFileLen;


private:

	/** 
	*  ���ģʽ:
	*  	0x01 ��׼���
	*  	0x02 ������ļ�
	*  	��ͬʱ���� ���� ��0x03
	*  ������: ������
	*  �汾�ţ� 0.0.1
	*  ʱ��: 2007-01-30 
	*/
	char m_cOutputMode;


	/** 
	*  �����������
	*  	m_cOutputLeve <= 60 :
	*  	1--10 ���ش���
	*  	11--20 ��ͨ����
	*  	21--30 ��Ҫ���
	*  	31--40 ��ͨ���
	* 	41--51 �������
	*  	OutputLog() ������cLevel����������m_cOutputLevelʱ���
	*  	m_cOutputLeve > 60:
	*  	OutputLog() ������cLevel��������m_cOutputLevelʱ���
	*   
	*  
	*  ������: ������
	*  �汾�ţ� 0.0.1
	*  ʱ��: 2007-01-30
	*/
	char m_cOutputLevel;


	/** 
	*  ������ض�����
	*   
	*  
	*  ������: ������
	*  �汾�ţ� 0.0.1
	*  ʱ��: 2007-01-30
	*/
	char m_cOutputLevelDesi;


	/** 
	*  �Ƿ������չ���� ��
	*  	long OutputLog(char *pcInfo, char *pcData, long nDataLen, char cLeve)
	*  	�ڶ�������
	*  	true ����
	*  	false ������
	* 	
	*   
	*  
	*  ������: ������
	*  �汾�ţ� 0.0.1
	*  ʱ��: 2007-02-10
	*/
	bool m_IsOutDump;


	/** 
	*  ��־������ļ���,
	*  	��չ��Ϊ".log"�Զ����
	*  	�����ļ�ʱ��"."ǰ�Զ�������
	*  ������: ������
	*  �汾�ţ� 0.0.1
	*  ʱ��: 2007-01-31
	*/
	char m_szFileName[CLOGOUT_FILE_LEN];


	/** 
	*  �ļ����������
	*  ������: ������
	*  �汾�ţ� 0.0.1
	*  ʱ��: 2007-02-01
	*/
	CLogFile m_CLogFile;

};

#endif /*CLOGOUT_H_*/
