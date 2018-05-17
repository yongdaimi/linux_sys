LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE    := file
LOCAL_SRC_FILES := fileSystem_jni.c jnihelp.cpp
LOCAL_LDLIBS +=  -llog
include $(BUILD_SHARED_LIBRARY)

