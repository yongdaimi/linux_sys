#ifdef __ANDROID__ 
#include <jni.h>
#include <android/log.h>
#include "jnihelp.h"
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>


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

static const char *content = "www.baidu.com";


JNIEXPORT void call_read_file_information(JNIEnv *env, jobject thiz)
{
	int fd;
	if ((fd = open("/sdcard/2018-02-02.txt", O_CREAT|O_RDWR, 0777)) < 0) {
		LOGE("%s", strerror(errno));
	}
	
	struct stat sb;
	if (fstat(fd, &sb) < 0) {
		LOGE("%s", strerror(errno));
	} else {

		/*FILE TYPE*/
		LOGE("FILE TYPE:");
		switch (sb.st_mode & S_IFMT) {
			case S_IFBLK:	LOGE("block device\n");	break;
			case S_IFCHR:	LOGE("character device\n");	break;
			case S_IFDIR:	LOGE("directory\n");		break;
			case S_IFIFO:	LOGE("FIFO/pipe\n");		break;
			case S_IFLNK:	LOGE("symlink\n");		break;
			case S_IFREG:	LOGE("regular file\n");	break;
			case S_IFSOCK:	LOGE("socket\n");		break;
			default:	LOGE("unknown?\n");		break;
		}	
		
		/*FILE SIZE*/
		LOGE("FILE Size: %lld bytes\n", (long long)sb.st_size);
		/*FILE Last Access Time*/
		LOGE("Last file access: %s", ctime(&sb.st_atime));
		/*FILE Permission*/
		LOGE("FILE Mode: %lo (octal)\n", (unsigned long)sb.st_mode);
		
	}	
		
	close(fd);
}


JNIEXPORT jint call_check_file_exists(JNIEnv *env, jobject thiz)
{
	if (access("/sdcard/2018-02-02.txt", F_OK|X_OK) < 0) {
		return -1;
	}
	return 0;	
}


JNIEXPORT jint call_set_file_execute_permission(JNIEnv *env, jobject thiz)
{
	int ret = chmod("/sdcard/2018-02-02.txt", S_IRUSR|S_IWUSR|S_IXUSR);	
	if (ret < 0) {
		LOGE("%s\n", strerror(errno));
	}
	return ret;
}


JNIEXPORT void call_add_new_log_file(JNIEnv *env, jobject thiz) {

	if (access("/sdcard/myCrash", F_OK) < 0) {
		if (mkdir("/sdcard/myCrash", 0777) < 0) {
			LOGE("%s\n", strerror(errno));
			return;
		}		
	}
	
	time_t timep;
	time(&timep);	
	struct tm *p;
	p = localtime(&timep);
	char buf[30] = {0};
	char *format = "%Y-%m-%d-%H-%M-%S";
	char *suffix = ".log";	
	char fullFileName[128] = "/sdcard/myCrash/";	
	

	
	strftime(buf, sizeof(buf), format, p);
	char *logFileName = strncat(buf, suffix, strlen(suffix));
	char *logFilePath = strncat(fullFileName, logFileName, strlen(logFileName));
	LOGE("%s\n", logFilePath);
	
	int fd;
	if ((fd = open(logFilePath, O_CREAT|O_RDWR|O_APPEND, 0777)) < 0) {
		LOGE("%s\n", strerror(errno));
		return;
	}
		
	write(fd, content, strlen(content));
	close(fd);
		
} 


JNIEXPORT void call_create_new_process(JNIEnv *env, jobject thiz)
{
	pid_t pid;
	pid = fork();
	if (pid > 0) {
		LOGE("cur process is: parent\n");
		LOGE("cur pid is: %d, ppid is: %d\n", getpid(), getppid());
	} else if (pid == 0) {
		LOGE("cur process is: child\n");
		LOGE("cur pid is: %d, ppid is: %d\n", getpid(), getppid());
	} else {
		LOGE("%s\n", strerror(errno));
	}	
}


JNIEXPORT jint call_calculate_two_number(JNIEnv *env, jobject thiz, jstring var1, jstring var2)
{
	
	if (var1 == NULL || var2 == NULL) {
		LOGE("string argus can not be empty");
		return -1;
	}

	int ret = -1;
	const char *str1 = (*env)->GetStringUTFChars(env, var1, NULL);
	const char *str2 = (*env)->GetStringUTFChars(env, var2, NULL);	
	
	
	ret = atoi(str1) + atoi(str2);
	
	(*env)->ReleaseStringUTFChars(env, var1, str1);
	(*env)->ReleaseStringUTFChars(env, var2, str2);
	return ret;
}

JNIEXPORT void send_exit_signal_2_self(JNIEnv *env, jobject thiz)
{
	LOGE("current name is: dog\n");
	LOGE("current name is: cat\n");
	LOGE("current name is: pig\n");
	
	//raise(9);
	alarm(5);
}


JNIEXPORT jbyteArray testJbyteArrayMethods(JNIEnv *env, jobject thiz)
{
	char *aaa = "hello";
	jbyteArray array = (*env)->NewByteArray(env, 5);
	(*env)->SetByteArrayRegion(env, array, 0, 5, (jbyte*)aaa);
	
	return array;
}

JNIEXPORT void call_exit_func(JNIEnv *env, jobject thiz)
{
	_exit(0);
}



static JNINativeMethod methods[] = {
    {"call_read_file_information","()V",(void*)call_read_file_information},
    {"call_check_file_exists","()I", (void*)call_check_file_exists},
    {"call_set_file_execute_permission","()I", (void*)call_set_file_execute_permission},
    {"call_add_new_log_file","()V", (void*)call_add_new_log_file},
    {"call_create_new_process","()V", (void*)call_create_new_process},
    {"call_calculate_two_number","(Ljava/lang/String;Ljava/lang/String;)I", (void*)call_calculate_two_number},
    {"send_exit_signal_2_self","()V", (void*)send_exit_signal_2_self},
    {"testJbyteArrayMethods","()[B", (void*)testJbyteArrayMethods},
    {"call_exit_func","()V", (void*)call_exit_func},
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
