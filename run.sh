#!/bin/bash


DEST=$1
PROJECT_NAME=$2

if [ -d $DEST ]; then
    echo project name: $PROJECT_NAME
    cp -r $PWD/template $DEST
    mv $DEST/template $DEST/$PROJECT_NAME
else
    echo destination path doesn\'t exist;
fi



