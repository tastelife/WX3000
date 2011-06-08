//WXCommFun.h
#pragma once
#include "WXCommMacroCode.h"
#include <algorithm>
#include <COMUTIL.H>
#include <string>
#include <sstream>


//输出日志记录函数轨迹
#define	WX_COMM_FUN_TRAJECTORY(nModule)	\
	{\
		std::string msg;\
		msg += __FILE__;\
		msg += "\t";\
		std::stringstream strStr;\
		strStr << __LINE__;\
		msg += "行号:";\
		msg += strStr.str();\
		msg += "\t";\
		msg += "函数:";\
		msg +=  __FUNCTION__;\
		CWXLogOutSingle::Init()->Output(0, nModule, msg.c_str(), NULL, 0, 3);\
	}


//异常抛出类
class CWXCommThrow
{
public:
	CWXCommThrow();
	CWXCommThrow(int nNo, std::string strMsg="");
	CWXCommThrow(CWXCommThrow& comThrow);
	~CWXCommThrow();
private:
	WX_COMM_ADD_ATTRIBUTE_0(std::string, Msg, str);
	WX_COMM_ADD_ATTRIBUTE_0(int, No, n);
};
//断言异常抛出类
class CWXCommAssertThrow : public CWXCommThrow
{
public:
	CWXCommAssertThrow(std::string fileAndLine);
	CWXCommAssertThrow(CWXCommAssertThrow& assertThrow);
	~CWXCommAssertThrow();
};

//生成单件类的基类
template<class S, class T = CWXCommInt2Type<0> >
class CWXCommSingleClass
{
public:
    static S* Init()
    {
        static S s;

        return &s;
    }
};
////说明：
////根据要产生单件类的类名和传入的数字共同确定单件类
////#define WX_M1            1
////#define WX_M2            2
////
////class WX
////{
////public:
////    int m_n;
////};
////
////class A : public CWXCommSingleClass<WX, Int2Type<WX_M1> >
////{
////};
////class B : public CWXCommSingleClass<WX> //相当于 <WX, Int2Type<0> >
////{
////};

//常用类型转换
class CWXConver
{
public:
	//string to wstring
	static std::wstring s2ws(const std::string str);
	//wstring to string
	static std::string ws2s(const std::wstring& wstr);
	//single type to string
	template <typename T>
	static std::string single2s(const T t)
	{
		std::string rtnStr;
		std::stringstream sstr;

		sstr << t;
		sstr >> rtnStr;

		return rtnStr;
	}
	//date to string
	static std::string date2s(DATE date, std::string strFormat="%Y-%m-%d %H:%M");

	//自定义的业务、数据类型的转换	
	template<class SRC, class OBJ, int nSrcBegin, int nObjBegin, int nCount>
	class CBnsDbConver
	{
	public:
		void operator()(const SRC& src, OBJ& obj)
		{
			obj.Set<nObjBegin>(src.Get<nSrcBegin>());

			CBnsDbConver<SRC, OBJ, nSrcBegin+1, nObjBegin+1, nCount-1>()(src, obj);
		}
	};
	template<class SRC, class OBJ, int nSrcBegin, int nObjBegin>
	class CBnsDbConver<SRC, OBJ, nSrcBegin, nObjBegin,1>
	{
	public:
		void operator()(const SRC& src, OBJ& obj)
		{
			obj.Set<nObjBegin>(src.Get<nSrcBegin>());				
		}
	};
	template<class SRC, class OBJ, int nSrcBegin, int nObjBegin, int nCount>
	static void BnsDbConver(const SRC& src, OBJ& obj)
	{

		CBnsDbConver<SRC, OBJ, nSrcBegin+1, nObjBegin+1, nCount-1>()(src, obj);
	}

private:
	static wchar_t* Char2WChar(const char* p);
	static char* WChar2Char(const wchar_t* pw);

};

