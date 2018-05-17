#ifdef __ANDROID__

#include <jni.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <android/log.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>


#include "jnihelp.h"

#define LOG_TAG "jni"


#ifdef LOG_TAG
	#define LOGI(...)  __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__) 
	#define LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__) 
	#define LOGV(...) __android_log_print(ANDROID_LOG_VERBOSE,LOG_TAG,__VA_ARGS__) 
#else
	#define LOGI(...)  
	#define LOGE(...)  
	#define LOGV(...)  
#endif


static const char *str = "http://www.baidu.com\n";


JNIEXPORT void call_create_new_file(JNIEnv *env, jobject thiz, jstring name)
{
	const char *filename = (*env)->GetStringUTFChars(env, name, NULL);
	LOGE("cur file name is: %s\n", filename);
	
	int fd;
	if ((fd = open(filename, O_CREAT|O_RDWR|O_APPEND, 0777))<0) {
		LOGE("error msg is: %s\n", strerror(errno));
	} else {
		write(fd, str, strlen(str));
	}		
	
	close(fd);
	(*env)->ReleaseStringUTFChars(env, name, filename);
}


JNIEXPORT void call_read_file_content(JNIEnv *env, jobject thiz, jstring name)
{
	const char *filename = (*env)->GetStringUTFChars(env, name, NULL);
	int fd;
	if ((fd = open(filename, O_RDWR)) < 0) {
		LOGE("error msg is: %s\n", strerror(errno));
	} else {

		char buf[20];
		char dest[512];
		int len;
		int hasRead = 0;
		while ((len = read(fd, buf, sizeof(buf)))) {
			strncpy(dest+hasRead, buf, len);
			hasRead+=len;
		}
		dest[hasRead-1] = '\0';
		LOGE("current content is: %s\n", dest);
	}
	
	(*env)->ReleaseStringUTFChars(env, name, filename);
}


JNIEXPORT jstring call_return_file_content(JNIEnv *env, jobject thiz, jstring name)
{
	const char *fileName = (*env)->GetStringUTFChars(env, name, NULL);
	int fd;
	char buf[512] = {'\0'};
	if ((fd = open(fileName, O_RDWR)) < 0) {
		LOGE("error msg is: %s\n", strerror(errno));	
	} else {
		int len = read(fd, buf, sizeof(buf));
		//buf[len-1] = '\0';
		close(fd);
	}	
	(*env)->ReleaseStringUTFChars(env, name, fileName);
	jstring retStr = NULL;
	retStr = (*env)->NewStringUTF(env, buf);
	return retStr;
}

JNIEXPORT void call_get_file_flags(JNIEnv *env, jobject thiz, jstring name)
{
	const char *fileName = (*env)->GetStringUTFChars(env, name, NULL);
	int fd;
	if ((fd = open(fileName, O_RDWR)) < 0) {
		LOGE("open error");
	} else {
		int var;
		if ((var = fcntl(fd, F_GETFL, 0)) < 0) {
			LOGE("fcntl error");
		}
		
		switch (var & O_ACCMODE) {
			case O_RDONLY:
				LOGE("RDONLY");
			break;
			case O_WRONLY:
				LOGE("WRONLY");
			break;
			case O_RDWR:
				LOGE("RDWR");
			break;
			default:
				LOGE("do not know...");
			break;
		}
		
		close(fd);
	}	

	(*env)->ReleaseStringUTFChars(env, name, fileName);
}

static JNINativeMethod methods[] = {
     {"call_create_new_file","(Ljava/lang/String;)V",(void*)call_create_new_file},
     {"call_read_file_content","(Ljava/lang/String;)V",(void*)call_read_file_content},
     {"call_return_file_content","(Ljava/lang/String;)Ljava/lang/String;",(void*)call_return_file_content},
     {"call_get_file_flags","(Ljava/lang/String;)V",(void*)call_get_file_flags},
};


static const char *classPathName = "com/yuneec/android/demo/Test";


static int registerNativeMethods(JNIEnv* env, const char* className,JNINativeMethod* gMethods, int numMethods)
{
    jclass clazz;

    clazz = (*env)->FindClass(env, className);
    if (clazz == NULL){
    	LOGE("find class error!");
        return JNI_FALSE;
    }

   if ((*env)->RegisterNatives(env, clazz, gMethods, numMethods) < 0)
    {
	   	LOGE("register nativers error");
        return JNI_FALSE;
    }

    return JNI_TRUE;
}


void JNI_OnUnload(JavaVM* vm, void* reserved)
{

	return;
}

/* Library init */
jint JNI_OnLoad(JavaVM* vm, void* reserved)
{
    JNIEnv *env;
    
   LOGV("JNI_OnLoad called");
    if ((*vm)->GetEnv(vm, (void**) &env, JNI_VERSION_1_4) != JNI_OK) {
        LOGE("Failed to get the environment using GetEnv()");
        return -1;
    }
    if (JNI_TRUE != registerNativeMethods(env, classPathName,methods, sizeof(methods) / sizeof(methods[0])))
    {
        LOGE("ERROR: registerNatives failed");
        return -1;
    }


    return JNI_VERSION_1_4;
}
#endif /* __ANDROID__ */
