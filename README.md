# NDKDemo
 这是一个android studio下的NDK的示例程序

---

## 2018.8.7##
	向工程添加JNI，要点1：CMakeLists.txt中 add_library 
	和 target_link_libraries中的lib库的名字不能是test
[https://blog.csdn.net/xiaoyunchengzhu/article/details/52982284](https://blog.csdn.net/xiaoyunchengzhu/article/details/52982284 "创建一个JNI项目")
## 2018.8.9##
	ndk build 是寻找目录下的Android.mk,Android.mk的模板（基本）：
	LOCAL_PATH := $(call my-dir)
	include $(CLEAR_VARS)
	LOCAL_MODULE := test
	LOCAL_SRC_FILES := test.c
	include $(BUILD_SHARED_LIBRARY)
	其他的根据实际情况自己添加,写这样的脚本最好是跟着大神的学，
	照猫画虎：熟悉基本的工程构建框架，抓住基本要素，其他的学大神的
[https://blog.csdn.net/qq_26819733/article/details/69061664](https://blog.csdn.net/qq_26819733/article/details/69061664 "android--使用ndk build 生成.so")
	
	cmake的基本执行文件CMakeLists.txt,要想CMake可以进行不同平台的编译，需要编写toolchain.cmake（androidstudio之所以能在电脑上编写arm上的.so就是这个原理，在NDK的build\cmake下有一个android.toolchain.cmake）执行的时候添加编译选项 -DCMAKE_TOOLCHAIN_FILE=path/to/toolchain.cmake
[https://blog.csdn.net/gw569453350game/article/details/46683845](https://blog.csdn.net/gw569453350game/article/details/46683845 "cmake 基本命令 & 交叉编译配置 & 模块的编写")