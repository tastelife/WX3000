
// wxDoc.h : CwxDoc ��Ľӿ�
//


#pragma once


class CwxDoc : public CDocument
{
protected: // �������л�����
	CwxDoc();
	DECLARE_DYNCREATE(CwxDoc)

// ����
public:

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// ʵ��
public:
	virtual ~CwxDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};


