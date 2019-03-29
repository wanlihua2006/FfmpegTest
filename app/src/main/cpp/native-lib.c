#include <jni.h>
#include <android/log.h>
//编码
#include "include/libavcodec/avcodec.h"
//封装格式处理
#include "include/libavformat/avformat.h"
//像素处理
#include "include/libswscale/swscale.h"

#define LOGI(FORMAT,...) __android_log_print(ANDROID_LOG_INFO,"wanlihua",FORMAT,__VA_ARGS__);
#define LOGE(FORMAT,...) __android_log_print(ANDROID_LOG_ERROR,"wanlihua",FORMAT,__VA_ARGS__);

JNIEXPORT jstring JNICALL
Java_com_qiku_ffmpegtest_VideoUtils_ffmpegInfo(JNIEnv *env, jclass type) {
    char info[10000] = { 0 };
    sprintf(info, "%s\n", avcodec_configuration());
    return (*env)->NewStringUTF(env, info);
}  