//浮点数的比较 std::cout << (CWXCommDoubleCmp(1.01)>(1.01-(1.00e-07)*2)) << std::endl;
#define WX_COMM_EPSILON                1.00e-07
class CWXCommDoubleCmp
{
public:
	CWXCommDoubleCmp(double lfData)
	{
		m_lfData = lfData;
	}

	bool CmpMh (double lfCmp)
	{
		return m_lfData > lfCmp+WX_COMM_EPSILON;
	}

	bool CmpLh (double lfCmp)
	{
		return m_lfData < lfCmp-WX_COMM_EPSILON;
	}

	bool operator > (double lfCmp)
	{
		return CmpMh(lfCmp);
	}

	bool operator < (double lfCmp)
	{
		return CmpLh(lfCmp);
	}

	bool operator = (double lfCmp)
	{
		return (!CmpMh(lfCmp))&&(!CmpLh(lfCmp));
	}

	bool operator >= (double lfCmp)
	{
		return !CmpLh(lfCmp);
	}

	bool operator <= (double lfCmp)
	{
		return !CmpMh(lfCmp);
	}


private:
	double m_lfData;
};
#undef    WX_COMM_EPSILON



#define WX_COMM_VAR_TYPE_ERR                ("获取类型与传入类型不一致")

//可变变量的值的取
template <typename R>
class CWXGetVariantValue;
//string
template<>
class CWXGetVariantValue <std::string>
{
public:
	std::string operator ()(const _variant_t& varData) throw(...)
	{
		if (VT_BSTR==varData.vt)
		{
			return std::string((char *)((_bstr_t)varData));
		}
		else
		{
			throw std::string(WX_COMM_VAR_TYPE_ERR);
		}
	}
	
	std::string operator ()(const _variant_t& varData, std::string strDefault) throw()
	{
		if (VT_BSTR==varData.vt)
		{
			return std::string((char *)((_bstr_t)varData));
		}
		else
		{
			return strDefault;
		}
	}
};
//int
template<>
class CWXGetVariantValue <int>
{
public:
	int operator ()(const _variant_t& varData) throw(...)
	{
		if ((VT_I4==varData.vt)||(VT_INT==varData.vt))
		{
			return varData.lVal;
		}
		else
		{
			throw std::string(WX_COMM_VAR_TYPE_ERR);
		}
	}
	
	int operator ()(const _variant_t& varData, int nDefault) throw()
	{
		if ((VT_I4==varData.vt)||(VT_INT==varData.vt))
		{
			return varData.lVal;
		}
		else
		{
			return nDefault;
		}
	}
};

//short
template<>
class CWXGetVariantValue <short>
{
public:
	short operator ()(const _variant_t& varData) throw(...)
	{
		if (VT_I2==varData.vt)
		{
			return varData.iVal;
		}
		else
		{
			throw std::string(WX_COMM_VAR_TYPE_ERR);
		}
	}
	
	short operator ()(const _variant_t& varData, short nDefault) throw()
	{
		if (VT_I2==varData.vt)
		{
			return varData.iVal;
		}
		else
		{
			return nDefault;
		}
	}
};

//date
template<>
class CWXGetVariantValue <DATE>
{
public:
	DATE operator ()(const _variant_t& varData) throw(...)
	{
		if (VT_DATE==varData.vt)
		{
			return varData.date;
		}
		else
		{
			throw std::string(WX_COMM_VAR_TYPE_ERR);
		}
	}
	
	DATE operator ()(const _variant_t& varData, DATE dateDefault) throw()
	{
		if (VT_DATE==varData.vt)
		{
			return varData.date;
		}
		else
		{
			return dateDefault;
		}
	}
};

namespace WXDB 
{

	enum E_DICTIONARY_FUNCTIONPOINTPOWER
	{
		E_DICTIONARY_FUNCTIONPOINTPOWER_CREATE				 = 1,
		E_DICTIONARY_FUNCTIONPOINTPOWER_DELETE				 = 2,
		E_DICTIONARY_FUNCTIONPOINTPOWER_EDIT				 = 4,
		E_DICTIONARY_FUNCTIONPOINTPOWER_READ				 = 8,
	};
	struct Power
	{
		int _nPower;

