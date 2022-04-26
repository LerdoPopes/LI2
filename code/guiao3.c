#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "operators.h"
#include "stack.h"
#include <math.h>
#include "type_changes.h"

void coloca(STACK *s, Container *vars, char *token){
    Container x = pop(s);
    int ascii = token[1];
    vars[ascii-65] = x;
    push(s,x);
}

void ifelse(STACK *s){
    Container z = pop(s);
    Container y = pop(s);
    Container x = pop(s);
    if(isZero(x)) push(s,y);
    else push(s,z);
}

void igual(STACK *s){
    Container y = pop(s);
    Container x = pop(s);
    if(comparaCont(x,y) == 1)
    {
        Container True;
        True.label = 2;
        True.type.numI = 1;
        push(s,True);
    }
    else
    {
        Container False;
        False.label = 2;
        False.type.numI = 0;
        push(s,False);
    }
}

void maior(STACK *s){
    Container y = pop(s);
    Container x = pop(s);
    x = toDouble(x);
    y = toDouble(y);
    if(comparaCont(x,y) == 2)
    {
        Container True;
        True.label = 2;
        True.type.numI = 1;
        push(s,True);
    }
    else
    {
        Container False;
        False.label = 2;
        False.type.numI = 0;
        push(s,False);
    }
}

void menor(STACK *s){
    Container y = pop(s);
    Container x = pop(s);
    x = toDouble(x);
    y = toDouble(y);
    if(comparaCont(x,y) == 3)
    {
        Container True;
        True.label = 2;
        True.type.numI = 1;
        push(s,True);
    }
    else
    {
        Container False;
        False.label = 2;
        False.type.numI = 0;
        push(s,False);
    }
}

void eAnd(STACK *s){
    Container y = pop(s);
    Container x = pop(s);
    if (isZero(x) && isZero(y))
    {
        push(s,y);
    }
    else{
        Container False;
        False.label = 2;
        False.type.numI = 0;
        push(s,False);
    }
}

void eOr(STACK *s){
    Container y = pop(s);
    Container x = pop(s);
    if (isZero(x))
    {
        push(s,x);
    }
    else if(isZero(y))
    {
        push(s,y);
    }
    else{
        Container False;
        False.label = 2;
        False.type.numI = 0;
        push(s,False);
    }
}

void eMaior(STACK *s){
    Container y = pop(s);
    Container x = pop(s);
    if(comparaCont(x,y) == 3)
    {
        push(s,y);
    }
    else
    {
        push(s,x);
    }
}

void eMenor(STACK *s){
    Container y = pop(s);
    Container x = pop(s);
    if(comparaCont(x,y) == 3)
    {
        push(s,x);
    }
    else
    {
        push(s,y);
    }
}

void nots(STACK *s){
    Container x = pop(s);
    x = toDouble(x);
    if (isZero(x))
    {
        Container False;
        False.label = 2;
        False.type.numI = 0;
        push(s,False);
    }
    else
    {
        Container True;
        True.label = 2;
        True.type.numI = 1;
        push(s,True);
    }
}