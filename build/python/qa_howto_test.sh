#!/bin/sh
export GR_DONT_LOAD_PREFS=1
export srcdir=/home/zitouni/git/workspace/gr-compare-vector/python
export PATH=/home/zitouni/git/workspace/gr-compare-vector/build/python:$PATH
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$DYLD_LIBRARY_PATH
export DYLD_LIBRARY_PATH=$LD_LIBRARY_PATH:$DYLD_LIBRARY_PATH
export PYTHONPATH=/home/zitouni/git/workspace/gr-compare-vector/build/swig:$PYTHONPATH
/usr/bin/python /home/zitouni/git/workspace/gr-compare-vector/python/qa_howto.py 
