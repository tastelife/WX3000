#pragma once

#include <map>
#include<string>

class CWXComboBoxCtrl
{
public:
	CWXComboBoxCtrl(CComboBox* pList);
	virtual ~CWXComboBoxCtrl(void);
public:
	//枚举数据加入下拉框内容
	void EnumFillCmbBox(std::map<int, std::string>& enumList);
	void EnumFillCmbBox(std::map<int, std::string>&& enumList);
	//下拉框默认选中第一行
	void SelectFirstCmbBox();
	//下拉框通过附加数据选中
	void SelectCmbBoxByItem(int nItem);

private:
	CWXComboBoxCtrl(void);
public:
	//操作List
	CComboBox* m_pList;
};

