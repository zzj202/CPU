
// CPUDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "CPU.h"
#include "CPUDlg.h"
#include "afxdialogex.h"

#include"fuzhu.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CCPUDlg 对话框



CCPUDlg::CCPUDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CPU_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCPUDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST3, m_list);
	DDX_Control(pDX, IDC_EDIT1, ed1);
	DDX_Control(pDX, IDC_EDIT2, ed2);
	DDX_Control(pDX, IDC_EDIT3, ed3);
}

BEGIN_MESSAGE_MAP(CCPUDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CCPUDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CCPUDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CCPUDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CCPUDlg::OnBnClickedButton4)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON5, &CCPUDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CCPUDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CCPUDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CCPUDlg::OnBnClickedButton8)
END_MESSAGE_MAP()


// CCPUDlg 消息处理程序

BOOL CCPUDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标




	// TODO: 在此添加额外的初始化代码
	HBRUSH   m_hbrush;
	m_hbrush = CreateSolidBrush(RGB(0, 0, 0));

	m_list.ModifyStyle(0, LVS_REPORT);
	GetDlgItem(IDC_BUTTON1)->EnableWindow(false);
	GetDlgItem(IDC_BUTTON2)->EnableWindow(false);
	GetDlgItem(IDC_BUTTON4)->EnableWindow(false);
	GetDlgItem(IDC_BUTTON3)->EnableWindow(false);
	GetDlgItem(IDC_BUTTON5)->EnableWindow(false);
	GetDlgItem(IDC_BUTTON7)->EnableWindow(false);
	GetDlgItem(IDC_BUTTON8)->EnableWindow(false);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CCPUDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CCPUDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CCPUDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CCPUDlg::OnBnClickedButton1()  //FCFS 
{
	suanfa = 1;
	CString str;
	GetDlgItem(IDC_BUTTON3)->EnableWindow(true);
	GetDlgItem(IDC_BUTTON5)->EnableWindow(true);
	while (j != vec.size() && vec[j].arrive_time <= mtime)
	{
		fvec.push_back(vec[j]);	 //得到某个时间之前所有的作业
		j++;
	}
	sort(fvec.begin(), fvec.end(), mcmp4);//fvec到达时间从大到小
	if (mtime == time1) //cpu1空闲
	{
		if (fvec.empty())//未有作业到达 cpu1的时间+1
		{
			time1++;
		}
		else //cpu1中加入作业 cpu1的时间变为该作业的结束时间
		{
			work tmp = fvec.back();
			time1 += tmp.running_time;
			tmp.end_time = time1;
			tmp.zz_time = time1 - tmp.arrive_time;
			tmp.dqzz_time = tmp.zz_time * 1.0 / tmp.running_time * 1.0;
			tmp.duilie = 1;
			tot_zz += tmp.zz_time;
			tot_dqzz += tmp.dqzz_time;
			ansvec.push_back(tmp);  //添加到vec
			fvec.pop_back();
		}
	}
	if (mtime == time2) //cpu2空闲
	{
		if (fvec.empty())//未有作业到达 cpu2的时间+1
		{
			time2++;
		}
		else //cpu2中加入作业 cpu1的时间变为该作业的结束时间
		{
			work tmp = fvec.back();
			time2 += tmp.running_time;
			tmp.end_time = time2;
			tmp.zz_time = time2 - tmp.arrive_time;
			tmp.dqzz_time = tmp.zz_time * 1.0 / tmp.running_time * 1.0;
			tmp.duilie = 2;
			tot_zz += tmp.zz_time;
			tot_dqzz += tmp.dqzz_time;
			ansvec.push_back(tmp); //添加到答案vec
			fvec.pop_back();
		}
	}
	while (m_list.GetCount() > 0)  //清空表
	{
		m_list.DeleteString(0);
	}

	for (auto it : ansvec)
	{
		CString ansstr;
		str.Format(L"%5c", it.name);
		ansstr += str;
		str.Format(L"%9d", it.duilie);
		ansstr += str;
		str.Format(L"%13d", it.arrive_time);
		ansstr += str;
		str.Format(L"%13d", it.running_time);
		ansstr += str;
		str.Format(L"%13d", it.end_time);
		ansstr += str;
		str.Format(L"%13d", it.zz_time);
		ansstr += str;
		str.Format(L"%15.2f", it.dqzz_time);
		ansstr += str;

		if (mtime <= it.end_time)
		{
			ansstr += "         正在执行！";
		}
		End = max(End, it.end_time);
		m_list.AddString(ansstr);
	}
	str.Format(L"%.2f", tot_zz / ansvec.size() * 1.0);
	GetDlgItem(IDC_STATIC3)->SetWindowTextW(str);
	str.Format(L"%.2f", tot_dqzz / ansvec.size() * 1.0);
	GetDlgItem(IDC_STATIC4)->SetWindowTextW(str);
	// TODO: 在此添加控件通知处理程序代码
}


