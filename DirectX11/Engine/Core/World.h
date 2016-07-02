#pragma once

#include <list>
#include <memory>
#include "Actor.h"

/*
	new�� ������ �ϸ� �ȵȴ�.
	����Ʈ �����ʹ� stack�� ������� ����ִ����� �Ǵ��ϱ� �����̴�.
*/

template <class T>
std::shared_ptr<T> CreatClass( ) {
	return std::shared_ptr<T> sp1( new T( ) );
}


class CWorld
{
	//����Ʈ �����ͷ� �籸��
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
