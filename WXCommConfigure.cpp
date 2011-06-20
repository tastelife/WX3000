#include "StdAfx.h"
#include "WXCommConfigure.h"
#include "WXCommFun.h"
#include "tinyxml.h"


CWXCommConfigure::CWXCommConfigure(void)
{
}


CWXCommConfigure::CWXCommConfigure(std::string strFilePath) : m_strFilePath(strFilePath)
{
}


CWXCommConfigure::CWXCommConfigure(CWXCommConfigure &config)
{
	this->SetFilePath(config.GetFilePath());
}


CWXCommConfigure::~CWXCommConfigure(void)
{
}

// 通过指定的节点和元素名，获得元素值的列表
bool CWXCommConfigure::GetAllElement(const std::string& strNote, const std::string& strEleName,
	std::vector<std::string>& vecElement)
{
	TiXmlElement* firstTiXmlElement = GetFirstTiXmlElementPoint(strNote, strEleName);
	if(NULL==firstTiXmlElement)
	{
		//元素不存在不算错误
		return true;
	}
	//节点下的所有元素加入到vecElement中
	this->AddAllXmlEleToVec(firstTiXmlElement, strEleName, vecElement);

	return true;
}


// 通过指定的节点和元素名，获得元素值
std::string CWXCommConfigure::GetElement(const std::string& strNote, const std::string& strEleName)
{	
	TiXmlElement* firstTiXmlElement = GetFirstTiXmlElementPoint(strNote, strEleName);
	if(NULL==firstTiXmlElement)
	{
		//元素不存在不算错误
		return "";
	}

	return firstTiXmlElement->GetText();
}

// 把所有同级的指定的元素加入到vector<string>中
void CWXCommConfigure::AddAllXmlEleToVec(TiXmlElement* firstTiXmlElement, std::string strEleName,
	std::vector<std::string>& vecElement)
{
	WX_COMM_ASSERT((NULL!=firstTiXmlElement), CWXCommAssertThrow);

	//元素加入到vector<string>
	TiXmlElement* iterTiXmlElement = firstTiXmlElement;
	while(NULL!=iterTiXmlElement)
	{
		vecElement.push_back(iterTiXmlElement->GetText());
		//获得同级的下一个元素
		iterTiXmlElement = iterTiXmlElement->NextSiblingElement(strEleName);
	}
}


//通过指定的节点和元素名获得元素值的第一个元素的指针
TiXmlElement* CWXCommConfigure::GetFirstTiXmlElementPoint(const std::string& strNote, const std::string& strEleName)
{
	//载入xml
	TiXmlDocument tiXmlDoc(this->GetFilePath().c_str());
	if(!tiXmlDoc.LoadFile())
	{
		return NULL;
	}
	//获得节点
	TiXmlNode* pTiXmlNode = NULL;
	pTiXmlNode = tiXmlDoc.FirstChild(strNote);
	if(NULL==pTiXmlNode)
	{
		return NULL;
	}
	//获得节点下的指定元素的首个元素
	TiXmlElement* firstTiXmlElement = NULL;
	firstTiXmlElement = pTiXmlNode->FirstChildElement(strEleName);

	return firstTiXmlElement;
}