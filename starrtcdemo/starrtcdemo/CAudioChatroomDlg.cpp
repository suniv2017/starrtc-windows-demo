// CAudioChatroomDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "starrtcdemo.h"
#include "CAudioChatroomDlg.h"
#include "afxdialogex.h"


// CAudioChatroomDlg 对话框

IMPLEMENT_DYNAMIC(CAudioChatroomDlg, CDialogEx)

CAudioChatroomDlg::CAudioChatroomDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_AUDIO_CHATROOM, pParent)
{

}

CAudioChatroomDlg::~CAudioChatroomDlg()
{
}

void CAudioChatroomDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CAudioChatroomDlg, CDialogEx)
END_MESSAGE_MAP()


// CAudioChatroomDlg 消息处理程序
