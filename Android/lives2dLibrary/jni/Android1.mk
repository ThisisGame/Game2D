# Copyright (C) 2009 The Android Open Source Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
LOCAL_PATH:= $(call my-dir)
JNI_PATH:=$(call my-dir)

# ProgmaBegin BuildLua
LUA_SRC_PATH:=../../../../Lives2D_Depends/lua-5.1.4/lua-5.1.4/src
include $(CLEAR_VARS)
LOCAL_PATH:=$(LUA_SRC_PATH)

LOCAL_MODULE    := libLua
LOCAL_SRC_FILES := lapi.c \
				lauxlib.c \
				lbaselib.c \
				lcode.c \
				ldblib.c \
				ldebug.c \
				ldo.c \
				ldump.c \
				lfunc.c \
				lgc.c \
				linit.c \
				liolib.c \
				llex.c \
				lmathlib.c \
				lmem.c \
				loadlib.c \
				lobject.c \
				lopcodes.c \
				loslib.c \
				lparser.c \
				lstate.c \
				lstring.c \
				lstrlib.c \
				ltable.c \
				ltablib.c \
				ltm.c \
				lua.c \
				luac.c \
				lundump.c \
				lvm.c \
				lzio.c \
				print.c \

include $(BUILD_STATIC_LIBRARY)

# ProgmaEnd

# ProgmaBegin BuildTOLUAPP

TOLUAPP_SRC_PATH:=../../../../Lives2D_Depends/toluapp-master/toluapp-master

include $(CLEAR_VARS)

LOCAL_PATH:=$(TOLUAPP_SRC_PATH)

LOCAL_MODULE    := libTOLUAPP

LOCAL_C_INCLUDES:= $(LUA_SRC_PATH) $(TOLUAPP_SRC_PATH)/include

LOCAL_SRC_FILES:=src/lib/tolua_event.c \
src/lib/tolua_is.c \
src/lib/tolua_map.c \
src/lib/tolua_push.c \
src/lib/tolua_to.c \

LOCAL_CPP_FEATURES:=rtti exceptions
#LOCAL_CFLAGS:=-O3 -fPIC

include $(BUILD_STATIC_LIBRARY)

# ProgmaEnd

# ProgmaBegin BuildFreeImage

FREE_IMAGE_SRC_PATH:=../../../../Lives2D_Depends/FreeImage

include $(CLEAR_VARS)

LOCAL_PATH:=$(FREE_IMAGE_SRC_PATH)

include $(FREE_IMAGE_SRC_PATH)/Makefile.srcs

LOCAL_MODULE    := libFreeImage

LOCAL_C_INCLUDES:= $(FREE_IMAGE_SRC_PATH)/Source \
$(FREE_IMAGE_SRC_PATH)/Metadata \
$(FREE_IMAGE_SRC_PATH)/FreeImageToolkit \
$(FREE_IMAGE_SRC_PATH)/LibJPEG \
$(FREE_IMAGE_SRC_PATH)/LibPNG \
$(FREE_IMAGE_SRC_PATH)/ZLib \
$(FREE_IMAGE_SRC_PATH)/LibOpenJPEG \

LOCAL_SRC_FILES:=$(SRCS)
LOCAL_CPP_FEATURES:=rtti exceptions
LOCAL_CFLAGS:=-O3 -fPIC

include $(BUILD_STATIC_LIBRARY)

# ProgmaEnd


# ProgmaBegin BuildGLM

GLM_SRC_PATH:=../../../../Lives2D_Depends/GLM-0.9.6.3

include $(CLEAR_VARS)

LOCAL_PATH:=$(GLM_SRC_PATH)

LOCAL_MODULE    := libGLM

LOCAL_C_INCLUDES:= $(GLM_SRC_PATH)/glm \
$(GLM_SRC_PATH)/glm/detail \
$(GLM_SRC_PATH)/glm/gtc \
$(GLM_SRC_PATH)/glm/gtx \

