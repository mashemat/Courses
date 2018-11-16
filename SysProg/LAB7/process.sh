#
#    [] denote identical branches (child process).
#    {} denote child thread.

#So n[{process_name}] meaning you have n threads under parent process process_name.

ps -eo pid,ppid,stat,cmd | awk -v pr=$1 -f awk.sh 