void CCPUDlg::OnBnClickedButton2()  //SJF
{
	CString str;
	suanfa = 2;
	GetDlgItem(IDC_BUTTON3)->EnableWindow(true);
	GetDlgItem(IDC_BUTTON5)->EnableWindow(true);
	while (j != vec.size() && vec[j].arrive_time <= mtime)
	{
		fvec.push_back(vec[j]);	 //得到某个时间之前所有的作业
		j++;
	}
	sort(fvec.begin(), fvec.end(), mcmp2);//fvec运行时间从大到小
	if (mtime == time1) //cpu1空闲
	{
		if (fvec.empty())//未有作业到达 cpu1的时间+1
		{
			time1++;
		}
		else //cpu1中加入作业 cpu1的时间变为该作业的结束时间
		{
			work tmp = fvec.back();
			time1 += tmp.running_time;
			tmp.end_time = time1;
			tmp.zz_time = time1 - tmp.arrive_time;
			tmp.dqzz_time = tmp.zz_time * 1.0 / tmp.running_time * 1.0;
			tmp.duilie = 1;
			tot_zz += tmp.zz_time;
			tot_dqzz += tmp.dqzz_time;
			ansvec.push_back(tmp);  //添加到vec
			fvec.pop_back();
		}
	}
	if (mtime == time2) //cpu2空闲
	{
		if (fvec.empty())//未有作业到达 cpu2的时间+1
		{
			time2++;
		}
		else //cpu2中加入作业 cpu1的时间变为该作业的结束时间
		{
			work tmp = fvec.back();
			time2 += tmp.running_time;
			tmp.end_time = time2;
			tmp.zz_time = time2 - tmp.arrive_time;
			tmp.dqzz_time = tmp.zz_time * 1.0 / tmp.running_time * 1.0;
			tmp.duilie = 2;
			tot_zz += tmp.zz_time;
			tot_dqzz += tmp.dqzz_time;
			ansvec.push_back(tmp); //添加到答案vec
			fvec.pop_back();
		}
	}
	while (m_list.GetCount() > 0)  //清空表
	{
		m_list.DeleteString(0);
	}

	for (auto it : ansvec)
	{
		CString ansstr;
		str.Format(L"%5c", it.name);
		ansstr += str;
		str.Format(L"%9d", it.duilie);
		ansstr += str;
		str.Format(L"%13d", it.arrive_time);
		ansstr += str;
		str.Format(L"%13d", it.running_time);
		ansstr += str;
		str.Format(L"%13d", it.end_time);
		ansstr += str;
		str.Format(L"%13d", it.zz_time);
		ansstr += str;
		str.Format(L"%15.2f", it.dqzz_time);
		ansstr += str;

		if (mtime <= it.end_time)
		{
			ansstr += "         正在执行！";
		}
		End = max(End, it.end_time);
		m_list.AddString(ansstr);
	}
	str.Format(L"%.2f", tot_zz/ansvec.size()*1.0);
	GetDlgItem(IDC_STATIC3)->SetWindowTextW(str);
	str.Format(L"%.2f", tot_dqzz / ansvec.size() * 1.0);
	GetDlgItem(IDC_STATIC4)->SetWindowTextW(str);

	// TODO: 在此添加控件通知处理程序代码
}

