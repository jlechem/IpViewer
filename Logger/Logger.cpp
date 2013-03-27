#include "StdAfx.h"
#include "Logger.h"

CLogger::CLogger(void)
{
}


CLogger::~CLogger(void)
{
}

void CLogger::LogError( CString message, CException* exception )
{
	TCHAR   szCause[255];
    CString strFormatted;

	exception->GetErrorMessage( szCause, 255 );
	strFormatted += TEXT("Message - ");
	strFormatted += message;
	strFormatted = TEXT("\nException - ");
	strFormatted += szCause;
	
	CLogger::Log( true, strFormatted );
}

void CLogger::LogError( CException* exception )
{
	TCHAR   szCause[255];
    CString strFormatted;

	exception->GetErrorMessage( szCause, 255 );
	strFormatted += szCause;

	CLogger::Log( TRUE, strFormatted );
}

void CLogger::LogError( CString error )
{
	CLogger::Log( TRUE, error );
}

void CLogger::Log( CString message )
{
	CLogger::Log( FALSE, message );
}

void::CLogger::Log( BOOL isError, CString message )
{	
	// Convert a TCHAR string to a LPCSTR
	CT2CA pszConvertedAnsiString(message);

	// construct a std::string using the LPCSTR input
	std::string strStd(pszConvertedAnsiString);

	if( isError )
	{
		log4cpp::Category& root = log4cpp::Category::getRoot();
		root.error( strStd );
	}
	else
	{
		log4cpp::Category& categoryData = log4cpp::Category::getInstance("AppLogging");
		categoryData.info( strStd );
	}
}

void CLogger::Init( void )
{
	try
	{
		std::string initFileName = "c:\\log4cpp.properties";
		log4cpp::PropertyConfigurator::configure(initFileName);
	}
	catch( log4cpp::ConfigureFailure e )
	{
		cout << e.what() << std::endl;
	}
}