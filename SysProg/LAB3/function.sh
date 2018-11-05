#!/bin/bash

# Introducing the variables

var_scope () {
local gv1='local init'
gv2='Changed inside'
echo Inside function: gv1 is $gv1 : gv2 is $gv2
}

gv1='global init'
gv2='global init'

echo Before call: gv1 is $gv1 : gv2 is $gv2
var_scope
echo After call: gv1 is $gv1 : gv2 is $gv2

