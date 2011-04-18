//WXCommMacroCode.h
#pragma once

#include <string>
#include <sstream>

//指针类型转换
#define	WX_COMM_PONTCONVER(type, val)	((type*)(val))

//断言
#define	WX_COMM_ASSERT(except, classAssert)	WX_COMM_ASSERT_3(except, classAssert, "")
#define	WX_COMM_ASSERT_3(except, classAssert, strMsg)	\
	{\
		if(!(except))\
		{\
			std::string msg;\
			msg += __FILE__;\
			msg += "\t";\
			std::stringstream strStr;\
			strStr << __LINE__;\
			msg += strStr.str();\
			msg += "\t";\
			msg += __FUNCTION__;\
			msg += "\t";\
			msg += strMsg;\
			classAssert ass(msg);\
			throw(ass);\
		}\
	}

//整数做为型别
template<int v>
struct CWXCommInt2Type
{
    enum {value = v};
};

//功能处理类 用于函数内使用类
#define WX_COMM_FUN_IN_FUN_BY_CLASS_BEGIN class FUN\
	{\
	public:
#define WX_COMM_FUN_IN_FUN_BY_CLASS_END };
////说明：
////WX_COMM_FUN_IN_FUN_BY_CLASS_BEGIN;
////static bool xxx(CWXBNSMsgMsger* msger)
////{
////    std::cout << msger->GetNo() << std::endl;
////    return true;
////}
////WX_COMM_FUN_IN_FUN_BY_CLASS_END;
//////下属消息链进行处理
////std::for_each(this->m_lstMsger.begin(), this->m_lstMsger.end(),FUN::xxx);

//给类加属性 值传递　WX_COMM_ADD_ATTRIBUTE_0(int, No, n);
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
//给类加属性 引用传递　WX_COMM_ADD_ATTRIBUTE_1(std::string, Name, Str);
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
//给类加属性 数组 WX_COMM_ADD_ATTRIBUTE_2(char, Arr, ch, 1024);
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

