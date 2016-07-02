#pragma once

#include <list>
#include <memory>
#include "Actor.h"

/*
	new로 생성을 하면 안된다.
	스마트 포인터는 stack을 기반으로 살아있는지를 판단하기 때문이다.
*/

template <class T>
std::shared_ptr<T> CreatClass( ) {
	return std::shared_ptr<T> sp1( new T( ) );
}


class CWorld
{
	//스마트 포인터로 재구성
	std::list<std::shared_ptr<CActor>> actorContainer;
	

public:

	CWorld( );
	~CWorld( );
	char strr[50];

	/*
		InsertData 
		return sussess
	*/
	bool SetInsertData( std::shared_ptr<CActor>& data );
	void Update( );
	void Render( );
	
};

/*
	ClassType CActor Child
	Currnet World Param
	return Sucsses
*/
template <class T>
bool InstanceActor( CWorld* world ) {

	if ( !world ) return false;
	return world->actorContainer.push_back( ISNTANCE::CreatClass<T>( ) );

}
