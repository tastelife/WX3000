#pragma once

#import "C:\Program Files\common files\system\ado\msado15.dll" no_namespace rename("EOF","adoEOF")

#include "WXCommMacroCode.h"
#include <string>
#include <vector>

class CWXDBConnect
{
public:
	CWXDBConnect(void);
	~CWXDBConnect(void);

	//初始化
	void Init();

	//打开数据库
	bool Open();

	//执行SQL
	_RecordsetPtr ExecText(std::string strText);

	//调用存储过程 参数中仅有输入参数 返回列表
	_RecordsetPtr ExecStoredProc(std::string strStoredProc, 
		const std::vector<_variant_t>& vecVarParam) throw(...);
	//调用存储过程 参数中有输出参数 返回变量
	_variant_t ExecStoredProc(std::string strStoredProc, 
		const std::vector<_variant_t>& vecVarParam, 
		std::vector<_variant_t>* pvecVarOutParam) throw(...);
	//判断数据是否发生变化
	bool isDataChange(std::string strStoredProc, 
		const std::vector<_variant_t>& vecVarParam, 
		const std::vector<_variant_t>& vecVarSrc) throw(...);
	//判断数据是否发生变化 pred判断数据是否相等，相等返回true
	template<class _Pr> 
	inline bool isDataChange(std::string strStoredProc, 
		const std::vector<_variant_t>& vecVarParam, 
		_Pr pred) throw(...);

	//关闭数据库
	bool Close();

private:
	_ConnectionPtr m_pConnection;
	_CommandPtr m_pCommandPtr;

	//"Provider=SQLOLEDB; Server=127.0.0.1\\uboxc;Database=MK_UboxChs; uid=user; pwd=****;"
	WX_COMM_ADD_ATTRIBUTE_0(std::string, SQLConcetText, str);

	//设定输入参数
	void SetCmdParam(const std::vector<_variant_t>& vecVarParam) throw(...);
	//获得参数和返回值
	_variant_t GetParamRtn(std::vector<_variant_t>* pvecVarOutParam);
};

//判断数据是否发生变化 pred判断数据是否相等，相等返回true
template<class _Pr> 
inline bool CWXDBConnect::isDataChange(std::string strStoredProc, 
	const std::vector<_variant_t>& vecVarParam, 
	_Pr pred) throw(...)
{
	std::vector<_variant_t> vecVarOutParam;

	this->ExecStoredProc(strStoredProc, vecVarParam, &vecVarOutParam);

	return !pred(vecVarOutParam);
}
