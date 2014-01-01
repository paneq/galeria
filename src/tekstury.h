#ifndef TEKSTURY_H
#define TEKSTURY_H

#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>
#include <GL/gl.h>

struct BMPImage
{
    int   width;
    int   height;
    char *data;
};

struct Vertex
{
    float tu, tv;
    float x, y, z;
};

void getBitmapImageData( const char *pFileName, BMPImage *pImage );
BMPImage loadTexture( const char *pFileName, GLuint &g_textureID );

#endif

