#include <iostream>  
#include <string.h>  
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
    lua_State *L = luaL_newstate();  
 
	luaL_openlibs(L);
	luaL_dofile(L,"Hello.lua");
	lua_getglobal(L,"str");
	lua_getfield(L,1,"name");
	lua_getfield(L,1,"age");
 
	if(lua_isstring(L,2))
	{
		cout<<"name= "<<lua_tostring(L,-2)<<endl;
	}
	if(lua_isnumber(L,3))
	{
		cout<<"age= "<<lua_tonumber(L,-1)<<endl;
	}
	lua_pop(L,2);
	lua_pushfstring(L,"So so");
	lua_setfield(L,1,"name");
	lua_getfield(L,1,"name");
	if(lua_isstring(L,2))
	{
		cout<<"name1= "<<lua_tostring(L,2)<<endl;
	}
	lua_pop(L,2);
	lua_newtable(L);
	lua_pushnumber(L,11);
	lua_pushstring(L,"New");
	lua_setfield(L,1,"name");
	lua_setfield(L,1,"age");
	lua_getfield(L,1,"name");
	lua_getfield(L,1,"age");
	if(lua_isstring(L,2))
	{
		cout<<"name= "<<lua_tostring(L,2)<<endl;
	}
	if(lua_isnumber(L,3))
	{
		cout<<"age= "<<lua_tonumber(L,3)<<endl;
	}
 
	lua_pop(L,3);
    lua_close(L);  
	
	int i;
	cin>>i;
    return 0 ;  
}
int main() {
  Table tb;
  tb.show();
  tb.addRow();
  tb.show();
  tb.addColumn();
  tb.show();
  Table tb1(5,5);
  tb1.show();
  tb1.set(1,1,30);
  tb1.set(2,2,"hello");
  tb1.show();
  tb1.delRow(1);
  tb1.show();
  tb1.delColumn(1);
  tb1.show();
  return 0;
}
