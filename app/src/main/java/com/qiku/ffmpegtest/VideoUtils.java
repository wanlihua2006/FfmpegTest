package com.qiku.ffmpegtest;

public class VideoUtils {
    static {
        //顺序不能乱
        System.loadLibrary("avutil");
        System.loadLibrary("swresample");
        System.loadLibrary("avcodec");
        System.loadLibrary("avformat");
        System.loadLibrary("swscale");
        System.loadLibrary("postproc");
        System.loadLibrary("avfilter");
        System.loadLibrary("avdevice");
        System.loadLibrary("native-lib");
    }
    public native static String ffmpegInfo();

}
