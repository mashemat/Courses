#!/bin/bash

LOGDATE=$(date +%Y%m%dT%H%M%S)
LOG_FILE="down_col.log"


message() {
    [ "$2" = OK ] && color=2 || color=1
    printf "%s\n" "$(tput setaf "$color")" "$1" 
} 

collect()
{

    pushd $HOME/Downloads

    if [ $? = 0 ]; 
      then           
       message "change directory to Download" "OK"
      else
       message "error changing directory to Download" "ERR"
    fi

    name="${LOGDATE}@$1"
    mkdir  -p $HOME/back_download
    tar -cvf $HOME/back_download/$name.tar * 2>> $HOME/$LOG_FILE.$$
    if [ $? = 0 ]; 
       then           
          message "Download folder archived" "OK"
       else
          message "archiving download folder  failed" "ERR"
       fi
}

echo "start collecting Download Folder"
collect $1
rm -rf * 
popd
echo "end"
