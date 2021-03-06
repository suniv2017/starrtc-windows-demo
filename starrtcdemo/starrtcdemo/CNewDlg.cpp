// CNewDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "starrtcdemo.h"
#include "CNewDlg.h"
#include "afxdialogex.h"


// CNewDlg 对话框

IMPLEMENT_DYNAMIC(CNewDlg, CDialogEx)

CNewDlg::CNewDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_NEW_DLG, pParent)
{
	m_strTitle = "";
	m_strContent = "";
	m_strText = "";
	m_strSureButton = "";
}

CNewDlg::~CNewDlg()
{
}

void CNewDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_NEW_TEXT, m_Text);
	DDX_Control(pDX, IDC_EDIT_NEW_CONTENT, m_edit);
	DDX_Control(pDX, IDC_BUTTON_START_NEW, m_SureButton);
}


BEGIN_MESSAGE_MAP(CNewDlg, CDialogEx)

	ON_BN_CLICKED(IDC_BUTTON_START_NEW, &CNewDlg::OnBnClickedButtonStartNew)
END_MESSAGE_MAP()


// CNewDlg 消息处理程序



void CNewDlg::OnBnClickedButtonStartNew()
{
	m_edit.GetWindowText(m_strContent);
	if (m_strContent == "")
	{
		AfxMessageBox("输入为空");
	}
	OnOK();
}


BOOL CNewDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	SetWindowText(m_strTitle);
	m_Text.SetWindowText(m_strText);
	m_SureButton.SetWindowText(m_strSureButton);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
