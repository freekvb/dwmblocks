//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {

    /*Icon*/	    /*Command*/		/*Update Interval*/	    /*Update Signal*/


    {"    cpu ",     "top -bn 1 | awk '/^%Cpu/ {print int($2 + $4 + $6)\"%\"}' ",    1,    0 },

    {"temp ",       "sensors | awk '/^Package/ { print $4+0\"°C\" }' ",    1,    0 },

    {"load ",       "cat /proc/loadavg | awk '{print $1, $2, $3}' ",    1,    0 },

    {"mem ",        "free -h | awk '/^Mem/ { print $3\"/\"$2 }' | sed s/i//g ",    5,	   0 },

    {"root ",       "df -h | awk '/^/dev/sda3/ { print $5 } ' ",   60,    0 },

    {"home ",       "df -h | awk '/^/dev/sda4/ { print $5 } ' ",   60,    0 },

    {"upd ",        "checkupdates | wc -l ",    10,    0 },

    {"mail ",       "mail_check ",    10,    0 },

    {"vol ",        "amixer sget Master | awk -F\"[][]\" '/%/ { print $2 }' | head -n1 ",    1,    0 },

	{" ",            "date '+%a %d %b %y   %H:%M ' ",    10,    0 },

};

//sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char delim[] = "    ";
static unsigned int delimLen = 5;
