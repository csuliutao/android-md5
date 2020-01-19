package com.tliu.md;

import android.content.Context;
import android.content.pm.PackageInfo;
import android.content.pm.PackageManager;
import android.content.pm.Signature;

public final class Md5Util {
    static {
        System.loadLibrary("md5");
    }

    public static native String getPackageName(Context context);
    public static native String getSignInfo(Context context);

    public static String getPname(Context context) {
        return context.getPackageName();
    }

    public static String getSign(Context context) {
        PackageManager packageManager = context.getPackageManager();
        try {
            PackageInfo info = packageManager.getPackageInfo(getPname(context), PackageManager.GET_SIGNATURES);
            Signature[] signatures = info.signatures;
            return signatures[0].toCharsString();
        } catch (PackageManager.NameNotFoundException e) {
            e.printStackTrace();
        }

        return null;
    }
}
