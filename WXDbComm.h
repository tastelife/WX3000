//WXDbComm.h
#pragma once

#include <vector>
#include "WXDBConnect.h"


//数据库命名空间
#define	NAMESPACE_DB_BEGIN	namespace WXDB{
#define NAMESPACE_DB_END	};

//自动生成数据库对应的结构体的变量,通过set<n> get<n>存取 
#define WX_COMM_STRUCT_MEM_VAR_SET_GET_USE(structName, viaMax) \
		typedef structName STRUCTNAME;\
		template<int nPos>\
		class SetClass;\
		template<int nPos>\
		void Set(const _variant_t& varData)\
		{\
			SetClass<nPos>()(this, varData);\
		}\
		\
		template<int nPos>\
		class GetClass;\
		template<int nPos>\
		_variant_t Get() const\
		{\
			return GetClass<nPos>()(this);\
		}\
		enum\
		{\
		E_VIA_MAX = viaMax\
		}

#define WX_COMM_STRUCT_MEM_VAR_SET_GET_ADD(type, name, pos) \
		type name;\
		template<>\
		class SetClass<pos>\
		{\
		public:\
			void operator()(STRUCTNAME* stru, const _variant_t& varData)\
			{\
				stru->name = CWXGetVariantValue<type>()(varData);\
			}\
		};\
		\
		template<>\
		class GetClass<pos>\
		{\
		public:\
			_variant_t operator()(const STRUCTNAME* stru)\
			{\
				return CWXSetVariantValue<type>()(stru->name);\
			}\
		};
//可变变量与指定类型不匹配时，set时成员变量设定为默认值
#define WX_COMM_STRUCT_MEM_VAR_SET_GET_ADD_DEFAULT(type, name, pos, tDefault) \
		type name;\
		template<>\
		class SetClass<pos>\
		{\
		public:\
			void operator()(STRUCTNAME* stru, const _variant_t& varData)\
			{\
				stru->name = CWXGetVariantValue<type>()(varData, tDefault);\
			}\
		};\
		\
		template<>\
		class GetClass<pos>\
		{\
		public:\
			_variant_t operator()(const STRUCTNAME* stru)\
			{\
				return CWXSetVariantValue<type>()(stru->name);\
			}\
		};

//数据库对应的结构体与vector<_variant_t>的转换
//T to vector<_variant_t>
template<typename T, int nCount=T::E_VIA_MAX>
class CWXDBdataToVecVar
{
public:
	std::vector<_variant_t>* operator()(const T& tData, std::vector<_variant_t>& vecVar)
	{
		CWXDBdataToVecVar<T, nCount-1>()(const_cast<T&>(tData), vecVar);

		vecVar.push_back(tData.Get<nCount>());

		return &vecVar;
	}
};
template<typename T>
class CWXDBdataToVecVar<T, 0>
{
public:

	std::vector<_variant_t>* operator()(const T& tData, std::vector<_variant_t>& vecVar)
	{
		vecVar.push_back(tData.Get<0>());

		return &vecVar;
	}
};
//vector<_variant_t> to T
template<typename T, int nCount=T::E_VIA_MAX>
class CWXVecVarToDBdata
{
public:
	T* operator()(const std::vector<_variant_t>& vecVar, T& tData)
	{
		CWXVecVarToDBdata<T, nCount-1>()(const_cast<std::vector<_variant_t>&>(vecVar), tData);

		tData.Set<nCount>(vecVar.at(nCount));

		return &tData;
	}
};
template<typename T>
class CWXVecVarToDBdata<T, 0>
{
public:
	T* operator()(const std::vector<_variant_t>& vecVar, T& tData)
	{
		tData.Set<0>(vecVar.at(0));

		return &tData;
	}
};


