package com.example.fade;

import androidx.appcompat.app.AppCompatActivity;

import android.media.Image;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.ImageView;

public class MainActivity extends AppCompatActivity {

    // tags are important if your log message gets lost b/w windows nutting put tag in filter
    boolean clicky = false;

    //
//    public void fade(View v) {
//        Log.i("Info", "fade started");
//
//        if (clicky == false) {
//            ImageView boruto = findViewById(R.id.boruto);
//            boruto.animate().alpha(0).setDuration(1000);
//
//            ImageView sasuke = findViewById(R.id.sasuke);
//            sasuke.animate().alpha(1).setDuration(1000);
//            clicky = true;
//        } else if (clicky == true) {
//
//            ImageView boruto = findViewById(R.id.boruto);
//            boruto.animate().alpha(1).setDuration(1000);
//
//            ImageView sasuke = findViewById(R.id.sasuke);
//            sasuke.animate().alpha(0).setDuration(1000);
//
//            clicky = false;
//        }
//    }
    public void fade(View v) {
        Log.i("Info", "fade started");


        ImageView boruto = findViewById(R.id.boruto);
        ImageView sasuke = findViewById(R.id.sasuke);

        if(!clicky)
        {
            boruto.animate().translationYBy(1500).setDuration(700);
            boruto.animate().alpha(0).rotation(720).setDuration(700);
            sasuke.animate().alpha(1).setDuration(700);
            clicky = true;

        }
        else if(clicky)
        {
            boruto.animate().translationYBy(-1500).setDuration(700);
            boruto.animate().alpha(1).rotation(-720).setDuration(700);
            sasuke.animate().alpha(0).setDuration(700);
            clicky = false;
        }

    }

    @Override
    protected void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }
}