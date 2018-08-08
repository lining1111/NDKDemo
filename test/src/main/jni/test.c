//
// Created by Administrator on 2018/8/7 0007.
//

#include <jni.h>

//extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_test_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject instance) {
//    std::string hello = "Hello from C++";
//    return env->NewStringUTF(hello.c_str());

    char *c ="hello from c";
    return (*env)->NewStringUTF(env,c);
}

JNIEXPORT void JNICALL
Java_com_example_test_MainActivity_callBackJavafromC(
        JNIEnv *env,
        jobject instance){
    //1.通过反射找到类
    jclass clazz;
    clazz = (*env)->FindClass(env,"com/example/test/MainActivity");

    //2.找到方法ID
    jmethodID methodId = (*env)->GetMethodID(env,clazz,"logout","()V");
    //3.调用方法，obj就是调用的类实例，所以不用再次创建
    (*env)->CallVoidMethod(env,instance,methodId);
}

JNIEXPORT void JNICALL
Java_com_example_test_MainActivity_hello(JNIEnv *env, jobject instance) {

    // TODO

}