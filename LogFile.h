/** 
*  �ļ�: 	CLogFile.h
*	����:
* 		��־�ļ�������
*  �汾�ţ� 0.0.1
*  ������: ������
*  ʱ��: 2007-02-01
*/




#ifndef CLOGFILE_H_
#define CLOGFILE_H_

class CLogFile
{
public:
	CLogFile();
	virtual ~CLogFile();

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
	long OpenFile(char *pszFileName);


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
	long CloseFile();


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
	bool IsOpen();


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
	long WriteFile(char *pcData, long nLen);


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
	*  �汾�ţ� 0.0.1
	*  ʱ��: 2007-01-31 
	*/
	long GetFileLength(); 



private: 
	/** 
	*  ���ļ����
	*  
	*  ������: ������
	*  �汾�ţ� 0.0.1
	*  ʱ��: 2007-01-31 
	*/
	void *m_hFile;

};

#endif /*CLOGFILE_H_*/
