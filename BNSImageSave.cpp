#include "StdAfx.h"
#include "BNSImageSave.h"


#include "StaticDB.h"
#include "WXCommFun.h"
#include "WXDBSqlite.h"

#include <afx.h>


NAMESPACE_BNS_BEGIN



CImageSave::CImageSave(void)
{
}


CImageSave::~CImageSave(void)
{
}


//����Ա�������ļ���·��
std::string CImageSave::DownLoadEmployeeImage(int nEmployeeNO)
{
	return DownAndWriteImage(CreatePathEmployeeImageDB(nEmployeeNO), CreatePathEmployeeImage(nEmployeeNO));
}
//�ϴ�Ա�������ļ���·��
bool CImageSave::PutEmployeeImage(int nEmployeeNO, std::string strPath)
{	
	return ReadAndPutImage(CreatePathEmployeeImageDB(nEmployeeNO), strPath);
}

//�ϳ�Ա�������ļ���·��
std::string CImageSave::CreatePathEmployeeImage(int nEmployeeNO)
{
	return CMM::Configure()->GetElement("CONFIG", "TEMPPATH") + "employee_" + CWXConver::single2s(nEmployeeNO) + "_image";
}

//�ϳ�Ա���������ݿ��·��
std::string CImageSave::CreatePathEmployeeImageDB(int nEmployeeNO)
{
	return CMM::Configure()->GetElement("CONFIG", "IMAGEDBPATH") + std::string("employee_") + CWXConver::single2s(nEmployeeNO);
}

//���ļ��ϴ�
bool CImageSave::ReadAndPutImage(std::string strDBName, std::string strFileName)
{
	std::string strExp; 
	strExp.assign(strFileName, strFileName.find_first_of('.'), strFileName.npos);
	CFile file;
	if(!file.Open(strFileName.c_str(), CFile::modeRead))
	{
		return false;
	}

	unsigned int nBufLen = file.GetLength();
	char* pchBuf = new char[nBufLen];

	file.SeekToBegin();
	file.Read(pchBuf, nBufLen);
	file.Close();

	CWXDBSqlite sqlite(strDBName);
	sqlite.Open();
	sqlite.CreateAnyBlobTable();
	bool bRtn = sqlite.SetAnyBlob("image", pchBuf, nBufLen, strExp.c_str());
	sqlite.Close();

	delete[] pchBuf;

	return bRtn;
}

//�������д�ļ�
std::string CImageSave::DownAndWriteImage(std::string strDBName, std::string strFileName)
{
	CWXDBSqlite sqlite(strDBName);
	sqlite.Open();
	bool bRtn = sqlite.GetAnyBlob("image", 
		[&strFileName](const unsigned char *pchBuf, int nLen, const unsigned char *pchOther)
		{
			strFileName += std::string((char *)pchOther);
			CFile file;
			if(!file.Open(strFileName.c_str(), CFile::modeCreate|CFile::modeWrite))
			{
				return;
			}

			file.Write(pchBuf, nLen);

			file.Close();
		});
	sqlite.Close();

	if(!bRtn)
	{
		return "";
	}

	return strFileName;
}


NAMESPACE_BNS_END

