/*
** Lua binding: LuaComponent
** Generated automatically by tolua++-1.0.92 on Sun Jun 24 02:35:02 2018.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_LuaComponent_open (lua_State* tolua_S);

#include"LuaComponent.h"

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_LuaComponent (lua_State* tolua_S)
{
 LuaComponent* self = (LuaComponent*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"LuaComponent");
 tolua_usertype(tolua_S,"Component");
}

/* method: new of class  LuaComponent */
#ifndef TOLUA_DISABLE_tolua_LuaComponent_LuaComponent_new00
static int tolua_LuaComponent_LuaComponent_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"LuaComponent",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   LuaComponent* tolua_ret = (LuaComponent*)  Mtolua_new((LuaComponent)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"LuaComponent");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  LuaComponent */
#ifndef TOLUA_DISABLE_tolua_LuaComponent_LuaComponent_new00_local
static int tolua_LuaComponent_LuaComponent_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"LuaComponent",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   LuaComponent* tolua_ret = (LuaComponent*)  Mtolua_new((LuaComponent)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"LuaComponent");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  LuaComponent */
#ifndef TOLUA_DISABLE_tolua_LuaComponent_LuaComponent_delete00
static int tolua_LuaComponent_LuaComponent_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaComponent",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaComponent* self = (LuaComponent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: DoFile of class  LuaComponent */
#ifndef TOLUA_DISABLE_tolua_LuaComponent_LuaComponent_DoFile00
static int tolua_LuaComponent_LuaComponent_DoFile00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaComponent",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaComponent* self = (LuaComponent*)  tolua_tousertype(tolua_S,1,0);
  const char* varFilePath = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'DoFile'", NULL);
#endif
  {
   self->DoFile(varFilePath);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'DoFile'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: BindAwake of class  LuaComponent */
#ifndef TOLUA_DISABLE_tolua_LuaComponent_LuaComponent_BindAwake00
static int tolua_LuaComponent_LuaComponent_BindAwake00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaComponent",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaComponent* self = (LuaComponent*)  tolua_tousertype(tolua_S,1,0);
  const char* varLuaFunctionName = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'BindAwake'", NULL);
#endif
  {
   self->BindAwake(varLuaFunctionName);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'BindAwake'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: BindOnEnable of class  LuaComponent */
#ifndef TOLUA_DISABLE_tolua_LuaComponent_LuaComponent_BindOnEnable00
static int tolua_LuaComponent_LuaComponent_BindOnEnable00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaComponent",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaComponent* self = (LuaComponent*)  tolua_tousertype(tolua_S,1,0);
  const char* varLuaFunctionName = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'BindOnEnable'", NULL);
#endif
  {
   self->BindOnEnable(varLuaFunctionName);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'BindOnEnable'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: BindStart of class  LuaComponent */
#ifndef TOLUA_DISABLE_tolua_LuaComponent_LuaComponent_BindStart00
static int tolua_LuaComponent_LuaComponent_BindStart00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaComponent",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaComponent* self = (LuaComponent*)  tolua_tousertype(tolua_S,1,0);
  const char* varLuaFunctionName = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'BindStart'", NULL);
#endif
  {
   self->BindStart(varLuaFunctionName);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'BindStart'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: BindUpdate of class  LuaComponent */
#ifndef TOLUA_DISABLE_tolua_LuaComponent_LuaComponent_BindUpdate00
static int tolua_LuaComponent_LuaComponent_BindUpdate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaComponent",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaComponent* self = (LuaComponent*)  tolua_tousertype(tolua_S,1,0);
  const char* varLuaFunctionName = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'BindUpdate'", NULL);
#endif
  {
   self->BindUpdate(varLuaFunctionName);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'BindUpdate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: BindOnDisable of class  LuaComponent */
#ifndef TOLUA_DISABLE_tolua_LuaComponent_LuaComponent_BindOnDisable00
static int tolua_LuaComponent_LuaComponent_BindOnDisable00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaComponent",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaComponent* self = (LuaComponent*)  tolua_tousertype(tolua_S,1,0);
  const char* varLuaFunctionName = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'BindOnDisable'", NULL);
#endif
  {
   self->BindOnDisable(varLuaFunctionName);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'BindOnDisable'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: BindOnDestroy of class  LuaComponent */
#ifndef TOLUA_DISABLE_tolua_LuaComponent_LuaComponent_BindOnDestroy00
static int tolua_LuaComponent_LuaComponent_BindOnDestroy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaComponent",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaComponent* self = (LuaComponent*)  tolua_tousertype(tolua_S,1,0);
  const char* varLuaFunctionName = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'BindOnDestroy'", NULL);
#endif
  {
   self->BindOnDestroy(varLuaFunctionName);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'BindOnDestroy'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: mLuaFilePath of class  LuaComponent */
#ifndef TOLUA_DISABLE_tolua_get_LuaComponent_mLuaFilePath
static int tolua_get_LuaComponent_mLuaFilePath(lua_State* tolua_S)
{
  LuaComponent* self = (LuaComponent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mLuaFilePath'",NULL);
#endif
  tolua_pushcppstring(tolua_S,(const char*)self->mLuaFilePath);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: mLuaFilePath of class  LuaComponent */
#ifndef TOLUA_DISABLE_tolua_set_LuaComponent_mLuaFilePath
static int tolua_set_LuaComponent_mLuaFilePath(lua_State* tolua_S)
{
  LuaComponent* self = (LuaComponent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mLuaFilePath'",NULL);
  if (!tolua_iscppstring(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->mLuaFilePath = ((std::string)  tolua_tocppstring(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_LuaComponent_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"LuaComponent","LuaComponent","Component",tolua_collect_LuaComponent);
  #else
  tolua_cclass(tolua_S,"LuaComponent","LuaComponent","Component",NULL);
  #endif
  tolua_beginmodule(tolua_S,"LuaComponent");
   tolua_function(tolua_S,"new",tolua_LuaComponent_LuaComponent_new00);
   tolua_function(tolua_S,"new_local",tolua_LuaComponent_LuaComponent_new00_local);
   tolua_function(tolua_S,".call",tolua_LuaComponent_LuaComponent_new00_local);
   tolua_function(tolua_S,"delete",tolua_LuaComponent_LuaComponent_delete00);
   tolua_function(tolua_S,"DoFile",tolua_LuaComponent_LuaComponent_DoFile00);
   tolua_function(tolua_S,"BindAwake",tolua_LuaComponent_LuaComponent_BindAwake00);
   tolua_function(tolua_S,"BindOnEnable",tolua_LuaComponent_LuaComponent_BindOnEnable00);
   tolua_function(tolua_S,"BindStart",tolua_LuaComponent_LuaComponent_BindStart00);
   tolua_function(tolua_S,"BindUpdate",tolua_LuaComponent_LuaComponent_BindUpdate00);
   tolua_function(tolua_S,"BindOnDisable",tolua_LuaComponent_LuaComponent_BindOnDisable00);
   tolua_function(tolua_S,"BindOnDestroy",tolua_LuaComponent_LuaComponent_BindOnDestroy00);
   tolua_variable(tolua_S,"mLuaFilePath",tolua_get_LuaComponent_mLuaFilePath,tolua_set_LuaComponent_mLuaFilePath);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_LuaComponent (lua_State* tolua_S) {
 return tolua_LuaComponent_open(tolua_S);
};
#endif