void CCPUDlg::OnBnClickedButton4()// HRRN
{
	CString str;
	suanfa = 3;
	GetDlgItem(IDC_BUTTON3)->EnableWindow(true);
	GetDlgItem(IDC_BUTTON5)->EnableWindow(true);
	while (j != vec.size() && vec[j].arrive_time <= mtime) //响应比
	{
		int wait_time = min(time1, time2);
		wait_time -= vec[j].arrive_time;
		vec[j].xyb = 1+(wait_time * 1.0 / vec[j].running_time * 1.0);
		fvec.push_back(vec[j]);	 //得到某个时间之前所有的作业
		j++;
	}
	sort(fvec.begin(), fvec.end(), mcmp3);//fvec响应比从小到大
	if (mtime == time1) //cpu1空闲
	{
		if (fvec.empty())//未有作业到达 cpu1的时间+1
		{
			time1++;
		}
		else //cpu1中加入作业 cpu1的时间变为该作业的结束时间
		{
			work tmp = fvec.back();
			time1 += tmp.running_time;
			tmp.end_time = time1;
			tmp.zz_time = time1 - tmp.arrive_time;
			tmp.dqzz_time = tmp.zz_time * 1.0 / tmp.running_time * 1.0;
			tmp.duilie = 1;
			tot_zz += tmp.zz_time;
			tot_dqzz += tmp.dqzz_time;
			ansvec.push_back(tmp);  //添加到vec
			fvec.pop_back();
		}
	}
	if (mtime == time2) //cpu2空闲
	{
		if (fvec.empty())//未有作业到达 cpu2的时间+1
		{
			time2++;
		}
		else //cpu2中加入作业 cpu1的时间变为该作业的结束时间
		{
			work tmp = fvec.back();
			time2 += tmp.running_time;
			tmp.end_time = time2;
			tmp.zz_time = time2 - tmp.arrive_time;
			tmp.dqzz_time = tmp.zz_time * 1.0 / tmp.running_time * 1.0;
			tmp.duilie = 2;
			tot_zz += tmp.zz_time;
			tot_dqzz += tmp.dqzz_time;
			ansvec.push_back(tmp); //添加到答案vec
			fvec.pop_back();
		}
	}
	while (m_list.GetCount() > 0)  //清空表
	{
		m_list.DeleteString(0);
	}
	for (auto it : ansvec)
	{
		CString ansstr;
		str.Format(L"%5c", it.name);
		ansstr += str;
		str.Format(L"%9d", it.duilie);
		ansstr += str;
		str.Format(L"%13d", it.arrive_time);
		ansstr += str;
		str.Format(L"%13d", it.running_time);
		ansstr += str;
		str.Format(L"%13d", it.end_time);
		ansstr += str;
		str.Format(L"%13d", it.zz_time);
		ansstr += str;
		str.Format(L"%15.2f", it.dqzz_time);
		ansstr += str;

		if (mtime <= it.end_time)
		{
			ansstr += "         正在执行！";
		}
		End = max(End, it.end_time);
		m_list.AddString(ansstr);
	}

	str.Format(L"%.2f", tot_zz / ansvec.size() * 1.0);
	GetDlgItem(IDC_STATIC3)->SetWindowTextW(str);
	str.Format(L"%.2f", tot_dqzz / ansvec.size() * 1.0);
	GetDlgItem(IDC_STATIC4)->SetWindowTextW(str);
	// TODO: 在此添加控件通知处理程序代码
}

