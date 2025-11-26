#!/bin/bash

ARCH_1=$(uname -a | awk '{print ""$1 " $2" " $3" " $4" " $5""}')
ARCH_2=$(cat /etc/redhat-release | awk '{print ""$1" " $4""}')
ARCH_3=$(uname -a | awk '{print ""$7" " $8" " $9" " $10" " $11" " $12" " $13" " $16""}')
KERNEL=$(uname -r)
CPU_PHYS=$(lscpu | grep "Core(s)" | awk '{print $4}')
VCPU=$(lscpu | grep "Thread(s)" | awk '{print $4}')
LAST_BOOT=$(who -b | awk '{print $3, $4}')
LVM=$(if [ $(lsblk | grep "lvm" | wc -l) -eq 0 ]; then echo no; else echo yes; fi)
TCP=$(ss --neopt | grep "ESTAB" | wc -l)
USER_LOG=$(users | wc -w)
IP=$(hostname -I)
MAC=$(/usr/sbin/ip link show | /usr/bin/grep "ether" | /usr/bin/awk '{print $2}')
SUDO=$(journalctl _COMM=sudo | grep COMMAND | wc -l)
cpu_load=$(top -bn1 | tail +8 | awk '{cpul += $9} END {printf("%.1f"), cpul}')
DISK=$(df -BG --output=size,used,pcent / | awk 'NR==2 {printf "%s/%s (%s)\n", $2, $1, $3}')
RAM=$(free -m | awk 'NR==2 {printf "%.0f/%.0fMB (%.2f%%)", $3, $2, $3*100/$2}')
wall << EOF

-------------------------------------------------------------
System Monitoring Report ($(date))
-------------------------------------------------------------
  OS Architecture :$ARCH_1 $ARCH_2 $ARCH_3
  Kernel          : $KERNEL
  Physical CPUs   : $CPU_PHYS
  Virtual CPUs    : $VCPU
  RAM             : $RAM
  Disk /          : $DISK
  CPU Utilization : ${cpu_load}%
  Last Reboot     : $LAST_BOOT
  LVM Active      : $LVM
  Connections     : $TCP TCP active
  Users Logged In : $USER_LOG
  Network (IPv4)  : $IP
  Network (MAC)   : $MAC
  Sudo Commands   : $SUDO executed
-------------------------------------------------------------

EOF