#!/bin/sh
export GR_DONT_LOAD_PREFS=1
export srcdir=/home/zitouni/git/workspace/gr-compare-vector/lib
export PATH=/home/zitouni/git/workspace/gr-compare-vector/build/lib:$PATH
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$DYLD_LIBRARY_PATH
export DYLD_LIBRARY_PATH=$LD_LIBRARY_PATH:$DYLD_LIBRARY_PATH
export PYTHONPATH=$PYTHONPATH
qa_howto_compare_vector_cci 
