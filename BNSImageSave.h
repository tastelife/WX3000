#pragma once

#include <string>
#include <vector>


#include "WXBNSComm.h"

NAMESPACE_BNS_BEGIN



class CImageSave
{
public:
	CImageSave(void);
	~CImageSave(void);
	
	//����Ա�������ļ���·��
	std::string DownLoadEmployeeImage(int nEmployeeNO);
	//�ϴ�Ա�������ļ���·��
	bool PutEmployeeImage(int nEmployeeNO, std::string strPath);
	//����ͻ������ļ���·��
	std::string DownLoadCustomerImage(int nCustomerNO);
	//�ϴ��ͻ������ļ���·��
	bool PutCustomerImage(int nCustomerNO, std::string strPath);
	//������Ʒ�����ļ���·��
	std::vector<std::string> DownLoadCommodityImage(int nCommodityNO);
	//�ϴ���Ʒ�����ļ���·��
	bool PutCommodityImage(int nCommodityNO, std::vector<std::string> vecStrPath);

private:
	//�ϳ�Ա�������ļ���·��
	std::string CreatePathEmployeeImage(int nEmployeeNO);
	//�ϳ�Ա���������ݿ��·��
	std::string CreatePathEmployeeImageDB(int nEmployeeNO);
	//���ļ��ϴ�
	bool ReadAndPut(std::string strDBName, std::string strFileName);
};




NAMESPACE_BNS_END

