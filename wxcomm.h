#if !defined(AFX_TTEMPLATE_H__2A080896_4B61_4DD2_A462_61957D494003__INCLUDED_)
#define AFX_TTEMPLATE_H__2A080896_4B61_4DD2_A462_61957D494003__INCLUDED_

#include <algorithm>
#include <string>


    //给类加属性 值传递　WX_ADD_ATTRIBUTE_0(int, No, n);
#define WX_COMM_ADD_ATTRIBUTE_0(mtype, pn, pp) \
private:\
    mtype m_##pp##pn; \
public:\
    void Set##pn(mtype pp##pn) \
    {\
    m_##pp##pn = pp##pn;\
}\
    mtype Get##pn()\
    {\
    return m_##pp##pn;\
}
    //给类加属性 引用传递　WX_ADD_ATTRIBUTE_1(std::string, Name, Str);
#define WX_COMM_ADD_ATTRIBUTE_1(mtype, pn, pp) \
private:\
    mtype m_##pp##pn; \
public:\
    void Set##pn(mtype& pp##pn) \
    {\
    m_##pp##pn = pp##pn;\
}\
    mtype* Get##pn()\
    {\
    return &m_##pp##pn;\
}
    //给类加属性 数组 WX_ADD_ATTRIBUTE_2(char, Arr, ch, 1024);
#define WX_COMM_ADD_ATTRIBUTE_2(mtype, pn, pp, count) \
private:\
    mtype m_##pp##pn[count]; \
public:\
    void Set##pn(mtype pp##pn, int nPos) \
    {\
    m_##pp##pn[nPos] = pp##pn;\
}\
    void Set##pn(mtype* pp##pn, mtype* (*cpy)(mtype* pObj, const mtype* pSource)) \
    {\
    cpy(m_##pp##pn, pp##pn);\
}\
    void Set##pn(mtype* pp##pn, unsigned int nCount, \
    void* (*cpy)(void* pObj, const void* pSource, unsigned int nCount)) \
    {\
    cpy(m_##pp##pn, pp##pn, nCount);\
}\
    mtype* Get##pn()\
    {\
    return m_##pp##pn;\
}


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
	int operator ()(const _variant_t& varData) throw(...)
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
	
	int operator ()(const _variant_t& varData, short nDefault) throw()
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

class CFun
{
public:
	CFun();
	~CFun();


	static int GetIPMacName(std::string& strIP, std::string& strMac, std::string& strHostName)
	{   
		////////////////
		// 初始化 Windows sockets API. 要求版本为 version 1.1
		//
		WORD wVersionRequested = MAKEWORD(1, 1);
		WSADATA wsaData;
		if (WSAStartup(wVersionRequested, &wsaData)) {
			return -1;
		}

		//////////////////
		// 获得主机名.
		//
		char hostname[256];
		int res = gethostname(hostname, sizeof(hostname));
		if (res != 0) {
			return -1;
		}
		strHostName = hostname;
		////////////////
		// 根据主机名获取主机信息. 
		//
		hostent* pHostent = gethostbyname(hostname);
		if (pHostent==NULL) {
			return -1;
		}
		//////////////////
		// 解析返回的hostent信息.
		//
		hostent& he = *pHostent;
		printf("name=%s\naliases=%s\naddrtype=%d\nlength=%d\n",
			he.h_name, he.h_aliases, he.h_addrtype, he.h_length);

		sockaddr_in sa;
		for (int nAdapter=0; he.h_addr_list[nAdapter]; nAdapter++) {
			memcpy ( &sa.sin_addr.s_addr, he.h_addr_list[nAdapter],he.h_length);
			// 输出机器的IP地址.
			strIP += inet_ntoa(sa.sin_addr); 
			strIP += "  "; // 显示地址串
		}
		//////////////////
		// 终止 Windows sockets API
		//
		WSACleanup();

		return 0;
	}
};

#endif // !defined(AFX_TTEMPLATE_H__2A080896_4B61_4DD2_A462_61957D494003__INCLUDED_)