		bool IsCreatePower()
		{
			return (_nPower&E_DICTIONARY_FUNCTIONPOINTPOWER_CREATE)!=0;
		}
		void SetCreatePower(bool bPower)
		{
			if(bPower)
			{
				_nPower = _nPower|E_DICTIONARY_FUNCTIONPOINTPOWER_CREATE;
			}
			else
			{
				_nPower = _nPower&(~E_DICTIONARY_FUNCTIONPOINTPOWER_CREATE);
			}
		}

		bool IsDeletePower()
		{
			return (_nPower&E_DICTIONARY_FUNCTIONPOINTPOWER_DELETE)!=0;
		}
		void SetDeletePower(bool bPower)
		{
			if(bPower)
			{
				_nPower = _nPower|E_DICTIONARY_FUNCTIONPOINTPOWER_DELETE;
			}
			else
			{
				_nPower = _nPower&(~E_DICTIONARY_FUNCTIONPOINTPOWER_DELETE);
			}
		}

		bool IsEditPower()
		{
			return (_nPower&E_DICTIONARY_FUNCTIONPOINTPOWER_EDIT)!=0;
		}
		void SetEditPower(bool bPower)
		{
			if(bPower)
			{
				_nPower = _nPower|E_DICTIONARY_FUNCTIONPOINTPOWER_EDIT;
			}
			else
			{
				_nPower = _nPower&(~E_DICTIONARY_FUNCTIONPOINTPOWER_EDIT);
			}
		}

		bool IsReadPower()
		{
			return (_nPower&E_DICTIONARY_FUNCTIONPOINTPOWER_READ)!=0;
		}
		void SetReadPower(bool bPower)
		{
			if(bPower)
			{
				_nPower = _nPower|E_DICTIONARY_FUNCTIONPOINTPOWER_READ;
			}
			else
			{
				_nPower = _nPower&(~E_DICTIONARY_FUNCTIONPOINTPOWER_READ);
			}
		}

		Power()
		{
			_nPower = 0;
		}

		explicit Power(int nPower)
		{
			_nPower = nPower;
		}

		Power(const Power& power)
		{
			_nPower = power._nPower;
		}

	};

}

//WXDB::Power
template<>
class CWXGetVariantValue <WXDB::Power>
{
public:
	WXDB::Power operator ()(const _variant_t& varData) throw(...)
	{
		if ((VT_I4==varData.vt)||(VT_INT==varData.vt))
		{
			WXDB::Power power(varData.lVal);
			return power;
		}
		else
		{
			throw std::string(WX_COMM_VAR_TYPE_ERR);
		}
	}
	
	WXDB::Power operator ()(const _variant_t& varData, 
		WXDB::Power dateDefault) throw()
	{
		if ((VT_I4==varData.vt)||(VT_INT==varData.vt))
		{
			WXDB::Power power(varData.lVal);
			return power;
		}
		else
		{
			return dateDefault;
		}
	}
};
#undef WX_COMM_VAR_TYPE_ERR

//可变变量的值的存
template <typename T>
class CWXSetVariantValue
{
public:
	_variant_t operator ()(const T& tData)
	{
		return _variant_t(tData);
	}
};
//string
template <>
class CWXSetVariantValue <std::string>
{
public:
	_variant_t operator ()(const std::string& tData)
	{
		return _variant_t(tData.c_str());
	}
};

//WXDB::Power
template <>
class CWXSetVariantValue <WXDB::Power>
{
public:
	_variant_t operator ()(const WXDB::Power& tData)
	{
		return _variant_t(tData._nPower);
	}
};

class CWXFun
{
public:
	CWXFun();
	~CWXFun();


	static int GetIPMacHostName(std::string& strIP, std::string& strMac, std::string& strHostName);
	static int GetMacByCmd(std::string& strMac);
	static int GetIPHostName(std::string& strIP, std::string& strHostName);
};

