#pragma once
class CLogger
{
public:
	CLogger(void);
	~CLogger(void);
	void LogError(CException* exception);
	void LogError(CString error);
	void Log(CString message);
private:
	CString m_strMessageLogFileName;
	CString m_strErrorLogFileName;
};

