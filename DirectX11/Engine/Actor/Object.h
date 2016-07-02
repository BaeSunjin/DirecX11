#pragma once

/*

	소멸자 Veritual
	생성자 아래서 파라미터로 넘겨주기

*/

/*
	
	생성 삭제의 기본이 되는 포인터를 제공 해주는 Class
	모든 생성되는 오브젝트의 기본이 되며 
	월드 상에서 계속 존재해야 하는 것들을 다룰때 사용을 하도록 한다.

*/
class Object
{
public:
	Object( );
	~Object( );
};

