#include "StdAfx.h"
#include "WXDBConnect.h"

CWXDBConnect::CWXDBConnect(void)
{
	//初始化Connection指针
	m_pConnection = NULL;
	//初始化m_pCommandPtr指针
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

//初始化
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

//设定输入参数
void CWXDBConnect::SetCmdParam(const std::vector<_variant_t>& vecVarParam) throw(...)
{
	//刷新存储过程的参数
	m_pCommandPtr->Parameters->Refresh(); 
	//输入参数个数大于存储过程的参数个数时，抛出异常
	if(vecVarParam.size() > (unsigned long)(m_pCommandPtr->Parameters->Count-1))
	{
		throw("param count error");
	}	

	//设定参数
	for(unsigned long i=0; i<vecVarParam.size(); ++i)
	{
		m_pCommandPtr->Parameters->GetItem((long)(i+1))->Value = vecVarParam.at(i); 
	}
}

//调用存储过程 参数中仅有输入参数 返回列表
_RecordsetPtr  CWXDBConnect::ExecStoredProc(std::string strStoredProcName, 
											const std::vector<_variant_t>& vecVarParam) throw(...)
{
	m_pCommandPtr->ActiveConnection = m_pConnection;  
	m_pCommandPtr->CommandText = _bstr_t(strStoredProcName.c_str());  
	m_pCommandPtr->CommandType = adCmdStoredProc;  

	//设定输入参数
	this->SetCmdParam(vecVarParam);

	return m_pCommandPtr->Execute(NULL,NULL,adCmdStoredProc);  
}

//调用存储过程 参数中有输出参数 返回变量
_variant_t CWXDBConnect::ExecStoredProc(std::string strStoredProc, 
								   const std::vector<_variant_t>& vecVarParam, 
								   std::vector<_variant_t>* pvecVarOutParam) throw(...)
{
	//调用存储过程
	this->ExecStoredProc(strStoredProc, vecVarParam);

	return this->GetParamRtn(pvecVarOutParam);
}

//获得参数和返回值
_variant_t CWXDBConnect::GetParamRtn(std::vector<_variant_t>* pvecVarOutParam)
{	
	if(NULL!=pvecVarOutParam)
	{
		//保存参数
		for(long i=1; i<m_pCommandPtr->Parameters->Count; ++i)
		{
			pvecVarOutParam->push_back(m_pCommandPtr->Parameters->GetItem(i)->Value);
		}
	}

	//返回值
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

//判断数据是否发生变化
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

