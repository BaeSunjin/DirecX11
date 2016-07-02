#pragma once
#include "World.h"

namespace WORLD { 
	
	template<class T>
	T* Init( ) {
		return new T( );
	}

}


class CWorld;

class B_VM
{

public:

	B_VM( );
	~B_VM( );

	CWorld* world;

	void Init( );


	void UpData( );
	void Render( );
};

