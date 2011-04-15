//WXMemDataVector.h
#pragma once

#include <vector>

template<class _Ty>
class CWXMemDataVector : public std::vector<_Ty>
{
public:
	CWXMemDataVector()
	{
	}
	~CWXMemDataVector()
	{
	}

	inline	void Add(const _Ty& tNewData)
	{
		push_back(tNewData);
	}


	//删除
	inline int Delete(const _Ty& tCurrent)
	{
		int nRtn = 0;

		for(int i=size()-1; i>=0; --i)
		{
			if(tCurrent==(at(i)))
			{
				erase(begin()+i);

				++nRtn;
			}
		}

		return nRtn;
	}
	//删除 pred
	template<class _Pr>
	inline int Delete(_Pr pred)
	{
		int nRtn = 0;

		for(int i=size()-1; i>=0; --i)
		{
			if(pred(at(i)))
			{
				erase(begin()+i);

				++nRtn;
			}
		}

		return nRtn;
	}

	//编辑
	inline int Edit(const _Ty& tCurrent, const _Ty& tEdit)
	{
		int nRtn = 0;

		for(iterator iter = begin(); iter!=end(); ++iter)
		{
			if(tCurrent==(*iter))
			{
				*iter = tEdit;

				++nRtn;
			}
		}

		return nRtn;
	}
	//编辑 pred
	template<class _Pr>
	inline int Edit(const _Ty& tEdit, _Pr pred)
	{
		int nRtn = 0;

		for(iterator iter = begin(); iter!=end(); ++iter)
		{
			if(pred(*iter))
			{
				*iter = tEdit;

				++nRtn;
			}
		}

		return nRtn;
	}

	//查找
	inline int Find(const _Ty& tCurrent, CWXMemDataVector<_Ty>& memDataVec)
	{
		int nRtn = 0;

		for(iterator iter=begin(); iter!=end(); ++iter)
		{
			if(tCurrent==(*iter))
			{
				memDataVec.push_back(*iter);

				++nRtn;
			}
		}

		return nRtn;
	}
	//查找 pred
	template<class _Pr>
	inline int Find(_Pr pred, CWXMemDataVector<_Ty>& memDataVec)
	{
		int nRtn = 0;

		for(iterator iter=begin(); iter!=end(); ++iter)
		{
			if(pred(*iter))
			{
				memDataVec.push_back(*iter);

				++nRtn;
			}
		}

		return nRtn;
	}
	
	//查找,返回找到的第一个 pred
	template<class _Pr>
	bool Find(_Pr pred, _Ty& data)
	{
		for(iterator iter=begin(); iter!=end(); ++iter)
		{
			if(pred(*iter))
			{
				data = *iter;
				return true;
			}
		}

		return false;
	}
};