LOCAL_SRC_FILES:=glm/detail/dummy.cpp \
glm/detail/glm.cpp \

LOCAL_CPP_FEATURES:=rtti exceptions
LOCAL_CFLAGS:=-O3 -fPIC

include $(BUILD_STATIC_LIBRARY)

# ProgmaEnd

# ProgmaBegin BuildFreeType
FreeType_PATH:=../../../../Lives2D_Depends/freetype
include $(CLEAR_VARS)
LOCAL_PATH:=$(FreeType_PATH)

LOCAL_MODULE    := libFreeType
LOCAL_SRC_FILES :=  \
 src/autofit/autofit.c \
 src/base/basepic.c \
 src/base/ftapi.c \
 src/base/ftbase.c \
 src/base/ftbbox.c \
 src/base/ftbitmap.c \
 src/base/ftdbgmem.c \
 src/base/ftdebug.c \
 src/base/ftglyph.c \
 src/base/ftinit.c \
 src/base/ftpic.c \
 src/base/ftstroke.c \
 src/base/ftsynth.c \
 src/base/ftsystem.c \
 src/cff/cff.c \
 src/pshinter/pshinter.c \
 src/pshinter/pshglob.c \
 src/pshinter/pshpic.c \
 src/pshinter/pshrec.c \
 src/psnames/psnames.c \
 src/psnames/pspic.c \
 src/raster/raster.c \
 src/raster/rastpic.c \
 src/sfnt/pngshim.c \
 src/sfnt/sfntpic.c \
 src/sfnt/ttbdf.c \
 src/sfnt/ttkern.c \
 src/sfnt/ttload.c \
 src/sfnt/ttmtx.c \
 src/sfnt/ttpost.c \
 src/sfnt/ttsbit.c \
 src/sfnt/sfobjs.c \
 src/sfnt/ttcmap.c \
 src/sfnt/sfdriver.c \
 src/smooth/smooth.c \
 src/smooth/ftspic.c \
 src/truetype/truetype.c \
 src/type1/t1driver.c \
 src/cid/cidgload.c \
 src/cid/cidload.c \
 src/cid/cidobjs.c \
 src/cid/cidparse.c \
 src/cid/cidriver.c \
 src/pfr/pfr.c \
 src/pfr/pfrgload.c \
 src/pfr/pfrload.c \
 src/pfr/pfrobjs.c \
 src/pfr/pfrsbit.c \
 src/type42/t42objs.c \
 src/type42/t42parse.c \
 src/type42/type42.c \
 src/winfonts/winfnt.c \
 src/pcf/pcfread.c \
 src/pcf/pcfutil.c \
 src/pcf/pcfdrivr.c \
 src/psaux/afmparse.c \
 src/psaux/psaux.c \
 src/psaux/psconv.c \
 src/psaux/psobjs.c \
 src/psaux/t1decode.c \
 src/tools/apinames.c \
 src/type1/t1afm.c \
 src/type1/t1gload.c \
 src/type1/t1load.c \
 src/type1/t1objs.c \
 src/type1/t1parse.c\
 src/bdf/bdfdrivr.c\
 src/bdf/bdflib.c\
 src/gzip/ftgzip.c\
 src/lzw/ftlzw.c \
 
LOCAL_CFLAGS := -DANDROID_NDK \
  -DFT2_BUILD_LIBRARY=1 
  
  
LOCAL_C_INCLUDES := $(JNI_PATH) \
  $(FreeType_PATH)/src \
  $(FreeType_PATH)/include
  
LOCAL_LDLIBS := -ldl -llog

include $(BUILD_STATIC_LIBRARY)

# ProgmaEnd


# ProgmaBegin BuildOpenAL

OpenAL_SRC_PATH:=../../../../Lives2D_Depends/openal-soft

include $(CLEAR_VARS)

LOCAL_PATH:=$(OpenAL_SRC_PATH)

