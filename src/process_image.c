#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include "image.h"

float get_pixel(image im, int x, int y, int c)
{
    if(x > im.w){
        x = im.w;
    }
    else if(x < 0){
        x = 0;
    }
    if(y > im.h){
        y = im.h;
    }
    else if(y < 0){
        y = 0;
    }

    return im.data[(c * im.h * im.w) + (im.w * y) + x];

}

void set_pixel(image im, int x, int y, int c, float v)
{
    if(x > im.w){
        return;
    }
    else if(x < 0){
        return;
    }
    if(y > im.h){
        return;
    }
    else if(y < 0){
        return;
    }
    im.data[(c * im.h * im.w) + (im.w * y) + x] = v;

}

image copy_image(image im)
{
    image copy = make_image(im.w, im.h, im.c);
    memcpy(copy.data, im.data, sizeof(float)*im.w * im.h * im.c);

    return copy;
}

image rgb_to_grayscale(image im)
{
    assert(im.c == 3);
    image gray = make_image(im.w, im.h, 1);
    for (int j = 0; j < im.h; j++){
        for (int k = 0; k < im.w; k++){
            // printf("Red:- %d\n", k + (im.w * j) * 1 );
            // printf("Green:- %d\n", k + (im.w * j) * 2 );
            // printf("Blue:- %d\n", k + (im.w * j) * 3 );
            // float red = 0.299 * (k + (im.w * j));
            // float green = 0.587 * ((k + (im.w * j)) * 2);
            // float blue = 0.114 * ((k + (im.w * j)) * 3);
            float red = im.data[(k + (im.w * j))];
            float green = im.data[((k + (im.w * j)) + (im.h * im.w) )];
            float blue = im.data[((k + (im.w * j)) + (im.h * im.w * 2))];
            gray.data[k + (im.w * j)] = (0.299 * red) + (0.587 * green) + (0.114 * blue);
           
        }
    }
    
    return gray;
}

void shift_image(image im, int c, float v)
{
    for (int j = 0; j < im.h; j++){
        for (int k = 0; k < im.w; k++){
            im.data[((k + (im.w * j)) + (im.h * im.w * c))] += v;          
        }
    }
}

void clamp_image(image im)
{
    // TODO Fill this in
}


// These might be handy
float three_way_max(float a, float b, float c)
{
    return (a > b) ? ( (a > c) ? a : c) : ( (b > c) ? b : c) ;
}

float three_way_min(float a, float b, float c)
{
    return (a < b) ? ( (a < c) ? a : c) : ( (b < c) ? b : c) ;
}

void rgb_to_hsv(image im)
{
    // TODO Fill this in
}

void hsv_to_rgb(image im)
{
    // TODO Fill this in
}
