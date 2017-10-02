/*
 * Copyright (C) 2009 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

// OpenGL ES 2.0 code

#include <jni.h>
#include <android/log.h>

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define  LOG_TAG    "Lives2D"
#define  LOGI(...)  __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)
#define  LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)


#include<iostream>
#include<string>
#include<fstream>
#include"FreeImage.h"



extern "C" {
    JNIEXPORT void JNICALL Java_com_lives2d_library_nativeWrap_init(JNIEnv * env, jobject obj,  jint width, jint height);
    JNIEXPORT void JNICALL Java_com_lives2d_library_nativeWrap_step(JNIEnv * env, jobject obj);
};

JNIEXPORT void JNICALL Java_com_lives2d_library_nativeWrap_init(JNIEnv * env, jobject obj,  jint width, jint height)
{
	std::string tmpFilePath = "/mnt/sdcard/1.png";
	
	//判断文件是否存在
	std::fstream fs;
	fs.open(tmpFilePath.c_str(),std::ios::in);
	if(!fs)
	{
		LOGE("file not exist");
		return;
	}

	//1、获取图片格式;
	FREE_IMAGE_FORMAT imageformat = FreeImage_GetFileType(tmpFilePath.c_str(), 0);

	//2、根据获取到的格式来加载图片;
	FIBITMAP *bitmap = FreeImage_Load(imageformat, tmpFilePath.c_str(), 0);

	if (bitmap == nullptr)
	{
		LOGE("Error not exist or other error ");
		return;
	}
	else
	{
		LOGI("FreeImage Working");
	}
}

JNIEXPORT void JNICALL Java_com_lives2d_library_nativeWrap_step(JNIEnv * env, jobject obj)
{

}