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


//保存员工形像文件的路径
std::string CImageSave::DownLoadEmployeeImage(int nEmployeeNO)
{
	std::string strPath;
	return strPath;
}
//上传员工形像文件的路径
bool CImageSave::PutEmployeeImage(int nEmployeeNO, std::string strPath)
{	
	return ReadAndPut(CreatePathEmployeeImageDB(nEmployeeNO), strPath);
}

//合成员工形像文件的路径
std::string CImageSave::CreatePathEmployeeImage(int nEmployeeNO)
{
	return CMM::Configure()->GetElement("CONFIG", "TEMPPATH") + "employee_" + CWXConver::single2s(nEmployeeNO);
}

//合成员工形像数据库的路径
std::string CImageSave::CreatePathEmployeeImageDB(int nEmployeeNO)
{
	return CMM::Configure()->GetElement("CONFIG", "IMAGEDBPATH") + "employee_" + CWXConver::single2s(nEmployeeNO);
}

//读文件上传
bool CImageSave::ReadAndPut(std::string strDBName, std::string strFileName)
{
	CFile file;
	if(!file.Open(strFileName.c_str(), CFile::modeRead))
	{
		return false;
	}

	char* pchBuf = new char[file.GetLength()];

	file.SeekToBegin();
	file.Read(pchBuf, file.GetLength());
	file.Close();
	CWXDBSqlite sqlite(strDBName);
	sqlite.CreateAnyBlobTable();
	bool bRtn = sqlite.SetAnyBlob("image", pchBuf, file.GetLength(), "jpg");

	delete[] pchBuf;

	return bRtn;
}



NAMESPACE_BNS_END

