get_time(){
	date '+%y-%m-%M %a %T'
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

xsetroot -name "$(get_battery_charging_status)$(get_battery_combined_percent)% [☯$(get_mem)M]$(get_time) ST"