LOCAL_MODULE    := libOpenAL
LOCAL_ARM_MODE   := arm
LOCAL_C_INCLUDES:= $(OpenAL_SRC_PATH)/Alc \
 $(OpenAL_SRC_PATH)/Alc/backends \
 $(OpenAL_SRC_PATH)/Alc/effects \
 $(OpenAL_SRC_PATH)/include/AL \
 $(OpenAL_SRC_PATH)/include \
 $(OpenAL_SRC_PATH) \
 $(OpenAL_SRC_PATH)/OpenAL32/Include

LOCAL_SRC_FILES:=Alc/backends/base.c \
#Alc/backends/alsa.c \
#Alc/backends/coreaudio.c \
Alc/backends/dsound.c \
#Alc/backends/jack.c \
Alc/backends/loopback.c \
Alc/backends/mmdevapi.c \
Alc/backends/null.c \
Alc/backends/opensl.c \
#Alc/backends/oss.c \
#Alc/backends/portaudio.c \
#Alc/backends/pulseaudio.c \
#Alc/backends/qsa.c \
#Alc/backends/sndio.c \
Alc/backends/wave.c \
Alc/effects/chorus.c \
Alc/effects/compressor.c \
Alc/effects/dedicated.c \
Alc/effects/distortion.c \
Alc/effects/echo.c \
Alc/effects/equalizer.c \
Alc/effects/modulator.c \
Alc/effects/null.c \
Alc/effects/reverb.c \
Alc/ALc.c \
Alc/alconfig.c \
Alc/ALu.c \
Alc/ambdec.c \
Alc/bformatdec.c \
Alc/bs2b.c \
Alc/converter.c \
Alc/helpers.c \
Alc/hrtf.c \
Alc/mastering.c \
Alc/mixer.c \
Alc/mixer_c.c \
Alc/mixer_inc.c \
Alc/mixer_neon.c \
Alc/mixer_sse.c \
Alc/mixer_sse2.c \
Alc/mixer_sse3.c \
Alc/mixer_sse41.c \
Alc/nfcfilter.c \
Alc/panning.c \
Alc/ringbuffer.c \
Alc/uhjfilter.c \
Alc/OpenAL32/alAuxEffectSlot.c \
Alc/OpenAL32/alBuffer.c \
Alc/OpenAL32/alEffect.c \
Alc/OpenAL32/alError.c \
Alc/OpenAL32/alExtension.c \
Alc/OpenAL32/alFilter.c \
Alc/OpenAL32/alListener.c \
Alc/OpenAL32/alSource.c \
Alc/OpenAL32/alState.c \
Alc/OpenAL32/alThunk.c \
Alc/OpenAL32/sample_cvt.c \
Alc/common/almalloc.c \
Alc/common/atomic.c \
Alc/common/rwlock.c \
Alc/common/threads.c \
Alc/common/uintmap.c \


#LOCAL_CFLAGS:=-DAL_BUILD_LIBRARY -DAL_ALEXT_PROTOTYPES
				
				
LOCAL_LDLIBS := -lOpenSLES -llog -Wl,-s
LOCAL_ARM_NEON := true



include $(BUILD_STATIC_LIBRARY)

# ProgmaEnd





# ProgmaBegin BuildAlut

Alut_SRC_PATH:=../../../../Lives2D_Depends/freealut

include $(CLEAR_VARS)

LOCAL_PATH:=$(Alut_SRC_PATH)

LOCAL_MODULE    := libAlut

LOCAL_C_INCLUDES:= $(Alut_SRC_PATH) \
$(Alut_SRC_PATH)/include/AL \
$(OpenAL_SRC_PATH)/include/AL

LOCAL_SRC_FILES:=src/alutBufferData.c \
src/alutCodec.c \
src/alutError.c \
src/alutInit.c \
src/alutInputStream.c \
src/alutLoader.c \
src/alutOutputStream.c \
src/alutUtil.c \
src/alutVersion.c \
src/alutWaveform.c \

