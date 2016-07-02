#pragma once
#pragma comment( lib, "dbghelp.lib" )

#include <stdio.h>
#include <eh.h>
#include <windows.h>
#include <exception>

//¿¡·¯
#define GET_PRAGMA_MSG_LENGTH(x)   #x
#define PRAGMA_MSG_LENGTH(x)  GET_PRAGMA_MSG_LENGTH(x)
#define PRAGMA_WARN(desc) __pragma(message(__FILE__ "(" PRAGMA_MSG_LENGTH(__LINE__) "): warning Msg :" #desc))
#define PRAGMA_ERR(desc) __pragma(message(__FILE__ "(" PRAGMA_MSG_LENGTH(__LINE__) "): error Msg :" #desc))
#define PRAGMA_MSG(desc) __pragma(message(__FILE__ "(" PRAGMA_MSG_LENGTH(__LINE__) "): Msg :" #desc))

#define VS_SUPPORT_VERSION 1700
#if _MSC_VER < VS_SUPPORT_VERSION
	PRAGMA_ERR( "NOT SUPPORT VERSION - Support Version :: Visual Studio 2013" )
#endif

class SE_Exception : public std::exception{

public:

	unsigned int nSE;

	SE_Exception( ) { }
	SE_Exception( SE_Exception& ) {}
	SE_Exception( const char* what, const char* file, int line) {}
	SE_Exception( unsigned int n ) : nSE( n ) {}
	~SE_Exception( ) {}


	unsigned int getSeNumber( ) { return nSE; }

private:
	int line;
	const char* file;
	
};


//#define DISALLOW_COPY_AND_ASSIGN(TypeName) \
//  TypeName(const TypeName&)=delete;        \
//  void operator=(const TypeName&)=delete;   
//
//#define DISALLOW_NEW(TypeName) \
//   void* operator new(std::size_t) = delete;
//
//#define USE_SUPER(TypeName) \
//   typedef TypeName super;