//数据库对应的结构体与_RecordsetPtr的转换
template<typename T, int nCount=T::E_VIA_MAX>
class CWXRecordsetPtrToDBdata
{
public:
	T* operator()(const _RecordsetPtr& rec, T& tData)
	{
		CWXRecordsetPtrToDBdata<T, nCount-1>()(const_cast<_RecordsetPtr&>(rec), tData);

		tData.Set<nCount>(rec->GetCollect((long)nCount));

		return &tData;
	}
};
template<typename T>
class CWXRecordsetPtrToDBdata<T, 0>
{
public:
	T* operator()(const _RecordsetPtr& rec, T& tData)
	{
		tData.Set<0>(rec->GetCollect((long)0));

		return &tData;
	}
};


//数据库对应的结构体列表与_RecordsetPtr的转换
template<typename T, int nCount=T::E_VIA_MAX>
class CWXRecordsetPtrToVecDBdata
{
public:
	bool operator()(const _RecordsetPtr& rec, std::vector<T>& vecData)
	{
		if(rec->adoEOF||rec->BOF)
		{
			return true;
		}

		if(FAILED(rec->MoveFirst()))
		{
			return false;
		}

		T tData;

		while((!rec->adoEOF)&&(!rec->BOF))
		{
			CWXRecordsetPtrToDBdata<T, nCount>()(rec, tData);
			vecData.push_back(tData);

			if(FAILED(rec->MoveNext()))
			{
				return false;
			}
		}

		return true;
	}
};



//PROCEDURE [dbo].[Login45](
//    -- Add the parameters for the stored procedure here
//  @loginName nchar(20),
//  @passWord  int,
//  @empId     int out)
//AS
//BEGIN
//    -- SET NOCOUNT ON added to prevent extra result sets from
//    -- interfering with SELECT statements.
//    SET NOCOUNT ON;
//
//    -- Insert statements for procedure here
//    SELECT @empId=TOHOSPITAL_ID from  TOHOSPITAL_TBL where TH_PATIENT_ID = @passWord
//    SELECT UPDATER, TOHOSPITAL_ID,  TH_STATUS from  TOHOSPITAL_TBL
//
//    
//    return @@rowcount
//END

//
//struct DBdata
//{
//	WX_COMM_STRUCT_MEM_VAR_SET_GET_USE(DBdata, 2);
//
////	WX_COMM_STRUCT_MEM_VAR_SET_GET_ADD(std::string, _name, 0);
//	WX_COMM_STRUCT_MEM_VAR_SET_GET_ADD_DEFAULT(std::string, _name, 0, "-1-");
//	WX_COMM_STRUCT_MEM_VAR_SET_GET_ADD(int, _NO, 1);
//	WX_COMM_STRUCT_MEM_VAR_SET_GET_ADD(int, _NOq, 2);
//};


//CoInitialize(NULL);

//DBdata data;
//data.Set<1>(_variant_t((int)2));
//data.Set<2>(_variant_t((int)133));
//data.Set<0>(_variant_t("sss"));

//std::vector<_variant_t> vecVarParam;
//CWXDBdataToVecVar<DBdata, 2>()(data, vecVarParam);

//CWXDBConnect db;
//db.SetSQLConcetText(("Provider=SQLOLEDB; Server=7BWZ82X_win7pro\\uboxc;Database=MK_UboxChs; uid=sa; pwd=U-BOXc1921#;"));
//if(!db.Open())
//{
//	std::cout<< "open error" << endl;
//}

//std::vector<_variant_t> vecVarOutParam;
//_variant_t ret = db.ExecStoredProc("Login45",vecVarParam, &vecVarOutParam);

//CWXVecVarToDBdata<DBdata, 2>()(vecVarOutParam, data);
//cout << data._name.c_str() << "   " << data._NO << "   " << data._NOq << endl;

//_RecordsetPtr rec = db.ExecStoredProc("Login45",vecVarParam);

//vector<DBdata> vecData;
//CWXRecordsetPtrToVecDBdata<DBdata, 2>()(rec, vecData);
//for(unsigned int i=0; i<vecData.size(); ++i)
//{
//	data = vecData.at(i);
//	cout << data._name.c_str() << "   " << data._NO << "   " << data._NOq << endl;
//}

//CoUninitialize();