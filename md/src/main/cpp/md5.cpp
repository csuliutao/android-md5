#include <jni.h>
#include <string>

extern "C"
JNIEXPORT jstring JNICALL
Java_com_tliu_md_Md5Util_getPackageName(JNIEnv *env, jclass clazz, jobject context) {
    jclass j_clz = env->GetObjectClass(context);
    jmethodID j_method_id = env->GetMethodID(j_clz, "getPackageName", "()Ljava/lang/String;");
    return (jstring) env->CallObjectMethod(context, j_method_id);
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_tliu_md_Md5Util_getSignInfo(JNIEnv *env, jclass clazz, jobject context) {
    jclass j_context = env->GetObjectClass(context);

    jmethodID j_m_pm = env->GetMethodID(j_context, "getPackageManager", "()Landroid/content/pm/PackageManager;");
    jobject j_obj_pm = env->CallObjectMethod(context, j_m_pm);
    jclass j_clz_pm = env->GetObjectClass(j_obj_pm);

    jmethodID j_method_pg = env->GetMethodID(j_context, "getPackageName", "()Ljava/lang/String;");
    jstring j_name = (jstring) env->CallObjectMethod(context, j_method_pg);

    jmethodID j_m_pi = env->GetMethodID(j_clz_pm, "getPackageInfo", "(Ljava/lang/String;I)Landroid/content/pm/PackageInfo;");
    jobject j_obj_pi = env->CallObjectMethod(j_obj_pm, j_m_pi, j_name, 64);
    jclass j_clz_pi = env->GetObjectClass(j_obj_pi);

    jfieldID jfield = env->GetFieldID(j_clz_pi, "signatures", "[Landroid/content/pm/Signature;");
    jobjectArray j_signs =(jobjectArray) env->GetObjectField(j_obj_pi, jfield);

    jobject j_sign = env->GetObjectArrayElement(j_signs, 0);
    jmethodID j_sign_m = env->GetMethodID(env->GetObjectClass(j_sign), "toCharsString", "()Ljava/lang/String;");

    return (jstring) env->CallObjectMethod(j_sign, j_sign_m);
}