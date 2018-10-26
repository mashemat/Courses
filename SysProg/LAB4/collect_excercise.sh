LOG_FILE="excs_col.log"
LOGDATE=$(date +%Y%m%dT%H%M%S)
YEAR=2018
: '
This script can collect the excercise from home directory of users 
Then archive them. There is a state log as well.
'

message() {
    [ "$2" = OK ] && color=2 || color=1
    printf "%s\n" "$(tput setaf "$color")" "$1" 
} 

logit() 
{
    echo "[${USER}][`date`] - ${*}" >> $HOME/sysprog$YEAR/${LOGDATE}
}

collect_user(){

## get UID limit ##
l=$(grep "^UID_MIN" /etc/login.defs)

## use awk to print  UID >= $UID_LIMIT ##
array=$(awk -F':' -v "limit=${l##UID_MIN}" '{ if ( $3 >= limit ) print $1}' /etc/passwd)

}

collect()
{
for user in $array
do
    if [ "$user" = "nobody" ];
	then 
	continue	
    fi
    
    cd /home/$user 2>> /$HOME/$LOG_FILE.$$

    if [ $? = 0 ]; 
      then           
       message "change home directory to $user" "OK"
      else
       message "error changing home directory to $user" "ERR"
    fi

    if [ -d "$HOME/sysprog2018" ];
	then
          tar --append --file=$HOME/sysprog$YEAR/sysprog$YEAR.tar sysprog_$user\_$YEAR.zip 2>> /$HOME/$LOG_FILE.$$
          if [ $? = 0 ]; 
            then           
              message "$user's file added" "OK"
              logit $user 
          else
              message "collecting $user's file failed" "ERR"
          fi
     else
          mkdir $HOME/sysprog$YEAR
	  tar -cvf $HOME/sysprog$YEAR/sysprog$YEAR.tar sysprog_$user\_$YEAR.zip 2>> /$HOME/$LOG_FILE.$$
          if [ $? = 0 ]; 
            then           
              message "$user's file added" "OK"
              logit $user 
          else
              message "collecting $user's file failed" "ERR"
          fi
    fi
    done
}

echo "#starting the script at [`date`]#" > /$HOME/$LOG_FILE.$$

collect_user

echo "#collecting excercise#" >> /$HOME/$LOG_FILE.$$
message "#Users computed#" "OK"

collect

echo "script finished check the log file for possible errors" 
