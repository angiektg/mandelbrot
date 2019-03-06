#include <stdio.h>
#include <math.h>
#include <allegro5/allegro.h>

/*
The Mandelbrot set is a set of (x,y) points in the plane. It lies entirely inside the circle centered at (0,0) with radius 2. 
To find out whether the point (a,b) is in the Mandelbrot set, do the following computation: Let x = a and let y = b. 
Then do the following step over and over: Replace (x,y) with (x2−y2−a, 2xy−b). 
The number of times that you repeat this step is the number of "iterations." 
As you continue doing this step, if you get a value for (x,y) that is outside the circle centered at (0,0) with radius 2, 
then you know that the initial point (a,b) is NOT in the Mandelbrot set. 
The Mandelbrot set is defined as the set of points (a,b) for which the iteration never leaves that circle.
*/

double maxX = 1.0;
double minX = -2.0;
double maxY = 1.0;
double minY = -1.0;
double a,b;
int iters = 100;
double factorX, factorY;
double cx, cy;

int main(int argc, char **argv){
   
   ALLEGRO_DISPLAY *display = NULL;

   al_init();
int s=0;
   display = al_create_display(1200, 800);

    factorX = (abs(minX)+abs(maxX))/1200.0;
    factorY = (abs(minY)+abs(maxY))/800.0;
  //  printf("Fx = %f, Fy = %f", factorX, factorY);
    int i;
for(int y=0; y<800; y++){
    for(int x=0; x<1200; x++){
        cx = (double)minX+(double)x*factorX;
        cy = (double)minY+(double)y*factorY;
        //if(x%200==0)printf("cx = %f, cy = %f\n", cx, cy);
        a = 0.0;
        b = 0.0;
        for(i=0; i<iters; i++){
            double a2 = a*a;
            double b2 = b*b;
            if(a2+b2>4.0)break;
            double dosab = 2*a*b;
            a = a2-b2+cx;
            b = dosab+cy;
            if(i>s)s=i;
        }
        if(i<iters-1)al_draw_pixel(x,y, al_map_rgb((log10((double)i))*128.0,(log10((double)i))*64.0,(log10((double)i*2))*128.0));
    }
    //if(y%199==0)    
    al_flip_display();
}
 //   printf("%i",s);
//    al_rest(10.0);
    al_destroy_display(display);

   return 0;
}





/*
   for (long i=0; i<100000; i++){
       al_draw_pixel(300+((sin((float)i/100))*sin((float)i/10000)*150), (300+(sin((float)i/101))*sin((float)i/10011)*150), al_map_rgb((sin((float)i/1000)+1)*128, (sin((float)i/2000)+1)*128, (sin((float)i/3000)+1)*128));
     //  al_clear_to_color(al_map_rgb((sin((float)i/1000)+1)*128, (sin((float)i/2000)+1)*128, (sin((float)i/3000)+1)*128));
       if(i%10==0) al_flip_display();
     //al_draw_pixel(x,y,al_map_rgb((sin((float)(y+x*y)/1000)+1)*128, (sin((float)(y+x*y)/2000)+1)*128, (sin((float)(y+x*y)/3000)+1)*128));
   }
*/