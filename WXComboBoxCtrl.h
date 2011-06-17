#pragma once

#include <map>
#include<string>

class CWXComboBoxCtrl
{
public:
	CWXComboBoxCtrl(CComboBox* pList);
	virtual ~CWXComboBoxCtrl(void);
public:
	//ö�����ݼ�������������
	void EnumFillCmbBox(std::map<int, std::string>& enumList);
	void EnumFillCmbBox(std::map<int, std::string>&& enumList);
	//������Ĭ��ѡ�е�һ��
	void SelectFirstCmbBox();
	//������ͨ����������ѡ��
	void SelectCmbBoxByItem(int nItem);

private:
	CWXComboBoxCtrl(void);
public:
	//����List
	CComboBox* m_pList;
};

