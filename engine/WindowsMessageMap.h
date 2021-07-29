/******************************************************************************************
*	Engine Direct3D Engine																  *
*	Copyright 2018 PlanetEngine <http://www.planetEngine.net>								  *
*																						  *
*	This file is part of Engine Direct3D Engine.											  *
*																						  *
*	Engine Direct3D Engine is free software: you can redistribute it and/or modify		  *
*	it under the terms of the GNU General Public License as published by				  *
*	the Free Software Foundation, either version 3 of the License, or					  *
*	(at your option) any later version.													  *
*																						  *
*	The Engine Direct3D Engine is distributed in the hope that it will be useful,		  *
*	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
*	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
*	GNU General Public License for more details.										  *
*																						  *
*	You should have received a copy of the GNU General Public License					  *
*	along with The Engine Direct3D Engine.  If not, see <http://www.gnu.org/licenses/>.    *
******************************************************************************************/
#pragma once
#include <unordered_map>
#include "EngineWin.h"

class WindowsMessageMap
{
public:
	WindowsMessageMap() noexcept;
	std::string operator()( DWORD msg,LPARAM lp,WPARAM wp ) const noexcept;
private:
	std::unordered_map<DWORD,std::string> map;
};