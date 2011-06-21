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
	
	//保存员工形像文件的路径
	std::string DownLoadEmployeeImage(int nEmployeeNO);
	//上传员工形像文件的路径
	bool PutEmployeeImage(int nEmployeeNO, std::string strPath);
	//保存客户形像文件的路径
	std::string DownLoadCustomerImage(int nCustomerNO);
	//上传客户形像文件的路径
	bool PutCustomerImage(int nCustomerNO, std::string strPath);
	//保存商品形像文件的路径
	std::vector<std::string> DownLoadCommodityImage(int nCommodityNO);
	//上传商品形像文件的路径
	bool PutCommodityImage(int nCommodityNO, std::vector<std::string> vecStrPath);

private:
	//合成员工形像文件的路径
	std::string CreatePathEmployeeImage(int nEmployeeNO);
	//合成员工形像数据库的路径
	std::string CreatePathEmployeeImageDB(int nEmployeeNO);
	//读文件上传
	bool ReadAndPut(std::string strDBName, std::string strFileName);
};




NAMESPACE_BNS_END

