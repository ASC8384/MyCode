get_time(){
	date '+%y-%m-%d %a %T'
}

get_mem(){
	memfree=$(($(grep -m1 'MemAvailable:' /proc/meminfo | awk '{print $2}') / 1024))
	echo -e "$memfree"
}

get_battery_combined_percent() {
	# get charge of all batteries, combine them
	total_charge=$(expr $(acpi -b | awk '{print $4}' | grep -Eo "[0-9]+" | paste -sd+ | bc));
	# get amount of batteries in the device
	battery_number=$(acpi -b | wc -l);

	percent=$(expr $total_charge / $battery_number);
	echo $percent;
}


get_battery_charging_status() {
	if $(acpi -b | grep --quiet Discharging); then
		echo "🔋";
	else # acpi can give Unknown or Charging if charging, https://unix.stackexchange.com/questions/203741/lenovo-t440s-battery-status-unknown-but-charging
		echo "🔌";
	fi
}

get_cpu() {
    # 计算CPU使用率(上一秒)
    # CPU使用率计算公式：CPU_USAGE=(IDLE2-IDLE1) / (CPU_TIME2-CPU_TIME1) * 100
    # CPU_TIME计算公式 ：CPU_TIME=user + system + nice + idle + iowait + irq + softirq
    PRE_CPU_INFO=$(cat /proc/stat | grep -w cpu | awk '{print $2,$3,$4,$5,$6,$7,$8}')
    IDLE1=$(echo $PRE_CPU_INFO | awk '{print $4}')
    CPU_TIME1=$(echo $PRE_CPU_INFO | awk '{print $1+$2+$3+$4+$5+$6+$7}')

    # 计算CPU使用率(下一秒)
    NEXT_CPU_INFO=$(cat /proc/stat | grep -w cpu | awk '{print $2,$3,$4,$5,$6,$7,$8}')
    IDLE2=$(echo $NEXT_CPU_INFO | awk '{print $4}')
    CPU_TIME2=$(echo $NEXT_CPU_INFO | awk '{print $1+$2+$3+$4+$5+$6+$7}')
    # (IDLE2 - IDLE1)
    SYSTEM_IDLE=`echo ${IDLE2} ${IDLE1} | awk '{print $1-$2}'`
    # (CPU_TIME2 - CPU_TIME1)
    TOTAL_TIME=`echo ${CPU_TIME2} ${CPU_TIME1} | awk '{print $1-$2}'`
    # (IDLE2-IDLE1) / (CPU_TIME2-CPU_TIME1) * 100
	# CPU UASGE
    echo ${SYSTEM_IDLE} ${TOTAL_TIME} | awk '{printf "%.2f", 100-$1/$2*100}'
}

cpu=`top -b -n1 | fgrep "Cpu(s)" | tail -1 | awk -F'id,' '{split($1, vs, ","); v=vs[length(vs)]; sub(/\s+/, "", v);sub(/\s+/, "", v); printf "%.1f", 100-v;}'`

xsetroot -name "💻$cpu|$(get_battery_charging_status)$(get_battery_combined_percent)% [☯$(get_mem)M]$(get_time)🕑ST"
