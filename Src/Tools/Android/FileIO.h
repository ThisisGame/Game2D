#pragma once
#include"Helper.h"

#ifdef ANDROID
#include"jni.h"
#include"android\asset_manager_jni.h"
#endif

class FileIO
{
public:
	FileIO(void);
	~FileIO(void);



public:
#ifdef ANDROID
	static AAssetManager* sAAssetManager;
#endif
};