include $(BUILD_STATIC_LIBRARY)

# ProgmaEnd





# ProgmaBegin BuildEngine

ENGINE_SRC_PATH:=../../../Src

include $(CLEAR_VARS)

LOCAL_PATH:=$(ENGINE_SRC_PATH)

LOCAL_MODULE    := libEngine


LOCAL_SRC_FILES := Tools/Helper.cpp \
		Tools/Application.cpp \
		Tools/lua_Application.cpp \
		Audio/AudioSource.cpp \
		Audio/lua_AudioSource.cpp \
		Audio/AudioCard.cpp \
		GLProgram/GLProgram.cpp \
		GLProgram/GLProgram_Texture.cpp \
		GUI/Font.cpp \
		GUI/FontManager.cpp \
		GUI/UIRect.cpp \
		GUI/UIDrawRect.cpp \
		GUI/UIClickRect.cpp \
		GUI/UIButton.cpp \
		GUI/UILabel.cpp \
		GUI/UIRoot.cpp \
		GUI/lua_UIRect.cpp \
		GUI/lua_UIDrawRect.cpp \
		GUI/lua_UIClickRect.cpp \
		GUI/lua_UIButton.cpp \
		GUI/lua_UILabel.cpp \
		GUI/lua_UIRoot.cpp \
		Image/Image.cpp \
		Image/lua_Image.cpp \
		ImageAnimation/ImageAnimationClip.cpp \
		ImageAnimation/ImageAnimation.cpp \
		ImageAnimation/lua_ImageAnimationClip.cpp \
		ImageAnimation/lua_ImageAnimation.cpp \
		KeyTouch/KeyCode.cpp \
		KeyTouch/KeyTouchListener.cpp \
		KeyTouch/KeyTouch.cpp \
		KeyTouch/lua_KeyTouchListener.cpp \
		KeyTouch/lua_KeyTouch.cpp \
		LuaEngine/BinaryPacker.cpp \
		LuaEngine/NetworkClient.cpp \
		LuaEngine/NetworkDispatch.cpp \
		LuaEngine/lua_BinaryPacker.cpp \
		LuaEngine/lua_NetworkClient.cpp \
		Texture2D/Texture2D.cpp \
		LuaEngine/LuaEngine.cpp \
		
LOCAL_C_INCLUDES:= $(LUA_SRC_PATH) \
$(TOLUAPP_SRC_PATH)/include \
$(FREE_IMAGE_SRC_PATH)/Source \
$(GLM_SRC_PATH)\
$(FreeType_PATH)/include \
$(Alut_SRC_PATH)/include \
$(OpenAL_SRC_PATH)/include \
$(ENGINE_SRC_PATH) \
$(JNI_PATH) \

LOCAL_STATIC_LIBRARIES := libLua libTOLUAPP libFreeImage libGLM libFreeType libOpenAL libAlut

include $(BUILD_STATIC_LIBRARY)

# ProgmaEnd


include $(CLEAR_VARS)
LOCAL_PATH:= $(JNI_PATH)

LOCAL_MODULE    := liblives2d
LOCAL_CFLAGS    := -Werror -Wno-deprecated-register
LOCAL_SRC_FILES := ./AndroidGame.cpp \
./JniHelper.cpp

LOCAL_LDLIBS    := -llog -lGLESv2

LOCAL_C_INCLUDES:= $(LUA_SRC_PATH) \
$(TOLUAPP_SRC_PATH)/include \
$(TOLUAPP_SRC_PATH)/src/lib \
$(FREE_IMAGE_SRC_PATH)/Source \
$(GLM_SRC_PATH) \
$(FreeType_PATH)/include \
$(ENGINE_SRC_PATH) \
$(JNI_PATH) \

LOCAL_STATIC_LIBRARIES := libEngine

include $(BUILD_SHARED_LIBRARY)
