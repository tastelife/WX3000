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
	TiXmlElement* firstTiXmlElement = GetFirstTiXmlElementPoint(strNote, strEleName);
	if(NULL==firstTiXmlElement)
	{
		//Ԫ�ز����ڲ������
		return true;
	}
	//�ڵ��µ�����Ԫ�ؼ��뵽vecElement��
	this->AddAllXmlEleToVec(firstTiXmlElement, strEleName, vecElement);

	return true;
}


// ͨ��ָ���Ľڵ��Ԫ���������Ԫ��ֵ
std::string CWXCommConfigure::GetElement(const std::string& strNote, const std::string& strEleName)
{	
	TiXmlElement* firstTiXmlElement = GetFirstTiXmlElementPoint(strNote, strEleName);
	if(NULL==firstTiXmlElement)
	{
		//Ԫ�ز����ڲ������
		return "";
	}

	return firstTiXmlElement->GetText();
}

// ������ͬ����ָ����Ԫ�ؼ��뵽vector<string>��
void CWXCommConfigure::AddAllXmlEleToVec(TiXmlElement* firstTiXmlElement, std::string strEleName,
	std::vector<std::string>& vecElement)
{
	WX_COMM_ASSERT((NULL!=firstTiXmlElement), CWXCommAssertThrow);

	//Ԫ�ؼ��뵽vector<string>
	TiXmlElement* iterTiXmlElement = firstTiXmlElement;
	while(NULL!=iterTiXmlElement)
	{
		vecElement.push_back(iterTiXmlElement->GetText());
		//���ͬ������һ��Ԫ��
		iterTiXmlElement = iterTiXmlElement->NextSiblingElement(strEleName);
	}
}


//ͨ��ָ���Ľڵ��Ԫ�������Ԫ��ֵ�ĵ�һ��Ԫ�ص�ָ��
TiXmlElement* CWXCommConfigure::GetFirstTiXmlElementPoint(const std::string& strNote, const std::string& strEleName)
{
	//����xml
	TiXmlDocument tiXmlDoc(this->GetFilePath().c_str());
	if(!tiXmlDoc.LoadFile())
	{
		return NULL;
	}
	//��ýڵ�
	TiXmlNode* pTiXmlNode = NULL;
	pTiXmlNode = tiXmlDoc.FirstChild(strNote);
	if(NULL==pTiXmlNode)
	{
		return NULL;
	}
	//��ýڵ��µ�ָ��Ԫ�ص��׸�Ԫ��
	TiXmlElement* firstTiXmlElement = NULL;
	firstTiXmlElement = pTiXmlNode->FirstChildElement(strEleName);

	return firstTiXmlElement;
}