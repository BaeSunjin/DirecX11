#include "SE_Exception.h"
#include <iostream>
#include <string>
#include <DbgHelp.h>
#include <time.h>

// trans_func 등록 함수
// u Execption type
void trans_func( unsigned int u, _EXCEPTION_POINTERS* pExp )
{
	time_t rawtime;
	tm timeinfo;

	std::string curTime = "";

	time( &rawtime );
	localtime_s( &timeinfo, &rawtime );

	curTime.append( std::to_string( timeinfo.tm_year + 1900 ) );
	curTime.append( "-" );
	curTime.append( std::to_string( timeinfo.tm_mon + 1 ) );
	curTime.append( "-" );
	curTime.append( std::to_string( timeinfo.tm_mday ) );

	curTime.append( "_" );
	curTime.append( std::to_string( timeinfo.tm_hour ) );
	curTime.append( "-" );
	curTime.append( std::to_string( timeinfo.tm_min ) );
	curTime.append( "-" );
	curTime.append( std::to_string( timeinfo.tm_sec ) );

	std::wstring filename( curTime.length( ), L' ' );
	copy( curTime.begin( ), curTime.end( ), filename.begin( ) );
	filename.append( L".dmp" );

	MINIDUMP_EXCEPTION_INFORMATION MinidumpExceptionInformation;

	MinidumpExceptionInformation.ThreadId = ::GetCurrentThreadId( );
	MinidumpExceptionInformation.ExceptionPointers = pExp;
	MinidumpExceptionInformation.ClientPointers = FALSE;

	HANDLE hDumpFile = ::CreateFileW( filename.c_str( ),
		GENERIC_WRITE,
		FILE_SHARE_WRITE,
		NULL,
		CREATE_ALWAYS,
		FILE_ATTRIBUTE_NORMAL, NULL );

	//create dump
	MiniDumpWriteDump( GetCurrentProcess( ),
		GetCurrentProcessId( ),
		hDumpFile,
		MiniDumpNormal,
		&MinidumpExceptionInformation,
		NULL,
		NULL );


	switch ( u )
	{
	case EXCEPTION_INT_DIVIDE_BY_ZERO:
		THROW_EXCEPTION( "EXCEPTION_INT_DIVIDE_BY_ZERO" );
		break;

	case EXCEPTION_INVALID_HANDLE:
		THROW_EXCEPTION( "EXCEPTION_INVALID_HANDLE" );
		break;

	case EXCEPTION_STACK_OVERFLOW:
		THROW_EXCEPTION( "EXCEPTION_STACK_OVERFLOW" );
		break;

	case EXCEPTION_ACCESS_VIOLATION:
		THROW_EXCEPTION( "EXCEPTION_ACCESS_VIOLATION" );
		break;

	case EXCEPTION_ARRAY_BOUNDS_EXCEEDED:
		THROW_EXCEPTION( "EXCEPTION_ARRAY_BOUNDS_EXCEEDED" );
		break;

	case EXCEPTION_FLT_DIVIDE_BY_ZERO:
		THROW_EXCEPTION( "EXCEPTION_FLT_DIVIDE_BY_ZERO" );
		break;

	case EXCEPTION_FLT_OVERFLOW:
		THROW_EXCEPTION( "EXCEPTION_FLT_OVERFLOW" );
		break;

	}
}