void CCPUDlg::OnBnClickedButton3()  //单步执行
{
	mtime++;
	CString str;
	str.Format(L"%d", mtime);
	GetDlgItem(IDC_STATIC2)->SetWindowTextW(str);
	if (suanfa == 1)
	{
		OnBnClickedButton1();
	}
	else if (suanfa == 2)
	{
		OnBnClickedButton2();

	}
	else if(suanfa ==3)
	{
		OnBnClickedButton4();
	}
	// TODO: 在此添加控件通知处理程序代码
}


void CCPUDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (nIDEvent == 1)
	{
		if (End==mtime)
		{
			OnBnClickedButton5();
			return;
		}
		OnBnClickedButton3();
	}
	CDialogEx::OnTimer(nIDEvent);
}


void CCPUDlg::OnBnClickedButton5()  //自动执行
{
	CString str;
	GetDlgItem(IDC_BUTTON5)->GetWindowTextW(str);
	if (str == "自动执行")
	{
		GetDlgItem(IDC_BUTTON5)->SetWindowTextW(L"暂停");
		SetTimer(1, 500, NULL);
	}
	else
	{
		GetDlgItem(IDC_BUTTON5)->SetWindowTextW(L"自动执行");
		KillTimer(1);
	}
	// TODO: 在此添加控件通知处理程序代码
}


void CCPUDlg::OnBnClickedButton6()  //初始化
{
	CString str;
	mtime = 0;
	suanfa = 0;
	time1 = 0;	//cpu1任务结束时间
	time2 = 0;	//cpu2任务结束时间
	j = 0;
	End = 0;
	tot_zz = 0;	//总的周转时间	
	tot_dqzz = 0;	//总的带权周转时间
	
	str.Format(L"%d", mtime);
	GetDlgItem(IDC_STATIC2)->SetWindowTextW(str);
	while (m_list.GetCount() > 0)
	{
		m_list.DeleteString(0);
	}
	str.Format(_T("%d"), tot_zz);
	GetDlgItem(IDC_STATIC3)->SetWindowTextW(str);
	str.Format(L"%d", tot_dqzz);
	GetDlgItem(IDC_STATIC4)->SetWindowTextW(str);
	GetDlgItem(IDC_BUTTON3)->EnableWindow(false);
	GetDlgItem(IDC_BUTTON5)->EnableWindow(false);
	GetDlgItem(IDC_BUTTON1)->EnableWindow(true);
	GetDlgItem(IDC_BUTTON2)->EnableWindow(true);
	GetDlgItem(IDC_BUTTON4)->EnableWindow(true);
	GetDlgItem(IDC_BUTTON7)->EnableWindow(true);
	GetDlgItem(IDC_BUTTON8)->EnableWindow(true);
	vec.clear();
	ansvec.clear();
	fvec.clear();
	// TODO: 在此添加控件通知处理程序代码
}


void CCPUDlg::OnBnClickedButton7() //添加作业
{
	CString str;
	string s;
	work tmp;
	ed1.GetWindowTextW(str);
	s = (CW2A)str.GetString();
	tmp.name = s[0];
	ed2.GetWindowTextW(str);
	tmp.arrive_time = atoi((CW2A)str.GetString());
	ed3.GetWindowTextW(str);
	tmp.running_time = atoi((CW2A)str.GetString());
	vec.push_back(tmp);
	sort(vec.begin(), vec.end(), mcmp1);
	MessageBox(L"添加成功");

	// TODO: 在此添加控件通知处理程序代码
}


void CCPUDlg::OnBnClickedButton8()
{
	FILE* fp;
	work tmp;
	fp = fopen("作业调度.txt", "r");
	while (!feof(fp))
	{
		fscanf(fp, "%s", &tmp.name);
		fscanf(fp, "%d", &tmp.arrive_time);
		fscanf(fp, "%d\n", &tmp.running_time);
		vec.push_back(tmp);
	}
	sort(vec.begin(), vec.end(), mcmp1);
	// TODO: 在此添加控件通知处理程序代码
}
