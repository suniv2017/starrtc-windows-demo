#pragma once
#include "CProcessInfo.h"
#include "CLiveProgram.h"
#include "CUserManager.h"
#include "CDataShowView.h"
#include "CDataControl.h"
#include "XHLiveManager.h"
#include "CSoundManager.h"
#include "ILiveManagerListener.h"
#include "IChatroomGetListListener.h"
#include "CConfigManager.h"
// CInteracteLiveDlg 对话框

/*
 * 互动直播对话框
 */
class CInteracteLiveDlg : public CDialogEx, public CLocalDataControl, public CPicControlCallback, public ILiveManagerListener, public IChatroomGetListListener, public ISoundCallback
{
	DECLARE_DYNAMIC(CInteracteLiveDlg)

public:
	CInteracteLiveDlg(CUserManager* pUserManager, CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CInteracteLiveDlg();

	// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_LIVE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()

public:
	/**
	 * 查询聊天室列表回调
	 */
	virtual int chatroomQueryAllListOK(list<ChatroomInfo>& listData);
	/*
	 * 获取直播列表
	 */
	void getLiveList();

	afx_msg LRESULT OnRecvLiveMsg(WPARAM wParam, LPARAM lParam);

	/*
	 * 刷新列表
	 */
	afx_msg void OnBnClickedButtonLiveBrushList();
	/*
	 * 关闭当前直播
	 */
	afx_msg LRESULT setShowPictures(WPARAM wParam, LPARAM lParam);
	/*
	 * 绘制
	 */
	afx_msg void OnPaint();

	/*
	 * 销毁函数
	 */
	afx_msg void OnDestroy();
	/*
	 * 创建新直播
	 */
	afx_msg void OnBnClickedButtonCreateNewLive();
	/*
	 * 初始化对话框
	 */
	virtual BOOL OnInitDialog();
	
	/*
	 * 查询直播内容
	 */
	CLiveProgram* getLiveProgram(CString strId, CString strName, CString strCreator);
	void setConfig(CConfigManager* pConfig);
public:
	// picture control 回调函数
	virtual void changeShowStyle(string strUserId);
	virtual void closeCurrentLive();

public:
	// start回调函数
	/**
	 * 有主播加入
	 * @param liveID 直播ID
	 * @param actorID 新加入的主播ID
	 */
	virtual void onActorJoined(string liveID, string actorID);

	/**
	 * 有主播离开
	 * @param liveID 直播ID
	 * @param actorID 离开的主播ID
	 */
	virtual void onActorLeft(string liveID, string actorID);

	/**
	 * 房主收到其他用户的连麦申请
	 * @param liveID
	 * @param applyUserID
	 */
	virtual void onApplyBroadcast(string liveID, string applyUserID);

	/**
	 * 申请连麦用户收到的回复
	 * @param liveID
	 * @param result
	 */
	virtual void onApplyResponsed(string liveID, bool bAgree);

	/**
	* 普通用户收到连麦邀请
	* @param liveID 直播ID
	* @param applyUserID 发出邀请的人的ID（主播ID）
	*/
	virtual void onInviteBroadcast(string liveID, string applyUserID);

	/**
	 * 主播收到的邀请连麦结果
	 * @param liveID 直播ID
	 * @param result 邀请结果
	 */
	virtual void onInviteResponsed(string liveID);

	/**
	 * 一些异常情况引起的出错，请在收到该回调后主动断开直播
	 * @param liveID 直播ID
	 * @param error 错误信息
	 */
	virtual void onLiveError(string liveID, string error);

	/**
	 * 聊天室成员数变化
	 * @param number
	 */
	virtual void onMembersUpdated(int number);

	/**
	 * 自己被踢出聊天室
	 */
	virtual void onSelfKicked();

	/**
	 * 自己被踢出聊天室
	 */
	virtual void onSelfMuted(int seconds);

	/**
	 * 连麦者的连麦被强制停止
	 * @param liveID 直播ID
	 */
	virtual void onCommandToStopPlay(string  liveID);

	/**
	 * 收到消息
	 * @param message
	 */
	virtual void onReceivedMessage(CIMMessage* pMessage);

	/**
	 * 收到私信消息
	 * @param message
	 */
	virtual void onReceivePrivateMessage(CIMMessage* pMessage);

	virtual int getRealtimeData(string strUserId, uint8_t* data, int len);
	virtual int getVideoRaw(string strUserId, int w, int h, uint8_t* videoData, int videoDataLen);
public:
	virtual void addUpId();
	virtual void insertVideoRaw(uint8_t* videoData, int dataLen, int isBig);
	virtual int cropVideoRawNV12(int w, int h, uint8_t* videoData, int dataLen, int yuvProcessPlan, int rotation, int needMirror, uint8_t* outVideoDataBig, uint8_t* outVideoDataSmall);
	virtual void drawPic(YUV_TYPE type, int w, int h, uint8_t* videoData, int videoDataLen);
public:
	virtual void getLocalSoundData(char* pData, int nLength);
	virtual void querySoundData(char** pData, int* nLength);
public:
	CListBox m_liveList;
	CDataShowView* m_pDataShowView;
	CUserManager* m_pUserManager;
	CConfigManager* m_pConfig;

	XHLiveManager* m_pLiveManager;
	CSoundManager* m_pSoundManager;
	vector<CLiveProgram> mVLivePrograms;
	CLiveProgram* m_pCurrentLive;
	HANDLE m_hSetShowPicThread;
	HANDLE m_hSetShowPicEvent;

	int m_nUpId;

	CStatic m_ShowArea;
	CListCtrl m_liveListListControl;
	afx_msg void OnNMClickList2(NMHDR *pNMHDR, LRESULT *pResult);
	CButton m_ApplyUploadButton;
	afx_msg void OnBnClickedButtonLiveApplyUpload();
	afx_msg void OnBnClickedButtonLiveExitUpload();
	CButton m_ExitUpload;
};
