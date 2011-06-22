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

// ͨ��ָ���Ľڵ��Ԫ���������Ԫ��ֵ���б�
bool CWXCommConfigure::GetAllElement(const std::string& strNote, const std::string& strEleName,
	std::vector<std::string>& vecElement)
{
	LoadAndDispose(strNote, strEleName, 
		[&vecElement](TiXmlElement* elem){vecElement.push_back(elem->GetText());});

	return true;
}


// ͨ��ָ���Ľڵ��Ԫ���������Ԫ��ֵ
std::string CWXCommConfigure::GetElement(const std::string& strNote, const std::string& strEleName)
{	
	std::string strRtn;
	LoadAndDispose(strNote, strEleName, [&strRtn](TiXmlElement* elem){strRtn = elem->GetText();});

	return strRtn;
}
