// CCreateNewChatOneToOne.cpp: 实现文件
//

#include "stdafx.h"
#include "starrtcdemo.h"
#include "CCreateNewChatOneToOne.h"
#include "afxdialogex.h"


// CCreateNewChatOneToOne 对话框

IMPLEMENT_DYNAMIC(CCreateNewChatOneToOne, CDialogEx)

CCreateNewChatOneToOne::CCreateNewChatOneToOne(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_CREATE_NEW_CHAT, pParent)
{
	m_strUserName = "";
}

CCreateNewChatOneToOne::~CCreateNewChatOneToOne()
{
}

void CCreateNewChatOneToOne::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_NEW_CHAT_DIS_USERNAME, m_userNameEdit);
}


BEGIN_MESSAGE_MAP(CCreateNewChatOneToOne, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_START_NEW_CHAT, &CCreateNewChatOneToOne::OnBnClickedButtonStartNewChat)
END_MESSAGE_MAP()


// CCreateNewChatOneToOne 消息处理程序


void CCreateNewChatOneToOne::OnBnClickedButtonStartNewChat()
{
	m_userNameEdit.GetWindowText(m_strUserName);
	if (m_strUserName == "")
	{
		AfxMessageBox("请输入对方用户名");
	}
	OnOK();
}
