LOG_FILE="excs_col.log"
LOGDATE=$(date +%Y%m%dT%H%M%S)
YEAR=2018
: '
This script can collect the excercise from home directory of users 
Then archive them. There is a state log as well.
'

message() {
    [ x"$2" = xOK ] && color=2 || color=1
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
	echo "passdd"
	continue	
    fi

    message "Change home directory to $user" "OK"
    
    cd /home/$user 

    if [ -d "$HOME/sysprog2018" ];
	then
          tar --append --file=$HOME/sysprog$YEAR/sysprog$YEAR.tar sysprog_$user\_$YEAR.zip
          logit $user 
        else
          mkdir $HOME/sysprog$YEAR
	  tar -cvf $HOME/sysprog$YEAR/sysprog$YEAR.tar sysprog_$user\_$YEAR.zip
          logit $user 
    fi
    done
}


echo "Initializing the list of users" > /$HOME/$LOG_FILE.$$

collect_user

echo "Collecting the excercise" >> /$HOME/$LOG_FILE.$$
message "Users computed and loged" "OK"


collect

message "Files collected and loged: check log file" "OK"

