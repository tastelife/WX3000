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

	//��ʼ��
	void Init();

	//�����ݿ�
	bool Open();

	//ִ��SQL
	_RecordsetPtr ExecText(std::string strText);

	//���ô洢���� �����н���������� �����б�
	_RecordsetPtr ExecStoredProc(std::string strStoredProc, 
		const std::vector<_variant_t>& vecVarParam) throw(...);
	//���ô洢���� ��������������� ���ر���
	_variant_t ExecStoredProc(std::string strStoredProc, 
		const std::vector<_variant_t>& vecVarParam, 
		std::vector<_variant_t>* pvecVarOutParam) throw(...);
	//�ж������Ƿ����仯
	bool isDataChange(std::string strStoredProc, 
		const std::vector<_variant_t>& vecVarParam, 
		const std::vector<_variant_t>& vecVarSrc) throw(...);
	//�ж������Ƿ����仯 pred�ж������Ƿ���ȣ���ȷ���true
	template<class _Pr> 
	inline bool isDataChange(std::string strStoredProc, 
		const std::vector<_variant_t>& vecVarParam, 
		_Pr pred) throw(...);

	//�ر����ݿ�
	bool Close();

private:
	_ConnectionPtr m_pConnection;
	_CommandPtr m_pCommandPtr;

	//"Provider=SQLOLEDB; Server=127.0.0.1\\uboxc;Database=MK_UboxChs; uid=user; pwd=****;"
	WX_COMM_ADD_ATTRIBUTE_0(std::string, SQLConcetText, str);

	//�趨�������
	void SetCmdParam(const std::vector<_variant_t>& vecVarParam) throw(...);
	//��ò����ͷ���ֵ
	_variant_t GetParamRtn(std::vector<_variant_t>* pvecVarOutParam);
};

//�ж������Ƿ����仯 pred�ж������Ƿ���ȣ���ȷ���true
template<class _Pr> 
inline bool CWXDBConnect::isDataChange(std::string strStoredProc, 
	const std::vector<_variant_t>& vecVarParam, 
	_Pr pred) throw(...)
{
	std::vector<_variant_t> vecVarOutParam;

	this->ExecStoredProc(strStoredProc, vecVarParam, &vecVarOutParam);

	return !pred(vecVarOutParam);
}
