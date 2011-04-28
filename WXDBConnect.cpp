#include "StdAfx.h"
#include "WXDBConnect.h"

CWXDBConnect::CWXDBConnect(void)
{
	//��ʼ��Connectionָ��
	m_pConnection = NULL;
	//��ʼ��m_pCommandPtrָ��
	m_pCommandPtr = NULL;
	
	this->Init();
}

CWXDBConnect::~CWXDBConnect(void)
{
	if(NULL!=m_pConnection)
	{
		m_pConnection.Release();
		m_pConnection = NULL;
	}
	if(NULL!=m_pCommandPtr)
	{
		m_pCommandPtr.Release();
		m_pCommandPtr = NULL;
	}
}

//��ʼ��
void CWXDBConnect::Init()
{
	if(NULL==m_pConnection)
	{
		m_pConnection.CreateInstance(_uuidof(Connection)); 
	}
	if(NULL==m_pCommandPtr)
	{
		m_pCommandPtr.CreateInstance(_uuidof(Command));
	}
}

bool CWXDBConnect::Open()
{
	HRESULT hr;
	
	hr = m_pConnection->Open(this->m_strSQLConcetText.c_str(),"","",NULL);

	if(FAILED(hr))
	{
		return false;
	}

	return true;
}

bool CWXDBConnect::Close()
{	
	HRESULT hr;

	hr = m_pConnection->Close();

	if(FAILED(hr))
	{
		return false;
	}

	return true;
}


_RecordsetPtr  CWXDBConnect::ExecText(std::string strText)
{
	m_pCommandPtr->ActiveConnection = m_pConnection;  
	m_pCommandPtr->CommandText = strText.c_str();  
	m_pCommandPtr->CommandType = adCmdText;  

	return m_pCommandPtr->Execute(NULL,NULL,adCmdUnknown);  
}

//�趨�������
void CWXDBConnect::SetCmdParam(const std::vector<_variant_t>& vecVarParam) throw(...)
{
	//ˢ�´洢���̵Ĳ���
	m_pCommandPtr->Parameters->Refresh(); 
	//��������������ڴ洢���̵Ĳ�������ʱ���׳��쳣
	if(vecVarParam.size() > (unsigned long)(m_pCommandPtr->Parameters->Count-1))
	{
		throw("param count error");
	}	

	//�趨����
	for(unsigned long i=0; i<vecVarParam.size(); ++i)
	{
		m_pCommandPtr->Parameters->GetItem((long)(i+1))->Value = vecVarParam.at(i); 
	}
}

//���ô洢���� �����н���������� �����б�
_RecordsetPtr  CWXDBConnect::ExecStoredProc(std::string strStoredProcName, 
											const std::vector<_variant_t>& vecVarParam) throw(...)
{
	m_pCommandPtr->ActiveConnection = m_pConnection;  
	m_pCommandPtr->CommandText = _bstr_t(strStoredProcName.c_str());  
	m_pCommandPtr->CommandType = adCmdStoredProc;  

	//�趨�������
	this->SetCmdParam(vecVarParam);

	return m_pCommandPtr->Execute(NULL,NULL,adCmdStoredProc);  
}

//���ô洢���� ��������������� ���ر���
_variant_t CWXDBConnect::ExecStoredProc(std::string strStoredProc, 
								   const std::vector<_variant_t>& vecVarParam, 
								   std::vector<_variant_t>* pvecVarOutParam) throw(...)
{
	//���ô洢����
	this->ExecStoredProc(strStoredProc, vecVarParam);

	return this->GetParamRtn(pvecVarOutParam);
}

//��ò����ͷ���ֵ
_variant_t CWXDBConnect::GetParamRtn(std::vector<_variant_t>* pvecVarOutParam)
{	
	if(NULL!=pvecVarOutParam)
	{
		//�������
		for(long i=1; i<m_pCommandPtr->Parameters->Count; ++i)
		{
			pvecVarOutParam->push_back(m_pCommandPtr->Parameters->GetItem(i)->Value);
		}
	}

	//����ֵ
	_variant_t varRet;
	if(m_pCommandPtr->Parameters->Count>0)
	{
		varRet = m_pCommandPtr->Parameters->GetItem((long)(0))->Value;
	}
	else
	{
		varRet.Clear();
	}
	
	return varRet;
}

//�ж������Ƿ����仯
bool CWXDBConnect::isDataChange(std::string strStoredProc, 
	const std::vector<_variant_t>& vecVarParam, 
	const std::vector<_variant_t>& vecVarSrc) throw(...)
{
	std::vector<_variant_t> vecVarOutParam;

	this->ExecStoredProc(strStoredProc, vecVarParam, &vecVarOutParam);

	if(vecVarOutParam==vecVarSrc)
	{
		return false;
	}
	else
	{
		return true;
	}
}

