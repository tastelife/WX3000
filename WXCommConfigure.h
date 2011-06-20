#pragma once

#include <vector>
#include <string>
#include "WXCommMacroCode.h"

class TiXmlElement;

class CWXCommConfigure
{
public:
	CWXCommConfigure(void);
	CWXCommConfigure(std::string strFilePath);
	CWXCommConfigure(CWXCommConfigure &config);
	virtual ~CWXCommConfigure(void);

public:
	// ͨ��ָ���Ľڵ��Ԫ���������Ԫ��ֵ���б�
	bool GetAllElement(const std::string& strNote, const std::string& strEleName,
		std::vector<std::string>& vecElement);
	// ͨ��ָ���Ľڵ��Ԫ���������Ԫ��ֵ
	std::string GetElement(const std::string& strNote, const std::string& strEleName);

private:
	WX_COMM_ADD_ATTRIBUTE_0(std::string, FilePath, str);
	// ������ͬ����Ԫ�ؼ��뵽vector<string>��
	void AddAllXmlEleToVec(TiXmlElement* firstTiXmlElement, std::string strEleName,
		std::vector<std::string>& vecElement);
	//ͨ��ָ���Ľڵ��Ԫ�������Ԫ��ֵ�ĵ�һ��Ԫ�ص�ָ��
	TiXmlElement* GetFirstTiXmlElementPoint(const std::string& strNote, const std::string& strEleName);
};

