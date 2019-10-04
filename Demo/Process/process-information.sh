if [ $# == 1 ]; then
	echo "Pid:    $1"
	cat /proc/$1/status | grep PPid
	cat /proc/$1/status | grep Groups
	echo "SessionID:  "`cat /proc/$1/sessionid`
	echo "Memory Maps:"
	cat /proc/$1/maps
	echo "Arguments from cmdline: "`cat /proc/$1/cmdline`
else
	echo "Usage: sh process-information.sh pid"
fi
