package com.tliu.test;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.text.TextUtils;
import android.widget.TextView;

import com.tliu.md.Md5Util;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Example of a call to a native method
        TextView tv = findViewById(R.id.sample_text);
        if (TextUtils.equals(Md5Util.getPname(this), Md5Util.getPackageName(this))) {
            if (TextUtils.equals(Md5Util.getSign(this), Md5Util.getSignInfo(this))) {
                tv.setText("sign info is equal!");
            } else {
                tv.setText("package is equal!");
            }
        } else {
            tv.setText("nothing is equal!");
        }
    }
}
