#pragma once

extern "C"
{
#include "lua.h"    
#include "lualib.h"    
#include "lauxlib.h"    
#include "luaconf.h"    

#include"lua_cjson.h"
}
#include "tolua++.h"

#include<functional>



class LuaFunctionPoint
{
public:
	lua_State* mlua_State;

public:
	int mFunctionIndexInStack;
	int mArgumentIndexInStack;

public:
	int mFunctionPoint;
	int mArgumentPoint;

public:
	LuaFunctionPoint() :mFunctionPoint(LUA_REFNIL), mArgumentPoint(LUA_REFNIL)
	{

	}
};

class LuaEngine
{
private:
	static LuaEngine* m_pSingleton;

	lua_State* m_pLua_State;

	bool mErrorPause;
private:
	LuaEngine();
	~LuaEngine();

public:
	static LuaEngine* GetSingleton();

	void SetLuaPath();
	
	void DoFile(const char* varFilePath);

	void DoFile(const char* varFilePath, std::function<void(lua_State*)> varFunction);

	void CallLuaFunction(const char* varLuaFunctionName, int varParamCount, std::function<void(lua_State*)> varFunction);

	void CallLuaFunction(const char* varLuaFunctionName);

	void CallLuaFunction(const char* varLuaFunctionName, const char* varTypeName, void* varTypeData);



	LuaFunctionPoint* GetLuaFunction(LuaFunctionPoint* varLuaFunctionPoint);

	void ExecuteLuaFunction(LuaFunctionPoint* varLuaFunctionPoint);

	void ExecuteLuaFunction(int varLuaFunctionUniqueIndex);

	int GetGlobalViriable(const char* varName);

private:
	void PrintError();

	void RegisterThirdParty();
};

