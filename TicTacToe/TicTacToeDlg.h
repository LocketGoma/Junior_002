// �����Ҽ��� ����
// TicTacToeDlg.h : ��� ����
// m_board ��������

#pragma once

#include "TicTacToeAI.h"
#include <iostream>
#include <queue>

#include <assert.h> // ����� ����

using namespace std;
// CTicTacToeDlg ��ȭ ����
class CTicTacToeDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CTicTacToeDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_TICTACTOE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnBnClickedButtonStart();
	afx_msg void OnBnClickedButtonInit();
	afx_msg void OnBnClickedButtonLoad();
	afx_msg void OnBnClickedButtonExit();
	afx_msg void OnBnClickedButtonUndoA();
	afx_msg void OnBnClickedButtonUndoB();

	afx_msg void OnBnClickedB1();
	afx_msg void OnBnClickedB2();
	afx_msg void OnBnClickedB3();
	afx_msg void OnBnClickedB4();
	afx_msg void OnBnClickedB5();
	afx_msg void OnBnClickedB6();
	afx_msg void OnBnClickedB7();
	afx_msg void OnBnClickedB8();
	afx_msg void OnBnClickedB9();
	afx_msg void OnBnClickedB10();
	afx_msg void OnBnClickedB11();
	afx_msg void OnBnClickedB12();
	afx_msg void OnBnClickedB13();
	afx_msg void OnBnClickedB14();
	afx_msg void OnBnClickedB15();
	afx_msg void OnBnClickedB16();


	virtual BOOL PreTranslateMessage(MSG* pMsg);	
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	HACCEL m_hAccelTable;
	CButton m_undoA;
	CButton m_undoB;	
	CComboBox m_comboA;
	CComboBox m_comboB;
	CEdit m_listA;
	CEdit m_listB;
	HBRUSH m_BKColor;

	/* ����� ���� �Լ� */

	void SetGame();			/* ���� �ʱ� ȭ�� ���� */
	int CheckReady();		/* ���� ���� �غ� ���¸� �˻� */
	int WaitUndo();			/* �����⸦ ��ٸ� */
	void UpdateGame();		/* ���� ���� ȭ�鿡 ������Ʈ */
	void ResetGame();		/* �������� �ٽ� �ʱ�ȭ */
	void PrintTreeNode(Node* root);	/* eval �� ������ ��� */
	void StartGame();			/* ���� ���� */
	void EndGame();				/* ���� ���� */
	void LoadGame();			/* ���� �ҷ����� */
	void SaveGame();			//----------------------- save ������ -------------------------------
	//int WaitPush();				//--------�Է±���
	void WaitPush();
	/*	����� ���� ���� */

	GameBoard m_board;		/* ���� ���� ���� */
	int m_levelA;			/* ��ǻ�� A�� LA-level */
	int m_levelB;			/* ��ǻ�� B�� LA-level */
	int m_startCom;			/* �����ϴ� COM ���� */
	int m_isLoad;			/* ������ �ε� �� ���� ���� */
	int m_checkUndo;		/* �����⸦ �ߴ��� ���� ���� */

	int m_inputposition;	//��� ��ġ�� ����������
	int m_clicked_check=0;	//�־���?

};
