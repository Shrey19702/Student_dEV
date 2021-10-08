package com.vaibhav.tictactoegame;

import androidx.appcompat.app.AppCompatActivity;
import androidx.gridlayout.widget.GridLayout;

import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {
    int tr = 1;
    int[] GameState = {2,2,2,2,2,2,2,2,2};
    int[][] Winners = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, {0, 4, 8}, {2, 4, 6}};
    boolean Check = true;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }
    public void DropIn(View view) {
        ImageView img = (ImageView) view;
        Log.i("Tag", img.getTag().toString());
        int ind = Integer.parseInt(img.getTag().toString());
        if (GameState[ind] == 2 && Check) {
            GameState[ind] = tr;
            img.setTranslationY(-1500);
            if (tr == 1) {
                img.setImageResource(R.drawable.cross);
                img.animate().translationYBy(1500).rotation(3600).setDuration(300);
                tr = 0;
            } else {
                img.setImageResource(R.drawable.zero);
                img.animate().translationYBy(1500).rotation(3600).setDuration(300);
                tr = 1;
            }
            for (int[] Win : Winners) {
                if (GameState[Win[0]] == GameState[Win[1]] && GameState[Win[1]] == GameState[Win[2]] && GameState[Win[1]] != 2) {
                    Check = false;
                    String Winner = "";
                    if (tr == 0) {
                        Winner = "Cross";
                    } else {
                        Winner = "ZERO";
                    }
                    Toast.makeText(this, Winner + " Won", Toast.LENGTH_SHORT).show();
                    Button Plag = (Button) findViewById(R.id.button);
                    TextView txt = (TextView) findViewById(R.id.Winner);
                    txt.setText(Winner + " has Won");
                    Plag.setVisibility(View.VISIBLE);
                    txt.setVisibility(View.VISIBLE);
                }
            }
        }
    }

    public void Restart(View view) {
        Button Pl = (Button) findViewById(R.id.button);
        TextView txt = (TextView) findViewById(R.id.Winner);
        Pl.setVisibility(View.INVISIBLE);
        txt.setVisibility(View.INVISIBLE);
        GridLayout grid = findViewById(R.id.gridlayout);
        for (int i = 0; i < grid.getChildCount(); i++) {
            ImageView Con = (ImageView) grid.getChildAt(i);
            Con.setImageDrawable(null);
            Log.d("Prob","running "+i);
        }
        for (int i = 0; i < GameState.length; i++) {
            GameState[i] = 2;
            Log.d("Prob","gamestate "+i);
        }
        Check = true;
        tr = 1;
    }

}