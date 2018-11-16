#! /bin/bash -
pid=${1?Please give a pid}
while
  [ "$pid" -gt 0 ] &&
    read -r ppid name < <(ps -o ppid= -o comm= -p "$pid")
do
  printf '%s\n' "$pid $name"
  pid=$ppid
done
