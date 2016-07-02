#include "World.h"


CWorld::CWorld( )
{
}


CWorld::~CWorld( )
{
}


void CWorld::Update( ) {

	//int size = actorContainer.size( );
	//_stprintf( strr, TEXT( " num : %d" ), size );

}

void CWorld::Render( ) {


}

bool CWorld::SetInsertData( std::shared_ptr<CActor>& data ) {

	int val = actorContainer.size( );
	
	actorContainer.push_back(data);

	if ( val == actorContainer.size( ) + 1 ) return true;
	return false;

}