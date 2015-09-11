//
//  Object.h
//  AugmentedPlatformer
//
//  Created by Tom Woudenberg on 12/17/2013.
//  Copyright (c) 2013 Tom Woudenberg. All rights reserved.
//

#ifndef __AugmentedPlatformer__Object__
#define __AugmentedPlatformer__Object__

#include <iostream>

class Object{
public:
    float position[3];
    float scale[3];
    int shape;
    float color[3];
    
    Object();
    void set(float, float,float,float,float,float,float,float,float,int);
    
    void drawObject(void);
    
};

#endif /* defined(__AugmentedPlatformer__Object__) */
