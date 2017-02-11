#include <jni.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
  JNIEnv *env;
  JavaVM *jvm;
  JNIEnv jni;
  JavaVM vmi;
  JavaVMInitArgs vm_args;
  JavaVMOption options[4];
  printf("beginning execution...\n");

  /*
   * /opt/blackdown-jdk-1.4.2/がJavaのルートディレクトリの場合
   */
  options[0].optionString = (char *)"-Djava.class.path=.:/usr/lib/jvm/java-1.8.0-openjdk-1.8.0.121-0.b13.el7_3.x86_64/jre/lib/rt.jar";
  options[1].optionString = (char *)"-Djava.compiler=NONE";
  vm_args.version = JNI_VERSION_1_8;
  vm_args.options = options;
  vm_args.nOptions = 2;
  vm_args.ignoreUnrecognized = JNI_FALSE;

  /*
   * JavaVMを初期化，起動する
   * JNIインターフェースへのポインタを返す
   */
  JNI_CreateJavaVM(&jvm,(void **)&env,&vm_args);
  jni = *env;
  vmi = *jvm;

  /*
   * クラスをさがす
   */
  jclass cls = jni->FindClass(env, "CalledJ");
  if (cls == 0) {
    printf("cannot found Test\n");
    exit(1);
  }

  /*
   * Methodをさがす
   * GetStaticMethodIDの引数については後述
   */
  jmethodID mid = jni->GetStaticMethodID(env, cls, "testmethod", "()V");
  if (mid == 0) {
    printf("Could not locate method testmthod with signature ()V");
    exit(1);
  }

  /*
   * 実行
   */
  jni->CallStaticVoidMethod(env, cls, mid, NULL);

  /*
   * VMを終了する
   */
  vmi->DestroyJavaVM(jvm);
}

