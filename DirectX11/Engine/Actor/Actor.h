#pragma once
#include "Object.h"

/*

	생성,삭제, 렌더링 여부를 결정짓는 인터페이스를 제공해주는 클래스 이다.
	스켈레톤 메쉬, 또는 스테틱 매쉬가 존재 해야 한다.

*/


class CActor :
	public Object
{
public:
	CActor( );
	~CActor( );
};

