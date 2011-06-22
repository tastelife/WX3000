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
	template<class Pred>
	bool LoadAndDispose(const std::string& strNote, const std::string& strEleName, Pred _pred);
};


//ͨ��ָ���Ľڵ��Ԫ�������Ԫ��ֵ�ĵ�һ��Ԫ�ص�ָ��
template<class Pred>
bool CWXCommConfigure::LoadAndDispose(const std::string& strNote, const std::string& strEleName, Pred _pred)
{
	//����xml
	TiXmlDocument tiXmlDoc(this->GetFilePath().c_str());
	if(!tiXmlDoc.LoadFile())
	{
		return false;
	}
	//��ýڵ�
	TiXmlNode* pTiXmlNode = NULL;
	pTiXmlNode = tiXmlDoc.FirstChild(strNote);
	if(NULL==pTiXmlNode)
	{
		return false;
	}
	//��ýڵ��µ�ָ��Ԫ�ص��׸�Ԫ��	//����
	TiXmlElement* iterTiXmlElement = pTiXmlNode->FirstChildElement(strEleName);;
	while(NULL!=iterTiXmlElement)
	{
		_pred(iterTiXmlElement);
		//���ͬ������һ��Ԫ��
		iterTiXmlElement = iterTiXmlElement->NextSiblingElement(strEleName);
	}

	return true;
}