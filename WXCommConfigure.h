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
	// 通过指定的节点和元素名，获得元素值的列表
	bool GetAllElement(const std::string& strNote, const std::string& strEleName,
		std::vector<std::string>& vecElement);
	// 通过指定的节点和元素名，获得元素值
	std::string GetElement(const std::string& strNote, const std::string& strEleName);

private:
	WX_COMM_ADD_ATTRIBUTE_0(std::string, FilePath, str);
	// 把所有同级的元素加入到vector<string>中
	void AddAllXmlEleToVec(TiXmlElement* firstTiXmlElement, std::string strEleName,
		std::vector<std::string>& vecElement);
	//通过指定的节点和元素名获得元素值的第一个元素的指针
	template<class Pred>
	bool LoadAndDispose(const std::string& strNote, const std::string& strEleName, Pred _pred);
};


//通过指定的节点和元素名获得元素值的第一个元素的指针
template<class Pred>
bool CWXCommConfigure::LoadAndDispose(const std::string& strNote, const std::string& strEleName, Pred _pred)
{
	//载入xml
	TiXmlDocument tiXmlDoc(this->GetFilePath().c_str());
	if(!tiXmlDoc.LoadFile())
	{
		return false;
	}
	//获得节点
	TiXmlNode* pTiXmlNode = NULL;
	pTiXmlNode = tiXmlDoc.FirstChild(strNote);
	if(NULL==pTiXmlNode)
	{
		return false;
	}
	//获得节点下的指定元素的首个元素	//处理
	TiXmlElement* iterTiXmlElement = pTiXmlNode->FirstChildElement(strEleName);;
	while(NULL!=iterTiXmlElement)
	{
		_pred(iterTiXmlElement);
		//获得同级的下一个元素
		iterTiXmlElement = iterTiXmlElement->NextSiblingElement(strEleName);
	}

	return true;
}