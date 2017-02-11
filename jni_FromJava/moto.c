#include <stdio.h>
#include "saki.h"
JNIEXPORT void JNICALL Java_saki_hello(JNIEnv *env, jobject obj){
  printf("Hello\n");
  return;
}

