//==========================================================
// Author: Borodenko Oleg
// 05/11/2008 <oktamail@gmail.com>
//==========================================================
// 
#pragma once
/////////////////////////////////////////////////////////////////////////////
#include "OutlookTabCtrl.h"
#include "..\Resource.h"
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
// 
class OutlookTabCtrlEx : public OutlookTabCtrl
{private:
	DECLARE_DYNCREATE(OutlookTabCtrlEx)

private:
	virtual void ShowMenu(CRect const *prcButtonMenu);

protected:
	DECLARE_MESSAGE_MAP()
	afx_msg void OnPop();
	afx_msg void OnPush();
	afx_msg void OnManage();
};
/////////////////////////////////////////////////////////////////////////////
// 
class OutlookTabCtrlCmdDialog : public CDialog
{public:
	OutlookTabCtrlCmdDialog(OutlookTabCtrlEx *pTabCtrl, vector<HTAB> *pvtrtabs);

private:
	OutlookTabCtrlEx *m_pTabCtrl;
	CImageList m_ImageList;
		// 
	vector<HTAB> *m_pvtritems;
	typedef vector<HTAB>::iterator m_i_vtritems;

private:
	void FillList();
	int GetSelectListItem();
	void SelectListItem(int idx);

protected:
	DECLARE_MESSAGE_MAP()
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnBnClickedUp();
	afx_msg void OnBnClickedDown();
	afx_msg void OnBnClickedReset();
};
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////



























